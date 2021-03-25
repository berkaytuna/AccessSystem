#include "relaiscommunicator.h"
#include "settings.h"
#include "bcm2835.h"

#define PIN0 RPI_BPLUS_GPIO_J8_40
#define PIN1 RPI_BPLUS_GPIO_J8_36

RelaisCommunicator::RelaisCommunicator(Settings &inSettings, QObject *parent)
    : QObject(parent)
{
    settings = &inSettings;

    bcm2835_init();
    bcm2835_gpio_fsel(PIN0, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(PIN1, BCM2835_GPIO_FSEL_OUTP);
}

RelaisCommunicator::~RelaisCommunicator()
{

}

void RelaisCommunicator::operatePins(bool isAccessGranted)
{
    if (isAccessGranted) {
        int pin = settings->currentD() ? PIN0 : PIN1;
        bcm2835_gpio_write(pin, HIGH);

        qDebug() << "openning pin: " << QString::number(pin);
        //settings->sendDebugMessage("openning pin: " + QString::number(pin));
    }
}

void RelaisCommunicator::closePins()
{
    bcm2835_gpio_write(PIN0, LOW);
    bcm2835_gpio_write(PIN1, LOW);
}
