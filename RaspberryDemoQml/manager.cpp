#include "manager.h"
#include "reader.h"

Manager::Manager(Settings &settings, QObject *parent)
    : QObject(parent)
{
    server = new Server(settings);
    reader = new Reader(settings);

    reader->init();
}

Manager::~Manager()
{
    delete server;
    delete reader;
}