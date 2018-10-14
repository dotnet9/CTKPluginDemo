#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDirIterator>
#include <QtDebug>

#include <ctkPluginFrameworkLauncher.h>
#include <ctkPluginFrameworkFactory.h>
#include <ctkPluginFramework.h>
#include <ctkPluginException.h>
#include <ctkPluginContext.h>

#include "pluginservice.h"
#include "eventlistener.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadPlugin();
}

MainWindow::~MainWindow()
{
    ctkPluginFrameworkLauncher::stop();

    delete ui;
}

void MainWindow::loadPlugin()
{

    // get plugin location path
    QString path = QApplication::applicationDirPath() + "/plugins";

    //add the path to plugin search path list
    ctkPluginFrameworkLauncher::addSearchPath(path);

    //set and start CTK Plugin System
    ctkPluginFrameworkLauncher::start("org.commontk.eventadmin");

    //get plugin context
    context = ctkPluginFrameworkLauncher::getPluginContext();

    // event listener
    EventListener listener;
    context->connectFrameworkListener(&listener, SLOT(onFrameworkEvent(ctkPluginFrameworkEvent)));
    context->connectPluginListener(&listener, SLOT(onPluginEvent(ctkPluginEvent)));
    // filter ctkEventAdmin服务
    // QString filter = QString("(%1=%2)").arg(ctkPluginZZZConstants::OBJECTCLASS).arg("org.commontk.eventadmin")
    context->connectServiceListener(&listener, "onServiceEvent"); //, filter);

    QDirIterator itPlugin(path, QStringList() << "*.dll" << "*.so", QDir::Files);
    while(itPlugin.hasNext()) {
        QString strPlugin = itPlugin.next();
        try {
            QSharedPointer<ctkPlugin> plugin = context->installPlugin(QUrl::fromLocalFile(strPlugin));

            // 获取清单头和值
            QHash<QString, QString> headers = plugin->getHeaders();
            qDebug() << "Headers:" << headers << "\r\n";

            // 获取符号名
            QString symb = plugin->getSymbolicName();
            qDebug() << "Symbolic Name:" << symb << "\r\n";

            plugin->start(ctkPlugin::START_TRANSIENT);
            qDebug() << "Plugin start ...";



            ctkServiceReference reference = context->getServiceReference<PluginService>();
            if (reference) {
                PluginService* service = qobject_cast<PluginService *>(context->getService(reference));
                if(service != Q_NULLPTR) {
                    service->doSomeThing();
                    QWidget* w = service->getWidget();
                    if("Plugin.A" == symb) {
                        ui->glPluginA->addWidget(w);;
                    }
                    else if("Plugin.B" == symb) {
                        ui->glPluginB->addWidget(w);;
                    }
                    else {
                        ui->glLog->addWidget(w);
                    }
                }
            }
        } catch(const ctkPluginException &e) {
            qDebug() << "Failed to install plugin" << e.what();
            return;
        }
    }
}
