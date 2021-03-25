#ifndef CARDWINDOW_H
#define CARDWINDOW_H

#include "tabwindow.h"

class CardWindow : public TabWindow
{
    Q_OBJECT

public:
    CardWindow(Parameters *settings, QWidget *parent = nullptr);
};

#endif // CARDWINDOW_H
