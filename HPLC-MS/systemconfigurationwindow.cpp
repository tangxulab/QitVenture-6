#include "systemconfigurationwindow.h"
#include "ui_systemconfigurationwindow.h"

SystemConfigurationWindow::SystemConfigurationWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SystemConfigurationWindow)
{
    ui->setupUi(this);
    ui->tabWidget->removeTab(1);




}

SystemConfigurationWindow::~SystemConfigurationWindow()
{
    delete ui;
}
