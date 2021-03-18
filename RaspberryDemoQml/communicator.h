#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H

#include <QObject>

#include "request.h"

class Settings;
class QTcpSocket;

class Communicator : public QObject
{
    Q_OBJECT
public:
    explicit Communicator(Settings &inSettings, QObject *parent = nullptr);
    ~Communicator();

    void sendComPortRequest();
    void sendAccessPriceRequest(QString cardNumber, double price, int time);

private slots:
    void connected();
    void readyRead();

private:
    Settings *settings;
    QTcpSocket *socket;

    void connectToServer();
    void disconnect();
};

#endif // COMMUNICATOR_H
