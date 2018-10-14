#ifndef CHATMSGMRG_H
#define CHATMSGMRG_H

#include <ctkPluginContext.h>
#include "../../MainApp/chatmessage.h"

class ChatMsgEventAdmin
{
public:
    ChatMsgEventAdmin(ctkPluginContext* context);
    void publishMessage(const ChatMessage& msg);

private:
    ctkPluginContext* m_pContext;
};

#endif // CHATMSGMRG_H
