#include "controlpancelwindow.h"
#include "ui_controlpancelwindow.h"

ControlPancelWindow::ControlPancelWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ControlPancelWindow)
{
    ui->setupUi(this);
    //setFixedSize(400,300);
}

ControlPancelWindow::~ControlPancelWindow()
{
    delete ui;
}



