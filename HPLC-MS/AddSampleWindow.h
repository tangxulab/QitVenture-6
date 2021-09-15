#ifndef ADDSAMPLEWINDOW_H
#define ADDSAMPLEWINDOW_H

#include <QMainWindow>

namespace Ui {
class AddSampleWindow;
}

class AddSampleWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddSampleWindow(QWidget *parent = nullptr);
    ~AddSampleWindow();

private:
    Ui::AddSampleWindow *ui;
};

#endif // ADDSAMPLEWINDOW_H
