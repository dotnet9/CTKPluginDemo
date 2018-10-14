#ifndef SERVICETRACKER_H
#define SERVICETRACKER_H

#include <ctkPluginContext.h>
#include <ctkServiceTracker.h>
#include "../../MainApp/logservice.h"

class ServiceTracker : public ctkServiceTracker<LogService *>
{
public:
    ServiceTracker(ctkPluginContext* context);
    ~ServiceTracker();

protected:
    LogService* addingService(const ctkServiceReference &reference) Q_DECL_OVERRIDE;
    void modifiedService(const ctkServiceReference& reference, LogService* service) Q_DECL_OVERRIDE;
    void removedService(const ctkServiceReference& reference, LogService* service) Q_DECL_OVERRIDE;
};

#endif // SERVICETRACKER_H
