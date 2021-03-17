#ifndef UIWINDOW_H
#define UIWINDOW_H

#include "tabwindow.h"

class UIWindow : public TabWindow
{
    Q_OBJECT

public:
    UIWindow(Parameters *settings, QWidget *parent = nullptr);

private:
    /*const QVector <QString> labelNames1 = { "text" };
    const QVector <QString> labelNames2 = { "doorNum", "startNum", "interval" };
    const QVector <QString> groupNames = { "General", "Door", "Time", "Check-in" };*/
};

#endif // UIWINDOW_H
