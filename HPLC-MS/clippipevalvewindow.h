#ifndef CLIPPIPEVALVEWINDOW_H
#define CLIPPIPEVALVEWINDOW_H


/**
  气压图
  */
#include <QWidget>
#include "MyCustomPlot.h"
namespace Ui {
class ClipPipeValveWindow;
}

class ClipPipeValveWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ClipPipeValveWindow(QWidget *parent = nullptr);
    ~ClipPipeValveWindow();

public:
    QCPGraph *pGraph;
    MyCustomPlot* m_customPlot;
    QList<MyTracer *> tracerType;
    QList<MyTracer *> tracerTypeTime;

private:
    Ui::ClipPipeValveWindow *ui;
    double x_val;
    double y_val;
};


#endif // CLIPPIPEVALVEWINDOW_H
