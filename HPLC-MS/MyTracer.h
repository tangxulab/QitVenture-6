//图像标定类
#pragma once
#include <QObject>
#include "qcustomplot.h"
class MyTracer :public QObject
{
	Q_OBJECT
public:
	enum TracerType
	{
		XAxisTracer,
		YAxisTracer,
		DataTracer
	};
public:
	explicit MyTracer(QCustomPlot* _plot, TracerType _type, QObject* parent = nullptr);
	~MyTracer();
	void setPen(const QPen& pen);
	void setBrush(const QBrush& brush);
	void setText(const QString& text);
	void setLabelPen(const QPen& pen);
	void updatePosition(double xValue, double yValue);
    void updatePosition_time(double xValue, double yValue,double time);
	void setVisible(bool visible);
protected:
	QCustomPlot* plot = nullptr;
	QCPItemTracer* tracer = nullptr;// 跟踪的点
	QCPItemText* label = nullptr;   // 显示的数值
	QCPItemLine* arrow = nullptr;   // 箭头

	TracerType type = DataTracer;
	bool visible = false;
};

///
/// \brief The XxwCrossLine class:用于显示鼠标移动过程中的鼠标位置的直线
///
class MyTraceLine : public QObject
{
public:
    enum LineType
    {
        VerticalLine,//垂直线
        HorizonLine, //水平线
        Both//同时显示水平和垂直线
    };
    explicit MyTraceLine(QCustomPlot *_plot, LineType _type = VerticalLine, QObject *parent = Q_NULLPTR);
    ~MyTraceLine();
    void initLine();
    void updatePosition(double xValue, double yValue);


    void setVisible(bool vis)
    {
        if(m_lineV)
            m_lineV->setVisible(vis);
        if(m_lineH)
            m_lineH->setVisible(vis);
    }

protected:
    bool m_visible;//是否可见
    LineType m_type;//类型
    QCustomPlot *m_plot;//图表
    QCPItemStraightLine *m_lineV; //垂直线
    QCPItemStraightLine *m_lineH; //水平线
};
