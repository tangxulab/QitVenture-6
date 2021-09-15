#ifndef SYSTEMCHECKWINDOW_H
#define SYSTEMCHECKWINDOW_H

#include <QMainWindow>

namespace Ui {
class SystemCheckWindow;
}

class SystemCheckWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SystemCheckWindow(QWidget *parent = nullptr);
    ~SystemCheckWindow();

private:
    Ui::SystemCheckWindow *ui;
};

#endif // SYSTEMCHECKWINDOW_H
