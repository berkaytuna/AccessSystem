#include "request.h"

AccessPriceReq::AccessPriceReq(QString cardNumber, double price, int time,
                               QString deviceIp,int devicePort, QString id,
                               QString commandTypeName, bool isResponse, bool isNotification)
    : RequestBase(deviceIp, devicePort, id, commandTypeName, isResponse, isNotification)
{
    insert(reqCst::labels.accessPrice[0], cardNumber);
    insert(reqCst::labels.accessPrice[1], price);
    insert(reqCst::labels.accessPrice[2], time);
}

ComPortReq::ComPortReq(QString comIp, int comPort, QString deviceIp,
                       int devicePort, QString id, QString commandTypeName,
                       bool isResponse, bool isNotification)
    : RequestBase(deviceIp, devicePort, id, commandTypeName, isResponse, isNotification)
{
    insert(reqCst::labels.comPort[0], comIp);
    insert(reqCst::labels.comPort[1], comPort);
}

RequestBase::RequestBase(QString deviceIp, int devicePort, QString id,
                         QString commandTypeName, bool isResponse, bool isNotification)
{
    /*QJsonObject a;
    a.insert("ali", 3);
    a.insert("veli", "bb");
    a.insert("deli", true);

    QJsonDocument b(a);

    qDebug() << b.toJson();
    QFile file("test");
    file.open(QIODevice::WriteOnly);
    file.write(b.toJson());
    file.close();*/

    insert(reqCst::labels.base[0], deviceIp);
    insert(reqCst::labels.base[1], devicePort);
    insert(reqCst::labels.base[2], id);
    insert(reqCst::labels.base[3], commandTypeName);
    insert(reqCst::labels.base[4], isResponse);
    insert(reqCst::labels.base[5], isNotification);
}
