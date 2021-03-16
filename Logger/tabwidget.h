#ifndef TABWIDGET_H
#define TABWIDGET_H

#include "paramstab.h"
#include "logger.h"

#include <QTabWidget>
#include <QGroupBox>

class QWidget;

class TabWidget : public QTabWidget
{
    Q_OBJECT

public:
    TabWidget(QWidget *parent = nullptr);
    ~TabWidget();

private:
    ParamsTab *paramsTab;
    Logger *logger;

};
#endif // TABWIDGET_H
