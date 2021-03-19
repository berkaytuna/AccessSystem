#ifndef TABWIDGET_H
#define TABWIDGET_H

#include "logger.h"

#include <QTabWidget>
#include <QGroupBox>

class QWidget;
class TabWindow;

class TabWidget : public QTabWidget
{
    Q_OBJECT

public:
    TabWidget(QWidget *parent = nullptr);
    ~TabWidget();

private:
    TabWindow *paramsTab;
    TabWindow *cardTab;
    Logger *logger;

    //QVector <QString> cardGroupNames = { "Group A", "Group B", "Group C" };

};
#endif // TABWIDGET_H
