#include "parameters.h"
#include "tabwidget.h"
#include "uiwindow.h"
#include "cardwindow.h"

#include <QWidget>

TabWidget::TabWidget(QWidget *parent)
    : QTabWidget(parent)
{
    /*paramsTab = new UIWindow;
    cardTab = new CardWindow;
    logger = new Logger;

    addTab(paramsTab, tr("UI"));
    addTab(cardTab, tr("Card"));
    addTab(logger, tr("Logging"));*/
}

TabWidget::~TabWidget()
{
    delete paramsTab;
    delete cardTab;
    delete logger;
}
