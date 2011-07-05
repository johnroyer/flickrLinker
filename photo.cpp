#include "photo.h"
#include <QDataStream>

Photo::Photo()
{
}

void Photo::setTitle(QString title){
    this->title = title;
}

void Photo::setUniqUrl(QString uniqUrl){
    this->uniqUrl = uniqUrl;
}

QString Photo::getUniqUrl(){
    return this->getUniqUrl();
}

QString Photo::getTitle(){
    return this->title;
}

QDataStream &operator<<(QDataStream &out, Photo &p){
    out << p.getTitle();
    return out;
}

QDataStream &operator>>(QDataStream &in, Photo &photo){
    QString url;
    QString title;
    in >> url >> title;
    photo.setUniqUrl(title);

    return in;
}
