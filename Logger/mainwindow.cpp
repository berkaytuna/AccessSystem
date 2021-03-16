#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , tabWidget(new TabWidget)
{
    setWindowTitle(tr("Logger"));
    setCentralWidget(tabWidget);
}

MainWindow::~MainWindow()
{
    delete tabWidget;
}

