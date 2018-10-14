#ifndef CHATMSGEVENTADMIN_H
#define CHATMSGEVENTADMIN_H

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


#endif // CHATMSGEVENTADMIN_H
