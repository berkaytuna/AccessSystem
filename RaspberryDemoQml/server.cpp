#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>
#include <QCoreApplication>
//#include <QSettings>

//#include "settings.h"
#include "server.h"
#include "constants.h"

Server::Server(Settings &inSettings, QObject *parent)
    : QObject(parent)
{
    settings = &inSettings;
    setSettings();
    server = new QTcpServer(this);
    connect(server, &QTcpServer::newConnection, this, &Server::newConnection);
    qDebug() << "Listening: " << server->listen(QHostAddress::Any, 8080);
}

Server::~Server()
{
    delete server;
    delete settings;
}

void Server::newConnection()
{
    QTcpSocket *socket = server->nextPendingConnection();
    qDebug() << "socket: " << socket;
    connect(socket, &QAbstractSocket::readyRead, this, &Server::readyRead);
    QFile file(cst::getPath());
    file.open(QIODevice::ReadOnly);
    QByteArray data = file.readAll();
    qDebug() << "sending: " << data;
    qDebug() << "sent bytes: " << socket->write(data);
}

void Server::readyRead()
{
    //qDebug() << "settingsReadyRead";
    QTcpSocket *socket = static_cast<QTcpSocket*>(sender());
    QByteArray data = socket->readAll();
    qDebug() << "received: " << data;
    QFile file(cst::getPath());
    file.open(QIODevice::WriteOnly);
    file.write(data);
    file.close();

    settings->sync();
    setSettings();
}

void Server::setSettings()
{
    //QSettings serverSettings(Settings::getPath(), QSettings::IniFormat);
    settings->setDNum(settings->value(cst::labelNames.lines[1]).toInt());
    settings->setDTypeOne(1);
    settings->setDTypeTwo(0);
    settings->setNum(settings->value(cst::labelNames.lines[2]).toInt());
    settings->setInterval(settings->value(cst::labelNames.lines[3]).toInt());

    // checkBox Layouts
    settings->isCheckedArrays.resize(cst::checkBoxLayoutCount);
    for (int i = 0; i < settings->isCheckedArrays.size(); i++) {
        settings->isCheckedArrays[i] = cst::readCheckBoxArr(settings, cst::labelNames.devices[i]);
    }

    // checkBoxes
    settings->isCheckedSingleArrays.resize(cst::labelNames.checkBoxes.size());
    for (int i = 0; i < settings->isCheckedSingleArrays.size(); i++) {
        settings->isCheckedSingleArrays[i] = settings->value(cst::labelNames.checkBoxes[i]).toBool();
    }
}

/*QString Server::getPath()
{
    QString path = QCoreApplication::applicationDirPath();
    path.append("/config.ini");
    return path;
}*/
