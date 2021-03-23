#ifndef RELAISWINDOW_H
#define RELAISWINDOW_H

#include "tabwindow.h"

class RelaisWindow : public TabWindow
{
    Q_OBJECT

public:
    RelaisWindow(Parameters* inSettings, QWidget *parent = nullptr);
};

#endif // RELAISWINDOW_H
