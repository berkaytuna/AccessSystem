#include <QGroupBox>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QCoreApplication>

#include "uiwindow.h"
#include "constants.h"

UIWindow::UIWindow(Parameters *settings, QWidget *parent)
    : TabWindow(settings, parent)
{
    setLayout(layout);

    createGroups(cst::groupNames.ui);

    QVector <QString> labelNamesSet;

    // Group 1: General
    labelNamesSet = { cst::labelNames.lines[0] };
    items = { new QLineEdit };
    createFormLayout(labelNamesSet, items, 0);
    for (int i = 0; i < labelNamesSet.size(); i++) {
        //settings->labels.push_back(labelNamesSet[i]);
        settings->lines.push_back(dynamic_cast<QLineEdit*>(items[i]));
    }

    /*// Group 2: Door
    labelNamesSet = { cst::labelNames.lines[1] };
    items = { new QLineEdit };
    createFormLayout(labelNamesSet, items, 1);
    for (int i = 0; i < labelNamesSet.size(); i++) {
        //settings->labels.push_back(labelNamesSet[i]);
        settings->lines.push_back(dynamic_cast<QLineEdit*>(items[i]));
    }

    // Group 3: Time
    labelNamesSet = { cst::labelNames.lines[2], cst::labelNames.lines[3] };
    items = { new QLineEdit, new QLineEdit };
    createFormLayout(labelNamesSet, items, 2);
    for (int i = 0; i < labelNamesSet.size(); i++) {
        //settings->labels.push_back(labelNamesSet[i]);
        settings->lines.push_back(dynamic_cast<QLineEdit*>(items[i]));
    }*/
}
