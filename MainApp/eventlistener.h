#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H

#include <QObject>
#include <ctkPluginFrameworkEvent.h>
#include <ctkPluginEvent.h>
#include <ctkServiceEvent.h>

class EventListener : public QObject
{
    Q_OBJECT

public:
    explicit EventListener(QObject *parent = nullptr);
    ~EventListener();

signals:

public slots:
    void onFrameworkEvent(const ctkPluginFrameworkEvent& event);
    void onPluginEvent(const ctkPluginEvent& event);
    void onServiceEvent(const ctkServiceEvent& event);
};

#endif // EVENTLISTENER_H
