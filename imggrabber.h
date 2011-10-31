#ifndef IMGGRABBER_H
#define IMGGRABBER_H

#include <QObject>
#include <QtNetwork>

class ImgGrabber : public QObject
{
    Q_OBJECT
public:
    explicit ImgGrabber(QObject *parent = 0);

signals:

public slots:

private:
    QNetworkAccessManager networkManager;

private slots:
    void handleNetworkData(QNetworkReply *networkReply);

};

#endif // IMGGRABBER_H
