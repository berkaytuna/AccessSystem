#ifndef TABWINDOW_H
#define TABWINDOW_H

#include <QWidget>

#include "parameters.h"

class QGroupBox;
class QGridLayout;
class QHBoxLayout;
class QLabel;
class QLineEdit;

/*constexpr int numGroups = 3;
constexpr int numLabels[numGroups] = { 3, 1, 2 };
constexpr int maxWidths[] = {60, 60, 30, 40, 70, 90, 120, 35, 100, 70};*/

/*class ParamsTab : public QWidget
{
    Q_OBJECT

public:
    ParamsTab(QWidget *parent = nullptr);
    ~ParamsTab();

private:
    void createGroups();

    QGridLayout *layout;
    QGroupBox *groups[numGroups];
    QVector <QString> groupNames;
    QVector <QString> labelNames;
    QVector <QLabel*> labels;
    QVector <QLineEdit*> fields;
};*/

class TabWindow : public QWidget
{
    Q_OBJECT

public:
    TabWindow(Parameters *inSettings, QWidget *parent = nullptr);
    ~TabWindow();

protected:
    QGridLayout *layout;
    QVector <QGroupBox*> groups;
    QVector <QObject*> items;
    Parameters *settings;

    void createGroups(const QVector <QString> groupNames);
    void createFormLayout(QVector <QString> labelNames, QVector <QObject*> items, int groupIndex);
    QHBoxLayout* createCheckBoxLayout(QVector <QCheckBox*> &checkBoxes, int size);
};

#endif // TABWINDOW_H
