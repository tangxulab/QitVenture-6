#ifndef SAMPLEINFOINSERTWINDOW_H
#define SAMPLEINFOINSERTWINDOW_H

#include <QMainWindow>

namespace Ui {
class SampleInfoInsertWindow;
}

class SampleInfoInsertWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SampleInfoInsertWindow(QWidget *parent = nullptr);
    ~SampleInfoInsertWindow();

private:
    Ui::SampleInfoInsertWindow *ui;
};

#endif // SAMPLEINFOINSERTWINDOW_H
