#ifndef THERMOMETER_H
#define THERMOMETER_H

#include <QDialog>

namespace Ui {
class thermometer;
}

class thermometer : public QDialog
{
    Q_OBJECT

public:
    explicit thermometer(QWidget *parent = nullptr);
    ~thermometer();

    void setLabel(QString bugInfo);
    void setProgressBar(double temperature);
private:
    Ui::thermometer *ui;
};

#endif // THERMOMETER_H
