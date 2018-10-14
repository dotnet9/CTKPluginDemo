#include "form.h"
#include "ui_form.h"
#include <ctkPluginContext.h>
#include "chatmsgeventadmin.h"
#include <QDateTime>
#include "chatmsgeventhandler.h"
#include "servicetracker.h"

Form::Form(ctkPluginContext* context, ServiceTracker* tracker, ChatMsgEventHandler* msgEventHandler, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form),
    m_pContext(context),
    m_pTracker(tracker),
    m_pChatMrg(nullptr),
    m_pMsgEventHandler(msgEventHandler)
{
    ui->setupUi(this);

    connect(ui->btnSend, &QPushButton::clicked, this, &Form::sendMsg_Clicked);
    connect(m_pMsgEventHandler, &ChatMsgEventHandler::handleEventSignal, this, &Form::handleEventFromOther);
}

Form::~Form()
{
    delete ui;
}

void Form::sendMsg_Clicked()
{
    if(m_pChatMrg == nullptr)
    {
        m_pChatMrg = new ChatMsgEventAdmin(m_pContext);
    }
    ChatMessage msg;
    msg.msg = ui->txtSend->toPlainText();
    m_pChatMrg->publishMessage(msg);

    ui->txtAll->append(QString("I:\n%1: %2").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz")).arg(msg.msg));

    LogService* service = m_pTracker->getService();
    if(service != Q_NULLPTR) {
        service->debug(QString("Now plugin B send msg to other plugin, the msg is %1").arg(msg.msg));
    }
}

void Form::handleEventFromOther(const ctkEvent& event)
{
    QString msg = event.getProperty("message").toString();
    ui->txtAll->append(QString("A:\n%1: %2").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz")).arg(msg));
}
