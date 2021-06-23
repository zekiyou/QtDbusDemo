#include "mythermometer.h"
#include <QPen>
#include <QPainter>

MyThermometer::MyThermometer(QWidget *parent) :
    QWidget(parent)
{

}

void MyThermometer::paintEvent(QPaintEvent *)
{
        QPainter painter(this);             // 创建QPainter一个对象
        QPen pen;

        if (37.2 <= temperature){
            pen.setColor(Qt::green);            // 设置画笔颜色
        }
        if (37.2 > temperature) {
            pen.setColor(Qt::red);
        }
        painter.setPen(pen);                // 设置画笔
        painter.drawRect(QRect(1, 1, 300, 100));
        painter.restore();
}

void MyThermometer::setTemperature(double temperature)
{
    this->temperature=temperature;
}

