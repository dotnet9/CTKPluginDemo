#include "pluginimpl.h"

#include <ctkPluginContext.h>
#include <QDebug>
#include "logview.h"

PluginImpl::PluginImpl(ctkPluginContext* context, LogImpl* logImpl)
    :m_pContext(context),
     m_pLogImpl(logImpl)
{
    context->registerService<PluginService>(this);
}

void PluginImpl::doSomeThing()
{
    qDebug() << "Plugin for log";
}

QWidget* PluginImpl::getWidget()
{
    return new LogView(m_pLogImpl ,nullptr);
}
