#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager networkManager;

private slots:
    void handleNetworkData(QNetworkReply *networkReply);

private slots:
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
