#include "settings.h"

void Settings::changeDoorSelection()
{
    QString s;
    s = currentD() ? cst::settingsNames.lines[5] : cst::settingsNames.lines[2];
    setNum(value(s).toInt());
    s = currentD() ? cst::settingsNames.lines[6] : cst::settingsNames.lines[3];
    setInterval(value(s).toInt());

    setBCanRead(_b2D ? _bCanRead : true);
}
