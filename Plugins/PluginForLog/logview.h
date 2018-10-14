#ifndef LOGVIEW_H
#define LOGVIEW_H

#include <QWidget>

namespace Ui {
class LogView;
}

class LogImpl;
class LogView : public QWidget
{
    Q_OBJECT

public:
    explicit LogView(LogImpl *logImpl, QWidget *parent = 0);
    ~LogView();

private:
    void receiveDebugLog(const QString& msg);

private:
    Ui::LogView *ui;

    LogImpl* m_plogImpl;
};

#endif // LOGVIEW_H
