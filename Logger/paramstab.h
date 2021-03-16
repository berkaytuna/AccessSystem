#ifndef PARAMSTAB_H
#define PARAMSTAB_H

#include <QWidget>

class QGridLayout;
class QGroupBox;
class QLabel;
class QLineEdit;

constexpr int numGroups = 4;
constexpr int numLabels[numGroups] = { 3, 1, 2, 4 };
constexpr int maxWidths[] = {60, 60, 30, 40, 70, 90, 120, 35, 100, 70};

class ParamsTab : public QWidget
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
};
#endif // PARAMSTAB_H
