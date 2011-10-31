#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QtNetwork>
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
        QString link = url.toString();
        QString pageNumber = link.mid(link.indexOf("page"), link.lastIndexOf("/") - 1 );
        ui->statusBar->showMessage("Reading " + pageNumber);

        while(pf.hasPhoto()){
            QString path = pf.nextPhoto();
            path = "http://www.flickr.com" + path;
            ui->status->append(path);
        }

        if(pf.hasPage()){
            QString page = pf.nextPage();
            page = "http://www.flickr.com" + page;
            networkManager.get(QNetworkRequest(QUrl(page)));
        }else{
            ui->statusBar->showMessage("Finished", 5);
            ui->pushButton->setEnabled(true);
        }
    }else{
        ui->statusBar->showMessage("Error", 10);
    }

}

void MainWindow::on_pushButton_clicked()
{
    ui->status->setText("");
    ui->pushButton->setEnabled(false);

    QString homeUrl = ui->homeUrl->text();
    if(homeUrl.indexOf("www.flickr.com") != -1 && homeUrl.indexOf("photos") != -1
       && homeUrl.indexOf("http") != -1){
        // Get content
        QUrl url(homeUrl);
        ui->statusBar->showMessage("Reading URL: " + homeUrl);
        networkManager.get(QNetworkRequest(url));
    }else{
        // URL incorrect
        QMessageBox::warning(NULL,"Alert","Please input a Flickr photo stream URL.\nLike: http://www.flickr.com/photos/myphoto/");
        ui->pushButton->setEnabled(true);
    }

}
