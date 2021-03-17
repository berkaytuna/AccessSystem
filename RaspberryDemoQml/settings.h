#ifndef SETTINGS_H
#define SETTINGS_H

#endif // SETTINGS_H

//#include <QObject>
#include <QSettings>
#include <QCoreApplication>
#include <QString>
#include <QDebug>

class Settings : public QSettings
{
    Q_OBJECT
    Q_PROPERTY(QString color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(QString dColor READ dColor WRITE setDColor NOTIFY dColorChanged)
    Q_PROPERTY(QString dImg READ dImg WRITE setDImg NOTIFY dImgChanged)
    Q_PROPERTY(QString dOne READ dOne WRITE setDOne NOTIFY dOneChanged)
    Q_PROPERTY(QString dTwo READ dTwo WRITE setDTwo NOTIFY dTwoChanged)
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
    Q_PROPERTY(QString numText READ numText WRITE setNumText NOTIFY numTextChanged)
    Q_PROPERTY(QString minImg READ minImg WRITE setMinImg NOTIFY minImgChanged)
    Q_PROPERTY(QString plusImg READ plusImg WRITE setPlusImg NOTIFY plusImgChanged)
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
    Q_PROPERTY(int dTextS READ dTextS WRITE setDTextS NOTIFY dTextSChanged)
    Q_PROPERTY(int dY READ dY WRITE setDY NOTIFY dYChanged)
    Q_PROPERTY(int textY READ textY WRITE setTextY NOTIFY textYChanged)
    Q_PROPERTY(int textS READ textS WRITE setTextS NOTIFY textSChanged)
    Q_PROPERTY(int dTypeOne READ dTypeOne WRITE setDTypeOne NOTIFY dTypeOneChanged)
    Q_PROPERTY(int dTypeTwo READ dTypeTwo WRITE setDTypeTwo NOTIFY dTypeTwoChanged)
    Q_PROPERTY(int minW READ minW WRITE setMinW NOTIFY minWChanged)
    Q_PROPERTY(int minH READ minH WRITE setMinH NOTIFY minHChanged)
    Q_PROPERTY(int minX READ minX WRITE setMinX NOTIFY minXChanged)
    Q_PROPERTY(int plusW READ plusW WRITE setPlusW NOTIFY plusWChanged)
    Q_PROPERTY(int plusH READ plusH WRITE setPlusH NOTIFY plusHChanged)
    Q_PROPERTY(int plusX READ plusX WRITE setPlusX NOTIFY plusXChanged)
    Q_PROPERTY(int numTextS READ numTextS WRITE setNumTextS NOTIFY numTextSChanged)
    Q_PROPERTY(int interval READ interval WRITE setInterval NOTIFY intervalChanged)

signals:
    void colorChanged(const QString &newColor);
    void dColorChanged(const QString &newDColor);
    void dImgChanged(const QString &newDImg);
    void dOneChanged(const QString &newDOne);
    void dTwoChanged(const QString &newDTwo);
    void textChanged(const QString &newText);
    void numTextChanged(const QString &newNumText);
    void minImgChanged(const QString &newMinImg);
    void plusImgChanged(const QString &newPlusImg);
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
    void dTextSChanged(const int &newTextS);
    void dYChanged(const int &newDY);
    void textYChanged(const int &newTextY);
    void textSChanged(const int &newTextS);
    void dTypeOneChanged(const int &newDTypeOne);
    void dTypeTwoChanged(const int &newDTypeTwo);
    void minWChanged(const int &newMinW);
    void minHChanged(const int &newMinH);
    void minXChanged(const int &newMinX);
    void plusWChanged(const int &newPlusW);
    void plusHChanged(const int &newPlusH);
    void plusXChanged(const int &newPlusX);
    void numTextSChanged(const int &newNumTextS);
    void intervalChanged(const int &newInterval);

public:
    inline Settings(const QString &fileName, Format format, QObject *parent = nullptr)
        : QSettings(fileName, format, parent) { };

    QString color() const { return _color; };
    QString dColor() const { return _dColor; };
    QString dImg() const { return _dImg; };
    QString dOne() const { return _dOne; };
    QString dTwo() const { return _dTwo; };
    QString text() const { return _text; };
    QString numText() const { return _numText; };
    QString minImg() const { return _minImg; };
    QString plusImg() const { return _plusImg; };
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
    int dTextS() const { return _dTextS; };
    int dY() const { return _dY; };
    int textY() const { return _textY; };
    int textS() const { return _textS; };
    int dTypeOne() const { return _dTypeOne; };
    int dTypeTwo() const { return _dTypeTwo; };
    int minW() const { return _minW; };
    int minH() const { return _minH; };
    int minX() const { return _minX; };
    int plusW() const { return _plusW; };
    int plusH() const { return _plusH; };
    int plusX() const { return _plusX; };
    int numTextS() const { return _numTextS; };
    int interval() const { return _interval; };

    void setColor(QString inColor) { _color = inColor; };
    void setDColor(QString inColor) { _dColor = inColor; };
    void setDImg(QString inImg) { _dImg = inImg; };
    void setDOne(QString inText) { _dOne = inText; };
    void setDTwo(QString inText) { _dTwo = inText; };
    void setText(QString inText) { _text = inText; };
    void setNumText(QString inText) { _numText = inText; };
    void setMinImg(QString inText) { _minImg = inText; };
    void setPlusImg(QString inText) { _plusImg = inText; };
    void setScreenW(int inW) { _screenW = inW; };
    void setScreenH(int inH) { _screenH = inH; };
    void setNum(int inNum) {
        _num = inNum;
        setNumText(QString::number(inNum));
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
    void setDTextS(int inS) { _dTextS = inS; };
    void setDY(int inY) { _dY = inY; };
    void setTextY(int inY) { _textY = inY; };
    void setTextS(int inS) { _textS = inS; };
    void setDTypeOne(int inType) { _dTypeOne = inType; };
    void setDTypeTwo(int inType) { _dTypeTwo = inType; };
    void setMinW(int inW) { _minW = inW; };
    void setMinH(int inH) { _minH = inH; };
    void setMinX(int inX) { _minX = inX; };
    void setPlusW(int inW) { _plusW = inW; };
    void setPlusH(int inH) { _plusH = inH; };
    void setPlusX(int inX) { _plusX = inX; };
    void setNumTextS(int inS) { _numTextS = inS; };
    void setInterval(int inInterval) { _interval = inInterval; };

    static QString getPath() {
        QString path = QCoreApplication::applicationDirPath();
        path.append("/config.ini");
        return path;
    };

private:
    QString _color = "#7C1111";
    QString _dColor = "#7C1111";
    QString _dImg = "qrc:images/door.png";
    QString _dOne = "DoorOne";
    QString _dTwo = "DoorTwo";
    QString _text = "Please choose...";
    QString _numText;
    QString _minImg = "qrc:images/minus.png";
    QString _plusImg = "qrc:images/plus.png";
    int _screenW = 480;
    int _screenH = 320;
    int _num = 30;
    int _dTextY = 15;
    int _dNum = 2;
    int _space = 30;
    int _dWidth = 160;
    int _dHeight = 220;
    int _dImgWidth = 140;
    int _dImgHeight = 180;
    int _dImgY = 40;
    int _dTextS = 20;
    int _dY = 35;
    int _textY = 260;
    int _textS = 18;
    int _dTypeOne = 1;
    int _dTypeTwo = 0;
    int _minW = 60;
    int _minH = 60;
    int _minX = 100;
    int _plusW = 60;
    int _plusH = 60;
    int _plusX = 320;
    int _numTextS = 36;
    int _interval = 5;
};
