#include "imggrabber.h"
#include <QtNetwork>
#include <QUrl>

ImgGrabber::ImgGrabber(QObject *parent) :
    QObject(parent)
{
    connect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(handleNetworkData(QNetworkReply*)));
}

void ImgGrabber::handleNetworkData(QNetworkReply *networkReply){
    QUrl url = networkReply->url();
    if (!networkReply->error()) {
        // Handle downloaded data
    }else{
        // Error Message
    }

}
