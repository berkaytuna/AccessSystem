#ifndef READER_H
#define READER_H

#include <QObject>
#include <QSerialPort>
//#include <QThread>

class QSerialPortInfo;

static struct {
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
} LF;

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
    explicit Reader(QObject *parent = nullptr);
    ~Reader();

    bool init();

private slots:
    void readyRead();

private:
    QVector <QSerialPort*> readers;
    QVector <QString> readerNames;
    //QString cardNumber;
    //ReadThread *LFThread;
    //ReadThread *QRThread;
    //QSerialPort *serialPortLF;
    //QSerialPort *serialPortQR;

    void addReader(QSerialPortInfo info, QSerialPort *serialPort);
    //void startThread(ReadThread *thread);
    //void cardNumberReceived(const QString &cardNumber);
};

#endif // READER_H
