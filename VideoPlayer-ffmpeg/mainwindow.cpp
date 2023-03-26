#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

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
