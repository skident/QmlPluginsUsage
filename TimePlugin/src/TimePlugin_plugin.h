#ifndef TIMEPLUGIN_PLUGIN_H
#define TIMEPLUGIN_PLUGIN_H

#include <QQmlExtensionPlugin>

class TimePluginPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override;
};

#endif // TIMEPLUGIN_PLUGIN_H
