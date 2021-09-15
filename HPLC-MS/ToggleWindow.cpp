#include "ToggleWindow.h"
#include "ui_ToggleWindow.h"

ToggleWindow::ToggleWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ToggleWindow)
{
    ui->setupUi(this);

   QQuickWidget *quickProgressBar = new QQuickWidget();
    // QQuickWidget quickProgressBar;
  //  quickProgressBar->setResizeMode(QQuickWidget::SizeRootObjectToView );
    quickProgressBar->setSource(QUrl("qrc:///QmlToggleButton.qml"));
    //QVBoxLayout *pLayout = new QVBoxLayout(this);
   // ui->verticalLayout->addWidget(quickProgressBar);
    this->setCentralWidget(quickProgressBar);

   // setLayout(pLayout);



}

ToggleWindow::~ToggleWindow()
{
    delete ui;
}
