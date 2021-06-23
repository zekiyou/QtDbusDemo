#include "mythermometer.h"
#include "mythermometerplugin.h"

#include <QtPlugin>

MyThermometerPlugin::MyThermometerPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void MyThermometerPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool MyThermometerPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *MyThermometerPlugin::createWidget(QWidget *parent)
{
    return new MyThermometer(parent);
}

QString MyThermometerPlugin::name() const
{
    return QLatin1String("MyThermometer");
}

QString MyThermometerPlugin::group() const
{
    return QLatin1String("MyThermometer");
}

QIcon MyThermometerPlugin::icon() const
{
    return QIcon();
}

QString MyThermometerPlugin::toolTip() const
{
    return QLatin1String("");
}

QString MyThermometerPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool MyThermometerPlugin::isContainer() const
{
    return false;
}

QString MyThermometerPlugin::domXml() const
{
    return QLatin1String("<widget class=\"MyThermometer\" name=\"myThermometer\">\n</widget>\n");
}

QString MyThermometerPlugin::includeFile() const
{
    return QLatin1String("mythermometer.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(mythermometerplugin, MyThermometerPlugin)
#endif // QT_VERSION < 0x050000
