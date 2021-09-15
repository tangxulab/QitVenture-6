#include "systemcheckwindow.h"
#include "ui_systemcheckwindow.h"

SystemCheckWindow::SystemCheckWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SystemCheckWindow)
{
    ui->setupUi(this);
}

SystemCheckWindow::~SystemCheckWindow()
{
    delete ui;
}
