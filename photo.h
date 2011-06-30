#ifndef PHOTO_H
#define PHOTO_H
#include <QString>
#include <QtNetwork>

class Photo
{
public:
    Photo();
    Photo(QString);
    void setUniqUrl(QString);
    QString getUniqUrl();
    QString getTitle();
    QString getAlt();
    QString getThumbUrl();
    QString getMediumUrl();
    QString getLargeUrl();
    QString getOrigUrl();
    QString getThumbImage();
    QString getMediumImage();
    QString getLargeImage();
    QString getOrigImage();

private:
    QString uniqUrl;
    QString alt;
    QString title;
};

#endif // PHOTO_H
