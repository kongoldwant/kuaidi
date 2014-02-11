#include "getinfo.h"

getInfo::getInfo(QString path)
{
    jsondata=new JsonData;
    jsondata->get_json_data(path);
}

 QList<std::tuple<QString,QString>> getInfo::insertIntoYuple()
 {
     QList<std::tuple<QString,QString>> infoList;
     QJsonObject hdtypeObj=jsondata->get_josn_object();
     QJsonArray  dataArray=hdtypeObj["data"].toArray();

     QJsonArray::iterator it;
     for(it=dataArray.begin();it!=dataArray.end();++it)
     {
         if((*it).isObject())
         {
             QJsonObject obj=(*it).toObject();

             QString time=obj.find("time").value().toString();
             QString context=obj.find("context").value().toString();
             qDebug()<<"time"<<time<<"context"<<context;
             infoList.append(std::make_tuple(time,context));
         }
     }
    return infoList;
 }

 bool getInfo::checkStatus()
 {
     QJsonObject hdtypeObj=jsondata->get_josn_object();
     QJsonValue  status=hdtypeObj["status"];
     if(status.isString())
     {
         QString strStatus=status.toString();
         qDebug()<<"状态:"<<strStatus;
         if(strStatus != "200")
             return false;
     }
     return true;
 }

  QString getInfo::getMsg()
  {
      QJsonObject hdtypeObj=jsondata->get_josn_object();
      QJsonValue  message=hdtypeObj["message"];
      if(message.isString())
      {
          QString strmessage=message.toString();
          qDebug()<<"状态:"<<strmessage;
          return strmessage;
      }
      return "";
  }
