#include "servicetracker.h"

ServiceTracker::ServiceTracker(ctkPluginContext* context)
    :ctkServiceTracker<LogService *>(context)
{

}

ServiceTracker::~ServiceTracker()
{

}

LogService* ServiceTracker::addingService(const ctkServiceReference &reference)
{
    qDebug() << "Adding service: " << reference.getPlugin()->getSymbolicName();
    LogService* service = (LogService *)(ctkServiceTracker::addingService(reference));
    if(service != Q_NULLPTR) {
        service->debug("OK");
    }

    return service;
}

void ServiceTracker::modifiedService(const ctkServiceReference &reference, LogService *service)
{
    qDebug() << "Modified service: " << reference.getPlugin()->getSymbolicName();
    ctkServiceTracker::modifiedService(reference, service);
}

void ServiceTracker::removedService(const ctkServiceReference &reference, LogService *service)
{
    qDebug() << "Removed service: " << reference.getPlugin()->getSymbolicName();
    ctkServiceTracker::removedService(reference, service);
}
