#include <QDebug>

#include "mainwindow.h"
#include <stdio.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QString cardNumber;

    // Turn bytes
    cardNumber = "E00200BA";
    qDebug() << cardNumber;
    QByteArray cmd = QByteArray::fromHex(cardNumber.toLatin1());
    QByteArray cmdRev(cmd.size(), 0);
    std::copy(cmd.crbegin(), cmd.crend(), cmdRev.begin());
    cardNumber = QString((cmdRev.toHex().toUpper()));
    qDebug() << cardNumber;

    // Turn bits
    cardNumber = "E00200BA";
    qDebug() << cardNumber;
    cmd = QByteArray::fromHex(cardNumber.toLatin1());
    QByteArray cmdBitRev(cmd.size(), 0);
    for (int i = 0; i < cmd.size(); i++)
        cmdBitRev[i] = swapBits(cmd[i], 4, 0, 4);
    cardNumber = QString((cmdBitRev.toHex().toUpper()));
    qDebug() << cardNumber;


}

MainWindow::~MainWindow()
{
}

int MainWindow::swapBits(unsigned int x, unsigned int p1, unsigned int p2, unsigned int n)
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

