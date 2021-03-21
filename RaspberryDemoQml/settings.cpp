#include <QProcess>

#include "settings.h"

void Settings::changeDoorSelection()
{
    QString s;
    s = currentD() ? cst::settingsNames.lines[5] : cst::settingsNames.lines[2];
    setNum(value(s).toInt());
    s = currentD() ? cst::settingsNames.lines[6] : cst::settingsNames.lines[3];
    setInterval(value(s).toInt());

    setBCanRead(_b2D ? _bCanRead : true);

    _typeText = currentD() ? value(cst::settingsNames.comboBoxes[1]).toString()
                           : value(cst::settingsNames.comboBoxes[0]).toString();
    setTypeText(_typeText);
    _typeImgSrc = "qrc:images/";
    if (_typeText == "solarium")
        _typeImgSrc += "solarium";
    else if (_typeText == "massage")
        _typeImgSrc += "massage";
    _typeImgSrc += ".png";
    setTypeImgSrc(_typeImgSrc);
}

void Settings::restart()
{
    //delete timer;

    qDebug() << "timeout...";

    setCurrentV(0);

    QString s;
    s = currentD() ? cst::settingsNames.lines[5] : cst::settingsNames.lines[2];
    setNum(value(s).toInt());
    s = currentD() ? cst::settingsNames.lines[6] : cst::settingsNames.lines[3];
    setInterval(value(s).toInt());
}

void Settings::startTimeoutTimer()
{
    if (timer != nullptr)
        delete timer;

    qDebug()  << "restart timeout started";

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Settings::restart);
    timer->setSingleShot(true);
    timer->start(10000);
}

void Settings::deleteTimeoutTimer()
{
    qDebug() << "timeout operation stopped";

    timer->stop();
}
