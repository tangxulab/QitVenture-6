#include "WaveFormWindow.h"
WaveFormWindow::WaveFormWindow(QWidget* parent) :QWidget(parent)
{

    WaveFormWindowUI.setupUi(this);
    showMaximized();
    toolButton = new QToolButton(this); //新建toolButton
    toolButton->setToolTip("还原"); //设置内容
    toolButton->setIcon(QPixmap(":/images/arrow_refresh.png"));
    toolBar = new QToolBar(this); //添加工具栏

    lookPeakButton = new QToolButton(this);
    lookPeakButton->setIcon(QPixmap(":/images/diagramm.png"));
    lookPeakButton->setToolTip("寻峰");


    checkButton = new QToolButton(this);
    checkButton->setIcon(QPixmap(":/images/application_view_columns.png"));
    checkButton->setToolTip("校对");

//    historyButton = new QToolButton(this);
//    historyButton->setIcon(QPixmap(":/images/chart_curve_link.png"));
//    historyButton->setToolTip("历史纪录");

    lockButton = new QToolButton(this);
    lockButton->setIcon(QPixmap(":/images/lock.png"));
    lockButton->setToolTip("范围锁定");

    saveButton = new QToolButton(this);
    saveButton->setIcon(QPixmap(":/images/file_save_as.png"));
    saveButton->setToolTip("保存");

//    insertToDB = new QToolButton(this);
//    insertToDB->setIcon(QPixmap(":/images/coins_add.png"));
//    insertToDB->setToolTip("录入");


   // radioButton = new QRadioButton(this);
    //quickwidget = new QQuickWidget();
    // 加入qml界面
   //quickwidget->setSource(QUrl("qrc:///QmlToggleButton.qml"));


    toolBar->addWidget(toolButton); //将toolButtn添加到工具栏中
    toolBar->addWidget(lookPeakButton);
    toolBar->addWidget(checkButton);
   // toolBar->addWidget(historyButton);
    toolBar->addWidget(lockButton);
   // toolBar->addWidget(quickwidget);
    toolBar->addWidget(saveButton);
    //toolBar->addWidget(insertToDB);

    this->setParent(parent);
    m_customPlot = new MyCustomPlot(this); 
    m_customPlot->legend->setVisible(true);
    //m_customPlot->clearGraphs();
   // m_customPlot->setSubGridVisible()
    QFont legendFont = font();
    legendFont.setPointSize(9);
    m_customPlot->xAxis->grid()->setVisible(false);
    m_customPlot->yAxis->grid()->setVisible(false);
    m_customPlot->legend->setFont(legendFont);
    m_customPlot->legend->setBrush(QBrush(QColor(255,255,255,230)));
    m_customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignCenter);  
    connect(m_customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), m_customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(m_customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), m_customPlot->yAxis2, SLOT(setRange(QCPRange)));
    m_customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);


    QPen pen;

    pGraph = m_customPlot->addGraph();

    pGraph->setName("质谱图");

    pGraph->setPen(QPen(Qt::blue));

    m_customPlot->xAxis->setRange(80,1000);

    m_customPlot->xAxis->setLabel("质量数（m/z）");
    m_customPlot->yAxis->setLabel("丰度值");


    QVBoxLayout *pLayout = new QVBoxLayout;
    pLayout->addWidget(toolBar);
    pLayout->addWidget(m_customPlot);
    setLayout(pLayout);

}


WaveFormWindow::~WaveFormWindow()
{
}
