#include "photofinder.h"
#include <QString>

photoFinder::photoFinder(QByteArray in)
{
    this->content = in;
    indexOfPage = 0;
    indexOfPhoto = 0;
}

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
    int indexOfClass = content.indexOf("class=\"Next\"");
    QByteArray cut = content.left(indexOfClass);
    int indexOfUrl = cut.lastIndexOf("href=\"") + sizeof("href=\"");
    int indexOfLastQuote = cut.lastIndexOf("\"");
    QString path = cut.mid(indexOfUrl-1, indexOfLastQuote - indexOfUrl+1);
    return path;
}

QString photoFinder::nextPhoto(){
    int indexOfContainer = content.indexOf("<span class=\"photo_container", this->indexOfPhoto);
    int indexOfRight = content.indexOf("<div class=\"title\">", this->indexOfPhoto);
    QByteArray cut = content.mid(indexOfContainer, indexOfRight);
    int start = cut.indexOf("<a href=\"") + sizeof("<a href=\"");
    int end = cut.indexOf("\"", start + 1);
    QString path = cut.mid(start - 1, end - start + 1);
    this->indexOfPhoto = indexOfRight + 10;
    return path;
}
