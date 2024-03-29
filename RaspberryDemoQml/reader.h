#ifndef READER_H
#define READER_H

#include <QObject>
#include <QSerialPort>
//#include <QThread>

class QSerialPortInfo;
class Settings;

/*static struct {
    //int readSize = 14;
    QString friendlyName = "QR";
    QString vid = "1a86";
    QString pid = "7523";
} QR;

static struct {
    int readSize = 13;
    QString friendlyName = "LF";
    QString vid = "403";
    QString pid = "6001";
} LF;*/

/*class ReadThread : public QThread
{
    Q_OBJECT

    void run() override;

public:
    ReadThread(int inSize, QSerialPort *inSerialPort);
    //~ReadThread();

signals:
    void readCardNumber(const QString &cardNumber);

private slots:
    void readyRead();

private:
    int expectedSize;
    QSerialPort *serialPort;

    void read();
};*/

class Reader : public QObject
{
    Q_OBJECT

public:
    explicit Reader(Settings &inSettings, QObject *parent = nullptr);
    ~Reader();

    bool init();

signals:
    void readCardNumber(QString cardNumber);

private slots:
    void readyRead();

private:
    Settings *settings;

    QVector <QSerialPort*> readers;
    QVector <QString> readerNames;
    //QString cardNumber;
    //ReadThread *LFThread;
    //ReadThread *QRThread;
    //QSerialPort *serialPortLF;
    //QSerialPort *serialPortQR;

    void addReader(QSerialPortInfo info, QSerialPort *serialPort);
    QString removeChars(QString &inCardNumber, QVector <bool> inIsCheckedArr);
    static void removeZeroFirst(QString &inCardNumber);
    static void removeZeroInside(QString &inCardNumber);
    static void turnBytes(QString &inCardNumber);
    static void turnBits(QString &inCardNumber);
    static int swapBits(unsigned int x, unsigned int p1, unsigned int p2, unsigned int n);

    //void startThread(ReadThread *thread);
    //void cardNumberReceived(const QString &cardNumber);
};

#endif // READER_H
