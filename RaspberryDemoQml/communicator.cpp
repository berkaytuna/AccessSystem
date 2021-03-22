#include <QTcpSocket>
#include <QTimer>
#include <QThread>

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
    // Get server ip from settings
    QString serverIp = settings->value(cst::settingsNames.lines[7]).toString();
    qDebug() << "serverIp: " << serverIp;

    // Connect to the server
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
    // If connected, send "Add Communication Port Request"
    sendComPortRequest();
}

void Communicator::readyRead()
{
    // Read the message from server
    QString msg = socket->readAll();
    qDebug() << "from server: " << msg;

    // Convert the json message to an object
    QJsonDocument doc = QJsonDocument::fromJson(msg.toUtf8());
    QJsonObject obj = doc.object();

    // Send the json object to the manager
    emit hasJsonObject(obj);
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

/*void Communicator::resetUI()
{
    bcm2835_gpio_write(PIN0, LOW);
    bcm2835_gpio_write(PIN1, LOW);
    settings->setText("Please choose...");

    qDebug() << "returned to main screen";
    settings->setBSuccess(false);
    settings->setCurrentV(0);
    delete timer;
}*/
