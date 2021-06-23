#include "mainwindow.h"
#include <QApplication>
#include "mainwindowadaptor.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //建立Dbus连接
    QDBusConnection connection = QDBusConnection::sessionBus();
    //注册Dbus服务
    connection.registerService("com.qdbus.server");
    //注册Dbus对象


    //用Object来导出信号和槽函数
    //connection.registerObject("/com/qdbus/server", &w, QDBusConnection::ExportAllSlots | QDBusConnection::ExportAllSignals);

    //用适配器方式来导出信号和槽函数
    ServerAdaptor adaptor(&w);
    connection.registerObject("/com/qdbus/server", &w);


    return a.exec();
}
