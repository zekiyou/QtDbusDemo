#include "thermometer.h"
#include "ui_thermometer.h"

thermometer::thermometer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::thermometer)
{
    ui->setupUi(this);
}

thermometer::~thermometer()
{
    delete ui;
}

void thermometer::setLabel(QString bugInfo)
{
    ui->label->setText(bugInfo);
}

void thermometer::setProgressBar(double temperature)
{

    ui->progressBar->setValue(temperature);
    if(temperature >= 37.2)
        ui->progressBar->setStyleSheet("QProgressBar::chunk { background-color: red }");
    if(temperature < 37.2)
        ui->progressBar->setStyleSheet("QProgressBar::chunk { background-color: green }");

}
