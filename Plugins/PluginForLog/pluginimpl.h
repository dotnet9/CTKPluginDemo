#ifndef PLUGINIMPL_H
#define PLUGINIMPL_H

#include <QObject>
#include "../../MainApp/pluginservice.h"

class ctkPluginContext;
class LogImpl;
class PluginImpl : public QObject, public PluginService
{
    Q_OBJECT
    Q_INTERFACES(PluginService)
public:
    PluginImpl(ctkPluginContext* context, LogImpl* logImpl);
    void doSomeThing() Q_DECL_OVERRIDE;
    QWidget* getWidget() Q_DECL_OVERRIDE;

private:
    ctkPluginContext* m_pContext;
    LogImpl* m_pLogImpl;
};

#endif // PLUGINIMPL_H
