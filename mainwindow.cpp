#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>
#include <QFileDialog>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
/*

#include <opencv2/core/core.hpp>


#include <qtextcodec.h>

#include <QResizeEvent>
#include <QMessageBox>
#include <QTextCodec>

#include <QCoreApplication>

#include <math.h>
#include <QLabel>
#include <stdlib.h>
#include <stdio.h>
#include <opencv2/ml/ml.hpp>
#include "zbar.h"
using namespace zbar;
*/
using namespace std;
using namespace cv;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent ( QResizeEvent * event )
{
    scaledmat2label(mat_opened, ui->pic_label0);
 /*   statusBar()->removeWidget(aixLabel_pencentage);
    aixLabel_pencentage = new QLabel(QString::number(pecentage*100,10,2)+"%");
    statusBar()->addWidget(aixLabel_pencentage, 2);
    */
}





void MainWindow::on_actionClose_triggered()
{

}

void MainWindow::on_actionOpen_triggered()
{
    QFileDialog *fileDialog = new QFileDialog(this);//创建一个QFileDialog对象，构造函数中的参数可以有所添加。
    fileDialog->setWindowTitle(tr("Open"));//设置文件保存对话框的标题
    fileDialog->setAcceptMode(QFileDialog::AcceptOpen);//设置文件对话框为保存模式
    fileDialog->setFileMode(QFileDialog::AnyFile);//设置文件对话框弹出的时候显示任何文件，不论是文件夹还是文件
    fileDialog->setViewMode(QFileDialog::Detail);//文件以详细的形式显示，显示文件名，大小，创建日期等信息；
    //还有另一种形式QFileDialog::List，这个只是把文件的文件名以列表的形式显示出来
    fileDialog->setGeometry(10,30,300,200);//设置文件对话框的显示位置
    fileDialog->setDirectory(".");//设置文件对话框打开时初始打开的位置
    // fileDialog->setFilter(tr("Image Files(*.jpg *.png)"));//设置文件类型过滤器
    if(fileDialog->exec() == QDialog::Accepted)//注意使用的是QFileDialog::Accepted或者QDialog::Accepted,不是QFileDialog::Accept
    {
        QString  curr_picname = fileDialog->selectedFiles()[0];//得到用户选择的文件名
        mat_opened = imread(curr_picname.toLocal8Bit().constData());
        if(mat_opened.data)
        {
            scaledmat2label(mat_opened, ui->pic_label0);
        }
        /*
        statusBar()->setVisible(true);
        statusBar()->removeWidget(aixLabel);
        statusBar()->removeWidget(aixLabel_pencentage);
        aixLabel = new QLabel(curr_picname);
        aixLabel_pencentage = new QLabel(QString::number(pecentage*100,10,2)+"%");
        statusBar()->setStyleSheet(QString("QStatusBar::item{border: 0px}")); // 设置不显示label的边框
        statusBar()->addWidget(aixLabel, 1);
        statusBar()->addWidget(aixLabel_pencentage, 2);
        */
    }

}

void MainWindow::on_actionGrey_triggered()
{
    cvtColor(mat_opened, mat_opened, CV_RGB2GRAY);
    // mat_opened = imread("D:\\图片\\background (3).jpg");
    //   ui->pic_label0->clear();
    //    ui->pic_label0->setPixmap(QPixmap::fromImage(cvMat2QImage(mat_opened)));
    // ui->pic_label0->show();
    scaledmat2label(mat_opened, ui->pic_label0);
}
