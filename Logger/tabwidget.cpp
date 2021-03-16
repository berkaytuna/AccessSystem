#include "tabwidget.h"

#include <QWidget>

TabWidget::TabWidget(QWidget *parent)
    : QTabWidget(parent)
    , paramsTab(new ParamsTab(this))
    , logger(new Logger(this))
{
    addTab(paramsTab, tr("Parameters"));
    addTab(logger, tr("Logging"));
}

TabWidget::~TabWidget()
{
    delete paramsTab;
    delete logger;
}
