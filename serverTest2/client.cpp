#include <QString>
#include <QTcpSocket>
#include <QFile>
#include <QCoreApplication>
#include <QDebug>

#include "client.h"
#include "constants.h"

Client::Client()
{

}

void Client::connectServer(const QString &serverIp)
{
    qDebug() << "serverIp: " << serverIp;

    socket = new QTcpSocket(this);
    connect(socket, &QAbstractSocket::readyRead, this, &Client::readyRead);
    connect(socket, &QAbstractSocket::connected, this, &Client::connected);
    socket->connectToHost(serverIp, 8080);
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

    if ((data[0] == 'D') && (data[1] == 'e') && (data[2] == 'b') && (data[3] == 'u') &&
        (data[4] == 'g') && (data[5] == ':') && (data[6] == ' ')) {

        data.remove(0, 6);

        emit debugMessageReceived(data);
        return;
    }

    QFile file(cst::getPath());
    file.open(QIODevice::WriteOnly);
    file.write(data);
    file.close();
}

void Client::connected() {

    emit debugMessageReceived("connected!");
    emit clientConnected();
}

void Client::sendSettings()
{
    QFile file(cst::getPath());
    file.open(QIODevice::ReadOnly);
    QByteArray data = file.readAll();
    qDebug() << "sending: " << data;
    qDebug() << "sent bytes: " << socket->write(data);
    file.close();
}

void Client::send(const QByteArray &data)
{
    socket->write(data);
}

/*QString Client::getPath()
{
    QString path = QCoreApplication::applicationDirPath();
    path.append("/config.ini");
    return path;
}*/
