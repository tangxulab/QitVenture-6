#ifndef SYSTEMCONFIGURATIONWINDOW_H
#define SYSTEMCONFIGURATIONWINDOW_H

#include <QMainWindow>

namespace Ui {
class SystemConfigurationWindow;
}

class SystemConfigurationWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SystemConfigurationWindow(QWidget *parent = nullptr);
    ~SystemConfigurationWindow();

private:
    Ui::SystemConfigurationWindow *ui;
};

#endif // SYSTEMCONFIGURATIONWINDOW_H
