#ifndef LOGIMPL_H
#define LOGIMPL_H

#include <QObject>
#include "../../MainApp/logservice.h"

class ctkPluginContext;
class LogImpl : public QObject, public LogService
{
    Q_OBJECT
    Q_INTERFACES(LogService)
public:
    LogImpl(ctkPluginContext* context);
    void debug(const QString& msg) Q_DECL_OVERRIDE;

signals:
    void sendDebugMsg(const QString& msg);

private:
    ctkPluginContext* m_pContext;
};

#endif // LOGIMPL_H
