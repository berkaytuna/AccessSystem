#include <QDebug>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>

#include "parameters.h"

Line::Line(const QString labelStr, QWidget* parent)
    : QWidget(parent)
{
    /*widgets.push_back(new QLabel(labelStr));
    widgets.push_back(new QLineEdit);
    layout = new QFormLayout;
    for (auto &e : widgets)
        layout->addRow();
    setLayout(layout);*/
}

Line::~Line()
{
    for (auto &e : widgets)
        delete e;
}

QString Line::label()
{
    QLabel *label = dynamic_cast<QLabel*>(widgets[0]);
    if (label != nullptr)
        return label->text();
    else
        return "label is nullptr";
}

QString Line::text()
{
    QLineEdit *lineEdit = dynamic_cast<QLineEdit*>(widgets[1]);
    if (lineEdit != nullptr)
        return lineEdit->text();
    else
        return "lineEdit is nullptr";
}

Parameters::Parameters(const QString &fileName, Format format, QObject *parent)
    : QSettings(fileName, format, parent)
{
    // create line settings

    //for (int i = 0; i < labelStrings.length(); i++)
        //lines.push_back(new Line(labelStrings[i]));

    /*for (int i = 0; i < labelStrings.size(); i++) {
        labels.push_back(new QLabel(labelStrings[i]));
    }
    for (int i = 0; i < lineEditSize; i++) {
        lineEdits.push_back(new QLineEdit);
    }*/

    // create dropbox settings

    // create choose box settings
}

Parameters::~Parameters()
{
    for (auto &e : lines)
        delete e;
    for (auto &e : checkBoxesLF)
        delete &e;
    for (auto &e : checkBoxesQR)
        delete &e;
}


