#include "eventlistener.h"

EventListener::EventListener(QObject *parent)
    : QObject(parent)
{

}

EventListener::~EventListener()
{

}

void EventListener::onFrameworkEvent(const ctkPluginFrameworkEvent &event)
{
    if(!event.isNull()) {
        QSharedPointer<ctkPlugin> plugin = event.getPlugin();
        qDebug() << "FrameworkEvent: [" << plugin->getSymbolicName() << "]" << event.getType() << event.getErrorString();
    } else {
        qDebug() << "The framework event is null";
    }
}

void EventListener::onPluginEvent(const ctkPluginEvent &event)
{
    if(!event.isNull()) {
        QSharedPointer<ctkPlugin> plugin = event.getPlugin();
        qDebug() << "PluginEvent: [" << plugin->getSymbolicName() << "]" << event.getType();
    } else {
        qDebug() << "The plugin event is null";
    }
}

void EventListener::onServiceEvent(const ctkServiceEvent &event)
{
    if(!event.isNull()) {
        ctkServiceReference ref = event.getServiceReference();
        QSharedPointer<ctkPlugin> plugin = ref.getPlugin();
        qDebug() << "ServiceEvent: [" << event.getType() << "]" << plugin->getSymbolicName() << ref.getUsingPlugins();
    } else {
        qDebug() << "The service event is null";
    }
}
