#include <QWidget>
#include <QGroupBox>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QComboBox>
#include <QLabel>
#include <QSettings>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QProcess>
#include <QTimer>

#include "mainwindow.h"
#include "constants.h"
#include "parameters.h"
#include "tabwidget.h"
#include "uiwindow.h"
#include "cardwindow.h"
#include "relaiswindow.h"
#include "serverwindow.h"
#include "debugwindow.h"
#include "client.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , client(new Client)
    , widget(new QWidget)
    , connectGroup(new QGroupBox(tr("Connection")))
    , settingsGroup(new QGroupBox(tr("Settings")))
    , layout(new QVBoxLayout(widget))
    , connectLayout(new QHBoxLayout)
    //, tabWidget(new TabWidget())
    , settingsLayout(new QFormLayout)
    , connectLine(new QLineEdit)
    , connectButton(new QPushButton(tr("Connect")))
    , saveButton(new QPushButton(tr("Apply")))
    , restartButton(new QPushButton(tr("Restart")))
{
    settings = new Parameters(cst::getPath(), QSettings::IniFormat);

    QTabWidget *tabWidget1 = new QTabWidget;
    uiWindow = new UIWindow(settings);
    cardWindow = new CardWindow(settings);
    relaisWindow = new RelaisWindow(settings);
    serverWindow = new ServerWindow(settings);
    debugWindow = new DebugWindow(settings);

    tabWidget1->addTab(uiWindow, cst::tabNames[0]);
    tabWidget1->addTab(cardWindow, cst::tabNames[1]);
    tabWidget1->addTab(relaisWindow, cst::tabNames[2]);
    tabWidget1->addTab(serverWindow, cst::tabNames[3]);
    tabWidget1->addTab(debugWindow, cst::tabNames[4]);

    // Set ui
    setCentralWidget(widget);
    layout->addWidget(connectGroup);
    layout->addWidget(tabWidget1);
    //layout->addWidget(settingsGroup);

    //connectGroup->setParent(widget);
    //settingsGroup->setParent(widget);
    connectGroup->setLayout(connectLayout);
    settingsGroup->setLayout(settingsLayout);
    connectLayout->addWidget(connectLine);
    connectLayout->addWidget(connectButton);
    connectLayout->addWidget(saveButton);
    connectLayout->addWidget(restartButton);

    //QString path = getPath();
    //QSettings settings(QString(path), QSettings::IniFormat);
    //for (int i = 0; i < settingsSize; i++) {
        //settingsLabels.push_back(new QLabel(settingsStrings[i]));
        //settingsLines.push_back(new QLineEdit);
        //settingsLayout->addRow(settingsLabels[i], settingsLines[i]);
        //settingsLines[i]->setText(settings.value(settingsLabels[i]->text()).toString());
    //}
    //settingsLayout->addRow(saveButton);

    // Set connectButton function
    connect(connectButton, &QPushButton::released, this, &MainWindow::onConnect);
    connect(saveButton, &QPushButton::released, this, &MainWindow::onSave);
    connect(restartButton, &QPushButton::released, this, &MainWindow::onRestart);
    connect(this, &MainWindow::connectServer, client, &Client::connectServer);
    connect(client, &Client::clientConnected, this, &MainWindow::clientConnected);
    connect(client, &Client::debugMessageReceived, this, &MainWindow::debugMessageReceived);

    /*QJsonObject a;
    a.insert("ali", 3);
    a.insert("veli", "bb");

    QJsonDocument b(a);

    qDebug() << b.toJson();
    QFile file(getPath());
    file.open(QIODevice::WriteOnly);
    file.write(b.toJson());
    file.close();*/
}

MainWindow::~MainWindow()
{
    delete uiWindow;
    delete cardWindow;
    delete relaisWindow;
    delete serverWindow;
    delete debugWindow;
    delete settings;
    delete client;
    delete widget;
    delete connectGroup;
    delete settingsGroup;
    delete layout;
    delete connectLayout;
    delete tabWidget;
    delete settingsLayout;
    for (int i = 0; i < cst::settingsSize; i++) {
        delete settingsLabels[i];
        delete settingsLines[i];
    }
    delete connectLine;
    delete connectButton;
    delete saveButton;
    delete restartButton;
}

void MainWindow::onConnect()
{
    emit connectServer(connectLine->text());
}

void MainWindow::onRestart()
{
    client->send("restart");

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::restart);
    timer->setSingleShot(true);
    timer->start(10);
}

void MainWindow::restart()
{
    delete timer;

    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}

void MainWindow::onSave()
{
    //qDebug() << getPath();
    //QString path = client->getPath();
    //QSettings settings(QString(path), QSettings::IniFormat);

    // Lines
    for (int i = 0; i < cst::settingsNames.lines.size(); i++) {
        settings->setValue(cst::settingsNames.lines[i], settings->lines[i]->text());
    }

    // CheckBox Layouts
    writeCheckBoxArr(settings, cst::labelNames.devices[0], settings->checkBoxesLF);
    writeCheckBoxArr(settings, cst::labelNames.devices[1], settings->checkBoxesQR);
    writeCheckBoxArr(settings, cst::labelNames.devices[2], settings->checkBoxesArduino);

    /*settings->beginWriteArray(checkBoxArr.Remove);
    for (int i = 0; i < settings->checkBoxesLF.size(); ++i) {
        settings->setArrayIndex(i);
        settings->setValue(checkBoxArr.LF, settings->checkBoxesLF[i]->isChecked());
    }
    settings->endArray();

    settings->beginWriteArray(checkBoxArr.Remove);
    for (int i = 0; i < settings->checkBoxesQR.size(); ++i) {
        settings->setArrayIndex(i);
        settings->setValue(checkBoxArr.QR, settings->checkBoxesQR[i]->isChecked());
    }
    settings->endArray();*/

    // CheckBoxes
    for (int i = 0; i < cst::labelNames.checkBoxes.size(); i++) {
        settings->setValue(cst::labelNames.checkBoxes[i], settings->checkBoxes[i]->isChecked());
    }

    // ComboBoxes
    for (int i = 0; i < cst::settingsNames.comboBoxes.size(); i++) {
        settings->setValue(cst::settingsNames.comboBoxes[i], settings->comboBoxes[i]->currentText());
    }

    settings->sync();
    client->sendSettings();

    //qDebug() << settings->checkBoxesLF[8]->isChecked();
    //qDebug() << settings->lines[2]->text();
}

void MainWindow::debugMessageReceived(const QByteArray &data)
{
    debugWindow->displayDebugMessage(data);
}

void MainWindow::clientConnected()
{
    setLines();
}

void MainWindow::setLines()
{
    settings->sync();
    //QString path = getPath();
    //QSettings settings(path, QSettings::IniFormat);

    // lineEdits
    for (int i = 0; i < cst::settingsNames.lines.size(); i++) {
        settings->lines[i]->setText(settings->value(cst::settingsNames.lines[i]).toString());
        qDebug() << i;
    }

    // CheckBox Layouts
    QVector<QVector<bool>> isCheckedArrays;
    for (int i = 0; i < cst::labelNames.devices.size(); i++) {
        QVector <bool> isCheckedArr = cst::readCheckBoxArr(settings, cst::labelNames.devices[i]);
        isCheckedArrays.push_back(isCheckedArr);
    }

    fillCheckBoxArr(settings->checkBoxesLF, isCheckedArrays[0]);
    fillCheckBoxArr(settings->checkBoxesQR, isCheckedArrays[1]);
    fillCheckBoxArr(settings->checkBoxesArduino, isCheckedArrays[2]);

    // CheckBoxes
    for (int i = 0; i < cst::labelNames.checkBoxes.size(); i++)
        settings->checkBoxes[i]->setChecked(settings->value(cst::labelNames.checkBoxes[i]).toBool());

    // ComboBoxes
    for (int i = 0; i < cst::settingsNames.comboBoxes.size(); i++)
        settings->comboBoxes[i]->setCurrentText(settings->value(cst::settingsNames.comboBoxes[i]).toString());
}

/*QVector <bool> MainWindow::readCheckBoxArr(QSettings *inSettings, const QString &deviceStr)
{
    QVector <bool> isCheckedArr;
    int size = inSettings->beginReadArray(deviceStr);
    for (int i = 0; i < size; ++i) {
        inSettings->setArrayIndex(i);
        isCheckedArr.push_back(settings->value(deviceStr).toBool());
    }
    settings->endArray();
    return isCheckedArr;
}*/

/*void MainWindow::writeCheckBoxArr(const QString &deviceStr, QVector <QCheckBox*> &checkBoxArr)
{
    settings->beginWriteArray(deviceStr);
    for (int i = 0; i < checkBoxArr.size(); ++i) {
        settings->setArrayIndex(i);
        settings->setValue(deviceStr, checkBoxArr[i]->isChecked());
    }
    settings->endArray();
}*/

void MainWindow::writeCheckBoxArr(QSettings *inSettings, const QString &deviceStr, QVector <QCheckBox*> &checkBoxArr) {
    inSettings->beginWriteArray(deviceStr);
    for (int i = 0; i < checkBoxArr.size(); ++i) {
        inSettings->setArrayIndex(i);
        inSettings->setValue(deviceStr, checkBoxArr[i]->isChecked());
    }
    inSettings->endArray();
}

void MainWindow::fillCheckBoxArr(QVector <QCheckBox*> &checkBoxArr, QVector <bool> isCheckedArr)
{
    for (int i = 0; i < isCheckedArr.size(); i++) {
            checkBoxArr[i]->setChecked(isCheckedArr[i]);
    }
}
