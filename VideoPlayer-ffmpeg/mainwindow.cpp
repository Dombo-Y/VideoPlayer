#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include<SDL2/SDL.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("加油~~~");


//    qRegisterMetaType<videoPlayer::VideoSwsSpec>("VideoSwsSpec&");

//    _player = new videoPlayer();
//    connect(_player, &videoPlayer::stateChanged,this,&MainWindow::onPlayerStateChanged);
//    connect(_player, &videoPlayer::stateChanged,this,&MainWindow::onPlayerStateChanged);
//    connect(_player, &videoPlayer::stateChanged,this,&MainWindow::onPlayerStateChanged);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    qDebug()<<"aaaaaaaa";
    QStringList filenames  = QFileDialog::getOpenFileNames(this,"看看电影","/",
                                                           "视频文件(*.mp4 *.avi *.mkv);;"
                                                           "音频文件(*.mp3 *.acc)");
//    QString filenames = QFileDialog::getOpenFileName(this,tr("选择文件"), "/", "All files (*)");
    foreach(QString const & str,filenames){
        qDebug() << str << "on_pushButton_clicked";
    }// D:/github/VideoPlayer/video_001.mp4
}

void MainWindow::on_pushButton_2_clicked()
{
    qDebug()<<"bbbbbbb";
}

void MainWindow::on_pasueButton_3_clicked()
{
    qDebug()<<"ccccccc";
}

void MainWindow::on_stopButton_4_clicked()
{
    qDebug()<<"dddddddd";
    SDL_version version;
    SDL_VERSION(&version);
    qDebug() << version.major << version.patch;

}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    qDebug() << "on_horizontalSlider_valueChanged" << value;
}
