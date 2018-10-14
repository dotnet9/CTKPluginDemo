#ifndef PLUGINACTIVATOR_H
#define PLUGINACTIVATOR_H


#include <ctkPluginActivator.h>
#include "../../MainApp/pluginservice.h"

class ChatMsgEventHandler;
class ServiceTracker;
class PluginActivator : public QObject, public ctkPluginActivator
{
    Q_OBJECT
    Q_INTERFACES(ctkPluginActivator)
    Q_PLUGIN_METADATA(IID "PluginA_CTK")

public:
    void start(ctkPluginContext* context);
    void stop(ctkPluginContext* context);

private:
    QScopedPointer<PluginService> s;
    ChatMsgEventHandler* m_pChatMsgEventHandler;
    ServiceTracker* m_pTracker;
};

#endif // PLUGINACTIVATOR_H
