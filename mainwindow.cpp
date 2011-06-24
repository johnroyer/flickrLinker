#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QtNetwork>
#include <QXmlStreamReader>
#include "photofinder.h"
#include <iostream>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(handleNetworkData(QNetworkReply*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleNetworkData(QNetworkReply *networkReply){
    QUrl url = networkReply->url();
    if (!networkReply->error()) {
        QByteArray response(networkReply->readAll());
        QString content(response);

        photoFinder pf(response);
        ui->status->append("Parsing HTML .....");

        while(pf.hasPhoto()){
            QString path = pf.nextPhoto();
            path = "http://www.flickr.com" + path;
            ui->status->append(path + "\n");
//            QMessageBox::about(NULL, "path", path);
        }

        if(pf.hasPage()){
            QString page = pf.nextPage();
            page = "http://www.flickr.com" + page;
            ui->status->append("Has another page: " + page + "\n");
        }
    }else{
        ui->status->append("error");
    }

}

void MainWindow::on_pushButton_clicked()
{
    ui->status->setText("");

    QString homeUrl = ui->homeUrl->text();
    QUrl url(homeUrl);
    ui->status->append("Set URL to " + homeUrl);

    networkManager.get(QNetworkRequest(url));

}
