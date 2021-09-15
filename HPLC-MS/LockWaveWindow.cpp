 #include "LockWaveWindow.h"
#include "ui_LockWaveWindow.h"

LockWaveWindow::LockWaveWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LockWaveWindow)
{
    ui->setupUi(this);
}

LockWaveWindow::~LockWaveWindow()
{
    delete ui;
}
