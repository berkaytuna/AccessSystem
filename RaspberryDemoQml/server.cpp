#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>
#include <QCoreApplication>
#include <QProcess>
//#include <QSettings>

//#include "settings.h"
#include "server.h"
#include "constants.h"

Server::Server(Settings &inSettings, QObject *parent)
    : QObject(parent)
{
    settings = &inSettings;
    if (QFile(cst::getPath()).exists())
        setSettings();
    server = new QTcpServer(this);
    connect(server, &QTcpServer::newConnection, this, &Server::newConnection);
    qDebug() << "Listening: " << server->listen(QHostAddress::Any, 8080);
}

Server::~Server()
{
    delete socket;
    delete server;
    delete settings;
}

void Server::newConnection()
{
    socket = server->nextPendingConnection();
    connect(socket, &QAbstractSocket::disconnected, this, &Server::disconnected);
    settings->setIsConnectedToSettings(true);
    //settings->sendDebugMessage("connected!");

    qDebug() << "socket: " << socket;
    //settings->sendDebugMessage(socket->toString());

    connect(socket, &QAbstractSocket::readyRead, this, &Server::readyRead);
    QFile file(cst::getPath());
    file.open(QIODevice::ReadOnly);
    QByteArray data = file.readAll();

    qDebug() << "sending: " << data;
    //settings->sendDebugMessage("sending: " + QString(data));

    int sentBytes = socket->write(data);
    qDebug() << "sent bytes: " << sentBytes;
    //settings->sendDebugMessage("sent bytes: " + QString(sentBytes));
}

void Server::readyRead()
{
    //socket = static_cast<QTcpSocket*>(sender());
    QByteArray data = socket->readAll();

    if (data == "restart") {
        qApp->quit();
        QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
    }
    else {
        //qDebug() << "settingsReadyRead";
        qDebug() << "received: " << data;
        QFile file(cst::getPath());
        file.open(QIODevice::WriteOnly);
        file.write(data);
        file.close();

        settings->sync();
        setSettings();
    }
}

void Server::setSettings()
{
    //QSettings serverSettings(Settings::getPath(), QSettings::IniFormat);
    //settings->setDNum(settings->value(cst::labelNames.lines[1]).toInt());
    //settings->setDTypeOne(1);
    //settings->setDTypeTwo(0);

    settings->changeDoorSelection(); // initialNum, Interval

    // checkBox Layouts
    settings->isCheckedArrays.resize(cst::labelNames.devices.size());
    for (int i = 0; i < settings->isCheckedArrays.size(); i++) {
        settings->isCheckedArrays[i] = cst::readCheckBoxArr(settings, cst::labelNames.devices[i]);
    }

    // checkBoxes
    settings->isCheckedSingleArrays.resize(cst::labelNames.checkBoxes.size());
    for (int i = 0; i < settings->isCheckedSingleArrays.size(); i++) {
        settings->isCheckedSingleArrays[i] = settings->value(cst::labelNames.checkBoxes[i]).toBool();
    }
    settings->setB2D(settings->value(cst::labelNames.checkBoxes[12]).toBool());

    // comboBoxes
    for (int i = 0; i < cst::settingsNames.comboBoxes.size(); i++) {
        settings->typeNames.insert( i, (settings->value(cst::settingsNames.comboBoxes[i]).toString()) );
    }

    QString typeOneStr = settings->value(cst::settingsNames.comboBoxes[0]).toString();
    if (typeOneStr == "solarium")
        settings->setDTypeOne(0);
    else if (typeOneStr == "massage")
        settings->setDTypeOne(1);

    QString typeTwoStr = settings->value(cst::settingsNames.comboBoxes[1]).toString();
    if (typeTwoStr == "solarium")
        settings->setDTypeTwo(0);
    else if (typeTwoStr == "massage")
        settings->setDTypeTwo(1);
}

void Server::send(const QString &msg)
{
    qDebug() << "sending: " << msg;
    socket->write(msg.toUtf8());
}

void Server::disconnected()
{
    settings->setIsConnectedToSettings(false);
}
