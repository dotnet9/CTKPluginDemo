#include "pluginactivator.h"
#include "pluginimpl.h"
#include "logimpl.h"

void PluginActivator::start(ctkPluginContext* context)
{
    m_pLogImpl = new LogImpl(context);
    s.reset(new PluginImpl(context, m_pLogImpl));
    logS.reset(m_pLogImpl);
}

void PluginActivator::stop(ctkPluginContext* context)
{
    Q_UNUSED(context)
}
