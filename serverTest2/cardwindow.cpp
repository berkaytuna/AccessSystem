#include <QGroupBox>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QCoreApplication>

#include "cardwindow.h"
#include "constants.h"

CardWindow::CardWindow(Parameters *settings, QWidget *parent)
    : TabWindow(settings, parent)
{
    createGroups(groupNames.card);

    // Group 1: Remove
    items = { createCheckBoxLayout(settings->checkBoxesLF, LF.numberSize),
              createCheckBoxLayout(settings->checkBoxesQR, QR.numberSize)
    };
    createFormLayout(labelNames.cardRemove, items, 0);
}
