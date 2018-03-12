#include "picfunction.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "picfunction.h"
#include <iostream>


#include <QFileDialog>
#include <QLabel>
#include <qtextcodec.h>

#include <QResizeEvent>
#include <QMessageBox>
#include <QTextCodec>

#include <QCoreApplication>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <math.h>
#include <QLabel>
#include <stdlib.h>
#include <stdio.h>
#include <opencv2/ml/ml.hpp>
#include "zbar.h"


using namespace std;
using namespace cv;
using namespace zbar;
//using namespace PICF;

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

QImage cvMat2QImage(const cv::Mat& mat)
{
    // 8-bits unsigned, NO. OF CHANNELS = 1
    if(mat.type() == CV_8UC1)
    {
        QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
        // Set the color table (used to translate colour indexes to qRgb values)
        image.setColorCount(256);
        for(int i = 0; i < 256; i++)
        {
            image.setColor(i, qRgb(i, i, i));
        }
        // Copy input Mat
        uchar *pSrc = mat.data;
        for(int row = 0; row < mat.rows; row ++)
        {
            uchar *pDest = image.scanLine(row);
            memcpy(pDest, pSrc, mat.cols);
            pSrc += mat.step;
        }
        return image;
    }
    // 8-bits unsigned, NO. OF CHANNELS = 3
    else if(mat.type() == CV_8UC3)
    {
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return image.rgbSwapped();
    }
    else if(mat.type() == CV_8UC4)
    {
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
        return image.copy();
    }
    else
    {
        return QImage();
    }
}


void MainWindow::on_actionClose_triggered()
{

}

void MainWindow::on_actionOpen_triggered()
{
    Mat image0 = imread("D:\\1.jpg");

 //   Picfunction picf;// = Picfunction.Picfunction();
  //  image0 =picf.rgb2grey(image0);
    imshow("iamge",image0);
    ui->pic_label0->clear();
       ui->pic_label0->setPixmap(QPixmap::fromImage(cvMat2QImage(image0)));
    ui->pic_label0->show();
    //delete picf;
    /*   */
 //   int result0 =picf.sum(1,2);
//    cout<<result0<<endl;
  //  picf.~Picfunction();
}

void MainWindow::on_actionGrey_triggered()
{

}
