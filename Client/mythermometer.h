#ifndef MYTHERMOMETER_H
#define MYTHERMOMETER_H

#include <QWidget>

class MyThermometer : public QWidget
{
    Q_OBJECT
private:
    double temperature;
public:
    MyThermometer(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void setTemperature(double temperature);
};

#endif
