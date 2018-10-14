#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <service/event/ctkEventHandler.h>

namespace Ui {
class Form;
}

class ctkPluginContext;
class ChatMsgEventAdmin;
class ChatMsgEventHandler;
class ServiceTracker;
class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(ctkPluginContext* context, ServiceTracker* tracker, ChatMsgEventHandler* msgEventHandler, QWidget *parent = 0);
    ~Form();

private:
    void sendMsg_Clicked();
    void handleEventFromOther(const ctkEvent& event);

private:
    Ui::Form *ui;

    ctkPluginContext* m_pContext;
    ServiceTracker* m_pTracker;
    ChatMsgEventAdmin* m_pChatMrg;
    ChatMsgEventHandler* m_pMsgEventHandler;
};

#endif // FORM_H
