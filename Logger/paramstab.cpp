#include "paramstab.h"

#include <QGridLayout>
#include <QFormLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QDebug>

ParamsTab::ParamsTab(QWidget *parent)
    : QWidget(parent)
    , layout(new QGridLayout(this))
{
    // Step 1: Create Groups
    groupNames = { tr("Group 1"), tr("Group 2"), tr("Group 3"), tr("Group 4") };
    for (auto &e : groups) {
        int i = &e - &groups[0];
        bool row = (i & ( 1 << 1 )) >> 1;
        bool column = (i & ( 1 << 0 )) >> 0;
        e = new QGroupBox(groupNames[i]);
        layout->addWidget(e, row, column);
    }

    int numParams = 0;

    /* Groups are left independent, even when this means repeating actions.
     * It is a design choice to let them be easily modifiable independantly,
     * for example when changing layout object of a certain group.
    */
    // Step 2.1: Group 1
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

    // Step 2.2: Group 2
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
}

