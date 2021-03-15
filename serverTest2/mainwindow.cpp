#include <QWidget>
#include <QGroupBox>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QSettings>

#include "mainwindow.h"
#include "client.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , client(new Client)
    , widget(new QWidget)
    , connectGroup(new QGroupBox(tr("Connect")))
    , settingsGroup(new QGroupBox(tr("Settings")))
    , layout(new QVBoxLayout(widget))
    , connectLayout(new QFormLayout)
    , settingsLayout(new QFormLayout)
    , connectLine(new QLineEdit)
    , connectButton(new QPushButton(tr("Connect")))
    , saveButton(new QPushButton(tr("Save")))
{
    // Set ui
    setCentralWidget(widget);
    layout->addWidget(connectGroup);
    layout->addWidget(settingsGroup);

    //connectGroup->setParent(widget);
    //settingsGroup->setParent(widget);
    connectGroup->setLayout(connectLayout);
    settingsGroup->setLayout(settingsLayout);
    connectLayout->addWidget(connectLine);
    connectLayout->addWidget(connectButton);

    QString path = client->getPath();
    QSettings settings(QString(path), QSettings::IniFormat);
    for (int i = 0; i < settingsSize; i++) {
        settingsLabels.push_back(new QLabel(settingsStrings[i]));
        settingsLines.push_back(new QLineEdit);
        settingsLayout->addRow(settingsLabels[i], settingsLines[i]);
        //settingsLines[i]->setText(settings.value(settingsLabels[i]->text()).toString());
    }
    settingsLayout->addRow(saveButton);

    // Set connectButton function
    connect(connectButton, &QPushButton::released, this, &MainWindow::onConnect);
    connect(saveButton, &QPushButton::released, this, &MainWindow::onSave);
    connect(this, &MainWindow::connectServer, client, &Client::connectServer);
    connect(client, &Client::clientConnected, this, &MainWindow::clientConnected);

}

MainWindow::~MainWindow()
{
    delete client;
    delete widget;
    delete connectGroup;
    delete settingsGroup;
    delete layout;
    delete connectLayout;
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
    QString path = client->getPath();
    QSettings settings(QString(path), QSettings::IniFormat);
    for (int i = 0; i < settingsSize; i++) {
        settings.setValue(settingsLabels[i]->text(), settingsLines[i]->text());
    }
    settings.sync();
    client->sendSettings();
}

void MainWindow::clientConnected()
{
    setLines();
}

void MainWindow::setLines()
{
    QString path = client->getPath();
    QSettings settings(path, QSettings::IniFormat);
    for (int i = 0; i < settingsSize; i++)
        settingsLines[i]->setText(settings.value(settingsLabels[i]->text()).toString());
}
