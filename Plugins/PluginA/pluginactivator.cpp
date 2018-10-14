#include "pluginactivator.h"
#include "pluginimpl.h"
#include "chatmsgeventhandler.h"
#include "servicetracker.h"
#include "service/event/ctkEventConstants.h"

void PluginActivator::start(ctkPluginContext* context)
{
    m_pTracker = new ServiceTracker(context);
    m_pTracker->open();

    m_pChatMsgEventHandler = new ChatMsgEventHandler();
    s.reset(new PluginImpl(context, m_pTracker, m_pChatMsgEventHandler));

    ctkDictionary props;
    props[ctkEventConstants::EVENT_TOPIC] = "org/commontk/chatmsgmrg_B/published";
    context->registerService<ctkEventHandler>(m_pChatMsgEventHandler, props);
}

void PluginActivator::stop(ctkPluginContext* context)
{
    Q_UNUSED(context)
}
