#include "videoplayer.h"
#include <thread>
#include <QDebug>
#include <SDL2/SDL.h>

#define AUDIO_MAX_PKT_SIZE 1000
#define VIDEO_MAX_PKT_SIZE 500

videoPlayer::videoPlayer(QObject *parent) : QObject(parent)
{

    if(SDL_Init(SDL_INIT_AUDIO)){
        qDebug()<< "SDL_Init error" << SDL_GetError();
        return;
    }
}

videoPlayer::~videoPlayer() {
//    disconnect();
//    stop();
    SDL_Quit();
}

#pragma mark - 公共方法
void videoPlayer::play() {
    if(_state == Playing) return;
    if(_state == Stopped){
        // 开始线程：读取文件
        std::thread([this]() {
            readFile();
        }).detach();
    }else {
        // 改变状态
        setState(Playing);
    }
}

void videoPlayer::pause() {
    if(_state != Playing) return;
    setState(Paused);
}

void videoPlayer::stop() {
    if(_state == Stopped) return;
    _state = Stopped;
    free();
    emit stateChanged(this);
}

bool videoPlayer::isPlaying() {
    return  _state == Playing;
}

videoPlayer::State videoPlayer::getState() {
    return _state;
}

void videoPlayer::setFilename(QString &filename) {
    const char *name = filename.toStdString().c_str();
    memcpy(_filename,name, strlen(name) + 1);
}

int videoPlayer::getDuration() {
    double_t c_duration =_fmtCtx->duration * av_q2d(AV_TIME_BASE_Q);
    int temp_duration = static_cast<int>(round(c_duration));
    return _fmtCtx ? temp_duration : 0;
}

int videoPlayer::getTime() {
    return static_cast<int>(round(_aTime));
}

void videoPlayer::setTime(int seekTime) {
    _seekTime = seekTime;
}

#pragma mark - 私有方法
void videoPlayer::readFile() {
    int ret = 0;//返回结果

    ret = avformat_open_input(&_fmtCtx,_filename,nullptr,nullptr);// 创建解封装上下文、打开文件
    ret = avformat_find_stream_info(_fmtCtx,nullptr); //检索流信息
    av_dump_format(_fmtCtx,0,_filename,0);
    fflush(stderr);

    _hasAudio = initAudioInfo() >= 0; //初始化啊音频信息
    _hasVideo = initVideoInfo() >= 0; // 初始化视频信息
    if(!_hasAudio && !_hasVideo){
        fataError();
        return;
    }

//    emit initFinished(this);
    setState(Playing);
    SDL_PauseAudio(0);// 音频解码子程序开始工作
    //视频解码子程序：开始工作

    AVPacket pkt;//从输入文件中读取数据
    while(_state != Stopped){
        if(_seekTime >= 0) {
            int streamIdx;
            if(_hasAudio){
                streamIdx = _aStream->index;
            }else {
                streamIdx = _vStream->index;
            }

            //现实时间  -》 时间戳
            AVRational timeBase = _fmtCtx->streams[streamIdx]->time_base;
            int64_t ts = _seekTime / av_q2d(timeBase);
            ret = av_seek_frame(_fmtCtx, streamIdx, ts, AVSEEK_FLAG_BACKWARD);
            if(ret < 0) {
                qDebug() << "seek 失败" << _seekTime << ts << streamIdx;
                _seekTime = -1;
            }else {
                qDebug()<<"seek 成功" <<_seekTime << ts << streamIdx;
                _vSeekTime = _seekTime;
                _aSeekTime = _seekTime;
                _seekTime = -1;
                _aTime = 0;
                _vTime = 0;

//                // 清空之前读取的数据包
                clearAudioPktList();
                clearVideoPktList();
            }
        }
        int vSize = _vPktList.size();
        int aSize = _aPktList.size();
        if(vSize >= VIDEO_MAX_PKT_SIZE || aSize >= AUDIO_MAX_PKT_SIZE) {
                continue;
        }

        ret = av_read_frame(_fmtCtx, &pkt);
        if(ret == 0){
            if(pkt.stream_index == _aStream->index) { //读取到的是音频数据
                addAudioPkt(pkt);
            }else if(pkt.stream_index == _vStream->index) { // 读取到的是视频数据
                addVideoPkt(pkt);
            }else { //如果不是音频、视频，直接释放
                av_packet_unref(&pkt);
            }
        }else if(ret == AVERROR_EOF) {
            if(vSize == 0 && aSize == 0) {
                _fmtCtxCanFree = true;
                break;
            }
        } else {
            ERROR_BUF
            qDebug()<<"av_read_frame error" << errbuf;
            continue;
        }
    }
    if(_fmtCtxCanFree){ //文件正常播放完毕
        stop();
    }else {
        // 标记一下：_fmtCtx可以释放了
        _fmtCtxCanFree = true;
    }
}

//初始化解码器
int videoPlayer::initDecoder(AVCodecContext **decodeCtx, AVStream **stream, AVMediaType type) {
    int ret = av_find_best_stream(_fmtCtx,type,-1, -1, nullptr,0);
    RET(av_find_best_stream);

    int streamIdx = ret;
    *stream = _fmtCtx->streams[streamIdx];
    if(!*stream){
        qDebug()<<"stream is empty";
        return -1;
    }

    const AVCodec *decoder = nullptr;
    decoder = avcodec_find_decoder((*stream)->codecpar->codec_id);
    if(!decoder){
        qDebug() << "decoder not found" << (*stream)->codecpar->codec_id;
        return -1;
    }

    *decodeCtx = avcodec_alloc_context3(decoder);
    if(!decodeCtx){
        qDebug()<<"avcodec_alloc_context3 error";
        return -1;
    }

    ret = avcodec_parameters_to_context(*decodeCtx,(*stream)->codecpar);// 从流中拷贝参数到解码上下文中
    RET(avcodec_parameters_to_context);

    ret = avcodec_open2(*decodeCtx, decoder, nullptr);
    RET(avcodec_open2);
    return 0;
}

void videoPlayer::setState(State state) {
    if(state == _state) return;
    _state = state;
    emit stateChanged(this);
}

void videoPlayer::free(){

}

void videoPlayer::fataError() {
    _state = Playing;
    stop();

}


