#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QNetworkAccessManager>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
}
