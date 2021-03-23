#include <QCheckBox>
#include <QLineEdit>
#include <QComboBox>

#include "relaiswindow.h"
#include "constants.h"

RelaisWindow::RelaisWindow(Parameters *inSettings, QWidget *parent)
    : TabWindow(inSettings, parent)
{
    createGroups(cst::groupNames.relais);

    // Group 1: RelaisOne
    QComboBox* comboBox1 = new QComboBox;
    comboBox1->insertItems(0, cst::typeNames);

    items = { new QWidget, comboBox1, new QLineEdit, new QLineEdit};
    QVector <QString> labelNames = { "", cst::labelNames.comboBoxes[0], cst::labelNames.lines[1],
                                     cst::labelNames.lines[2] };

    // lineEdits
    for (int i = 0; i < items.size(); i++) {
        QLineEdit* lineEdit = dynamic_cast<QLineEdit*>(items[i]);
        if (lineEdit != nullptr)
            settings->lines.push_back(lineEdit);
    }

    // ComboBoxes
    settings->comboBoxes.push_back(dynamic_cast<QComboBox*>(items[1]));

    createFormLayout(labelNames, items, 0);

    // Group 2: RelaisTwo
    QComboBox* comboBox2 = new QComboBox;
    comboBox2->insertItems(0, cst::typeNames);

    items = { new QCheckBox, comboBox2, new QLineEdit, new QLineEdit};
    labelNames = { cst::labelNames.checkBoxes[8], cst::labelNames.comboBoxes[0],
                   cst::labelNames.lines[1], cst::labelNames.lines[2] };

    // CheckBoxes
    settings->checkBoxes.push_back(dynamic_cast<QCheckBox*>(items[0]));

    // lineEdits
    for (int i = 0; i < items.size(); i++) {
        QLineEdit* lineEdit = dynamic_cast<QLineEdit*>(items[i]);
        if (lineEdit != nullptr)
            settings->lines.push_back(lineEdit);
    }

    // ComboBoxes
    settings->comboBoxes.push_back(dynamic_cast<QComboBox*>(items[1]));

    createFormLayout(labelNames, items, 1);
}
