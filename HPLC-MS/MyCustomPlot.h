#ifndef MYCUSTOMPLOT_H
#define MYCUSTOMPLOT_H
/**
  图像控件的基类
  */
#include "qcustomplot.h"
#include "MyTracer.h"


class QRubberBand;
class QMouseEvent;
class QWidget;

class MyCustomPlot:public QCustomPlot
{
    Q_OBJECT

   public:
       MyCustomPlot(QWidget *parent = nullptr);
        void setZoomMode(bool mode);
        //鼠标事件
   protected:
        void mouseMoveEvent(QMouseEvent *event);
       void mousePressEvent(QMouseEvent * event);   
       void mouseReleaseEvent(QMouseEvent * event);

   public:
       ///
       /// \brief 设置是否显示鼠标追踪器
       /// \param show:是否显示
       ///
       void showTracer(bool show)
       {
           m_isShowTracer = show;
           if(m_xTracer)
               m_xTracer->setVisible(m_isShowTracer);
           foreach (MyTracer *tracer, m_dataTracers)
           {
               if(tracer)
                   tracer->setVisible(m_isShowTracer);
           }
           if(m_lineTracer)
               m_lineTracer->setVisible(m_isShowTracer);
       }

       ///
       /// \brief 是否显示鼠标追踪器
       /// \return
       ///
       bool isShowTracer(){return m_isShowTracer;};


   private:
       bool m_isShowTracer;//是否显示追踪器（鼠标在图中移动，显示对应的值）
       MyTracer *m_xTracer;//x轴
       MyTracer *m_yTracer;//y轴
       QList<MyTracer *> m_dataTracers;//
       MyTraceLine  *m_lineTracer;//直

       bool mZoomMode;
       QRubberBand * mRubberBand;
       QPoint mOrigin;

public:
       int postion;
};

#endif // MYCUSTOMPLOT_H
