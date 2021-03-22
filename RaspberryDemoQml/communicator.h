#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H

#include <QObject>

#include "request.h"

class Settings;
class QTcpSocket;
class QTimer;

class Communicator : public QObject
{
    Q_OBJECT
public:
    explicit Communicator(Settings &inSettings, QObject *parent = nullptr);
    ~Communicator();

    void sendComPortRequest();
    void sendAccessPriceRequest(QString cardNumber, double price, int time);

signals:
    void hasJsonObject(const QJsonObject &inJsonObject);

private slots:
    void connected();
    void readyRead();

private:
    Settings *settings;
    QTcpSocket *socket;
    QTimer *timer;

    void connectToServer();
    void disconnect();
    //void resetUI();
};

#endif // COMMUNICATOR_H
