#include "MyTracer.h"


MyTracer::MyTracer(QCustomPlot* _plot, TracerType _type, QObject* parent) : plot(_plot),
type(_type),
QObject(parent)
{

	if (plot)
	{
		tracer = new QCPItemTracer(plot);
		tracer->setStyle(QCPItemTracer::tsCircle);
		tracer->setPen(QPen(Qt::red));
		tracer->setBrush(Qt::red);
		tracer->setSize(10);

		label = new QCPItemText(plot);
		label->setLayer("overlay");
		label->setClipToAxisRect(false);
		label->setPadding(QMargins(5, 5, 5, 5));
		label->setBrush(QBrush(QColor(244, 244, 244, 100)));
		label->setPen(QPen(Qt::blue));
		label->position->setParentAnchor(tracer->position);
		label->setFont(QFont("宋体", 10));

		arrow = new QCPItemLine(plot);
		arrow->setLayer("overlay");
        arrow->setClipToAxisRect(false);
		arrow->setHead(QCPLineEnding::esSpikeArrow);

		switch (type) {
		case XAxisTracer:
		{
			tracer->position->setTypeX(QCPItemPosition::ptPlotCoords);
			tracer->position->setTypeY(QCPItemPosition::ptAxisRectRatio);

			label->setPositionAlignment(Qt::AlignTop | Qt::AlignHCenter);

			arrow->end->setParentAnchor(tracer->position);
			arrow->start->setParentAnchor(arrow->end);
			arrow->start->setCoords(20, 0);//偏移量
			break;
		}
		case YAxisTracer:
		{
			tracer->position->setTypeX(QCPItemPosition::ptAxisRectRatio);
			tracer->position->setTypeY(QCPItemPosition::ptPlotCoords);

			label->setPositionAlignment(Qt::AlignRight | Qt::AlignHCenter);

			arrow->end->setParentAnchor(tracer->position);
			arrow->start->setParentAnchor(label->position);
			arrow->start->setCoords(-20, 0);//偏移量
			break;
		}
		case DataTracer:
		{
			tracer->position->setTypeX(QCPItemPosition::ptPlotCoords);
			tracer->position->setTypeY(QCPItemPosition::ptPlotCoords);

			label->setPositionAlignment(Qt::AlignLeft | Qt::AlignVCenter);

			arrow->end->setParentAnchor(tracer->position);
			arrow->start->setParentAnchor(arrow->end);
            arrow->start->setCoords(25, 0);
			break;
		}

		default:
			break;
		}

		setVisible(false);
	}
		
}
MyTracer::~MyTracer()
{
	if (tracer)
		plot->removeItem(tracer);
	if (label)
		plot->removeItem(label);
}

void MyTracer::setPen(const QPen& pen)
{
	tracer->setPen(pen);
	arrow->setPen(pen);
}

void MyTracer::setBrush(const QBrush& brush)
{
	tracer->setBrush(brush);
}

void MyTracer::setLabelPen(const QPen& pen)
{
	label->setPen(pen);
}

void MyTracer::setText(const QString& text)
{
	label->setText(text);
}

void MyTracer::setVisible(bool visible)
{
	tracer->setVisible(visible);
	label->setVisible(visible);
	arrow->setVisible(visible);
}

void MyTracer::updatePosition(double xValue, double yValue)
{
	if (!visible)
	{
		setVisible(true);
		visible = true;
	}
//	if (yValue > plot->yAxis->range().upper)
//		yValue = plot->yAxis->range().upper;
	switch (type) {
	case XAxisTracer:
	{
		tracer->position->setCoords(xValue, 1);
		label->position->setCoords(0, 15);
		arrow->start->setCoords(0, 15);
		arrow->end->setCoords(0, 0);
        setText(QString::number(xValue));
		break;
	}
	case YAxisTracer:
	{
		tracer->position->setCoords(1, yValue);
		label->position->setCoords(-20, 0);
        setText(QString::number(yValue));
		break;
	}
	case DataTracer:
	{
		tracer->position->setCoords(xValue, yValue);
        label->position->setCoords(-15,-10);
        setText(QString("%1").arg(xValue));
		break;
	}
	default:
		break;
	}

}



void MyTracer::updatePosition_time(double xValue, double yValue,double time){
    if (!visible)
    {
        setVisible(true);
        visible = true;
    }
//	if (yValue > plot->yAxis->range().upper)
//		yValue = plot->yAxis->range().upper;
    switch (type) {
    case XAxisTracer:
    {
        tracer->position->setCoords(xValue, 1);
        label->position->setCoords(0, 15);
        arrow->start->setCoords(0, 15);
        arrow->end->setCoords(0, 0);
        setText(QString::number(xValue));
        break;
    }
    case YAxisTracer:
    {
        tracer->position->setCoords(1, yValue);
        label->position->setCoords(-20, 0);
        setText(QString::number(yValue));
        break;
    }
    case DataTracer:
    {
        tracer->position->setCoords(xValue, yValue);
        label->position->setCoords(-10,-10);
        setText(QString("x:%1,y:%2,t:%3").arg(xValue).arg(yValue).arg(time));
        break;
    }
    default:
        break;
    }
}

MyTraceLine::MyTraceLine(QCustomPlot *_plot, LineType _type, QObject *parent)
    : QObject(parent),
      m_type(_type),
      m_plot(_plot)
{
    m_lineV = Q_NULLPTR;
    m_lineH = Q_NULLPTR;
    initLine();
}

MyTraceLine::~MyTraceLine()
{
    if(m_plot)
    {
        if (m_lineV)
            m_plot->removeItem(m_lineV);
        if (m_lineH)
            m_plot->removeItem(m_lineH);
    }
}

void MyTraceLine::initLine()
{
    if(m_plot)
    {
        QPen linesPen(Qt::red, 1, Qt::DashLine);

        if(VerticalLine == m_type || Both == m_type)
        {
            m_lineV = new QCPItemStraightLine(m_plot);//垂直线
            m_lineV->setLayer("overlay");
            m_lineV->setPen(linesPen);
            m_lineV->setClipToAxisRect(true);
            m_lineV->point1->setCoords(0, 0);
            m_lineV->point2->setCoords(0, 0);
        }

        if(HorizonLine == m_type || Both == m_type)
        {
            m_lineH = new QCPItemStraightLine(m_plot);//水平线
            m_lineH->setLayer("overlay");
            m_lineH->setPen(linesPen);
            m_lineH->setClipToAxisRect(true);
            m_lineH->point1->setCoords(0, 0);
            m_lineH->point2->setCoords(0, 0);
        }
    }
}

void MyTraceLine::updatePosition(double xValue, double yValue)
{
    if(VerticalLine == m_type || Both == m_type)
    {
        if(m_lineV)
        {
            m_lineV->point1->setCoords(xValue, m_plot->yAxis->range().lower);
            m_lineV->point2->setCoords(xValue, m_plot->yAxis->range().upper);
        }
    }

    if(HorizonLine == m_type || Both == m_type)
    {
        if(m_lineH)
        {
            m_lineH->point1->setCoords(m_plot->xAxis->range().lower, yValue);
            m_lineH->point2->setCoords(m_plot->xAxis->range().upper, yValue);
        }
    }
}
