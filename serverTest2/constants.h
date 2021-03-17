#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QCoreApplication>

// Size
static const struct {
    int maxH = 300;
    int maxW = 300;
} grid;

// Names
static const QVector <QString> tabNames = { "UI", "Card" };

static const struct {
    QVector <QString> uiGeneral = { "Text" };
    QVector <QString> uiDoor = { "Door number"};
    QVector <QString> uiTime = { "Initial number", "Interval" };
    QVector <QString> cardRemove = { "LF", "QR" };
} labelNames;

static const struct {
    QVector <QString> ui = { "General", "Door", "Time" };
    QVector <QString> card = { "Remove" };
} groupNames;

// Reader
static const struct {
    int readSize = 13;
    int numberSize = 11;
    QString friendlyName = "LF";
    QString vid = "403";
    QString pid = "6001";
} LF;

static const struct {
    int readSize = 14;
    int numberSize = 12;
    QString friendlyName = "QR";
    QString vid = "1a86";
    QString pid = "7523";
} QR;

// Functions
static const QString getPath() {
    QString path = QCoreApplication::applicationDirPath();
    path.append("/config.ini");
    return path;
};

#endif // CONSTANTS_H
