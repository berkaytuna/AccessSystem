#ifndef LOGGER_H
#define LOGGER_H

#include <QWidget>

class Logger : public QWidget
{
    Q_OBJECT

public:
    Logger(QWidget *parent = nullptr);
    ~Logger();
};
#endif // LOGGER_H
