#ifndef SETTINGS_H
#define SETTINGS_H

#endif // SETTINGS_H

//#include <QObject>
#include <QSettings>
#include <QCoreApplication>
#include <QString>
#include <QDebug>
#include <QTimer>

#include "constants.h"

namespace setCst {
    static const QString backgroundColor = "#7C1111";
}

class Settings : public QSettings
{
    Q_OBJECT
    Q_PROPERTY(QString color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(QString dColor READ dColor WRITE setDColor NOTIFY dColorChanged)
    Q_PROPERTY(QString rColor READ rColor WRITE setRColor NOTIFY rColorChanged)
    Q_PROPERTY(QString dImg READ dImg WRITE setDImg NOTIFY dImgChanged)
    //Q_PROPERTY(QString rImg READ rImg WRITE setRImg NOTIFY rImgChanged)
    Q_PROPERTY(QString dOne READ dOne WRITE setDOne NOTIFY dOneChanged)
    Q_PROPERTY(QString dTwo READ dTwo WRITE setDTwo NOTIFY dTwoChanged)
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
    Q_PROPERTY(QString numText READ numText WRITE setNumText NOTIFY numTextChanged)
    Q_PROPERTY(QString minImg READ minImg WRITE setMinImg NOTIFY minImgChanged)
    Q_PROPERTY(QString plusImg READ plusImg WRITE setPlusImg NOTIFY plusImgChanged)
    Q_PROPERTY(QString typeImgSrc READ typeImgSrc WRITE setTypeImgSrc NOTIFY typeImgSrcChanged)
    Q_PROPERTY(QString typeText READ typeText WRITE setTypeText NOTIFY typeTextChanged)
    Q_PROPERTY(int screenW READ screenW WRITE setScreenW NOTIFY screenWChanged)
    Q_PROPERTY(int screenH READ screenH WRITE setScreenH NOTIFY screenHChanged)
    Q_PROPERTY(int num READ num WRITE setNum NOTIFY numChanged)
    Q_PROPERTY(int dTextY READ dTextY WRITE setDTextY NOTIFY dTextYChanged)
    Q_PROPERTY(int dNum READ dNum WRITE setDNum NOTIFY dNumChanged)
    Q_PROPERTY(int space READ space WRITE setSpace NOTIFY spaceChanged)
    Q_PROPERTY(int dWidth READ dWidth WRITE setDWidth NOTIFY dWidthChanged)
    Q_PROPERTY(int dHeight READ dHeight WRITE setDHeight NOTIFY dHeightChanged)
    Q_PROPERTY(int dImgWidth READ dImgWidth WRITE setDImgWidth NOTIFY dImgWidthChanged)
    Q_PROPERTY(int dImgHeight READ dImgHeight WRITE setDImgHeight NOTIFY dImgHeightChanged)
    Q_PROPERTY(int dImgY READ dImgY WRITE setDImgY NOTIFY dImgYChanged)
    Q_PROPERTY(int rImgWidth READ rImgWidth WRITE setRImgWidth NOTIFY rImgWidthChanged)
    Q_PROPERTY(int rImgHeight READ rImgHeight WRITE setRImgHeight NOTIFY rImgHeightChanged)
    Q_PROPERTY(int rImgY READ rImgY WRITE setRImgY NOTIFY rImgYChanged)
    //Q_PROPERTY(int rImgX READ rImgX WRITE setRImgX NOTIFY rImgXChanged)
    Q_PROPERTY(int typeImgW READ typeImgW WRITE setTypeImgW NOTIFY typeImgWChanged)
    Q_PROPERTY(int typeImgH READ typeImgH WRITE setTypeImgH NOTIFY typeImgHChanged)
    Q_PROPERTY(int typeImgY READ typeImgY WRITE setTypeImgY NOTIFY typeImgYChanged)
    Q_PROPERTY(int dTextS READ dTextS WRITE setDTextS NOTIFY dTextSChanged)
    Q_PROPERTY(int dY READ dY WRITE setDY NOTIFY dYChanged)
    Q_PROPERTY(int textY READ textY WRITE setTextY NOTIFY textYChanged)
    Q_PROPERTY(int textS READ textS WRITE setTextS NOTIFY textSChanged)
    Q_PROPERTY(int dTypeOne READ dTypeOne WRITE setDTypeOne NOTIFY dTypeOneChanged)
    Q_PROPERTY(int dTypeTwo READ dTypeTwo WRITE setDTypeTwo NOTIFY dTypeTwoChanged)
    Q_PROPERTY(int minW READ minW WRITE setMinW NOTIFY minWChanged)
    Q_PROPERTY(int minH READ minH WRITE setMinH NOTIFY minHChanged)
    Q_PROPERTY(int minX READ minX WRITE setMinX NOTIFY minXChanged)
    Q_PROPERTY(int minY READ minY WRITE setMinY NOTIFY minYChanged)
    Q_PROPERTY(int plusW READ plusW WRITE setPlusW NOTIFY plusWChanged)
    Q_PROPERTY(int plusH READ plusH WRITE setPlusH NOTIFY plusHChanged)
    Q_PROPERTY(int plusX READ plusX WRITE setPlusX NOTIFY plusXChanged)
    Q_PROPERTY(int plusY READ plusY WRITE setPlusY NOTIFY plusYChanged)
    Q_PROPERTY(int typeTextY READ typeTextY WRITE setTypeTextY NOTIFY typeTextYChanged)
    Q_PROPERTY(int typeTextS READ typeTextS WRITE setTypeTextS NOTIFY typeTextSChanged)
    Q_PROPERTY(int numTextY READ numTextY WRITE setNumTextY NOTIFY numTextYChanged)
    Q_PROPERTY(int numTextS READ numTextS WRITE setNumTextS NOTIFY numTextSChanged)
    Q_PROPERTY(int interval READ interval WRITE setInterval NOTIFY intervalChanged)
    Q_PROPERTY(int currentD READ currentD WRITE setCurrentD NOTIFY currentDChanged)
    Q_PROPERTY(int currentV READ currentV WRITE setCurrentV NOTIFY currentVChanged)
    Q_PROPERTY(bool b2D READ b2D WRITE setB2D NOTIFY b2DChanged)
    Q_PROPERTY(bool bCanRead READ bCanRead WRITE setBCanRead NOTIFY bCanReadChanged)
    //Q_PROPERTY(bool bResult READ bResult WRITE setBResult NOTIFY bResultChanged)
    Q_PROPERTY(bool bSuccess READ bSuccess WRITE setBSuccess NOTIFY bSuccessChanged)
    //Q_PROPERTY(bool bTimeoutRequested READ bTimeoutRequested WRITE setBTimeoutRequested NOTIFY bTimeoutRequestedChanged)

signals:
    void colorChanged(const QString &newColor);
    void dColorChanged(const QString &newDColor);
    void rColorChanged(const QString &newRColor);
    void dImgChanged(const QString &newDImg);
    //void rImgChanged(const QString &newRImg);
    void dOneChanged(const QString &newDOne);
    void dTwoChanged(const QString &newDTwo);
    void textChanged(const QString &newText);
    void numTextChanged(const QString &newNumText);
    void minImgChanged(const QString &newMinImg);
    void plusImgChanged(const QString &newPlusImg);
    void typeImgSrcChanged(const QString &newTypeImgSrc);
    void typeTextChanged(const QString &newTypeText);
    void screenWChanged(const int &newScreenW);
    void screenHChanged(const int &newScreenH);
    void numChanged(const int &newNum);
    void dTextYChanged(const int &newDTextY);
    void dNumChanged(const int &newDNum);
    void spaceChanged(const int &newSpace);
    void dWidthChanged(const int &newDWidth);
    void dHeightChanged(const int &newDHeight);
    void dImgWidthChanged(const int &newDImgWidth);
    void dImgHeightChanged(const int &newDImgHeight);
    void dImgYChanged(const int &newDImgY);
    void rImgWidthChanged(const int &newRImgWidth);
    void rImgHeightChanged(const int &newRImgHeight);
    void rImgYChanged(const int &newRImgY);
    //void rImgXChanged(const int &newRImgX);
    void typeImgWChanged(const int &newTypeImgW);
    void typeImgHChanged(const int &newTypeImgH);
    void typeImgYChanged(const int &newTypeImgY);
    void dTextSChanged(const int &newTextS);
    void dYChanged(const int &newDY);
    void textYChanged(const int &newTextY);
    void textSChanged(const int &newTextS);
    void dTypeOneChanged(const int &newDTypeOne);
    void dTypeTwoChanged(const int &newDTypeTwo);
    void minWChanged(const int &newMinW);
    void minHChanged(const int &newMinH);
    void minXChanged(const int &newMinX);
    void minYChanged(const int &newMinY);
    void plusWChanged(const int &newPlusW);
    void plusHChanged(const int &newPlusH);
    void plusXChanged(const int &newPlusX);
    void plusYChanged(const int &newPlusY);
    void typeTextYChanged(const int &newTypeTextY);
    void typeTextSChanged(const int &newTypeTextS);
    void numTextYChanged(const int &newNumTextY);
    void numTextSChanged(const int &newNumTextS);
    void intervalChanged(const int &newInterval);
    void currentDChanged(const int &newCurrentD);
    void currentVChanged(const int &newCurrentV);
    void b2DChanged(const bool &newB2D);
    void bCanReadChanged(const bool &newBCanRead);
    //void bResultChanged(const bool &newBResult);
    void bSuccessChanged(const bool &newBSuccess);
    //void bTimeoutRequestedChanged(const bool &newBTimeoutRequested);

public:
    inline Settings(const QString &fileName, Format format, QObject *parent = nullptr)
        : QSettings(fileName, format, parent) {
        setBCanRead(_b2D ? false /*_bCanRead*/ : true);

        QString typeOneStr = value(cst::settingsNames.comboBoxes[0]).toString();
        if (typeOneStr == "solarium")
            setDTypeOne(0);
        else if (typeOneStr == "massage")
            setDTypeOne(1);

        QString typeTwoStr = value(cst::settingsNames.comboBoxes[1]).toString();
        if (typeTwoStr == "solarium")
            setDTypeTwo(0);
        else if (typeTwoStr == "massage")
            setDTypeTwo(1);
    };

    QTimer *timer = nullptr;
    //QVector <QString> connectedReaders;
    QVector <QVector<bool>> isCheckedArrays;
    QVector <bool> isCheckedSingleArrays;
    QStringList typeNames;

    QString color() const { return _color; };
    QString dColor() const { return _dColor; };
    QString rColor() const { return _rColor; };
    QString dImg() const { return _dImg; };
    //QString rImg() const { return _rImg; };
    QString dOne() const { return _dOne; };
    QString dTwo() const { return _dTwo; };
    QString text() const { return _text; };
    QString numText() const { return _numText; };
    QString minImg() const { return _minImg; };
    QString plusImg() const { return _plusImg; };
    QString typeImgSrc() const { return _typeImgSrc; };
    QString typeText() const { return _typeText; };
    int screenW() const { return _screenW; };
    int screenH() const { return _screenH; };
    int num() const { return _num; };
    int dTextY() const { return _dTextY; };
    int dNum() const { return _dNum; };
    int space() const { return _space; };
    int dWidth() const { return _dWidth; };
    int dHeight() const { return _dHeight; };
    int dImgWidth() const { return _dImgWidth; };
    int dImgHeight() const { return _dImgHeight; };
    int dImgY() const { return _dImgY; };
    int rImgWidth() const { return _rImgWidth; };
    int rImgHeight() const { return _rImgHeight; };
    int rImgY() const { return _rImgY; };
    //int rImgX() const { return _rImgX; };
    int typeImgW() const { return _typeImgW; };
    int typeImgH() const { return _typeImgH; };
    int typeImgY() const { return _typeImgY; };
    int dTextS() const { return _dTextS; };
    int dY() const { return _dY; };
    int textY() const { return _textY; };
    int textS() const { return _textS; };
    int dTypeOne() const { return _dTypeOne; };
    int dTypeTwo() const { return _dTypeTwo; };
    int minW() const { return _minW; };
    int minH() const { return _minH; };
    int minX() const { return _minX; };
    int minY() const { return _minY; };
    int plusW() const { return _plusW; };
    int plusH() const { return _plusH; };
    int plusX() const { return _plusX; };
    int plusY() const { return _plusY; };
    int typeTextY() const { return _typeTextY; };
    int typeTextS() const { return _typeTextS; };
    int numTextY() const { return _numTextY; };
    int numTextS() const { return _numTextS; };
    int interval() const { return _interval; };
    int currentD() const { return _currentD; };
    int currentV() const { return _currentV; };
    bool b2D() const { return _b2D; };
    bool bCanRead() const { return _bCanRead; };
    //bool bResult() const { return _bResult; };
    bool bSuccess() const { return _bSuccess; };
    //bool bTimeoutRequested() const { return _bTimeoutRequested; };

    void setColor(QString inColor) { _color = inColor; };
    void setDColor(QString inColor) { _dColor = inColor; };
    void setRColor(QString inColor) { _rColor = inColor; };
    void setDImg(QString inImg) { _dImg = inImg; };
    //void setRImg(QString inImg) { _rImg = inImg; };
    void setDOne(QString inText) { _dOne = inText; };
    void setDTwo(QString inText) { _dTwo = inText; };
    void setText(QString inText) {
        _text = inText;
        emit textChanged(_text);
    };
    void setNumText(QString inText) { _numText = inText; };
    void setMinImg(QString inText) { _minImg = inText; };
    void setPlusImg(QString inText) { _plusImg = inText; };
    void setTypeImgSrc(QString inSrc) {
        _typeImgSrc = inSrc;
        emit typeImgSrcChanged(_typeImgSrc);
    }
    void setTypeText(QString inText) {
        _typeText = inText;
        emit typeTextChanged(inText);
    };
    void setScreenW(int inW) { _screenW = inW; };
    void setScreenH(int inH) { _screenH = inH; };
    void setNum(int inNum) {
        _num = inNum;
        QString newNumTextMin = "";
        QString newNumTextSec = "";
        newNumTextMin = QString::number((int)(_num/60));
        if (_num%60 < 10)
            newNumTextSec += "0";
        newNumTextSec += QString::number(_num%60);
        setNumText( newNumTextMin + ":" + newNumTextSec );
        emit numTextChanged(_numText);
        qDebug() << "new numText: " << _numText;
    };
    void setDTextY(int inY) { _dTextY = inY; };
    void setDNum(int inNum) {
        _dNum = inNum;
        emit dNumChanged(_dNum);
        qDebug() << "new dNum: " << _dNum;
    };
    void setSpace(int inSpace) { _space = inSpace; };
    void setDWidth(int inWidth) { _dWidth = inWidth; };
    void setDHeight(int inHeight) { _dHeight = inHeight; };
    void setDImgWidth(int inWidth) { _dImgWidth = inWidth; };
    void setDImgHeight(int inHeight) { _dImgHeight = inHeight; };
    void setDImgY(int inY) { _dImgY = inY; };
    void setRImgWidth(int inWidth) { _rImgWidth = inWidth; };
    void setRImgHeight(int inHeight) { _rImgHeight = inHeight; };
    void setRImgY(int inY) { _rImgY = inY; };
    //void setRImgX(int inX) { _rImgX = inX; };
    void setTypeImgW(int inW) { _typeImgW = inW; };
    void setTypeImgH(int inH) { _typeImgH = inH; };
    void setTypeImgY(int inY) { _typeImgY = inY; };
    void setDTextS(int inS) { _dTextS = inS; };
    void setDY(int inY) { _dY = inY; };
    void setTextY(int inY) { _textY = inY; };
    void setTextS(int inS) { _textS = inS; };
    void setDTypeOne(int inType) {
        _dTypeOne = inType;
        emit dTypeOneChanged(_dTypeOne);
    };
    void setDTypeTwo(int inType) {
        _dTypeTwo = inType;
        emit dTypeTwoChanged(_dTypeTwo);
    };
    void setMinW(int inW) { _minW = inW; };
    void setMinH(int inH) { _minH = inH; };
    void setMinX(int inX) { _minX = inX; };
    void setMinY(int inY) { _minY = inY; };
    void setPlusW(int inW) { _plusW = inW; };
    void setPlusH(int inH) { _plusH = inH; };
    void setPlusX(int inX) { _plusX = inX; };
    void setPlusY(int inY) { _plusY = inY; };
    void setTypeTextY(int inY) { _typeTextY = inY; };
    void setTypeTextS(int inS) { _typeTextS = inS; };
    void setNumTextY(int inY) { _numTextY = inY; };
    void setNumTextS(int inS) { _numTextS = inS; };
    void setInterval(int inInterval) {
        _interval = inInterval;
        emit intervalChanged(_interval);
    };
    void setCurrentD(int inCurrentD) {
        _currentD = inCurrentD;
        changeDoorSelection();
    };
    void setCurrentV(int inCurrentV) {
        _currentV = inCurrentV;
        emit currentVChanged(_currentV);
    };
    void setB2D(bool inB2D) {
        _b2D = inB2D;
        emit b2DChanged(_b2D);
        qDebug() << "new b2D: " << _b2D;
        setCurrentD(inB2D ? _currentD : 0);
    };
    void setBCanRead(bool inBCanRead) {
        _bCanRead = inBCanRead;
        qDebug() << "bCanRead is: " << _bCanRead;
    };
    /*void setBResult(bool inBResult) {
        _bResult = inBResult;
        emit bResultChanged(_bResult);
    };*/
    void setBSuccess(bool inBSuccess) {
        _bSuccess = inBSuccess;
        emit bSuccessChanged(_bSuccess);
    };
    /*void setBTimeoutRequested(bool inBTimeoutRequested) {
        _bTimeoutRequested = inBTimeoutRequested;
        startTimeoutTimer();
    };*/

    void changeDoorSelection();
    void restart();
    Q_INVOKABLE void startTimeoutTimer();
    void deleteTimeoutTimer();

    /*static QString getPath() {
        QString path = QCoreApplication::applicationDirPath();
        path.append("/config.ini");
        return path;
    };*/

private:
    QString _color = setCst::backgroundColor;
    QString _dColor = setCst::backgroundColor;
    QString _rColor = setCst::backgroundColor;
    QString _dImg = "qrc:images/door.png";
    //QString _rImg = "qrc:images/rCross.png";
    QString _dOne = "DoorOne";
    QString _dTwo = "DoorTwo";
    QString _text = "Bitte wählen...";
    QString _numText;
    QString _minImg = "qrc:images/minus.png";
    QString _plusImg = "qrc:images/plus.png";
    QString _typeImgSrc = "qrc:images/solarium.png";
    QString _typeText = "solarium";
    int _screenW = 480;
    int _screenH = 320;
    int _num = 30;
    int _dTextY = 15;
    int _dNum = 2;
    int _space = 30;
    int _dWidth = 160;
    int _dHeight = 220;
    int _dImgWidth = 120;
    int _dImgHeight = 120;
    int _dImgY = 65;
    int _rImgWidth = 100;
    int _rImgHeight = 100;
    int _rImgY = 60;
    //int _rImgX = 40;
    int _typeImgW = 80;
    int _typeImgH = 80;
    int _typeImgY = 90;
    int _dTextS = 20;
    int _dY = 35;
    int _textY = 260;
    int _textS = 18;
    int _dTypeOne = 1;
    int _dTypeTwo = 0;
    int _minW = 60;
    int _minH = 60;
    int _minX = 100;
    int _minY = 200;
    int _plusW = 60;
    int _plusH = 60;
    int _plusX = 320;
    int _plusY = 200;
    int _typeTextY = 50;
    int _typeTextS = 24;
    int _numTextY = 200;
    int _numTextS = 36;
    int _interval = 5;
    int _currentD = 0;
    int _currentV = 0;
    bool _b2D = false;
    bool _bCanRead = false;
    //bool _bResult = false;
    bool _bSuccess = false;
    //bool _bTimeoutRequested = false;
};
