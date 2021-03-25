#include <QTextBrowser>
#include <QVBoxLayout>
#include <QDateTime>

#include "debugwindow.h"

DebugWindow::DebugWindow(Parameters *settings, QWidget *parent)
    : TabWindow(settings, parent)
{

    textBrowser = new QTextBrowser;
    QVBoxLayout *layout = new QVBoxLayout;

    layout->addWidget(textBrowser);
    setLayout(layout);
}

void DebugWindow::displayDebugMessage(const QByteArray &data)
{
    QString msg = QString(data);
    QString dateTimeStr = QDateTime::currentDateTime().toString();
    textBrowser->insertPlainText(dateTimeStr + ": " + msg + "\n");
}
