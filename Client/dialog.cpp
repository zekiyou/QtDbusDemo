#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , m_dialog(new Ui::Dialog)
{
    m_dialog->setupUi(this);
}

Dialog::~Dialog()
{
    delete m_dialog;
}

void Dialog::setLabel(QString bugInfo)
{
    m_dialog->label->setText(bugInfo);
}


