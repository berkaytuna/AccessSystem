#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QCoreApplication>
#include <QSettings>

namespace cst {

    // Size
    static const struct {
        int maxH = 300;
        int maxW = 300;
    } grid;

    static const int settingsSize = 4;
    static const int deviceSize = 2;

    // Names
    static const QStringList typeNames = { "solarium", "massage" };

    static const QVector <QString> tabNames = { "UI", "Card", "Relais", "Server" };

    static const struct {
        QVector <QString> lines = { "Text" , "Initial number", "Interval", "Server Ip"};
        QVector <QString> checkBoxes = { "LFZeroFirst", "QRZeroFirst", "LFzeroInside",
                                         "QRZeroInside", "LFTurnBytes", "QRTurnBytes",
                                         "LFTurnBits", "QRTurnBits", "Exist"};
        QVector <QString> comboBoxes = { "Type" };
        QVector <QString> devices = { "LF", "QR" };
    } labelNames;

    static const struct {
        QVector <QString> lines = { "text", "relaisOne/type", "relaisOne/initialNum",
                                    "relaisOne/interval", "relaisTwo/type",
                                    "relaisTwo/initialNum", "relaisTwo/interval", "serverip"};
        QVector <QString> comboBoxes = { "type0", "type1" };
    } settingsNames;

    /*static const struct {
        QVector <QString> uiGeneral = { "Text" };
        QVector <QString> uiDoor = { "Door number"};
        QVector <QString> uiTime = { "Initial number", "Interval" };
        QVector <QString> cardRemove = { "LF", "QR" };
    } labelNames;*/

    static const struct {
        QVector <QString> ui = { "General" };
        QVector <QString> card = { "Remove element", "Remove zero first", "Remove zero inside", "Turn bytes", "Turn bits within bytes" };
        QVector <QString> relais = { "RelaisOne", "RelaisTwo" };
        QVector <QString> server = { "Connection" };
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

    static QVector <bool> readCheckBoxArr(QSettings *inSettings, const QString &deviceStr) {
        QVector <bool> isCheckedArr;
        int size = inSettings->beginReadArray(deviceStr);
        for (int i = 0; i < size; ++i) {
            inSettings->setArrayIndex(i);
            isCheckedArr.push_back(inSettings->value(deviceStr).toBool());
        }
        inSettings->endArray();
        return isCheckedArr;
    };
};


#endif // CONSTANTS_H
