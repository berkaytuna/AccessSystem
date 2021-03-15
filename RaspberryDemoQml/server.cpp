#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>
#include <QCoreApplication>
#include <QSettings>

#include "server.h"

Server::Server(Settings &passedSettings, QObject *parent)
    : QObject(parent)
{
    settings = &passedSettings;
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
    QFile file(getPath());
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
    QFile file(getPath());
    file.open(QIODevice::WriteOnly);
    file.write(data);
    file.close();

    setSettings();
}

void Server::setSettings()
{
    QSettings serverSettings(getPath(), QSettings::IniFormat);
    settings->setDNum(serverSettings.value(settingsStrings[0]).toInt());
    settings->setDTypeOne(1);
    settings->setDTypeTwo(0);
    settings->setNum(serverSettings.value(settingsStrings[1]).toInt());
    settings->setInterval(serverSettings.value(settingsStrings[2]).toInt());
}

QString Server::getPath()
{
    QString path = QCoreApplication::applicationDirPath();
    path.append("/config.ini");
    return path;
}
