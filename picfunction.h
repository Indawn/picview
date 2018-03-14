#ifndef PICFUNCTION_H
#define PICFUNCTION_H

#include <QObject>
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


class Picfunction//: public Picfunction
{
public:
  //  Picfunction *picf;

    Picfunction();
    ~Picfunction();
    int sum(int a, int b);
   // QImage cvMat2QImage(const cv::Mat& mat);
    QImage cvMat2QImage(Mat mat);
    Mat rgb2grey(Mat image);

private:
 //  Picfunction *picf;

};

#endif // PICFUNCTION_H
