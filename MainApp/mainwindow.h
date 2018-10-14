#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

namespace Ui {
class MainWindow;
}

class ctkPluginContext;
class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void loadPlugin();

private:
    Ui::MainWindow *ui;

    ctkPluginContext *context;
};

#endif // MAINWINDOW_H
