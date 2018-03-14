#include "picfunction.h"
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
Picfunction::Picfunction()
{
   // picf = new Picfunction;
}
Picfunction::~Picfunction()
{
  //  delete picf;
    cout<<"delete picf"<<endl;
}
Mat Picfunction::rgb2grey(Mat image)
{
    cvtColor(image,image,CV_RGB2GRAY);
    return image;
}

int Picfunction::sum(int a, int b)
{
    int sum = a + b;
    return sum;
}

QImage cvMat2QImage(Mat mat)
{

    // 8-bits unsigned, NO. OF CHANNELS = 3

        // Copy input Mat
        const uchar *pSrc = mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return image.rgbSwapped();
}
