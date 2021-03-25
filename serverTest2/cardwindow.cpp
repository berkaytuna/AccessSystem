#include <QGroupBox>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QCoreApplication>
#include <QTabWidget>

#include "cardwindow.h"
#include "constants.h"

CardWindow::CardWindow(Parameters *settings, QWidget *parent)
    : TabWindow(settings, parent)
{
    setLayout(layout);

    createGroups(cst::groupNames.card);

    // Group 1: Remove element
    items = { createCheckBoxLayout(settings->checkBoxesLF, cst::LF.numberSize),
              createCheckBoxLayout(settings->checkBoxesQR, cst::QR.numberSize),
              createCheckBoxLayout(settings->checkBoxesArduino, cst::Arduino.numberSize)
    };
    createFormLayout(cst::labelNames.devices, items, 0);

    // Group 2: Remove zero first
    items = { new QCheckBox, new QCheckBox, new QCheckBox };
    for (int i = 0; i < items.size(); i++)
        settings->checkBoxes.push_back(dynamic_cast<QCheckBox*>(items[i]));
    createFormLayout(cst::labelNames.devices, items, 1);

    // Group 3: Remove zero inside
    items = { new QCheckBox, new QCheckBox, new QCheckBox };
    for (int i = 0; i < items.size(); i++)
        settings->checkBoxes.push_back(dynamic_cast<QCheckBox*>(items[i]));
    createFormLayout(cst::labelNames.devices, items, 2);

    // Group 4: Turn bytes
    items = { new QCheckBox, new QCheckBox, new QCheckBox };
    for (int i = 0; i < items.size(); i++)
        settings->checkBoxes.push_back(dynamic_cast<QCheckBox*>(items[i]));
    createFormLayout(cst::labelNames.devices, items, 3);

    // Group 5: Turn bits within bytes
    items = { new QCheckBox, new QCheckBox, new QCheckBox };
    for (int i = 0; i < items.size(); i++)
        settings->checkBoxes.push_back(dynamic_cast<QCheckBox*>(items[i]));
    createFormLayout(cst::labelNames.devices, items, 4);
}
