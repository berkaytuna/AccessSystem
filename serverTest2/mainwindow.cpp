#include <QWidget>
#include <QGroupBox>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QLabel>
#include <QSettings>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>

#include "mainwindow.h"
#include "constants.h"
#include "parameters.h"
#include "tabwidget.h"
#include "uiwindow.h"
#include "cardwindow.h"
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
{
    settings = new Parameters(cst::getPath(), QSettings::IniFormat);

    QTabWidget *tabWidget1 = new QTabWidget;
    UIWindow *uiWindow = new UIWindow(settings);
    CardWindow *cardWindow = new CardWindow(settings);

    tabWidget1->addTab(uiWindow, tr("UI"));
    tabWidget1->addTab(cardWindow, tr("Card"));

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
    connect(this, &MainWindow::connectServer, client, &Client::connectServer);
    connect(client, &Client::clientConnected, this, &MainWindow::clientConnected);


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
}

void MainWindow::onConnect()
{
    emit connectServer(connectLine->text());
}

void MainWindow::onSave()
{
    //qDebug() << getPath();
    //QString path = client->getPath();
    //QSettings settings(QString(path), QSettings::IniFormat);

    // Lines
    for (int i = 0; i < cst::labelNames.lines.size(); i++) {
        settings->setValue(cst::labelNames.lines[i], settings->lines[i]->text());
    }

    // CheckBox Layouts
    writeCheckBoxArr(settings, cst::labelNames.devices[0], settings->checkBoxesLF);
    writeCheckBoxArr(settings, cst::labelNames.devices[1], settings->checkBoxesQR);

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

    settings->sync();
    client->sendSettings();

    //qDebug() << settings->checkBoxesLF[8]->isChecked();
    //qDebug() << settings->lines[2]->text();
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
    for (int i = 0; i < cst::settingsSize; i++)
        settings->lines[i]->setText(settings->value(cst::labelNames.lines[i]).toString());

    // CheckBox Layouts
    QVector<QVector<bool>> isCheckedArrays;
    for (int i = 0; i < cst::deviceSize; i++) {
        QVector <bool> isCheckedArr = cst::readCheckBoxArr(settings, cst::labelNames.devices[i]);
        isCheckedArrays.push_back(isCheckedArr);
    }

    fillCheckBoxArr(settings->checkBoxesLF, isCheckedArrays[0]);
    fillCheckBoxArr(settings->checkBoxesQR, isCheckedArrays[1]);

    // CheckBoxes
    for (int i = 0; i < cst::labelNames.checkBoxes.size(); i++)
        settings->checkBoxes[i]->setChecked(settings->value(cst::labelNames.checkBoxes[i]).toBool());
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
