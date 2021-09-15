#include "clippipevalvewindow.h"
#include "ui_clippipevalvewindow.h"

ClipPipeValveWindow::ClipPipeValveWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClipPipeValveWindow)
{
    ui->setupUi(this);
    showMaximized();
    this->setParent(parent);

    //气压图控件配置
    m_customPlot = new MyCustomPlot(this);

    //取消鼠标跟踪
    m_customPlot->showTracer(false);
    m_customPlot->legend->setVisible(true);

    //字体样式
    QFont legendFont = font();
    legendFont.setPointSize(9);
    m_customPlot->legend->setFont(legendFont);
    m_customPlot->legend->setBrush(QBrush(QColor(255,255,255,230))); 


    m_customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignCenter);
    m_customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    //滚轮放大缩小信号与槽
    connect(m_customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), m_customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(m_customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), m_customPlot->yAxis2, SLOT(setRange(QCPRange)));  
    QPen pen;
    pGraph = m_customPlot->addGraph();

    //标题及XY轴名称
    pGraph->setName("夹管阀");
    m_customPlot->xAxis->setLabel("时间");
    m_customPlot->yAxis->setLabel("v"); 
    m_customPlot->replot();

    //布局
    QVBoxLayout *pLayout = new QVBoxLayout;
    pLayout->addWidget(m_customPlot);
    setLayout(pLayout);
}

ClipPipeValveWindow::~ClipPipeValveWindow()
{
    delete ui;
}
