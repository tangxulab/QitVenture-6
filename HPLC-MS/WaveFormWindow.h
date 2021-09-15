#pragma once
#include <qwidget.h>
#include "ui_WaveFormWindow.h"
#include "MyCustomPlot.h"
#include "MyTracer.h"
#include <QQuickWidget>

class WaveFormWindow :
	public QWidget
{
	Q_OBJECT
public:
	WaveFormWindow(QWidget* parent=nullptr);
	~WaveFormWindow();
double getX_val()
{
    return x_val;
}
double getY_val()
{
    return y_val;
}
public:
    QCPGraph *pGraph;
    MyCustomPlot* m_customPlot;
    QCPGraph *curGraph;
    QToolButton *toolButton;
    QToolBar * toolBar;
    QToolButton *lookPeakButton;
    QToolButton *checkButton;
   // QToolButton *historyButton;
    QToolButton *lockButton;
    QToolButton *saveButton;
    QToolButton *insertToDB;
    QRadioButton *radioButton;


    QList<MyTracer *> tracerList;
QQuickWidget *quickwidget;

private:
	Ui::WaveFormWindowClass WaveFormWindowUI;



    MyTracer *tracerType;
    double x_val;
    double y_val;
};

