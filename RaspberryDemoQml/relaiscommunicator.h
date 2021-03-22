#ifndef RELAISCOMMUNICATOR_H
#define RELAISCOMMUNICATOR_H

#include <QObject>

class Settings;

class RelaisCommunicator : public QObject
{
    Q_OBJECT

public:

    explicit RelaisCommunicator(Settings &inSettings, QObject *parent = nullptr);
    ~RelaisCommunicator();

    void operatePins(bool isAccessGranted);

    void closePins();

private:

    Settings *settings;
};

#endif // RELAISCOMMUNICATOR_H
