#include "photofinder.h"
#include <QString>

//photoFinder::photoFinder()
//{
//
//}

photoFinder::photoFinder(QByteArray in)
{
    this->content = in;
    indexOfPage = 0;
    indexOfPhoto = 0;
}

//void photoFinder::setContent(QString in){
//    this->content = in;
//}
//
//bool photoFinder::setContent(QByteArray in){
//    this->content = in;
//}

bool photoFinder::hasPage(){
    if( content.indexOf("class=\"Next\"",indexOfPage) != -1){
        return true;
    }
    return false;
}

bool photoFinder::hasPhoto(){
    if( content.indexOf("photo_container",indexOfPhoto) != -1 ){
        return true;
    }

    return false;
}

QString photoFinder::nextPage(){
    indexOfPage = content.indexOf("class=\"Next\"" ,indexOfPage) + 100;
    return NULL;
}

QString photoFinder::nextPhoto(){
    indexOfPhoto = content.indexOf("photo_container",indexOfPhoto) + 100;
    return NULL;
}
