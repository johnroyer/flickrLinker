#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QNetworkAccessManager>
#include <QFile>
#include "photofinder.h"
#include <iostream>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();

}
