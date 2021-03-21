#include "manager.h"
#include "reader.h"
#include "communicator.h"

Manager::Manager(Settings &inSettings, QObject *parent)
    : QObject(parent)
{
    settings = &inSettings;
    server = new Server(inSettings);
    reader = new Reader(inSettings);
    communicator = new Communicator(inSettings);

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
    settings->deleteTimeoutTimer();

    //communicator->sendAccessPriceRequest(inCardNumber, 13.5, settings->num());
}
