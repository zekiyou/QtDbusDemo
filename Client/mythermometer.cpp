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
        QBrush brush;   //画刷。填充几何图形的调色板，由颜色和填充风格组成

        brush.setStyle(Qt::SolidPattern);

        if (37.2 > temperature){
            pen.setColor(Qt::green);            // 设置画笔颜色
            brush.setColor(Qt::green);
        }
        if (37.2 <= temperature) {
            pen.setColor(Qt::red);
            brush.setColor(Qt::red);
        }
        painter.setPen(pen);                // 设置画笔
        painter.drawRect(QRect(0, 0, 200, 30   ));
        painter.setBrush(brush);
        painter.drawRect(QRect(0, 0, temperature*2, 30  ));
}

void MyThermometer::setTemperature(double temperature)
{
    this->temperature=temperature;
}

