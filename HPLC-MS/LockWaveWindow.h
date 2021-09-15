#ifndef LOCKWAVEWINDOW_H
#define LOCKWAVEWINDOW_H

#include <QMainWindow>

namespace Ui {
class LockWaveWindow;
}

class LockWaveWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LockWaveWindow(QWidget *parent = nullptr);
    ~LockWaveWindow();

private:
    Ui::LockWaveWindow *ui;
};

#endif // LOCKWAVEWINDOW_H
