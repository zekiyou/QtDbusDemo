#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtDBus/QtDBus>
#include <QStandardItemModel>

namespace Ui {
class MainWindow;
}

class MainWindowPrivate;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.qdbus.server")
    Q_DECLARE_PRIVATE(MainWindow)

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    MainWindowPrivate* d_ptr;
    Ui::MainWindow *ui;   
//    int count=0;
//    QStandardItemModel *model;

public slots:
     //接受Client发送的send_to_server数据已经发送信号
     void server_get(QString name , int age , QString id , QString tel , QString adress , double temperature);
signals:
     //发送给Client是否通行的信号
     void send_to_client_ok(void);
     void send_to_client_error(void);
};

#endif // MAINWINDOW_H
