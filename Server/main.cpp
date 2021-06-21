#include "mainwindow.h"
#include <QApplication>

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
    connection.registerObject("/com/qdbus/server", &w, QDBusConnection::ExportAllSlots | QDBusConnection::ExportAllSignals);

    QDBusConnection::sessionBus().connect("com.qdbus.client",
                                          "/com/qdbus/client",
                                          "com.qdbus.client",
                                          "send_to_server",
                                          &w,
                                          SLOT(server_get(QString name , int age , QString id , QString tel , QString adress , double temperature))
                                          );

    return a.exec();
}
