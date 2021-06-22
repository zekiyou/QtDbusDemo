#include "echoplugin.h"
#include <QDebug>

EchoPlugin::EchoPlugin(QObject *parent) :
    QObject(parent)
{
}

QString EchoPlugin::echo(const QString &message)
{
    qDebug()<<message;
    return message;
}
