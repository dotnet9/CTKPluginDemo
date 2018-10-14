#ifndef PLUGINACTIVATOR_H
#define PLUGINACTIVATOR_H

#include <ctkPluginActivator.h>
#include "../../MainApp/pluginservice.h"
#include "../../MainApp/logservice.h"

class LogImpl;
class PluginActivator : public QObject, public ctkPluginActivator
{
    Q_OBJECT
    Q_INTERFACES(ctkPluginActivator)
    Q_PLUGIN_METADATA(IID "PluginForLog_CTK")

public:
    void start(ctkPluginContext* context);
    void stop(ctkPluginContext* context);

private:
    QScopedPointer<PluginService> s;
    QScopedPointer<LogService> logS;
    LogImpl* m_pLogImpl;
};
#endif // PLUGINACTIVATOR_H
