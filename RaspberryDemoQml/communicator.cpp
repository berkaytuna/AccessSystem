#include <QTcpSocket>
#include <QTimer>
#include <QThread>

#include "communicator.h"
#include "settings.h"
#include "request.h"
#include "bcm2835.h"

#define PIN0 RPI_BPLUS_GPIO_J8_40
#define PIN1 RPI_BPLUS_GPIO_J8_36

Communicator::Communicator(Settings &inSettings, QObject *parent)
    : QObject(parent)
{
    settings = &inSettings;

    connectToServer();

    bcm2835_init();
    bcm2835_gpio_fsel(PIN0, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(PIN1, BCM2835_GPIO_FSEL_OUTP);
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

    settings->setText(obj.value("Message").toString());

    qDebug() << "isAccessGranted: " << isAccessGranted;

    //settings->setBResult(true);
    settings->setBSuccess(isAccessGranted);
    settings->setCurrentV(2);

    if (isAccessGranted) {
        int pin = settings->currentD() ? PIN0 : PIN1;
        bcm2835_gpio_write(pin, HIGH);
    }

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Communicator::resetUI);
    timer->setSingleShot(true);
    timer->start(5000);
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

void Communicator::resetUI()
{
    bcm2835_gpio_write(PIN0, LOW);
    bcm2835_gpio_write(PIN1, LOW);
    settings->setText("Please choose...");

    qDebug() << "returned to main screen";
    settings->setBSuccess(false);
    settings->setCurrentV(0);
    delete timer;
}
