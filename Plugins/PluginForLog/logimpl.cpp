#include "logimpl.h"

#include <ctkPluginContext.h>
#include <QDebug>
#include "logview.h"

LogImpl::LogImpl(ctkPluginContext* context)
    :m_pContext(context)
{
    context->registerService<LogService>(this);
}

void LogImpl::debug(const QString& msg)
{
    emit sendDebugMsg(msg);
}
