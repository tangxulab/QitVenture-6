#include "MyCustomPlot.h"
//#include <QDebug>
#include <QObject>
#include "MenuWindow.h"
double x_graph_val;
double y_graph_val;
bool enlarge_and_lessen_flag = true;
bool flag =false;
MyCustomPlot::MyCustomPlot(QWidget *parent)
    :QCustomPlot(parent)
    ,m_isShowTracer(false)
    ,m_xTracer(Q_NULLPTR)
    ,m_yTracer(Q_NULLPTR)
    ,m_dataTracers(QList<MyTracer *>())
    ,m_lineTracer(Q_NULLPTR)
    , mZoomMode(false)
    , mRubberBand(new QRubberBand(QRubberBand::Rectangle, this))

{
}
void MyCustomPlot::setZoomMode(bool mode)
{
    mZoomMode = mode;
}

void MyCustomPlot::mousePressEvent(QMouseEvent * event)
{
    if (true)
    {
        if (event->button() == Qt::LeftButton)
        {          
            mOrigin = event->pos();
            mRubberBand->setGeometry(QRect(mOrigin, QSize()));
            mRubberBand->show();
        }
    }
    QCustomPlot::mousePressEvent(event);
}

void MyCustomPlot::mouseMoveEvent(QMouseEvent * event)
{
    if (mRubberBand->isVisible())
    {
        mRubberBand->setGeometry(QRect(mOrigin, event->pos()).normalized());
    }

    if(m_isShowTracer)
    {
        //当前鼠标位置（像素坐标）
        int x_pos = event->pos().x();
        int y_pos = event->pos().y();

        //像素坐标转成实际的x,y轴的坐标
        double x_val = this->xAxis->pixelToCoord(x_pos);
        double y_val = this->yAxis->pixelToCoord(y_pos);

        if(Q_NULLPTR == m_xTracer)
            m_xTracer = new MyTracer(this, MyTracer::XAxisTracer);//x轴
        m_xTracer->updatePosition(x_val, y_val);

        if(Q_NULLPTR == m_yTracer)
            m_yTracer = new MyTracer(this, MyTracer::YAxisTracer);//y轴
        m_yTracer->updatePosition(x_val, y_val);

        int nTracerCount = m_dataTracers.count();
        int nGraphCount = graphCount();
        if(nTracerCount < nGraphCount)
        {
            for(int i = nTracerCount; i < nGraphCount; ++i)
            {
                MyTracer *tracer = new MyTracer(this, MyTracer::DataTracer);
                m_dataTracers.append(tracer);
            }
        }
        else if(nTracerCount > nGraphCount)
        {
            for(int i = nGraphCount; i < nTracerCount; ++i)
            {
                MyTracer *tracer = m_dataTracers[i];
                if(tracer)
                {
                    tracer->setVisible(false);
                }
            }
        }
        for (int i = 0; i < nGraphCount; ++i)
        {
            MyTracer *tracer = m_dataTracers[i];
            if(!tracer)
                tracer = new MyTracer(this, MyTracer::DataTracer);
            tracer->setVisible(true);
            tracer->setPen(this->graph(i)->pen());
            tracer->setBrush(Qt::NoBrush);
            tracer->setLabelPen(this->graph(i)->pen());
            auto iter = this->graph(i)->data()->findBegin(x_val);
            double value = iter->mainValue();        
            tracer->updatePosition(x_val, value);

        }

        if(Q_NULLPTR == m_lineTracer)
            m_lineTracer = new MyTraceLine(this,MyTraceLine::Both);//直线
        m_lineTracer->updatePosition(x_val, y_val);


        this->replot();//曲线重绘
    }

    QCustomPlot::mouseMoveEvent(event);
}

void MyCustomPlot::mouseReleaseEvent(QMouseEvent * event)
{
    if (mRubberBand->isVisible())
    {
        const QRect zoomRect = mRubberBand->geometry();
        int xp1, yp1, xp2, yp2;
        zoomRect.getCoords(&xp1, &yp1, &xp2, &yp2);

        if(qAbs(xp2-xp1)>2&&qAbs(yp1-yp2)>2)
        {         
            double x1 = xAxis->pixelToCoord(xp1);
            double x2 = xAxis->pixelToCoord(xp2);
            double y1 = yAxis->pixelToCoord(yp1);
            double y2 = yAxis->pixelToCoord(yp2);
            xAxis->setRange(x1, x2);
            yAxis->setRange(y1, y2);
            replot();
            enlarge_and_lessen_flag = false;
        }else {
             postion =(int)(xAxis->pixelToCoord(xp1)+0.5);
        }
        mRubberBand->hide();

    }
    QCustomPlot::mouseReleaseEvent(event);
}

