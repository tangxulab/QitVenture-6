#ifndef SLIDINGWINDOW_H
#define SLIDINGWINDOW_H

#include <QtGui>
#include <QSplitter>
#include <QFrame>
#include <QPushButton>
#include <QApplication>
#include <QListWidget>
#include <QVBoxLayout>
#include <QListWidgetItem>
#include "MyCustomPlot.h"
#include "MyTracer.h"
#include <QTreeView>
#include <QStandardItemModel>
#include <QMainWindow>
#include <QHBoxLayout>
extern int peak_max_count;
class SlidingWindow : public QMainWindow
{
    Q_OBJECT

public:
    SlidingWindow(QWidget *parent = 0);
    ~SlidingWindow();

protected:
    void mousePressEvent ( QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
   // void resizeEvent(QResizeEvent *event);
    bool eventFilter(QObject *obj, QEvent *event);

    QStringList getFileNames(const QString &path);


private:
    void setBtnPos();
    void setBtnIcon();

private slots:
    void slotClickedBtn();
    void slotSplitterMoved(int pos, int index);
    void getData(QListWidgetItem *item);
    void slotBtn_wave();
  //  void reflushFile();
    void treeItemChanged(QStandardItem *item);
    void slotTreeMenu(const QPoint &pos);
    void OnlineTreeViewDoubleClick(const QModelIndex &index);
public:
    MyCustomPlot *m_customPlot;
    QCPGraph *pGraph;
QListWidget *listWidget;
private:
    QPoint dragPosition;
    bool bPressFlag;
    QSplitter *splitter;
    QFrame *contentFrame;
    QFrame *listFrame;
    QPushButton *pushButton;
    QIcon leftIcon;
    QIcon rightIcon;
    QTreeView *treeView;
    QStandardItemModel *model;


    QVector<double> x, y;//质谱图XY
    QVBoxLayout *pLayout=nullptr;
    double **peaKCount;
    QList<MyTracer *> tracerList;
    QToolButton *toolButton;
    QToolButton *toolButton_1;
    QToolBar * toolBar;
    QToolBar *toolBar_1;
    QComboBox *QComboBox_seacrch_peak;
    double x_max=0,x_min=0;
    double y_max = 0;
   // QToolButton *lookPeakButton;
};

#endif // SLIDINGWINDOW_H
