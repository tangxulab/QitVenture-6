#ifndef PROGRESSBARWINDOW_H
#define PROGRESSBARWINDOW_H

#include <QMainWindow>

namespace Ui {
class ProgressBarWindow;
}

class ProgressBarWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProgressBarWindow(QWidget *parent = nullptr);
    ~ProgressBarWindow();

private:
    Ui::ProgressBarWindow *ui;
};

#endif // PROGRESSBARWINDOW_H
