#include <QSerialPortInfo>
#include <QDebug>

#include "reader.h"
#include "constants.h"
#include "settings.h"

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

Reader::Reader(Settings &inSettings, QObject *parent)
    : QObject(parent)
{
    settings = &inSettings;
}

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
        if (vid == cst::LF.vid && pid == cst::LF.pid) {
            qDebug() << "found LF!";
            serialPort = new QSerialPort;
            readerNames.push_back("LF");
            addReader(info, serialPort);
            //LFThread = new ReadThread(LF.readSize, serialPort);
            //startThread(LFThread);
            connect(serialPort, &QSerialPort::readyRead, this, &Reader::readyRead);
        }
        else if (vid == cst::QR.vid && pid == cst::QR.pid) {
            qDebug() << "found QR!";
            serialPort = new QSerialPort;
            readerNames.push_back("QR");
            addReader(info, serialPort);
            //QRThread = new ReadThread(QR.readSize, serialPort);
            //startThread(QRThread);
            connect(serialPort, &QSerialPort::readyRead, this, &Reader::readyRead);
        }
        settings->sync();
    }

    return false;
}

void Reader::readyRead()
{
    qDebug() << "bCanRead: " << settings->bCanRead();
    if (!settings->bCanRead()) return;

    QSerialPort *serialPort = static_cast<QSerialPort*>(sender());
    QString readerName;
    for (auto &e : readers) {
        if (e == serialPort)
            readerName = readerNames[&e - &readers[0]];
    }
    QString bufferStr(serialPort->readAll());

    QString cardNumber = bufferStr;
    if (readerName == cst::LF.friendlyName && bufferStr.length() != cst::LF.readSize) return;
    else {
        for (int i = 0; i < 2; i++)
            cardNumber.remove(cardNumber.length() - 1 , 1);
        qDebug() << "from: " << readerName << " card number: " << cardNumber;
    }

    if (readerName == cst::LF.friendlyName) {
        removeChars(cardNumber, settings->isCheckedArrays[0]);
        if (settings->isCheckedSingleArrays[0])
            removeZeroFirst(cardNumber);
        if (settings->isCheckedSingleArrays[2])
            removeZeroInside(cardNumber);
        if (settings->isCheckedSingleArrays[4])
            turnBytes(cardNumber);
        if (settings->isCheckedSingleArrays[6])
            turnBits(cardNumber);
    }
    else if (readerName == cst::QR.friendlyName) {
        removeChars(cardNumber, settings->isCheckedArrays[1]);
        if (settings->isCheckedSingleArrays[1])
            removeZeroFirst(cardNumber);
        if (settings->isCheckedSingleArrays[3])
            removeZeroInside(cardNumber);
        if (settings->isCheckedSingleArrays[5])
            turnBytes(cardNumber);
        if (settings->isCheckedSingleArrays[7])
            turnBits(cardNumber);
    }

    qDebug() << "modified: " + cardNumber;
    emit readCardNumber(cardNumber);
    settings->setBCanRead(false);
}

void Reader::addReader(QSerialPortInfo info, QSerialPort *serialPort)
{
    readers.push_back(serialPort);
    serialPort->setPort(info);
    serialPort->open(QIODevice::ReadOnly);
}

QString Reader::removeChars(QString &inCardNumber, QVector <bool> inIsCheckedArr)
{
    int removedChars = 0;
    for (int i = 0; i < inIsCheckedArr.size(); i++) {
        if (inIsCheckedArr[i] == true) {
            inCardNumber = inCardNumber.remove(i - removedChars, 1);
            removedChars ++;
        }
    }
    return inCardNumber;
}

void Reader::removeZeroFirst(QString &inCardNumber)
{
    bool cond = (inCardNumber[0] == '0') && (inCardNumber[1] == '0');
    if (cond) {
        for (int i = 0; i < 2; i++)
            inCardNumber.remove(0, 1);
    }
}

void Reader::removeZeroInside(QString &inCardNumber)
{
    bool cond1 = inCardNumber.contains("00");
    bool cond2 = !(inCardNumber[0] == '0' && inCardNumber[1] == '0');
    if (cond1 && cond2)
        inCardNumber.remove("00");
}

void Reader::turnBytes(QString &inCardNumber)
{
    QByteArray cmd = QByteArray::fromHex(inCardNumber.toLatin1());
    QByteArray cmdRev(cmd.size(), 0);
    std::copy(cmd.crbegin(), cmd.crend(), cmdRev.begin());
    inCardNumber = QString((cmdRev.toHex().toUpper()));
}

void Reader::turnBits(QString &inCardNumber)
{
    QByteArray cmd = QByteArray::fromHex(inCardNumber.toLatin1());
    QByteArray cmdBitRev(cmd.size(), 0);
    for (int i = 0; i < cmd.size(); i++)
        cmdBitRev[i] = swapBits(cmd[i], 4, 0, 4);
    inCardNumber = QString((cmdBitRev.toHex().toUpper()));
}

int Reader::swapBits(unsigned int x, unsigned int p1, unsigned int p2, unsigned int n)
{
    /* Move all bits of first set to rightmost side */
    unsigned int set1 = (x >> p1) & ((1U << n) - 1);

    /* Move all bits of second set to rightmost side */
    unsigned int set2 = (x >> p2) & ((1U << n) - 1);

    /* XOR the two sets */
    unsigned int exor = (set1 ^ set2);

    /* Put the xor bits back to their original positions */
    exor = (exor << p1) | (exor << p2);

    /* XOR the 'xor' with the original number so that the
       two sets are swapped */
    unsigned int result = x ^ exor;

    return result;
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
