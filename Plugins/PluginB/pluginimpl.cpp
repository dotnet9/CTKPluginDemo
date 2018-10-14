#include "pluginimpl.h"

#include <ctkPluginContext.h>
#include <QtDebug>
#include "form.h"
#include "servicetracker.h"

PluginImpl::PluginImpl(ctkPluginContext* context, ServiceTracker* tracker, ChatMsgEventHandler* msgEventHandler)
    :  m_pTracker(tracker),
      m_pMsgEventHandler(msgEventHandler),
      m_pContext(context)
{
    context->registerService<PluginService>(this);
}

void PluginImpl::doSomeThing()
{
    qDebug() << "Plugin B";
}

QWidget* PluginImpl::getWidget()
{
    return new Form(m_pContext, m_pTracker, m_pMsgEventHandler);
}
