#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QtNetwork>
#include <QXmlStreamReader>



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
//        content = content.replace("<", "&lt;");
//        content = content.replace(">", "&gt;");
//        ui->status->append(content);


        ui->status->append("Parsing HTML .....");
        QXmlStreamReader xml(response);
        while(!xml.atEnd()){
            xml.readNext();
            ui->status->append( xml.name().toString() );
        }
        if( xml.hasError() ){
            ui->status->append("parse failed");
            ui->status->append( xml.errorString() );
        }

        //ui->status->append(response);
        //ui->status->append("done");
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
