#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>

#include "server.h"

//class Settings;
//class Server;
class Reader;
class Communicator;

class Manager : public QObject
{
    Q_OBJECT
public:
    explicit Manager(Settings &inSettings, QObject *parent = nullptr);
    ~Manager();

private slots:
    void readCardNumber(QString cardNumber);

private:
    Settings *settings;
    Server *server;
    Reader *reader;
    Communicator *communicator;

};

#endif // MANAGER_H
