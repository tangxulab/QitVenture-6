#include "slidingwindow.h"

SlidingWindow::SlidingWindow(QWidget *parent)
    : QMainWindow(parent)
    , bPressFlag(false)
{
    resize(660, 460);


    splitter = new QSplitter(Qt::Horizontal);

    splitter->setHandleWidth(1);
    splitter->setStyleSheet("QSplitter::handle{background:#000000}");
    treeView = new QTreeView();
    contentFrame = new QFrame();
    splitter->addWidget(treeView);
    splitter->addWidget(contentFrame);

    contentFrame->setStyleSheet("background:#FFFFFF");
    contentFrame->resize(475, height());
    contentFrame->setMinimumWidth(405);



//    treeView->setStyle(QStyleFactory::create("windows"));
//    treeView->resize(200,500);
//    treeView->setHeaderHidden(true);
//    //treeView->expandsOnDoubleClick();
//    // treeView->setExpandsOnDoubleClick(true);
//    //  treeView->setc;
//    model= new QStandardItemModel(treeView);
//    treeView->setEditTriggers(QAbstractItemView::SelectedClicked);
//    //树节点改变时触发此信号
//    connect(model,SIGNAL(itemChanged(QStandardItem*)),this,SLOT(treeItemChanged(QStandardItem*)));
//    // connect(model,SIGNAL(DoubleCl(QStandardItem*)),this,SLOT(treeItemChanged(QStandardItem*)));
//    connect(treeView,SIGNAL(doubleClicked ( const QModelIndex)),this,SLOT(OnlineTreeViewDoubleClick(const QModelIndex)));

//    QIcon treeitemicon(QPixmap(":/images/script_text.png"));
//    QIcon treerooticon(QPixmap(":/images/folder.png"));

//    //set headerQPixmap(":/images/video.png")
//    // model->setHorizontalHeaderLabels(QStringList()<<QString("Setting"));
//    //add RootItem
//    QStandardItem* itemProject = new QStandardItem(treerooticon,QString("atmosphere"));
//    QStandardItem* itemProject1 = new QStandardItem(treerooticon,QString("pollution"));
//    QStandardItem* historyQStandardItem = new QStandardItem(treerooticon,QString("历史记录"));
//    itemProject->setCheckable(true);
//    itemProject1->setCheckable(true);
//    historyQStandardItem->setCheckable(true);
//    //set RootItem checkable
//    // model->appendRow(itemProject);
//    model->appendRow(historyQStandardItem);

//    treeView->setContextMenuPolicy(Qt::CustomContextMenu);
//    connect(treeView, &QTreeView::customContextMenuRequested, this, &SlidingWindow::slotTreeMenu);


//    //add item
//    QStandardItem* itemChild = new QStandardItem(treeitemicon,QString("childitem"));
//    QStandardItem* itemChild1 = new QStandardItem(treeitemicon,QString("childitem1"));
//    QStandardItem* itemChild2 = new QStandardItem(treeitemicon,QString("childitem2"));
//    QStandardItem* itemChild3 = new QStandardItem(treeitemicon,QString("childitem3"));

//    //set ChildItem checkable
//    itemChild->setCheckable(true);
//    //qDebug()<<itemChild->isCheckable();
//    itemChild1->setCheckable(true);
//    itemChild2->setCheckable(true);
//    itemChild3->setCheckable(true);
//    //定义QList
//    QList<QStandardItem*>ItemList;
//    QList<QStandardItem*>ItemList2;
//    //        ItemList.append(itemChild);
//    //        ItemList.append(itemChild1);
//    //将节点加入QList
//    ItemList<<itemChild<<itemChild1;
//    ItemList2<<itemChild2<<itemChild3;
//    //添加多个子节点，添加单个子节点时用appendRow
//    itemProject->appendRows(ItemList);
//    itemProject1->appendRows(ItemList2);
//    historyQStandardItem->appendRow(itemProject);
//    historyQStandardItem->appendRow(itemProject1);
//    treeView->setModel(model);






//    //    listFrame->setStyleSheet("background:#FFFFFF");
//    //    listFrame->resize(660 - 475, height());
//    //    listFrame->setMaximumWidth(660 - 405);
//    //    toolButton_1 = new QToolButton(this); //新建toolButton
//    //    toolButton_1->setToolTip("刷新"); //设置内容
//    //    toolButton_1->setIcon(QPixmap(":/images/arrow_refresh.png"));



//    //    toolBar_1 = new QToolBar(this); //添加工具栏
//    //    toolBar_1->addWidget(toolButton_1);


//    //    QVBoxLayout *layout = new QVBoxLayout( listFrame );

//    //    layout->addWidget(toolBar_1);


//    //    QStringList list = getFileNames(QDir::currentPath()+"/spectrumData/");

//    //    for(int i=0;i<list.length();i++){

//    //        listWidget->addItem(list.at(i));
//    //    }
//    //    connect(listWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(getData(QListWidgetItem*)));
//    connect(splitter, SIGNAL(splitterMoved(int,int)), this, SLOT(slotSplitterMoved(int,int)));
//    //    connect(toolButton_1, &QPushButton::clicked, this, &SlidingWindow::reflushFile);//刷新信号与槽
//    leftIcon = QIcon(":/left.png");
//    rightIcon = QIcon(":/right.png");


//    toolButton = new QToolButton(this); //新建toolButton
//    toolButton->setToolTip("还原"); //设置内容
//    toolButton->setIcon(QPixmap(":/images/arrow_refresh.png"));

//    QComboBox_seacrch_peak = new QComboBox();

//    toolBar = new QToolBar(this); //添加工具栏
//    toolBar->addWidget(toolButton);
//    toolBar->addWidget(QComboBox_seacrch_peak);
//    for (int i=1;i<=10;i++) {
//        QComboBox_seacrch_peak->addItem(QString::number(i));
//    }

//    pushButton = new QPushButton(this);
//    pushButton->setFocusPolicy(Qt::NoFocus);
//    pushButton->hide();
//    pushButton->setFixedSize(13, 42);
//    pushButton->setIconSize(pushButton->size());
//    pushButton->setStyleSheet("border:none;");
//    pushButton->setIcon(rightIcon);
//    pushButton->move(contentFrame->width() - pushButton->width()-2, (contentFrame->height() - pushButton->height())/2);
//    connect(pushButton,SIGNAL(clicked()),this,SLOT(slotClickedBtn()));
//    connect(toolButton, &QPushButton::clicked, this, &SlidingWindow::slotBtn_wave);//刷新信号与槽
//    contentFrame->setMouseTracking(true);
//    // listFrame->setMouseTracking(true);
//    contentFrame->installEventFilter(this);
//    // listFrame->installEventFilter(this);
//    m_customPlot = new MyCustomPlot(this);
//    m_customPlot->legend->setVisible(true);
//    QFont legendFont = font();
//    legendFont.setPointSize(9);


//    m_customPlot->legend->setFont(legendFont);
//    m_customPlot->legend->setBrush(QBrush(QColor(255,255,255,230)));
//    m_customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignCenter);
//    connect(m_customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), m_customPlot->xAxis2, SLOT(setRange(QCPRange)));
//    connect(m_customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), m_customPlot->yAxis2, SLOT(setRange(QCPRange)));
//    m_customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);


//    QPen pen;

//    pGraph = m_customPlot->addGraph();

//    pGraph->setName("质谱图");

//    pGraph->setPen(QPen(Qt::blue));



//    m_customPlot->xAxis->setLabel("质量数（m/z）");
//    m_customPlot->yAxis->setLabel("丰度值");
//    //  //qDebug()<<x.length();

//    pLayout = new QVBoxLayout();
//    pLayout->addWidget(toolBar);
//    pLayout->addWidget(m_customPlot);
//    contentFrame->setLayout(pLayout);
    QVBoxLayout *hbox = new QVBoxLayout(this);
    hbox->addWidget(splitter);
    setLayout(hbox);
}

SlidingWindow::~SlidingWindow()
{
    //delete
}

//void SlidingWindow::resizeEvent(QResizeEvent *event)
//{
//    //splitter->setGeometry(0, 0, width(), height());
//    move((QApplication::desktop()->width() - width())/2,  (QApplication::desktop()->height() - height())/2);
//    QWidget::resizeEvent(event);
//}

bool SlidingWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseMove) {
        QMouseEvent *mouseMove = static_cast<QMouseEvent*>(event);
        QRect rect = pushButton->frameGeometry();
        if (rect.contains(mouseMove->pos())) {
            pushButton->show();
        }
        else {
            pushButton->hide();
        }
    }
    return QWidget::eventFilter(obj, event);
}

void SlidingWindow::setBtnPos()
{
    pushButton->move(contentFrame->width() - pushButton->width(), (contentFrame->height() - pushButton->height())/2);
}

void SlidingWindow::setBtnIcon()
{
    if (listFrame->width() != 0) {
        pushButton->setIcon(rightIcon);
    }
    else {
        pushButton->setIcon(leftIcon);
    }
}

void SlidingWindow::slotClickedBtn()
{
    QList <int> sizeList;
    sizeList.clear();
    if (listFrame->width() != 0) {
        sizeList.append(660);
        sizeList.append(0);
    }
    else {
        sizeList.append(475);
        sizeList.append(660 - 475);
    }
    splitter->setSizes(sizeList);

    setBtnIcon();
    setBtnPos();
    pushButton->hide();
}

void SlidingWindow::slotSplitterMoved(int pos, int index)
{
    Q_UNUSED(pos)
    Q_UNUSED(index)
    setBtnIcon();
    setBtnPos();
}

void SlidingWindow::mousePressEvent ( QMouseEvent * event)
{
    bPressFlag = true;
    dragPosition = event->pos();
    QWidget::mousePressEvent(event);
}

void SlidingWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (bPressFlag) {
        QPoint relaPos(QCursor::pos() - dragPosition);
        move(relaPos);
    }
    QWidget::mouseMoveEvent(event);
}

void SlidingWindow::mouseReleaseEvent(QMouseEvent *event)
{
    bPressFlag = false;
    QWidget::mouseReleaseEvent(event);
}
QStringList SlidingWindow::getFileNames(const QString &path)
{
    QDir dir(path);
    //QStringList nameFilters;
    //nameFilters << "*.jpg" << "*.png";
    QStringList files = dir.entryList(QDir::Files|QDir::Readable, QDir::Name);
    return files;
}
void SlidingWindow::getData(QListWidgetItem *item){




    QString fileName = item->text();
    //qDebug()<<fileName;
    QFile file(QDir::currentPath()+"/spectrumData/"+fileName);
    //qDebug()<<QDir::currentPath()+"/spectrumData/"+fileName;
    int length = 0;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        //qDebug()<<"打开成功";
        QString line;
        QTextStream in(&file);  //用文件构造流

        line=in.readLine();//循环读取下行


        peaKCount = new double*[peak_max_count];
        for(int i=0;i<peak_max_count;i++)
        {
            peaKCount[i] = new double[2];
            peaKCount[i][0]=0;
            peaKCount[i][1]=0;
        }
        y_max =0;
        x_max =0;
        x_min = 0;
        while(!line.isNull()||line!="")//字符串有内容
        {
            //qDebug() << line;
            QStringList buff = line.split(",");


            x.resize(++length);
            y.resize(length);
            x.append(buff[0].toDouble());
            y.append(buff[1].toDouble());
            if(x[length-1]>x_max)
                x_max=x[length-1];
            if(x[length-1]<x_min)
                x_min=x[length-1];
            if(y[length-1]>y_max)
                y_max=y[length-1];

            line=in.readLine();//循环读取下行
        }
    }
    else{
        //qDebug()<<"打开失败";
    }
    file.close();
    peaKCount = new double*[peak_max_count];
    for(int i=0;i<peak_max_count;i++)
    {
        peaKCount[i] = new double[2];
    }
    // double peakData = 0;
    bool flagPeak =false;
    for(int i =0;i<length-1;i++)
    {
        //                QString data = "("+QString::number(this->x[i])+","+QString::number(y[i])+","+time+")";
        //                spectrumData<<data;

        //               spectrumData_x<<QString::number(this->x[i]);
        //               spectrumData_y<<QString::number(y[i]);
        //               createTime<<time;

        //spectrumData+=QString::number(this->x[i])+","+QString::number(y[i])+"\r\n";
        if(y[i]<y[i+1])
        {
            flagPeak =false;
        }
        else if(y[i]>y[i+1])
        {
            //                    double MIDI = 0;
            //                    double MI = 0;
            //                    double x;

            //                    if(i>=2&&i<=sum_count-3){
            //                        MIDI = y[i-2]*(this->x[i-2])+y[i-1]*(this->x[i-1])+y[i]*(this->x[i])+y[i+1]*(this->x[i+1])+y[i+2]*(this->x[i+2]);
            //                        MI=y[i-2]+y[i-1]+y[i]+y[i+1]+y[i+2];
            //                        x=(MIDI/MI);
            //                        this->x[i]=x;
            //                    }
            if(!flagPeak)
            {
                //peakData = y[i];
                if(y[i]>peaKCount[0][1])
                {
                    for(int k =peak_max_count-1;k>0;k--){
                        peaKCount[k][1] = peaKCount[k-1][1];
                        peaKCount[k][0] = peaKCount[k-1][0];
                    }
                    peaKCount[0][1]=y[i];
                    peaKCount[0][0]=this->x[i];
                }
                else {
                    for (int k=0;k<peak_max_count;k++) {
                        if(peaKCount[k][1]<y[i])
                        {
                            for(int j=peak_max_count-1;j>k;j--)
                            {
                                peaKCount[j][1] = peaKCount[j-1][1];
                                peaKCount[j][0] = peaKCount[j-1][0];
                            }
                            peaKCount[k][1] = y[i];
                            peaKCount[k][0]=this->x[i];
                            break;
                        }
                    }
                }
                flagPeak  = true;
            }

        }
    }


    m_customPlot->xAxis->setRange(x_min,x_max);
    m_customPlot->yAxis->setRange(0,y_max);
    pGraph->setData(x,y);
    m_customPlot->replot();
    qDeleteAll(tracerList);
    //protocol->spectrumData.clear();
    tracerList.clear();
    for (int i=0;i<peak_max_count;i++) {
        tracerList.append( new MyTracer(m_customPlot, MyTracer::DataTracer));

        tracerList[i]->updatePosition(QString::number(peaKCount[i][0],'f',1).toDouble()
                ,peaKCount[i][1]);
        //qDebug()<<"寻峰:"<<QString::number(peaKCount[i][0],'f',1).toDouble()<<","<<QString::number(peaKCount[i][1],'f',1).toDouble();
    }
    for (int i = 0; i < peak_max_count; ++i)
    {
        delete [] peaKCount[i];
    }
    delete [] peaKCount;
    peaKCount = NULL;


}


void SlidingWindow::slotBtn_wave(){

    //    m_customPlot->xAxis->setRange(MenuWindowUI->line_low_mass_number->text().toDouble(),MenuWindowUI->line_hight_mass_number->text().toDouble());
    //    m_customPlot->yAxis->setRange(0,(protocol->max_vollage_copy)*1.3);
    //    m_customPlot->replot();
    m_customPlot->xAxis->setRange(x_min,x_max);
    m_customPlot->yAxis->setRange(0,y_max);
    pGraph->setData(x,y);
    m_customPlot->replot();
}

//void SlidingWindow::reflushFile(){
//    listWidget->clear();
//    QStringList list = getFileNames(QDir::currentPath()+"/spectrumData/");
//    for(int i=0;i<list.length();i++){

//        listWidget->addItem(list.at(i));
//    }
//}
void SlidingWindow::treeItemChanged(QStandardItem *item)
{  // //qDebug()<<"item changed trigger";
    //如果节点可选并且含有子节点
    if ( item->isCheckable()&&item->hasChildren())
    {

        Qt::CheckState state = item->checkState (); //获取当前的选择状态
        //同步父子节点的状态
        for(int i = 0;i<item->rowCount();++i)
        {
            QStandardItem* childItems = item->child(i);
            childItems->setCheckState(state);
        }
    }
}

void SlidingWindow::slotTreeMenu(const QPoint &pos)
{
    QString qss = "QMenu{color:#E8E8E8;background:#4D4D4D;margin:2px;}\
            QMenu::item{padding:3px 20px 3px 20px;}\
            QMenu::indicator{width:13px;height:13px;}\
            QMenu::item:selected{color:#E8E8E8;border:0px solid #575757;background:#1E90FF;}\
            QMenu::separator{height:1px;background:#757575;}";

            QMenu menu;
    menu.setStyleSheet(qss);    //可以给菜单设置样式

    QModelIndex curIndex = treeView->indexAt(pos);      //当前点击的元素的index
    QModelIndex index = curIndex.sibling(curIndex.row(),0); //该行的第1列元素的index
    if (index.isValid())
    {
        //可获取元素的文本、data,进行其他判断处理
        //QStandardItem* item = mModel->itemFromIndex(index);
        //QString text = item->text();
        //QVariant data = item->data(Qt::UserRole + 1);
        //...

        //添加一行菜单，进行展开
        menu.addAction(QStringLiteral("打开"), this, SLOT(slotTreeMenuExpand(bool)));
        menu.addSeparator();    //添加一个分隔线
        menu.addAction(QStringLiteral("修改"), this, SLOT(slotTreeMenuCollapse(bool)));
        menu.addSeparator();    //添加一个分隔线
        menu.addAction(QStringLiteral("删除"), this, SLOT(slotTreeMenuCollapse(bool)));
        menu.addSeparator();    //添加一个分隔线
        menu.addAction(QStringLiteral("下载"), this, SLOT(slotTreeMenuCollapse(bool)));
    }
    menu.exec(QCursor::pos());  //显示菜单
}

void SlidingWindow::OnlineTreeViewDoubleClick(const QModelIndex &index){
    // //qDebug()<<"asdsa";
    QStandardItem *item = model->itemFromIndex(index);
    // QStandardItem* mode=(QStandardItem*)index.model();
    // //qDebug()<<item->hasChildren();
    if(item->hasChildren()){
        //  mode->
        // //qDebug()<<treeView->isExpanded(index);
        if(treeView->isExpanded(index))
            treeView->expand(index);
        else {
            treeView->collapse(index);
        }
    }
}
