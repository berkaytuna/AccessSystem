#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>

class QString;
class QTcpSocket;

class Client : public QObject
{
    Q_OBJECT

public:
    Client();
    ~Client();

    //QString getPath();
    void sendSettings();
    void send(const QByteArray &data);

signals:
    void clientConnected();
    void debugMessageReceived(const QByteArray &data);

public slots:
    void connectServer(const QString &serverIp);
    void readyRead();
    void connected();

private:
    QTcpSocket *socket;
};

#endif // CLIENT_H
