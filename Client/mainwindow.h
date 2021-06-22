#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QGSettings>
#include <QPainter>
#include "dialog.h"
#include "thermometer.h"
#include <QRegularExpression>
#include <QtDBus/QtDBus>

#include <QMainWindow>
#include <QGlobalStatic>

namespace Ui {
class MainWindow;
}

class MainWindowPrivate;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(MainWindow)
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    //录入输入框信息保存于GSettting xml
    void on_pushButton_clicked();

    //接受send_to_client是否通行信号
    void client_get_ok(void);
    void client_get_error(void);

private:

    MainWindowPrivate* d_ptr;
    Ui::MainWindow *ui;

    /*
    QGSettings* m_settings;
    Dialog* m_dialog;
    thermometer* m_thermometer;
    QRegExp id_exp;
    QRegExp tel_exp;
    */

};

#endif // MAINWINDOW_H
