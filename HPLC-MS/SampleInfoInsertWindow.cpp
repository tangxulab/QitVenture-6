#include "SampleInfoInsertWindow.h"
#include "ui_SampleInfoInsertWindow.h"

SampleInfoInsertWindow::SampleInfoInsertWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SampleInfoInsertWindow)
{
    ui->setupUi(this);
}

SampleInfoInsertWindow::~SampleInfoInsertWindow()
{
    delete ui;
}
