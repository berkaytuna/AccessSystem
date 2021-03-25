#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QSettings>

#include "settings.h"

class QTcpServer;
class QTcpSocket;

//const QVector <QString> settingsStrings = { "doorNum", "startNum", "interval" };

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(Settings &settings, QObject *parent = nullptr);
    ~Server();

    void setSettings();
    void send(const QString &msg);

private slots:
    void newConnection();
    void readyRead();
    void disconnected();

private:
    QTcpSocket *socket;
    QTcpServer *server;
    Settings *settings;

    //QString getPath();
};

#endif // SERVER_H
