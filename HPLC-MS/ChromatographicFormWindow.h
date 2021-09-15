#ifndef CHROMATOGRAPHICFORMWINDOW_H
#define CHROMATOGRAPHICFORMWINDOW_H

//该类暂时已废弃
#include <QWidget>
#include "MyCustomplot.h"
#include "MyTracer.h"
namespace Ui {
class ChromatographicFormWindow;
}

class ChromatographicFormWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ChromatographicFormWindow(QWidget *parent = nullptr);
    ~ChromatographicFormWindow();
    MyCustomPlot* pCustomPlot;
    QCPGraph *curGraph;
    QToolButton *toolButton;
    QToolBar * toolBar;
public slots:
    void slot_mouseMoveTip(QMouseEvent *event);
private:
    Ui::ChromatographicFormWindow *ui;

    MyTracer *tracerType;
};

#endif // CHROMATOGRAPHICFORMWINDOW_H
