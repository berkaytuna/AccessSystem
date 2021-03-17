#include <QSerialPortInfo>
#include <QDebug>

#include "reader.h"

/*ReadThread::ReadThread(int inSize, QSerialPort *inSerialPort)
{
    expectedSize = inSize;
    serialPort = inSerialPort;
}

void ReadThread::readyRead()
{
    qDebug() << serialPort->readAll();
}

void ReadThread::run()
{
    connect(serialPort, &QSerialPort::readyRead, this, &ReadThread::readyRead);
    //read();
    //QString result;
    // ... here is the expensive or blocking operation ...
    //emit resultReady(result);
}

void ReadThread::read()
{
    //qDebug() << "reading...";

    while(1) {
        int numRead = 0, numReadTotal = 0;
        char buffer[50];
        //numRead = serialPort->read(buffer, 50);
        //qDebug() << "numRead: " << numRead;
        //int bytesAvailable = serialPort->bytesAvailable();
        //qDebug() << "bytes available: " << bytesAvailable;
        if (false) {
            QString readBuffer(serialPort->readAll());
            qDebug() << readBuffer.length();
            //qDebug() << "buffer: " << readBuffer << " length: " << readBuffer.length();
            if (readBuffer.length() == expectedSize) {
                //QString readBuffer(serialPort->readAll());
                qDebug() << "cardnumber: " << readBuffer;
                //emit readCardNumber(readBuffer);
            }
            //QString cardNumber(buffer);
            //qDebug() << cardNumber;
            //emit readCardNumber(cardNumber);
        }

        //numReadTotal += numRead;
        if (numRead == 0 && !serialPort->waitForReadyRead()) {
           qDebug() << "breaking serial read!";
           break;
        }

        //qDebug() << serialPort->waitForReadyRead();
    }
}*/

Reader::Reader(QObject *parent) : QObject(parent) { }

Reader::~Reader()
{
    for (auto e : readers)
        delete e;

    //delete LFThread;
    //delete QRThread;
}

bool Reader::init()
{
    // ports info
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos) {
        QString vid = info.hasVendorIdentifier() ? QString::number(info.vendorIdentifier(), 16) : QString();
        QString pid = info.hasProductIdentifier() ? QString::number(info.productIdentifier(), 16) : QString();
        QString infoStr = QObject::tr("Port: ") + info.portName() + "\n"
            + QObject::tr("Location: ") + info.systemLocation() + "\n"
            + QObject::tr("Description: ") + info.description() + "\n"
            + QObject::tr("Manufacturer: ") + info.manufacturer() + "\n"
            + QObject::tr("Serial number: ") + info.serialNumber() + "\n"
            + QObject::tr("Vendor Identifier: ") + vid + "\n"
            + QObject::tr("Product Identifier: ") + pid + "\n"
            + QObject::tr("Busy: ") + (info.isBusy() ? QObject::tr("Yes") : QObject::tr("No")) + "\n";
        qDebug() << "serial port info: " << infoStr;

        // add to the reader list
        QSerialPort *serialPort;
        if (vid == LF.vid && pid == LF.pid) {
            qDebug() << "found LF!";
            serialPort = new QSerialPort;
            readerNames.push_back("LF");
            addReader(info, serialPort);
            //LFThread = new ReadThread(LF.readSize, serialPort);
            //startThread(LFThread);
            connect(serialPort, &QSerialPort::readyRead, this, &Reader::readyRead);
        }
        else if (vid == QR.vid && pid == QR.pid) {
            qDebug() << "found QR!";
            serialPort = new QSerialPort;
            readerNames.push_back("QR");
            addReader(info, serialPort);
            //QRThread = new ReadThread(QR.readSize, serialPort);
            //startThread(QRThread);
            connect(serialPort, &QSerialPort::readyRead, this, &Reader::readyRead);
        }
    }

    return false;
}

void Reader::readyRead()
{
    QSerialPort *serialPort = static_cast<QSerialPort*>(sender());
    QString readerName;
    for (auto &e : readers) {
        if (e == serialPort)
            readerName = readerNames[&e - &readers[0]];
    }
    QString bufferStr(serialPort->readAll());
    if (readerName == "LF" && bufferStr.length() != LF.readSize) return;
    else
        qDebug() << "from: " << readerName << " card number: " << bufferStr;
}

void Reader::addReader(QSerialPortInfo info, QSerialPort *serialPort)
{
    readers.push_back(serialPort);
    serialPort->setPort(info);
    serialPort->open(QIODevice::ReadOnly);
}

/*void Reader::startThread(ReadThread *thread)
{
    connect(thread, &ReadThread::readCardNumber, this, &Reader::cardNumberReceived);
    connect(thread, &ReadThread::finished, thread, &QObject::deleteLater);
    thread->start();
}*/

/*void Reader::cardNumberReceived(const QString &cardNumber)
{
    qDebug() << cardNumber;
}*/
