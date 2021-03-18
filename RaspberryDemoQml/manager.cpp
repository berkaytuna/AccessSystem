#include "manager.h"
#include "reader.h"
#include "communicator.h"

Manager::Manager(Settings &settings, QObject *parent)
    : QObject(parent)
{
    server = new Server(settings);
    reader = new Reader(settings);
    communicator = new Communicator(settings);

    connect(reader, &Reader::readCardNumber, this, &Manager::readCardNumber);

    reader->init();
}

Manager::~Manager()
{
    delete server;
    delete reader;
    delete communicator;
}

void Manager::readCardNumber(QString inCardNumber)
{
    communicator->sendAccessPriceRequest(inCardNumber, 13.5, 240);
}
