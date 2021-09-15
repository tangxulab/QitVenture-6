#ifndef CONTROLPANCELWINDOW_H
#define CONTROLPANCELWINDOW_H

//控制面板类
#include <QMainWindow>

namespace Ui {
class ControlPancelWindow;
}

class ControlPancelWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ControlPancelWindow(QWidget *parent = nullptr);
    ~ControlPancelWindow();

private slots:

private:
    Ui::ControlPancelWindow *ui;
};

#endif // CONTROLPANCELWINDOW_H
