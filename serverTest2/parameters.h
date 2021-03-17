#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <QWidget>
#include <QSettings>
#include <QCoreApplication>

class QHBoxLayout;
class QCheckBox;
class QFormLayout;
class QLabel;
class QLineEdit;

class Line : public QWidget
{
    Q_OBJECT

public:
    Line(const QString labelStr, QWidget *parent = nullptr);
    ~Line();

    QString label();
    QString text();

        QFormLayout *layout;

private:
    QVector <QWidget*> widgets;
    //QHBoxLayout *layout;
};

class Parameters : public QSettings
{
    Q_OBJECT

public:
    Parameters(const QString &fileName, Format format, QObject *parent = nullptr);
    ~Parameters();

    //QVector <Line*> lines;
    QVector <QString> labels;
    QVector <QLineEdit*> lines;
    QVector <QCheckBox*> checkBoxesLF;
    QVector <QCheckBox*> checkBoxesQR;

private:
    const int lineEditSize = 3;
    const QVector <QString> labelStrings = { "DoorNum", "StartNum", "Interval" };
};

#endif // PARAMETERS_H
