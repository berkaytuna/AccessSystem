#ifndef SERVERWINDOW_H
#define SERVERWINDOW_H

#include "tabwindow.h"

class ServerWindow : public TabWindow
{
    Q_OBJECT

public:
    ServerWindow(Parameters* inSettings, QWidget *parent = nullptr);
};

#endif // SERVERWINDOW_H
