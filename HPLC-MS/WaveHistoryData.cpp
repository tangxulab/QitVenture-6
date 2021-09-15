#include "WaveHistoryData.h"
#include "ui_WaveHistoryData.h"

WaveHistoryData::WaveHistoryData(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WaveHistoryData)
{
    resize(600,500);
    ui->setupUi(this);
    splitter = new QSplitter(Qt::Horizontal);
    // splitter->show();

    splitter->setHandleWidth(1);
    splitter->setStyleSheet("QSplitter::handle{background:#000000}");
    treeView = new QTreeView();
    contentFrame = new QFrame();


    saveToolButton = new QToolButton();
    saveToolButton->setToolTip("下载"); //设置内容
    saveToolButton->setIcon(QPixmap(":/images/download.png"));


//    deleteToolButton = new QToolButton();
//    deleteToolButton->setToolTip("删除"); //设置内容
//    deleteToolButton->setIcon(QPixmap(":/images/delete.png"));


    leftToolBar = new QToolBar(this); //添加工具栏

    leftToolBar->addWidget(saveToolButton);
 //   leftToolBar->addWidget(deleteToolButton);

    QWidget *w = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(w);
    layout->addWidget(leftToolBar);
    layout->addWidget(treeView);

    splitter->addWidget(w);
    splitter->addWidget(contentFrame);

    contentFrame->setStyleSheet("background:#FFFFFF");
    contentFrame->resize(475, height());
    contentFrame->setMinimumWidth(405);



    treeView->setStyle(QStyleFactory::create("windows"));
    treeView->resize(200,500);
    treeView->setHeaderHidden(true);
    //treeView->expandsOnDoubleClick();
    // treeView->setExpandsOnDoubleClick(true);
    //  treeView->setc;
    model= new QStandardItemModel(treeView);
    treeView->setEditTriggers(QAbstractItemView::SelectedClicked);
    //树节点改变时触发此信号
    connect(model,SIGNAL(itemChanged(QStandardItem*)),this,SLOT(treeItemChanged(QStandardItem*)));
    // connect(model,SIGNAL(DoubleCl(QStandardItem*)),this,SLOT(treeItemChanged(QStandardItem*)));
    connect(treeView,SIGNAL(doubleClicked ( const QModelIndex)),this,SLOT(OnlineTreeViewDoubleClick(const QModelIndex)));
    connect(model,&QStandardItemModel::itemChanged,this,&WaveHistoryData::getItemChanged,Qt::QueuedConnection);
    connect(saveToolButton,&QPushButton::clicked, this, &WaveHistoryData::saveToolFile);
    QIcon treeitemicon(QPixmap(":/images/script_text.png"));
    QIcon treerooticon(QPixmap(":/images/folder.png"));
    historyQStandardItem = new QStandardItem(treerooticon,QString("历史记录"));
    historyQStandardItem->setCheckable(true);
    QFile file(QDir::currentPath()+"/mapper/historyDataInventory.json");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QString data = file.readAll();
    CJsonObject oJson( data.toStdString());
    for(int i =0;i<oJson["array"].GetArraySize();i++){
        std::string strValue;
        oJson["array"][i].Get("dir", strValue) ;
        QStandardItem* itemProject = new QStandardItem(treerooticon,QString(QString::fromStdString (strValue)));
        itemProject->setCheckable(true);
        for (int j=0;j<oJson["array"][i]["items"].GetArraySize();j++) {
            std::string str;
            oJson["array"][i]["items"][j].Get("name",str);
            QStandardItem* item = new QStandardItem(treeitemicon,QString::fromStdString(str));
            itemProject->appendRow(item);
            item->setCheckable(true);
        }

        itemProject->setCheckable(true);
        historyQStandardItem->appendRow(itemProject);
    }
    model->appendRow(historyQStandardItem);
    treeView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(treeView, &QTreeView::customContextMenuRequested, this, &WaveHistoryData::slotTreeMenu);

    treeView->setModel(model);







    // connect(splitter, SIGNAL(splitterMoved(int,int)), this, SLOT(slotSplitterMoved(int,int)));
    //    connect(toolButton_1, &QPushButton::clicked, this, &SlidingWindow::reflushFile);//刷新信号与槽
    leftIcon = QIcon(":/left.png");
    rightIcon = QIcon(":/right.png");


    flushToolButton = new QToolButton(this); //新建toolButton
    flushToolButton->setToolTip("还原"); //设置内容
    flushToolButton->setIcon(QPixmap(":/images/arrow_refresh.png"));
    toolBar = new QToolBar(this); //添加工具栏
    QComboBox_seacrch_peak = new QComboBox(toolBar);


    toolBar->addWidget(flushToolButton);
    toolBar->addWidget(QComboBox_seacrch_peak);

    for (int i=1;i<=10;i++) {
        QComboBox_seacrch_peak->addItem(QString::number(i));
    }

    connect(QComboBox_seacrch_peak,SIGNAL(currentTextChanged(QString)),this,SLOT(comboBoxCurrentIndexChanged(QString)));
    pushButton = new QPushButton(this);
    pushButton->setFocusPolicy(Qt::NoFocus);
    pushButton->hide();
    pushButton->setFixedSize(13, 42);
    pushButton->setIconSize(pushButton->size());
    pushButton->setStyleSheet("border:none;");
    pushButton->setIcon(rightIcon);
    pushButton->move(contentFrame->width() - pushButton->width()-2, (contentFrame->height() - pushButton->height())/2);
    connect(pushButton,SIGNAL(clicked()),this,SLOT(slotClickedBtn()));
    connect(flushToolButton, &QPushButton::clicked, this, &WaveHistoryData::slotBtn_wave);//刷新信号与槽
    contentFrame->setMouseTracking(true);
    // listFrame->setMouseTracking(true);
    contentFrame->installEventFilter(this);
    // listFrame->installEventFilter(this);
    m_customPlot = new MyCustomPlot(this);
    m_customPlot->legend->setVisible(true);
    QFont legendFont = font();
    legendFont.setPointSize(9);


    m_customPlot->legend->setFont(legendFont);
    m_customPlot->legend->setBrush(QBrush(QColor(255,255,255,230)));
    m_customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignCenter);
    connect(m_customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), m_customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(m_customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), m_customPlot->yAxis2, SLOT(setRange(QCPRange)));
    m_customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);


    QPen pen;

    pGraph = m_customPlot->addGraph();

    pGraph->setName("质谱图");

    pGraph->setPen(QPen(Qt::blue));



    m_customPlot->xAxis->setLabel("质量数（m/z）");
    m_customPlot->yAxis->setLabel("丰度值");
    //  qDebug()<<x.length();

    pLayout = new QVBoxLayout();
    pLayout->addWidget(toolBar);
    pLayout->addWidget(m_customPlot);
    contentFrame->setLayout(pLayout);
    //    QVBoxLayout *hbox = new QVBoxLayout();
    //    hbox->addWidget(splitter);
    this->setCentralWidget(splitter);  /*setLayout(hbox);*/
}

WaveHistoryData::~WaveHistoryData()
{
    delete ui;
}
bool WaveHistoryData::eventFilter(QObject *obj, QEvent *event)
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

void WaveHistoryData::setBtnPos()
{
    pushButton->move(contentFrame->width() - pushButton->width(), (contentFrame->height() - pushButton->height())/2);
}

void WaveHistoryData::setBtnIcon()
{
    if (listFrame->width() != 0) {
        pushButton->setIcon(rightIcon);
    }
    else {
        pushButton->setIcon(leftIcon);
    }
}

void WaveHistoryData::slotClickedBtn()
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

void WaveHistoryData::slotSplitterMoved(int pos, int index)
{
    Q_UNUSED(pos)
    Q_UNUSED(index)
    setBtnIcon();
    setBtnPos();
}

void WaveHistoryData::mousePressEvent ( QMouseEvent * event)
{
    bPressFlag = true;
    dragPosition = event->pos();
    QWidget::mousePressEvent(event);
}

void WaveHistoryData::mouseMoveEvent(QMouseEvent *event)
{
    if (bPressFlag) {
        QPoint relaPos(QCursor::pos() - dragPosition);
        move(relaPos);
    }
    QWidget::mouseMoveEvent(event);
}

void WaveHistoryData::mouseReleaseEvent(QMouseEvent *event)
{
    bPressFlag = false;
    QWidget::mouseReleaseEvent(event);
}
QStringList WaveHistoryData::getFileNames(const QString &path)
{
    QDir dir(path);
    //QStringList nameFilters;
    //nameFilters << "*.jpg" << "*.png";
    QStringList files = dir.entryList(QDir::Files|QDir::Readable, QDir::Name);
    return files;
}
void WaveHistoryData::getData(QString name){




    QString fileName = name+".txt";
    qDebug()<<fileName;
    QFile file(QDir::currentPath()+"/spectrumData/"+fileName);
    qDebug()<<QDir::currentPath()+"/spectrumData/"+fileName;
    int length = 0;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"打开成功";
        QString line;
        QTextStream in(&file);  //用文件构造流

        line=in.readLine();//循环读取下行


        peaKCount = new double*[peak_count];
        for(int i=0;i<peak_count;i++)
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
            qDebug() << line;
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
        qDebug()<<"打开失败";
    }
    file.close();
    peaKCount = new double*[peak_count];
    for(int i=0;i<peak_count;i++)
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
                    for(int k =peak_count-1;k>0;k--){
                        peaKCount[k][1] = peaKCount[k-1][1];
                        peaKCount[k][0] = peaKCount[k-1][0];
                    }
                    peaKCount[0][1]=y[i];
                    peaKCount[0][0]=this->x[i];
                }
                else {
                    for (int k=0;k<peak_count;k++) {
                        if(peaKCount[k][1]<y[i])
                        {
                            for(int j=peak_count-1;j>k;j--)
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
    m_customPlot->yAxis->setRange(0,y_max*1.5);
    pGraph->setData(x,y);

    qDeleteAll(tracerList);
    //protocol->spectrumData.clear();
    tracerList.clear();
    for (int i=0;i<selectIndex;i++) {
        tracerList.append( new MyTracer(m_customPlot, MyTracer::DataTracer));

        tracerList[i]->updatePosition(QString::number(peaKCount[i][0],'f',1).toDouble()
                ,peaKCount[i][1]);
        qDebug()<<"寻峰:"<<QString::number(peaKCount[i][0],'f',1).toDouble()<<","<<QString::number(peaKCount[i][1],'f',1).toDouble();
    }
    m_customPlot->replot();
    //    for (int i = 0; i < peak_count; ++i)
    //    {
    //        delete [] peaKCount[i];
    //    }
    //    delete [] peaKCount;
    //    peaKCount = NULL;


}


void WaveHistoryData::slotBtn_wave(){

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
void WaveHistoryData::treeItemChanged(QStandardItem *item)
{  // qDebug()<<"item changed trigger";
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
QStandardItem *item;
void WaveHistoryData::slotTreeMenu(const QPoint &pos)
{
    QString qss = "QMenu{color:#E8E8E8;background:#4D4D4D;margin:2px;}\
            QMenu::item{padding:3px 20px 3px 20px;}\
            QMenu::indicator{width:13px;height:13px;}\
            QMenu::item:selected{color:#E8E8E8;border:0px solid #575757;background:#1E90FF;}\
            QMenu::separator{height:1px;background:#757575;}";

            QMenu menu;
    menu.setStyleSheet(qss);    //可以给菜单设置样式

    QModelIndex curIndex = treeView->indexAt(pos);      //当前点击的元素的index
    QModelIndex index= curIndex.sibling(curIndex.row(),0); //该行的第1列元素的index
    if (index.isValid())
    {
        //可获取元素的文本、data,进行其他判断处理
        //QStandardItem* item = mModel->itemFromIndex(index);
        //QString text = item->text();
        //QVariant data = item->data(Qt::UserRole + 1);
        //...

        //添加一行菜单，进行展开
        item = model->itemFromIndex(index);
        if(!item->hasChildren()){

            //            QAction *downAction = new QAction(this);
            //            downAction->setText("下载");
            //            menu.addAction(downAction);
            //            menu.addSeparator();    //添加一个分隔线
            //            connect(downAction, SIGNAL(triggered(QModelIndex)), this, SLOT(dockWidget_show()));

            menu.addAction(QStringLiteral("生成报告"), this, SLOT(createReport(bool)));
            menu.addSeparator();    //添加一个分隔线
            /* menu.addAction(QStringLiteral("修改"), this, SLOT(slotTreeMenuCollapse(bool)));
            menu.addSeparator();    //添加一个分隔线
            menu.addAction(QStringLiteral("删除"), this, SLOT(slotTreeMenuCollapse(bool)));
            menu.addSeparator(); */   //添加一个分隔线
            menu.addAction(QStringLiteral("下载"), this, SLOT(downLoadHistoryData()));
        }

    }
    menu.exec(QCursor::pos());  //显示菜单
}

void WaveHistoryData::OnlineTreeViewDoubleClick(const QModelIndex &index){
    // qDebug()<<"asdsa";
    QStandardItem *item = model->itemFromIndex(index);
    // QStandardItem* mode=(QStandardItem*)index.model();
    // qDebug()<<item->hasChildren();
    if(item->hasChildren()){
        //  mode->
        // qDebug()<<treeView->isExpanded(index);
        if(treeView->isExpanded(index))
            treeView->expand(index);
        else {
            treeView->collapse(index);
        }
    }else {
        getData(item->text());
    }
}

void WaveHistoryData::createReport(bool){

    QFile file(QDir::currentPath()+"/mapper/Spectral-Library.json");
    if(!file.open(QIODevice::ReadOnly)){

        //qDebug()<<"not";
        return;
    }
    QByteArray allData = file.readAll();
    file.close();
    QJsonParseError jsonError;
    QJsonDocument jsonDoc(QJsonDocument::fromJson(allData,&jsonError));
    //    if(jsonError.error == QJsonParseError::NoError){
    //        //qDebug()<<"json Error";
    //        return;
    //    }
    QJsonArray rootArray = jsonDoc.array();

    //QStringList keys = rootObj.keys();
    for (int i=0;i<rootArray.size();i++) {
        double sample_ms = rootArray[i].toObject().value("object_precursor_ion").toString().toDouble();

        QString sample_name = rootArray[i].toObject().value("obejct_name").toString();

        //qDebug()<<rootArray.size()<<"---"<<noTestSignal.size();
        for(int j = 0;j <selectIndex  ;j++){
            // int id = rootArray[i].toObject().value("id").toInt();
            //qDebug()<<noTestSignal.at(j)<<"----"<<sample_ms;
            if((peaKCount[i][0]>=(sample_ms-0.5))&&(peaKCount[i][0]<(sample_ms+0.5))){
                qDebug()<<"asdsadad";
                signalNameList.append(sample_name);
            }

        }

    }
    //    MenuWindowUI->textBrowser_result->clear();
    //    for(int i=0;i<signalNameList.size();i++){
    //        MenuWindowUI->textBrowser_result->append(signalNameList.at(i));
    //    }



    m_customPlot->replot();

    m_customPlot->savePng("customPlot.png", 600, 300);

    QString html = "";
    html += "<html>";
    html += "<head>";
    html += "<title>  定性分析报告</title>";
    html += "<head>";
    html += "<body bgcolor=\"#ffffff\">";
    html += "<h1  align=\"center\" style=\"background-color:white\">定性分析报告</h1>";
    html += "<hr>";

    html += "<table width=\"100%\" border=\"1\" cellspacing=\"1\" cellpadding=\"4\" align=\"center\">";
    html += "<tr>";
    html += "<td align=\"center\" height=\"60\">定性分析报告生成时间（当地时间）</td>";
    html += "</tr>";
    html += "<tr>";
    html += "<td align=\"center\" height=\"25\">" +  QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss") + "(UTC+08:00)</td>";
    html += "</tr>";
    html += "</table>";

    html += "<table width=\"100%\" border=\"0\" cellspacing=\"1\" cellpadding=\"4\" bgcolor=\"#ffffff\" align=\"center\">";

    html += "<tr>";

    html += "<th>数据文件</th>";
    html += "<th></th>";
    html += "<th>样品名称</th>";
    html += "<th>用户样品</th>";

    html += "</tr>";


    html += "<tr>";

    html += "<th>样品类型</th>";
    html += "<th>普通</th>";
    html += "<th>经纬度</th>";
    html += "<th>N</th>";

    html += "</tr>";

    html += "<tr>";
    html += "<th>仪器名称</th>";
    html += "<th>QitVenture 6</th>";
    html += "<th>用户名称</th>";
    html += "<th>Banff</th>";
    html += "</tr>";

    html += "<tr>";
    html += "<th>采集时间</th>";
    html += "<th></th>";
    html += "<th>采集方法</th>";
    html += "<th></th>";

    html += "</tr>";

    html += "</table>";

    html += "<br>";

    html += "<p>质谱</p>";

    html += "<br>";

    html+="<span style=\"font-family: 黑体\">离子模式： </span><span style=\"font-family: 宋体\">ESI</span>";

    html += "<hr  style=\"height:3px\"></hr>";


    html += "<p><img src=\"customPlot.png\" alt=\"picture\" width=\"600\" height=\"300\"></p>";


    html += "</table>";

    html += "<table width=\"100%\" border=\"0\" cellspacing=\"1\" cellpadding=\"4\" bgcolor=\"#ffffff\" align=\"center\">";


    for(int i=0;i<signalNameList.length();i++)

    {

        html += "<tr>";

        //                 html += "<th>保留时间</th>";
        //                 html += "<th>"+gccompoundslist[i].RT+" min</th>";
        html += "<th>化合物名</th>";
        html += "<th>"+signalNameList.at(i) +"</th>";

        html += "</tr>";

    }


    html += "</table>";


    html += "<p>---报告结束---</p>";
    html += "</body>";
    html += "</html>";




    QPrinter printer_html;

    printer_html.setPageSize(QPrinter::A4);

    printer_html.setOutputFormat(QPrinter::PdfFormat);

    //         int id=path.lastIndexOf("/");


    //         QString ph=path;

    QString pdfname="C:/report/report_.pdf";

    QString filepath=QFileDialog::getSaveFileName(this,"生成报告","deflaut","报告文件(*.pdf)");

    if(!filepath.isEmpty())

    {

        printer_html.setOutputFileName(filepath);

        QTextDocument text_document;

        text_document.setHtml(html);

        text_document.print(&printer_html);

        text_document.end();

        QMessageBox msg;
        msg.setText("报告生成完毕");
        msg.exec();

        //ShowMessage("报告生成完毕");


    }

}


void WaveHistoryData::downLoadHistoryData(){
    QUrl url("adasdas");
    QString text = item->text();
    QFileDialog *fileDialog = new QFileDialog(this);
    fileDialog->setFileMode(QFileDialog::Directory);
    fileDialog->show();
    //   fileDialog->setLabelText(QFileDialog::LookIn,tr("查看"));
    //fileDialog->setAcceptMode(QFileDialog::AcceptSave);
    fileDialog->setDirectory(QString("./"));
    fileDialog->setNameFilter(QString("所有文件(*.*)"));
    QList<QUrl> urls;
    urls << QUrl("file:")    //我的电脑

         << QUrl::fromLocalFile(QStandardPaths::standardLocations(QStandardPaths::DesktopLocation).first())
         << QUrl::fromLocalFile(QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).first())
         << QUrl::fromLocalFile(QStandardPaths::standardLocations(QStandardPaths::DownloadLocation).first())
         << QUrl::fromLocalFile(QStandardPaths::standardLocations(QStandardPaths::DesktopLocation).first());
    fileDialog->setSidebarUrls(urls);  //设置左边框有什么路径
    //fileDialog->install;
    connect(fileDialog,&QFileDialog::fileSelected,this,&WaveHistoryData::getFileSelectedName);
    qDebug()<<fileDialog->sidebarUrls();
}
void WaveHistoryData::getFileSelectedName(QString file){
    qDebug()<<file;
}
void WaveHistoryData::getStandardItem(QStandardItem* item,HistorySortData sort){
    if(HistorySortData::ITEM==sort)
        historyQStandardItem->appendRow(item);
    else if(HistorySortData::LEAF==sort)
    {
        int row = historyQStandardItem->rowCount();
        qDebug()<<row;
        historyQStandardItem->child(row-1)->appendRow(item);
    }

}

void WaveHistoryData::comboBoxCurrentIndexChanged(QString value)
{
    qDebug()<<value;
    selectIndex=value.toInt();
    qDeleteAll(tracerList);
    //protocol->spectrumData.clear();
    tracerList.clear();
    for (int i=0;i<selectIndex;i++) {
        tracerList.append( new MyTracer(m_customPlot, MyTracer::DataTracer));

        tracerList[i]->updatePosition(QString::number(peaKCount[i][0],'f',1).toDouble()
                ,peaKCount[i][1]);
        qDebug()<<"寻峰:"<<QString::number(peaKCount[i][0],'f',1).toDouble()<<","<<QString::number(peaKCount[i][1],'f',1).toDouble();
    }
    m_customPlot->replot();
    //    for (int i = 0; i < peak_count; ++i)
    //    {
    //        delete [] peaKCount[i];
    //    }
    //    delete [] peaKCount;
    //    peaKCount = NULL;
}

void WaveHistoryData::getItemChanged(QStandardItem *item){

    qDebug()<<item->text();
    if(list.contains(item->text())){
        if(item->checkState()){
            // map[item->text()] = item->checkState();
        }else {
            list.removeOne(item->text());
        }
    }else {
        if(!item->hasChildren())
            list.append(item->text());
    }
    qDebug()<<list;
}
void WaveHistoryData:: saveToolFile(){

    QFileDialog *fileDialog = new QFileDialog(this);
    fileDialog->setFileMode(QFileDialog::Directory);
    fileDialog->show();
    //   fileDialog->setLabelText(QFileDialog::LookIn,tr("查看"));
    //fileDialog->setAcceptMode(QFileDialog::AcceptSave);
    fileDialog->setDirectory(QString("./"));
    fileDialog->setNameFilter(QString("所有文件(*.*)"));
    QList<QUrl> urls;
    urls << QUrl("file:")    //我的电脑

         << QUrl::fromLocalFile(QStandardPaths::standardLocations(QStandardPaths::DesktopLocation).first())
         << QUrl::fromLocalFile(QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).first())
         << QUrl::fromLocalFile(QStandardPaths::standardLocations(QStandardPaths::DownloadLocation).first())
         << QUrl::fromLocalFile(QStandardPaths::standardLocations(QStandardPaths::DesktopLocation).first());
    fileDialog->setSidebarUrls(urls);  //设置左边框有什么路径
    //fileDialog->install;
    connect(fileDialog,&QFileDialog::fileSelected,this,&WaveHistoryData::getFileDir);

    //    for (int i =0 ;i<list.size();i++) {

    //        QFile file(QDir::currentPath()+"/spectrumData/"+list.at(i)+".txt");

    //    }
}

void WaveHistoryData::getFileDir(QString name){
    progresswindow = new ProgressWindow(this);
    progresswindow->show();
    QProgressBar *progressBar =  progresswindow->findChild<QProgressBar *>("progressBar");
    progressBar->setMaximum(list.size());
    progressBar->setMinimum(0);

    for (int i =0 ;i<list.size();i++) {

        //        QFile file(QDir::currentPath()+"/spectrumData/"+list.at(i)+".txt");
        //        file.open(QIODevice::ReadWrite);
        //        file.copy(name);

        if(QFile::copy(QDir::currentPath()+"/spectrumData/"+list.at(i)+".txt",name+"/"+list.at(i)+".txt")){  //将文件复制到新的文件路径下
            qDebug()<<QStringLiteral("复制成功");
        }else {
            qDebug()<<QStringLiteral("复制失败");
        }
        //return true;

        //  QThread::msleep(500);

        progressBar->setValue(i+1);
        //  connect(progressBar,&QToolButton::clicked, this, &MenuWindow::dipaphragm_pump_open);
        //  progresswindow->find()

    }
    //    progresswindow->hide();
}
