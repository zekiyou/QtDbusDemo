#ifndef INTERFACEPLUGIN_H
#define INTERFACEPLUGIN_H
#include <QtPlugin>

//定义接口
class InterfacePlugin
{
public:
    virtual ~InterfacePlugin() = 0 ;
    virtual void SetTemp(const double temp) = 0;
};

//唯一标识符
#define InterfacePlugin_iid "Test.Plugin.InterfacePlugin"
Q_DECLARE_INTERFACE(InterfacePlugin, InterfacePlugin_iid)


#endif // INTERFACEPLUGIN_H
