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
//    MainWindow w;
//    w.show();
    QFile file("flickr.html");
    if( file.exists() ){
        if( file.open(QIODevice::ReadOnly) ){
            //QMessageBox::about(NULL,"","file opened");
            photoFinder pf(file.readAll());
            while(pf.hasPhoto()){
                //get photo link
//                QMessageBox::about(NULL,"hasPhoto","has photo");
                std::cout<<"has photo"<<endl;
            }
            while(pf.hasPage()){
                //get next page link
//                QMessageBox::about(NULL,"","has page");
                std::cout<<"has page"<<endl;
            }
        }
    }


    //return a.exec();
    return 0;
}
