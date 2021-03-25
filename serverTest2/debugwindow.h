#ifndef DEBUGWINDOW_H
#define DEBUGWINDOW_H

#include "tabwindow.h"

class QTextBrowser;

class DebugWindow : public TabWindow
{
    Q_OBJECT

public:

    DebugWindow(Parameters *settings, QWidget *parent = nullptr);

    QTextBrowser *textBrowser;

    void displayDebugMessage(const QByteArray &data);
};

#endif // DEBUGWINDOW_H
