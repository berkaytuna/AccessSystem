#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QSettings>

#include "settings.h"

class QTcpServer;

const QVector <QString> settingsStrings = { "doorNum", "startNum", "interval" };

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(Settings &settings, QObject *parent = nullptr);
    ~Server();

    void setSettings();

private slots:
    void newConnection();
    void readyRead();

private:
    QTcpServer *server;
    Settings *settings;

    //QString getPath();
};

#endif // SERVER_H
