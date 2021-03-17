#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QWidget;
class Parameters;
class QGroupBox;
class QFormLayout;
class QVBoxLayout;
class QHBoxLayout;
class QLabel;
class QLineEdit;
class QCheckBox;
class QPushButton;
class QSettings;
class TabWidget;
class Client;

//const QVector <QString> settingsStrings = { "doorNum", "startNum", "interval" };

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void connectServer(const QString &connectLineText);

private slots:
    void onConnect();
    void onSave();
    void clientConnected();

private:
    Parameters *settings;
    Client *client;
    QWidget *widget;
    QGroupBox *connectGroup;
    QGroupBox *settingsGroup;
    QVBoxLayout *layout;
    QHBoxLayout *connectLayout;
    TabWidget *tabWidget;
    QFormLayout *settingsLayout;
    QVector <QLabel*> settingsLabels;
    QVector <QLineEdit*> settingsLines;
    QLineEdit *connectLine;
    QPushButton *connectButton;
    QPushButton *saveButton;

    void setLines();
    static void writeCheckBoxArr(QSettings *inSettings, const QString &deviceStr, QVector <QCheckBox*> &checkBoxArr);
    static void fillCheckBoxArr(QVector <QCheckBox*> &checkBoxArr, QVector <bool> isCheckedArr);
};
#endif // MAINWINDOW_H