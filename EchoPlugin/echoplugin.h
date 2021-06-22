#ifndef ECHOPLUGIN_H
#define ECHOPLUGIN_H

#include "../QtDbusDemo/Server/echointerface.h"

class EchoPlugin : public QObject, public EchoInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID EchoInterface_iid)
    Q_INTERFACES(EchoInterface)
public:
    explicit EchoPlugin(QObject *parent = 0);
    QString echo(const QString &message);
};

#endif // ECHOPLUGIN_H
