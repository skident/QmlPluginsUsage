#include "TimePlugin_plugin.h"

#include "GitsTimer.h"
#include "GitsDeadlineTimer.h"

#include <qqml.h>

void TimePluginPlugin::registerTypes(const char *uri)
{
    // @uri com.mycompany.qmlcomponents
    qmlRegisterType<GitsTimer>(uri, 1, 0, "GitsTimerCpp");
    qmlRegisterType<GitsDeadlineTimer>(uri, 1, 0, "GitsDeadlineTimerCpp");
}

