#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    static int swapBits(unsigned int x, unsigned int p1, unsigned int p2, unsigned int n);
};
#endif // MAINWINDOW_H
