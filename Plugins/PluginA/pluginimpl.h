#ifndef PLUGINIMPL_H
#define PLUGINIMPL_H


#include "../../MainApp/pluginservice.h"
#include <QObject>

class ctkPluginContext;
class ChatMsgEventHandler;
class ServiceTracker;

class PluginImpl : public QObject, public PluginService
{
    Q_OBJECT
    Q_INTERFACES(PluginService)

public:
    PluginImpl(ctkPluginContext* context, ServiceTracker* tracker, ChatMsgEventHandler* msgEventHandler);
    void doSomeThing() Q_DECL_OVERRIDE;
    QWidget* getWidget() Q_DECL_OVERRIDE;

private:
    ctkPluginContext* m_pContext;
    ChatMsgEventHandler* m_pMsgEventHandler;
    ServiceTracker* m_pTracker;
};

#endif // PLUGINIMPL_H
