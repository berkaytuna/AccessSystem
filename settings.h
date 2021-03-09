#ifndef SETTINGS_H
#define SETTINGS_H

#endif // SETTINGS_H

#include <QObject>
#include <QString>

class Settings : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString color READ color WRITE setColor)
    Q_PROPERTY(QString dColor READ dColor WRITE setDColor)
    Q_PROPERTY(QString dImg READ dImg WRITE setDImg)
    Q_PROPERTY(QString dOne READ dOne WRITE setDOne)
    Q_PROPERTY(QString dTwo READ dTwo WRITE setDTwo)
    Q_PROPERTY(QString text READ text WRITE setText)
    Q_PROPERTY(int dTextY READ dTextY WRITE setDTextY)
    Q_PROPERTY(int dNum READ dNum WRITE setDNum)
    Q_PROPERTY(int space READ space WRITE setSpace)
    Q_PROPERTY(int dWidth READ dWidth WRITE setDWidth)
    Q_PROPERTY(int dHeight READ dHeight WRITE setDHeight)
    Q_PROPERTY(int dImgWidth READ dImgWidth WRITE setDImgWidth)
    Q_PROPERTY(int dImgHeight READ dImgHeight WRITE setDImgHeight)
    Q_PROPERTY(int dImgY READ dImgY WRITE setDImgY)
    Q_PROPERTY(int dTextS READ dTextS WRITE setDTextS)
    Q_PROPERTY(int dY READ dY WRITE setDY)
    Q_PROPERTY(int textY READ textY WRITE setTextY)
    Q_PROPERTY(int textS READ textS WRITE setTextS)

public:
    QString color() const { return _color; };
    QString dColor() const { return _dColor; };
    QString dImg() const { return _dImg; };
    QString dOne() const { return _dOne; };
    QString dTwo() const { return _dTwo; };
    QString text() const { return _text; };
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

    void setColor(QString inColor) { _color = inColor; };
    void setDColor(QString inColor) { _dColor = inColor; };
    void setDImg(QString inImg) { _dImg = inImg; };
    void setDOne(QString inText) { _dOne = inText; };
    void setDTwo(QString inText) { _dTwo = inText; };
    void setText(QString inText) { _text = inText; };
    void setDTextY(int inY) { _dTextY = inY; };
    void setDNum(int inNum) { _dNum = inNum; };
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

private:
    QString _color = "#7C1111";
    QString _dColor = "#7C1111";
    QString _dImg = nullptr;
    QString _dOne = "DoorOne";
    QString _dTwo = "DoorTwo";
    QString _text = "Please choose...";
    int _dTextY = 15;
    int _dNum = 0;
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
};
