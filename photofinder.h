#ifndef PHOTOFINDER_H
#define PHOTOFINDER_H
#include <QString>

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
    int indexOfPhoto;
    int indexOfPage;
};

#endif // PHOTOFINDER_H
