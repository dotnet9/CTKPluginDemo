#ifndef CHATMSGEVENTHANDLER_H
#define CHATMSGEVENTHANDLER_H

#include <QObject>
#include <service/event/ctkEventHandler.h>

class ChatMsgEventHandler : public QObject, public ctkEventHandler
{
    Q_OBJECT
    Q_INTERFACES(ctkEventHandler)

public:
    void handleEvent(const ctkEvent& event) Q_DECL_OVERRIDE;

signals:
    void handleEventSignal(const ctkEvent& event);
};

#endif // CHATMSGEVENTHANDLER_H
