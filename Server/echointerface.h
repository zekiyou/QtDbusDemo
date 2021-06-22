#ifndef ECHOINTERFACE_H
#define ECHOINTERFACE_H


#include <QString>
#include <QtPlugin>

//定义接口
class EchoInterface
{
public:
    virtual ~EchoInterface() = 0;
    virtual QString echo(const QString &message) = 0;
};

#define EchoInterface_iid "Examples.Plugin.EchoInterface"

QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(EchoInterface, EchoInterface_iid)
QT_END_NAMESPACE


#endif // ECHOINTERFACE_H
