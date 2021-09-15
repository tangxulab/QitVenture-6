#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPalette palette(this->palette());
    palette.setColor(QPalette::Background, Qt::white);
    this->setPalette(palette);
    QWidget *ss = new QWidget(this);

    ss->setMaximumSize(0,0);

    this->setCentralWidget(ss);

    QDesktopWidget* desktopWidget = QApplication::desktop();

    QVBoxLayout *layout = new QVBoxLayout();
     QVBoxLayout *layout2 = new QVBoxLayout();
    QRect screenRect = desktopWidget->screenGeometry();
    int g_nActScreenX = screenRect.width();
    int g_nActScreenY = screenRect.height();



    //    QWidget* lTitleBar = ui->dockWidget_2->titleBarWidget();
    //    QWidget* lEmptyWidget = new QWidget();
    //    ui->dockWidget_2->setTitleBarWidget(lEmptyWidget);
    //    delete lTitleBar;
    //    QWidget *lTitleBar = new QWidget(this);
    //    ui->dockWidget_2->setTitleBarWidget(lTitleBar);

    //    lTitleBar = new QWidget(this);
    //    ui->dockWidget->setTitleBarWidget(lTitleBar);

    //    lTitleBar = new QWidget(this);
    //    ui->dockWidget_3->setTitleBarWidget(lTitleBar);
    //    lTitleBar = new QWidget(this);
    //    ui->dockWidget_4->setTitleBarWidget(lTitleBar);
    //    lTitleBar = ui->dockWidget->titleBarWidget();
    //    lEmptyWidget = new QWidget();
    //    ui->dockWidget->setTitleBarWidget(lEmptyWidget);
    //    delete lTitleBar;
    //    lTitleBar = ui->dockWidget_3->titleBarWidget();
    //    lEmptyWidget = new QWidget();
    //    ui->dockWidget_3->setTitleBarWidget(lEmptyWidget);
    //    delete lTitleBar;
    //    lTitleBar = ui->dockWidget_4->titleBarWidget();
    //    lEmptyWidget = new QWidget();
    //    ui->dockWidget_4->setTitleBarWidget(lEmptyWidget);
    //    delete lTitleBar;



    splitDockWidget(ui->dockWidget,ui->dockWidget_2,Qt::Horizontal);
    splitDockWidget(ui->dockWidget_2,ui->dockWidget_3,Qt::Vertical);
    splitDockWidget(ui->dockWidget_2,ui->dockWidget_4,Qt::Vertical);
    splitDockWidget(ui->dockWidget_3,ui->dockWidget_4,Qt::Horizontal);



    //showMaximized();
    waveMainFormWindow = new WaveFormWindow();
    layout->addWidget(waveMainFormWindow);
    clipPipeValveWindow = new ClipPipeValveWindow();
    layout2->addWidget(clipPipeValveWindow);
    // waveFormWindow->setMinimumSize(g_nActScreenX/10*8,g_nActScreenY/10*7-100);
    //waveFormWindow->setMinimumHeight(g_nActScreenY/10*5);
    // layout->setStyleSheet("background-color:black;");
    ui->tabWidget->widget(0)->setLayout(layout);
    ui->tabWidget->widget(1)->setLayout(layout2);
    ui->tabWidget->setMinimumSize(g_nActScreenX/10*8+20,g_nActScreenY/10*6);
    ui->dockWidget_4->setMinimumWidth(g_nActScreenX/10*2);
   // ui->dockWidget_4->setMaximumWidth(g_nActScreenX/10*2);
    //waveFormWindow->show();
   // showMaximized();
    //ui->widget->set (waveFormWindow);
    //    ui->tabWidget->insertTab(0,)
    //waveFormWindow->set(g_nActScreenX/10*8,g_nActScreenY/10*7);
    // waveFormWindow->show();
   // cameraWindow = new CameraWindow(this);

    // layout = new QVBoxLayout();
    // layout->addWidget(cameraWindow);
   // ui->dockWidget_4->setWidget(cameraWindow);
  //  ui->dockWidget_4->setAllowedAreas(Qt::BottomDockWidgetArea);

    // showMaximized();
    // ui->dockWidget_3->setFixedWidth(g_nActScreenX/10*4+40);
    // ui->dockWidget_2->setMinimumSize(0,0);

    // ui->dockWidget_2->setMinimumWidth(0);
    //  ui->dockWidget_2->setMinimumWidth(0);
    //waveFormWindow->setMinimumHeight(0);
    showMaximized();
}

MainWindow::~MainWindow()
{
    delete ui;
}
