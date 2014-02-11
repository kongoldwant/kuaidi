#ifndef GETINFO_H
#define GETINFO_H

#include<QString>
#include "jsondata.h"
#include <QList>

class getInfo
{
public:
    getInfo(QString path);
    QList<std::tuple<QString,QString>> insertIntoYuple();
    bool checkStatus();
    QString getMsg();
private:
    JsonData *jsondata;
};

#endif // GETINFO_H
