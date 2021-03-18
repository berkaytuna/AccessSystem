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

signals:
    void clientConnected();

public slots:
    void connectServer(const QString &serverIp);
    void readyRead();
    void connected();

private:
    QTcpSocket *socket;
};

#endif // CLIENT_H
