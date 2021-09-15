#ifndef WAVEHISTORYDATA_H
#define WAVEHISTORYDATA_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QStandardItem>
#include "MyCustomPlot.h"
#include "CJsonObject.hpp"
#include <iostream>
#include <QFileDialog>
#include <QList>
#include <QStandardPaths>
#include "stdfix.h"
#include "progresswindow.h"
#include <QThread>
using namespace neb;
using namespace std;


namespace Ui {
class WaveHistoryData;
}

class WaveHistoryData : public QMainWindow
{
    Q_OBJECT

public:
    explicit WaveHistoryData(QWidget *parent = nullptr);
    ~WaveHistoryData();
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

public slots:
    void slotClickedBtn();
    void slotSplitterMoved(int pos, int index);
    void getData(QString name);
    void slotBtn_wave();
    //  void reflushFile();
    void treeItemChanged(QStandardItem *item);
    void slotTreeMenu(const QPoint &pos);
    void OnlineTreeViewDoubleClick(const QModelIndex &index);
    void getFileSelectedName(QString file);
    void getStandardItem(QStandardItem* item,HistorySortData sort);
    void comboBoxCurrentIndexChanged(QString value);
    void getItemChanged(QStandardItem *item);
    void createReport(bool);
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
    QStandardItem* historyQStandardItem;


    QVector<double> x, y;//质谱图XY
    QVBoxLayout *pLayout=nullptr;
    double **peaKCount;
    QList<MyTracer *> tracerList;
    QToolButton *flushToolButton;

    QToolBar * toolBar;

    QComboBox *QComboBox_seacrch_peak;
    double x_max=0,x_min=0;
    double y_max = 0;

    QToolButton *saveToolButton;
    QToolButton *deleteToolButton;
    QToolBar *leftToolBar;
    QList<QString> list;
    ProgressWindow *progresswindow;
    QStringList signalNameList;


    // QToolButton *lookPeakButton;
private slots:
    void  downLoadHistoryData();
    void saveToolFile();
    void getFileDir(QString name);

private:
    Ui::WaveHistoryData *ui;
    int selectIndex =1;
    int peak_count =10;
};

#endif // WAVEHISTORYDATA_H
