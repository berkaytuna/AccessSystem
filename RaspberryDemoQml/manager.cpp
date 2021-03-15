#include "manager.h"
#include "server.h"
#include "reader.h"

Manager::Manager(Settings &settings, QObject *parent)
    : QObject(parent)
    , server(new Server(settings))
    , reader(new Reader)
{
    reader->init();
}

Manager::~Manager()
{
    delete server;
    delete reader;
}
