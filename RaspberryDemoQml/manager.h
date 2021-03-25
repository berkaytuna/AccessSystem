#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>

#include "server.h"

class Reader;
class Communicator;
class RelaisCommunicator;
class QJsonObject;
class QTimer;

/** Manager of this system */
class Manager : public QObject
{
    Q_OBJECT
public:

    explicit Manager(Settings &inSettings, QObject *parent = nullptr);
    ~Manager();

private slots:

    /** When a card number is read */
    void readCardNumber(QString cardNumber);

    /** Evaluates the json object */
    void evaluateJsonObject(const QJsonObject &inJsonObject);

    /** Returns to the state prior to the access operation */
    void returnToPreAccess();

    void sendDebugMessage(const QString &msg);

private:

    /**  Settings */
    Settings *settings;

    /** Communication with the settings client */
    Server *server;

    /** Communication with the readers */
    Reader *reader;

    /** Communication with the server */
    Communicator *communicator;

    /** Communication with the relais */
    RelaisCommunicator * relaisCommunicator;

    QTimer *timer;
};

#endif // MANAGER_H
