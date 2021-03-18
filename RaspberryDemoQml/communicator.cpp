#include <QTcpSocket>

#include "communicator.h"
#include "settings.h"
#include "request.h"

Communicator::Communicator(Settings &inSettings, QObject *parent)
    : QObject(parent)
{
    settings = &inSettings;

    connectToServer();
}

Communicator::~Communicator()
{
    delete settings;
    delete socket;
}

void Communicator::connectToServer()
{
    QString serverIp = settings->value(cst::settingsNames.lines[7]).toString();
    qDebug() << "serverIp: " << serverIp;

    socket = new QTcpSocket(this);
    connect(socket, &QAbstractSocket::readyRead, this, &Communicator::readyRead);
    connect(socket, &QAbstractSocket::connected, this, &Communicator::connected);
    socket->connectToHost(serverIp, 8150);
}

void Communicator::disconnect()
{

}

void Communicator::connected()
{
    sendComPortRequest();
}

void Communicator::readyRead()
{
    QString msg = socket->readAll();
    qDebug() << "from server: " << msg;

    QJsonDocument doc = QJsonDocument::fromJson(msg.toUtf8());
    QJsonObject obj = doc.object();
    bool isAccessGranted = obj.value("AccessGranted").toBool();

    qDebug() << "isAccessGranted: " << isAccessGranted;

    //settings->setBResult(true);
    settings->setBSuccess(isAccessGranted);
    settings->setCurrentV(2);
}

void Communicator::sendComPortRequest()
{
    ComPortReq comPortReq("192.168.2.152", socket->localPort(), "192.168.2.152", 1,
                          "d8dcbf42-c51b-4c1e-9d7d-d187c9ba847a",
                          reqCst::commandTypeNames.setDeviceCommunicationPortRequest);
    QByteArray data = QJsonDocument(comPortReq).toJson();
    data.remove(data.length() - 1, 1);

    qDebug() << data;
    socket->write(data);
}

void Communicator::sendAccessPriceRequest(QString cardNumber, double price, int time)
{
    AccessPriceReq accessPriceReq(cardNumber, price, time, "192.168.2.152", 1,
                                  "d8dcbf42-c51b-4c1e-9d7d-d187c9ba847a",
                                  reqCst::commandTypeNames.accessWithPriceRequest);
    QByteArray data = QJsonDocument(accessPriceReq).toJson();
    data.remove(data.length() - 1, 1);

    qDebug() << data;
    socket->write(data);
}

