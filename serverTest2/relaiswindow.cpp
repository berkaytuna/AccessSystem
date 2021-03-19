#include <QCheckBox>
#include <QLineEdit>

#include "relaiswindow.h"
#include "constants.h"

RelaisWindow::RelaisWindow(Parameters *inSettings, QWidget *parent)
    : TabWindow(inSettings, parent)
{
    createGroups(cst::groupNames.relais);

    // Group 1: RelaisOne
    items = { new QLineEdit, new QLineEdit, new QLineEdit};
    QVector <QString> labelNames = { cst::labelNames.lines[1], cst::labelNames.lines[2],
                                     cst::labelNames.lines[3] };
    for (int i = 0; i < items.size(); i++)
        settings->lines.push_back(dynamic_cast<QLineEdit*>(items[i]));
    createFormLayout(labelNames, items, 0);

    // Group 2: RelaisTwo
    items = { new QCheckBox, new QLineEdit, new QLineEdit, new QLineEdit};
    labelNames = { cst::labelNames.checkBoxes[8], cst::labelNames.lines[1],
                   cst::labelNames.lines[2], cst::labelNames.lines[3] };
    settings->checkBoxes.push_back(dynamic_cast<QCheckBox*>(items[0]));
    for (int i = 1; i < items.size(); i++)
        settings->lines.push_back(dynamic_cast<QLineEdit*>(items[i]));
    createFormLayout(labelNames, items, 1);
}
