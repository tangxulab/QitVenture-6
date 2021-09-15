#include "qualitative_param_window.h"
#include "ui_qualitative_param_window.h"

Qualitative_Param_Window::Qualitative_Param_Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Qualitative_Param_Window)
{
    ui->setupUi(this);
}

Qualitative_Param_Window::~Qualitative_Param_Window()
{
    delete ui;
}
