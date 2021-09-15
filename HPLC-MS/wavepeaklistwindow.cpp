#include "wavepeaklistwindow.h"
#include "ui_wavepeaklistwindow.h"

WavePeakListWindow::WavePeakListWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WavePeakListWindow)
{
    ui->setupUi(this);
    ui->setupUi(this);
    QWidget *widget = new QWidget();
    this->setCentralWidget(widget);
    this->setFixedSize(240,480);

    QGridLayout *pLayout = new QGridLayout();
    btn_search_peak = new  QPushButton();
    btn_search_peak->setText("寻峰");


    QComboBox_seacrch_peak = new QComboBox(this);
   // line_seacrch_peak->setText("1");
    for (int i=1;i<=10;i++) {
        QComboBox_seacrch_peak->addItem(QString::number(i));
    }
//    QComboBox_seacrch_peak->addItem(tr("Circle"));
//        QComboBox_seacrch_peak->addItem(tr("Pology"));


    table_seacrch_peak = new QTableWidget(this);
    table_seacrch_peak->setColumnCount(2);
    table_seacrch_peak->setHorizontalHeaderLabels(QStringList()<<"质量数"<<"丰度值");


    pLayout->addWidget(QComboBox_seacrch_peak,0,0);
    QComboBox_seacrch_peak->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QComboBox_seacrch_peak->setMaximumSize(160, 30);
    pLayout->addWidget(btn_search_peak,0,1);
    btn_search_peak->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    btn_search_peak->setMaximumSize(160, 30);
    pLayout->addWidget(table_seacrch_peak,1,0,1,2);
    centralWidget()->setLayout(pLayout);
    this->setWindowTitle("寻峰");
}

WavePeakListWindow::~WavePeakListWindow()
{
    delete ui;
}
