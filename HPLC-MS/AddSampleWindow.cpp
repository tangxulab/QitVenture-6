#include "AddSampleWindow.h"
#include "ui_AddSampleWindow.h"

AddSampleWindow::AddSampleWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddSampleWindow)
{
    ui->setupUi(this);
}

AddSampleWindow::~AddSampleWindow()
{
    delete ui;
}
