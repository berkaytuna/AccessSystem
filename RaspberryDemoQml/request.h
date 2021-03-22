#ifndef REQUEST_H
#define REQUEST_H

#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>

namespace reqCst {
    static const struct {
        QString setDeviceCommunicationPortRequest = "CDI_Shared_PCL.DataObjects.SetDeviceCommunicationPortRequest";
        QString accessWithPriceRequest = "CDI_Shared_PCL.DataObjects.AccessWithPriceRequest";
    } commandTypeNames;

    static const struct {
        QVector <QString> base = { "DeviceIp", "DevicePort", "ID", "CommandTypeName",
                                       "IsResponse", "IsNotification" };
        QVector <QString> comPort = { "DeviceCommuniationIp", "DeviceCommunicationPort" };
        QVector <QString> accessPrice = { "CardNumber", "Price", "SelectedTime" };
    } labels;

    enum requestType { ComPort, AccessPrice };
}

class RequestBase : public QJsonObject
{

public:
    explicit RequestBase(QString deviceIp, int devicePort, QString id,
                         QString commandTypeName, bool isResponse = false,
                         bool isNotification = false);
};

class ComPortReq : public RequestBase
{
public:
    explicit ComPortReq(QString comIp, int comPort, QString deviceIp,
                        int devicePort, QString id, QString commandTypeName,
                        bool isResponse = false, bool isNotification = false);
};

class AccessPriceReq : public RequestBase
{
public:
    explicit AccessPriceReq(QString cardNumber, double price, int time, QString deviceIp,
                            int devicePort, QString id, QString commandTypeName,
                            bool isResponse = false, bool isNotification = false);
};

#endif // REQUEST_H
