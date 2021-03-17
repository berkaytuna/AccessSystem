#include <QGridLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QDebug>

#include "constants.h"
#include "tabwindow.h"

TabWindow::TabWindow(Parameters *inSettings, QWidget *parent)
    : QWidget(parent)
{
    layout = new QGridLayout(this);
    settings = inSettings;
}

TabWindow::~TabWindow()
{
    delete layout;
    for (auto &e : groups)
        delete e;
}

void TabWindow::createGroups(const QVector <QString> groupNames)
{
    int row = 0, column = 0;
    for (int i = 0; i < groupNames.size(); i++) {
        groups.push_back(new QGroupBox(groupNames[i]));
        if (i <= 3) {
            row = (i & ( 1 << 1 )) >> 1;
            column = (i & ( 1 << 0 )) >> 0;
        }
        else if (i == 4) {
            row = 0;
            column = 2;
        }
        else if (i <= 8) {
            row = i / 3;
            column = i % 3;
        }
        layout->addWidget(groups[i], row, column);
        groups[i]->setMaximumHeight(cst::grid.maxH);
        groups[i]->setMaximumWidth(cst::grid.maxW);
    }
}

void TabWindow::createFormLayout(const QVector <QString> labelNames,
                                 QVector <QObject*> items, int groupIndex)
{
    QFormLayout *layout = new QFormLayout;
    for (int i = 0; i < labelNames.size(); i++) {
        QLayout *layoutCast = dynamic_cast<QLayout*>(items[i]);
        if (layoutCast != nullptr) {
            layout->addRow(new QLabel(labelNames[i]), layoutCast);
            continue;
        }
        QWidget *widgetCast = dynamic_cast<QWidget*>(items[i]);
        if (widgetCast != nullptr) {
            layout->addRow(new QLabel(labelNames[i]), widgetCast);
            continue;
        }
    }
    groups[groupIndex]->setLayout(layout);
}

QHBoxLayout* TabWindow::createCheckBoxLayout(QVector <QCheckBox*> &checkBoxes, int size)
{
    QHBoxLayout *layout = new QHBoxLayout;
    for (int i = 0; i < size; i++) {
        checkBoxes.push_back(new QCheckBox);
        layout->addWidget(checkBoxes[i]);
    }
    return layout;
}

/*ParamsTab::ParamsTab(QWidget *parent)
    : QWidget(parent)
    , layout(new QGridLayout(this))
{
    // Create Groups
    groupNames = { tr("Group 1"), tr("Group 2"), tr("Group 3"), tr("Group 4") };
    for (auto &e : groups) {
        int i = &e - &groups[0];
        bool row = (i & ( 1 << 1 )) >> 1;
        bool column = (i & ( 1 << 0 )) >> 0;
        e = new QGroupBox(groupNames[i]);
        layout->addWidget(e, row, column);
    }

    int numParams = 0;

    // Group 1
    labelNames = { tr("Parameter 1"), tr("Parameter 2"), tr("Parameter 3") };
    for (int i = numParams; i < labelNames.size(); i++) {
        labels.push_back(new QLabel(labelNames[i]));
        fields.push_back(new QLineEdit);
    }

    QFormLayout *group1 = new QFormLayout;
    for (int i = 0; i < labelNames.size(); i++) {
        group1->addRow(labels[i], fields[i]);
    }
    groups[0]->setLayout(group1);
    numParams = labelNames.size();

    // Group 2
    labelNames = { tr("Parameter 4") };
    for (int i = 0; i < labelNames.size(); i++) {
        labels.push_back(new QLabel(labelNames[i]));
        fields.push_back(new QLineEdit);
    }

    QFormLayout *group2 = new QFormLayout;
    for (int i = numParams; i < numParams + labelNames.size(); i++) {
        group2->addRow(labels[i], fields[i]);
    }
    groups[1]->setLayout(group2);
}

ParamsTab::~ParamsTab()
{
    for (auto &e : groups) {
        delete e;
    }
}*/

