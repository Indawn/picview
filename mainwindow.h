#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "picfunction.h"
#include <QMainWindow>

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



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionClose_triggered();

    void on_actionOpen_triggered();

    void on_actionGrey_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
