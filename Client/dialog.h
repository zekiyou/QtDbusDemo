#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

    //提供接口给主窗口修改错误信息接口
    void setLabel(QString bugInfo);

private:
    Ui::Dialog* m_dialog;
};

#endif // DIALOG_H
