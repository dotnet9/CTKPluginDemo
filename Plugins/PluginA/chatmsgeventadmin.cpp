#include "chatmsgeventadmin.h"
#include <service/event/ctkEventAdmin.h>
#include <QtDebug>

ChatMsgEventAdmin::ChatMsgEventAdmin(ctkPluginContext* context)
    : m_pContext(context)
{

}

void ChatMsgEventAdmin::publishMessage(const ChatMessage &msg)
{
    ctkServiceReference ref = m_pContext->getServiceReference<ctkEventAdmin>();
    if(ref) {
        ctkEventAdmin* eventAdmin = m_pContext->getService<ctkEventAdmin>(ref);
        ctkDictionary props;
        props["message"] = msg.msg;
        ctkEvent event("org/commontk/chatmsgmrg_A/published", props);
        qDebug() << "Publisher sends a message, properties: " << props;

        eventAdmin->sendEvent(event);
    }
}
