#ifndef TOGGLEWINDOW_H
#define TOGGLEWINDOW_H

#include <QMainWindow>
#include <QQmlApplicationEngine>
#include <QQuickWidget>
#include <QVBoxLayout>

namespace Ui {
class ToggleWindow;
}

class ToggleWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ToggleWindow(QWidget *parent = nullptr);
    ~ToggleWindow();

private:
    Ui::ToggleWindow *ui;
};

#endif // TOGGLEWINDOW_H
