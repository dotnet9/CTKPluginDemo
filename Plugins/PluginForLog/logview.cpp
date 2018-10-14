#include "logview.h"
#include "ui_logview.h"
#include "logimpl.h"
#include <QDateTime>

LogView::LogView(LogImpl* logImpl, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogView),
    m_plogImpl(logImpl)
{
    ui->setupUi(this);
    connect(m_plogImpl, &LogImpl::sendDebugMsg, this, &LogView::receiveDebugLog);
}

LogView::~LogView()
{
    delete ui;
}

void LogView::receiveDebugLog(const QString &msg)
{
    ui->txtLog->append(QString("%1: %2\n").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz")).arg(msg));
}
