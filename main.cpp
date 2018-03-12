#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
  //  Picfunction picf;
    //picf = new Picfunction();
    return a.exec();
}
