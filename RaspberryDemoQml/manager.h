#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>

class Settings;
class Server;
class Reader;

class Manager : public QObject
{
    Q_OBJECT
public:
    explicit Manager(Settings &settings, QObject *parent = nullptr);
    ~Manager();

private:
    Server *server;
    Reader *reader;

};

#endif // MANAGER_H
