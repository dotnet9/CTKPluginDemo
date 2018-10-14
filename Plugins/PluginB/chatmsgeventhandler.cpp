#include "chatmsgeventhandler.h"

void ChatMsgEventHandler::handleEvent(const ctkEvent& event)
{
    QString msg = event.getProperty("message").toString();
    qDebug() << "receive msg form plugin a: " << msg;
    emit handleEventSignal(event);
}
