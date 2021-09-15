#include "ChromatographicFormWindow.h"
#include "ui_ChromatographicFormWindow.h"
static double* src_array;
static char  FILE_PATH[] = "D://noiseSignal.txt";
ChromatographicFormWindow::ChromatographicFormWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChromatographicFormWindow)
{
    ui->setupUi(this);
    showMaximized();
    QDesktopWidget* desktopWidget = QApplication::desktop();
    QRect screenRect = desktopWidget->screenGeometry();
    int g_nActScreenX = screenRect.width();
    int g_nActScreenY = screenRect.height();
    toolButton = new QToolButton(this); //新建toolButton
    toolButton->setText("还原"); //设置内容
    toolButton->setIcon(QPixmap(":/images/arrow_refresh.png"));
    toolBar = new QToolBar(this); //添加工具栏

    toolBar->addWidget(toolButton); //将toolButtn添加到工具栏中
    this->setParent(parent);
    // 设置坐标范围、坐标名称
    pCustomPlot = new MyCustomPlot(this);
    pCustomPlot->xAxis->setRange(0, 10000);
    pCustomPlot->yAxis->setRange(0, 100000);
    pCustomPlot->xAxis->setLabel("时间/min");
    pCustomPlot->yAxis->setLabel("响应值");

    // 增加图层
    // 设置画笔风格
    QPen drawPen;
    drawPen.setColor(Qt::blue);
    drawPen.setWidth(1);

    // 绘制散点
    curGraph = pCustomPlot->addGraph();
    curGraph->setName("色谱图");
    curGraph->setPen(drawPen);
    pCustomPlot->legend->setVisible(true);
    QFont legendFont = font();  // start out with MainWindow's font..
    legendFont.setPointSize(9); // and make a bit smaller for legend
    pCustomPlot->legend->setFont(legendFont);
    pCustomPlot->legend->setBrush(QBrush(QColor(255,255,255,230)));

    pCustomPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignCenter);
    curGraph->setLineStyle((QCPGraph::LineStyle)1);
   // curGraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc,Qt::blue, 10));
    pCustomPlot->xAxis->setVisible(true);
    pCustomPlot->yAxis->setVisible(true);
    pCustomPlot->replot();
    QVBoxLayout *pLayout = new QVBoxLayout;
    pLayout->addWidget(toolBar);
    pLayout->addWidget(pCustomPlot);
    setLayout(pLayout);
}

void ChromatographicFormWindow::slot_mouseMoveTip(QMouseEvent *event)
{
    double xx = pCustomPlot->xAxis->pixelToCoord(event->x());
    double yx = pCustomPlot->yAxis->pixelToCoord(event->y());   
    pCustomPlot->xAxis->setSelectedLabelColor(Qt::black);
    QString str,strToolTip;
    QString qsPoint("X:%1,Y:%2");
    qsPoint = qsPoint.arg(xx).arg(yx);
    QToolTip::showText(cursor().pos(), qsPoint);
}

ChromatographicFormWindow::~ChromatographicFormWindow()
{
    delete ui;
}
