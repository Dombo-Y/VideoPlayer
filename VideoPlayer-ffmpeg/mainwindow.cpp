#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("加油~~~");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    qDebug()<<"aaaaaaaa";
    QStringList filenames  = QFileDialog::getOpenFileNames(this,"看看电影","C://Users/Administrator\Desktop",
                                                           "allfiles(*.*)"
                                                           "MP3(*.mp3);;"
                                                           "MP4(*.mp4);;"
                                                           "MKV(*mkv);;"
                                                           "AVI(*.AVI)");
//    QString filenames = QFileDialog::getOpenFileName(this,tr("选择文件"), "/", "All files (*)");
    foreach(QString const & str,filenames){
        qDebug() << str << "on_pushButton_clicked";
    }
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
}
