#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QObject>
#include <list>

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavutil/avutil.h>
#include <libswresample/swresample.h>
#include <libswscale/swscale.h>
}

#define ERROR_BUF \
    char errbuf[1024]; \
    av_strerror(ret, errbuf, sizeof (errbuf));

#define CODE(func, code) \
    if (ret < 0) { \
        ERROR_BUF; \
        qDebug() << #func << "error" << errbuf; \
        code; \
    }

#define END(func) CODE(func, fataError(); return;)
#define RET(func) CODE(func, return ret;)
#define CONTINUE(func) CODE(func, continue;)
#define BREAK(func) CODE(func, break;)


class videoPlayer : public QObject
{
    Q_OBJECT
public:
    explicit videoPlayer(QObject *parent = nullptr);
    ~videoPlayer();

public:
    typedef enum {
        Stopped = 0,
        Playing,
        Paused
    } State;

    //视频参数
    typedef struct {
        int width;
        int height;
        AVPixelFormat pixFmt;
        int size;
    } VideoSwsSpec;

    void play(); // 播放
    void pause();// 暂停
    void stop(); //停止
    bool isPlaying(); // 正在播放中
    State getState(); // 获取当前状态
    void setFilename(QString &filename);// 设置文件名
    int getDuration(); //获取总时长
    int getTime(); //当前播放的时长
    void setTime();
    void setTime(int seekTime);

private:
    typedef  struct {
        int sampleRate;
        AVSampleFormat sampleFmt;
        int chLayout;
        int chs;
        int bytesPerSampleFrame;
    }AudioSwrSpec;


    AVCodecContext *_aDecodeCtx = nullptr;// 解码上下文
    AVStream *_aStream = nullptr;// 流
    std::list<AVPacket> _aPktList; // 存放音频包的列表
//    CondMutex _aMutex;// 音频包列表的锁
    SwrContext *_aSwrCtx = nullptr;// 音频重采样上下文
    AudioSwrSpec _aSwrInSpec, _aSwrOutSpec; // 音频重采样输入 、输出参数
    AVFrame *_aSwrInframe = nullptr, * _aSwrOutFrame = nullptr;
    int _aSwrOutIdx = 0; // 音频重采样初始PCM的索引（从哪个位置开始取出PCM数据填充到SDL的音频缓冲区）
    int _aSwrOutSize = 0;// 音频采样输出PCM的大小
    double _aTime = 0; // 音频时钟，当前音频包对应的时间值
    bool _aCanFree = false;// 音频资源是否可以释放
    int _aSeekTime = -1; // 外面设置的当前播放时刻（用于完成seek 功能）
    int _hasAudio = false; // 是否有音频流

    AVCodecContext *_vDecodeCtx = nullptr; // 解码上下文
    AVStream *_vStream = nullptr;// 流
    AVFrame *_vSwsInframe = nullptr, *_vSwsOutFrame = nullptr;// 像素格式转换的输入\输出frame
    SwsContext *_vSwsCtx = nullptr; // 像素格式转换的上下文
    VideoSwsSpec _vSwsOutSpec;// 像素格式转换的输出frame的参数
    std::list<AVPacket> _vPktList;//存放视频包的列表
//       CondMutex _vMutex;//视频包列表的锁
    double _vTime = 0;// 视频时钟，当前视频包对应的时间值
    bool _vCanFree = false; // 视频资源是否可以释放
    int _vSeekTime = -1;// 外面设置的当前播放时刻（用于完成seek功能）
    bool _hasVideo = false; // 是否有视频流

    /******** 其他 ********/
    AVFormatContext *_fmtCtx = nullptr;// 解封装上下文
    bool _fmtCtxCanFree = false; // fmtCtx是否可以释放
    int _volumn = 100; // 音量
    bool _mute = false; // 静音
    State _state = Stopped;// 当前的状态
    char _filename[512];// 文件名
    int _seekTime = -1;//  外面设置的当前播放时刻（用于完成seek功能）

//    /** 初始化解码器和解码上下文 */
    int initDecoder(AVCodecContext **decodeCtx,
                    AVStream **stream,
                    AVMediaType type);
//    /** 改变状态 */
    void setState(State state);
//    /** 读取文件数据 */
    void readFile();
//    /** 释放资源 */
    void free();
    void freeAudio();
    void freeVideo();
//    /** 严重错误 */
    void fataError();

signals:
//    void stateChanged(videoPlayer *player);
//    void timeChanged(videoPlayer *player);
//    void initFinished(videoPlayer *player);
//    void playFailed(videoPlayer *player);
//    void frameDecoded(videoPlayer *player, uint8_t *data, VideoSwsSpec &spec);

public slots:
};

#endif // VIDEOPLAYER_H