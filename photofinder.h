#ifndef PHOTOFINDER_H
#define PHOTOFINDER_H
#include <QString>
#include <QRegExp>

class photoFinder
{
public:
//    photoFinder();
    photoFinder(QByteArray);
//    void setContent(QString);
//    void setContent(QByteArray);
    bool hasPhoto();
    bool hasPage();
    QString nextPhoto();
    QString nextPage();

private:
    QByteArray content;
    QRegExp *rx;
    int indexOfPhoto;
    int indexOfPage;
};

#endif // PHOTOFINDER_H
