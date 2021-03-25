#include <QJsonObject>
#include <QTimer>

#include "manager.h"
#include "reader.h"
#include "communicator.h"
#include "relaiscommunicator.h"

Manager::Manager(Settings &inSettings, QObject *parent)
    : QObject(parent)
{
    // Setting the objects
    settings = &inSettings;
    server = new Server(inSettings);

    if (QFile(cst::getPath()).exists()) {
        reader = new Reader(inSettings);
        communicator = new Communicator(inSettings);
        relaisCommunicator = new RelaisCommunicator(inSettings);

        // Connecting to the signals of subordinates
        connect(reader, &Reader::readCardNumber, this, &Manager::readCardNumber);
        connect(communicator, &Communicator::hasJsonObject, this, &Manager::evaluateJsonObject);
        connect(settings, &Settings::debugMessageReceived, this, &Manager::sendDebugMessage);

        // Initialize the reader object
        reader->init();
    }
}

Manager::~Manager()
{
    delete server;
    delete reader;
    delete communicator;
    delete relaisCommunicator;
}

void Manager::readCardNumber(QString inCardNumber)
{
    // Stop the timeout timer if a card is presented
    settings->deleteTimeoutTimer();

    // Send "Access with Price Request" to the server
    communicator->sendAccessPriceRequest(inCardNumber, 13.5, settings->num());
}

void Manager::evaluateJsonObject(const QJsonObject &inJsonObject)
{
    // Operations related to if access is granted
    bool isAccessGranted = inJsonObject.value("AccessGranted").toBool();
    qDebug() << "isAccessGranted: " << isAccessGranted;
    settings->setBSuccess(isAccessGranted);

    // Setting the access message to display
    settings->setText(inJsonObject.value("Message").toString());

    // Setting the current view
    settings->setCurrentV(2);

    // Relais related operations
    relaisCommunicator->operatePins(isAccessGranted);

    // Returning to the pre access state after a timer
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Manager::returnToPreAccess);
    timer->setSingleShot(true);
    timer->start(5000);
}

void Manager::returnToPreAccess()
{
    // Close pins
    relaisCommunicator->closePins();

    // Reverting the display text to its initial state
    settings->setText("Please choose...");

    qDebug() << "returned to main screen";

    // Reverting the bSuccess parameter that controls the access control display screen
    // to its original state
    settings->setBSuccess(false);

    // Change current view to the initial state
    settings->setCurrentV(0);

    // If we are directly getting into the increment screen after the timeout, let
    // readers to read
    settings->setBCanRead(settings->b2D() ? false : true);

    // setting initial num and interval
    QString s;
    s = settings->currentD() ? cst::settingsNames.lines[3] : cst::settingsNames.lines[1];
    settings->setNum(settings->value(s).toInt());
    s = settings->currentD() ? cst::settingsNames.lines[4] : cst::settingsNames.lines[2];
    settings->setInterval(settings->value(s).toInt());

    delete timer;
}

void Manager::sendDebugMessage(const QString &msg)
{
    const QString debugMsg = "Debug: " + msg;
    server->send(debugMsg);
}
