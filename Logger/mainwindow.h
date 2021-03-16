#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "tabwidget.h"

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    TabWidget *tabWidget;
};
#endif // MAINWINDOW_H
