#include <QWidget>
#include <QGroupBox>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QLabel>
#include <QSettings>

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
    settings = new Parameters(getPath(), QSettings::IniFormat);

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
    for (int i = 0; i < settingsSize; i++) {
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
    for (int i = 0; i < settings->labels.size(); i++) {
        settings->setValue(settings->labels[i], settings->lines[i]->text());
    }

    settings->beginWriteArray("Remove");
    for (int i = 0; i < settings->checkBoxesLF.size(); ++i) {
        settings->setArrayIndex(i);
        settings->setValue("LF", settings->checkBoxesLF[i]->isChecked());
    }
    settings->endArray();

    settings->beginWriteArray("Remove");
    for (int i = 0; i < settings->checkBoxesQR.size(); ++i) {
        settings->setArrayIndex(i);
        settings->setValue("QR", settings->checkBoxesQR[i]->isChecked());
    }
    settings->endArray();

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
    //QString path = getPath();
    //QSettings settings(path, QSettings::IniFormat);
    for (int i = 0; i < settingsSize; i++)
        settings->lines[i]->setText(settings->value(settings->labels[i]).toString());
}
