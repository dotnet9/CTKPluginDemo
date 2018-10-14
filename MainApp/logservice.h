#ifndef LOGSERVICE_H
#define LOGSERVICE_H

#include <QtPlugin>

class LogService
{
public:
    virtual ~LogService(){}

    virtual void debug(const QString& msg) = 0;
};

#define LogService_iid "org.commontk.service.demos.LogService"
Q_DECLARE_INTERFACE(LogService, LogService_iid)

#endif // LOGSERVICE_H
