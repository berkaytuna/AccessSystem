#include <QString>
#include <QTcpSocket>
#include <QFile>
#include <QCoreApplication>
#include <QDebug>

#include "client.h"

Client::Client()
{

}

void Client::connectServer(const QString &serverIp)
{
    qDebug() << "serverIp: " << serverIp;

    socket = new QTcpSocket(this);
    connect(socket, &QAbstractSocket::readyRead, this, &Client::readyRead);
    connect(socket, &QAbstractSocket::connected, this, &Client::connected);
    socket->connectToHost(serverIp, 8120);
    //qDebug() << socket->waitForConnected(15000);
    //char buffer[] = "ab";
    //qDebug() << socket->write(buffer, 50);
    /*QFile file("/home/berkay/settings.ini");
    file.open(QIODevice::ReadOnly);
    QByteArray data = file.readAll();
    qDebug() << data;
    qDebug() << socket->write(data);*/

}

Client::~Client()
{
    delete socket;
}

void Client::readyRead()
{
    //qDebug() << "settingsReadyRead";
    QTcpSocket *socket = static_cast<QTcpSocket*>(sender());
    QByteArray data = socket->readAll();
    qDebug() << "received: " << data;
    QFile file(getPath());
    file.open(QIODevice::WriteOnly);
    file.write(data);
    file.close();
}

void Client::connected() {
    emit clientConnected();
}

void Client::sendSettings()
{
    QFile file(getPath());
    file.open(QIODevice::ReadOnly);
    QByteArray data = file.readAll();
    qDebug() << "sending: " << data;
    qDebug() << "sent bytes: " << socket->write(data);
    file.close();
}

QString Client::getPath()
{
    QString path = QCoreApplication::applicationDirPath();
    path.append("/config.ini");
    return path;
}
