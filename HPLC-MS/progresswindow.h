#ifndef PROGRESSWINDOW_H
#define PROGRESSWINDOW_H

#include <QMainWindow>

namespace Ui {
class ProgressWindow;
}

class ProgressWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProgressWindow(QWidget *parent = nullptr);
    ~ProgressWindow();

private:
    Ui::ProgressWindow *ui;
};

#endif // PROGRESSWINDOW_H
