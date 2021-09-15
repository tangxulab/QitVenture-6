#include "MenuWindow.h"
#include "ui_MenuWindow.h"
//扫描参数的默认值
static int ionMoudle;
static int scanMoudle;

extern double x_graph_val;
extern double y_graph_val;
extern bool enlarge_and_lessen_flag;//质谱图放大标示

extern QVariantList  spectrumData_x;
extern QVariantList  spectrumData_y;
extern QVariantList  createTime;


QString line_vacuumString;//真空度
bool mode_flag=true;//原始数据和平均数据的标识
int clip_sum;//已废弃
int total_cycle;//总周期
extern bool ss_start;
extern int count_ss_times;



double low_v;
double high_v;
extern int clip_pipe_all_count;
extern bool methodSendRsult;
bool mainTemperatureFlag = true;
bool mainPressureFlag = true;

//bool main_menu_method_set = true;
QMessageBox *msgBox;
int peak_max_count =1;//寻峰个数默认值

QString checkAMS;



//以下static参数是控制面板按钮标识
static bool dipaphragm_pump_open_flag = true;
static bool toolButton_inject_sample_open_flag = true;
static bool toolButton_pinch_valve_open_flag = true;
static bool toolButton_high_voltage_open_flag = true;
static bool  toolButton_24_voltage_open_flag = true;
//static bool  toolButton_48_voltage_open_flag = true;
static bool toolButton_camera_lighting_open_flag = true;
static bool toolButton_molecular_pump_open_flag = true;


//界面按钮样式
static QString sheef="QPushButton{"
                     "background-color:#F0FFF0}";
static QString afterSheef="QPushButton{"
                          "background-color: #4CAF50;"
                          "border: none;color: white;"
                          "padding: 16px 16px;"
                          "text-align: center;"
                          "text-decoration: none;"
                          "border: 2px solid #4CAF50;}"
                          "QPushButton:hover "
                          "{background-color:white ;color: black;}";

static QString mainPushButtonSheef="QPushButton"
                                   "{background-color: #4CAF50; "
                                   "border: none;"
                                   "color: white;"
                                   "padding: 16px 16px; "
                                   "text-align: center;"
                                   "text-decoration: none;"
                                   "}";
static QString mainPushButtonAfterSheef="QPushButton"
                                        "{background-color: #FF2D2D; "
                                        "border: none;"
                                        "color: white;"
                                        "padding: 16px 16px; "
                                        "text-align: center;"
                                        "text-decoration: none;"
                                        "}";

extern QList<char*> messageQueue;
extern QMutex m_mutex;//互斥量
int g_nActScreenX;
int g_nActScreenY;
MenuWindow::MenuWindow(QWidget *parent) :
    QMainWindow(parent),
    MenuWindowUI(new Ui::MenuWindow)
{
    MenuWindowUI->setupUi(this);
    setWindowIcon(QIcon("logo.png"));
    setWindowFlags(Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint | Qt::WindowMinimizeButtonHint);
    QDesktopWidget* desktopWidget = QApplication::desktop();
    QRect screenRect = desktopWidget->screenGeometry();
    g_nActScreenX = screenRect.width();
    g_nActScreenY = screenRect.height();
    QWidget *ss = new QWidget(this);
    ss->setMaximumSize(0,0);
    this->setCentralWidget(ss);
    this->loadStyleSheet(":/qss/myStyleSheet.qss");


    //<!------------------------end------------------------------>

    PulseTimer = new  QTimer();//网口心跳检测定时器
    protocol = new Protocol();//协议引入类
    connectMessgae =new QMessageBox();
    //    connectMessgae->setText("正在连接仪器中,请稍候");
    //    connectMessgae->setWindowFlag(Qt::WindowStaysOnTopHint);
    //    connectMessgae->show();
    vacTimer = new QTimer;
    wavePeakListWindow = new WavePeakListWindow(this);
    /// mySql = new connectMYSQL();
    checkAMSWindow = new CheckAMSWindow();
    messageSendAndRevice = new QMessageSendAndRevice;
    historyDataDisk = new HistoryDataToDisk;
    thread = new  QThread(this);
    messageSendAndRevice->moveToThread(thread);
    historyDataDisk->moveToThread(thread);
    //sendInjectPump("/1ZU11N2R\r\n");

    //qDebug()<<g_nActScreenX<<","<<g_nActScreenY;



}

void MenuWindow::paramTree_init(){
    //<!---------------------参数设置栏------------>
    QTreeWidgetItem *group1=new QTreeWidgetItem(MenuWindowUI->treeWidget);
    // QTreeWidgetItem *group2=new QTreeWidgetItem(MenuWindowUI->treeWidget);
    QTreeWidgetItem *group3=new QTreeWidgetItem(MenuWindowUI->treeWidget);
    QTreeWidgetItem *group4=new QTreeWidgetItem(MenuWindowUI->treeWidget);
    group1->setText(0,"方法设置");
    group1->setIcon(0,QPixmap(":/images/application_edit.png"));
    group3->setText(0,"注射泵");
    group3->setIcon(0,QPixmap(":/images/injection.png"));
    group4->setText(0,"TD-ESI");
    group4->setIcon(0,QPixmap(":/images/molecule.png"));
    QTreeWidgetItem *item11=new QTreeWidgetItem(group1);
    QTreeWidgetItem *item33=new QTreeWidgetItem(group3);
    QTreeWidgetItem *item44=new QTreeWidgetItem(group4);
    MenuWindowUI->treeWidget->setItemWidget(item11, 0, MenuWindowUI->frame_4);
    MenuWindowUI->treeWidget->setItemWidget(item33, 0, MenuWindowUI->frame_5);
    MenuWindowUI->treeWidget->setItemWidget(item44, 0, MenuWindowUI->frame_3);
    MenuWindowUI->treeWidget->expandAll();
    MenuWindowUI->treeWidget->setIndentation(0);
    MenuWindowUI->treeWidget->setStyleSheet("QTreeWidget::item{margin-bottom:1px;background: #D3D3D3;font-size:20px;}");
    MenuWindowUI->treeWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //<!---------------------end-------------------->
}


void MenuWindow::dockWidget_init(){
    //<!---------------------浮动窗口-------------------->
    MenuWindowUI->dockWidget->setFeatures(QDockWidget::AllDockWidgetFeatures);
    MenuWindowUI->dockWidget->setAllowedAreas(Qt::AllDockWidgetAreas);
    MenuWindowUI->dockWidget_2->setFeatures(QDockWidget::AllDockWidgetFeatures);
    MenuWindowUI->dockWidget_2->setAllowedAreas(Qt::AllDockWidgetAreas);
    MenuWindowUI->dockWidget_2->setWindowTitle("质谱图");
    MenuWindowUI->dockWidget_3->setFeatures(QDockWidget::AllDockWidgetFeatures);
    MenuWindowUI->dockWidget_3->setAllowedAreas(Qt::AllDockWidgetAreas);
    MenuWindowUI->dockWidget_6->setFeatures(QDockWidget::AllDockWidgetFeatures);
    MenuWindowUI->dockWidget_6->setAllowedAreas(Qt::AllDockWidgetAreas);
    MenuWindowUI->dockWidget_6->setWindowTitle("气压图");
    MenuWindowUI->dockWidget_4->setFeatures(QDockWidget::AllDockWidgetFeatures);
    MenuWindowUI->dockWidget_4->setAllowedAreas(Qt::AllDockWidgetAreas);
    MenuWindowUI->dockWidget_4->setWindowTitle("总离子流图");

    //MenuWindowUI->dock_sample_test_result->setFeatures(QDockWidget::AllDockWidgetFeatures);
    //MenuWindowUI->dock_sample_test_result->setAllowedAreas(Qt::AllDockWidgetAreas);
    //MenuWindowUI->dock_sample_test_result->setWindowTitle("结果");


    splitDockWidget(MenuWindowUI->dockWidget,MenuWindowUI->dockWidget_2,Qt::Horizontal);
    splitDockWidget(MenuWindowUI->dockWidget,MenuWindowUI->dockWidget_3,Qt::Horizontal);
    splitDockWidget(MenuWindowUI->dockWidget_2,MenuWindowUI->dockWidget_3,Qt::Vertical);
    splitDockWidget(MenuWindowUI->dockWidget_2,MenuWindowUI->dockWidget_6,Qt::Horizontal);
    //splitDockWidget(MenuWindowUI->dockWidget_2,MenuWindowUI->dock_sample_test_result,Qt::Vertical);
    //splitDockWidget(MenuWindowUI->dock_sample_test_result,MenuWindowUI->dockWidget_3,Qt::Horizontal);
    splitDockWidget(MenuWindowUI->dockWidget_6,MenuWindowUI->dockWidget_4,Qt::Horizontal);
    //splitDockWidget(MenuWindowUI->dockWidget_3,MenuWindowUI->dockWidget_5,Qt::Horizontal);
    tabifyDockWidget(MenuWindowUI->dockWidget_2,MenuWindowUI->dockWidget_6);
    tabifyDockWidget(MenuWindowUI->dockWidget_6,MenuWindowUI->dockWidget_4);
    MenuWindowUI->dockWidget_2->raise();
    connect(MenuWindowUI->action_camera, SIGNAL(triggered()), this, SLOT(camera_window_open()));
}

void MenuWindow::paramSet_init(){
    //<!----------------------扫描方法设置---------------->
    //MenuWindowUI->tableWidget_set_method->setMaximumWidth(g_nActScreenX/5*1);
    // MenuWindowUI->dockWidget->setMaximumWidth(g_nActScreenX/5*1+100);
    MenuWindowUI->dockWidget->setFixedWidth(g_nActScreenX/5*1+100);
    MenuWindowUI->tableWidget_set_method->horizontalHeader()->setStretchLastSection(true);
    MenuWindowUI->tableWidget_set_method->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    MenuWindowUI->tableWidget_set_method->setHorizontalHeaderLabels(QStringList()<<"参数名称"<<"数值");
    MenuWindowUI->tableWidget_set_method->setSelectionBehavior(QAbstractItemView::SelectRows);  //整行选中的方式
    MenuWindowUI->tableWidget_set_method->setEditTriggers(QAbstractItemView::NoEditTriggers);   //禁止修改
    MenuWindowUI->tableWidget_set_method->setSelectionMode(QAbstractItemView::SingleSelection);  //设置为可以选中单
    // MenuWindowUI->tableWidget_set_method->verticalHeader()->setDefaultSectionSize(15);
    MenuWindowUI->tableWidget_set_method->setColumnWidth(0,100);
    QFile file(QDir::currentPath()+"/mapper/filePermission.json");
    if(!file.open(QIODevice::ReadOnly)){

        //qDebug()<<"not";
        return;
    }
    QByteArray allData = file.readAll();
    file.close();
    QJsonParseError jsonError;
    QJsonDocument jsonDoc(QJsonDocument::fromJson(allData,&jsonError));
    if(jsonError.error != QJsonParseError::NoError){
        //qDebug()<<"json Error";
        return;
    }
    QJsonArray rootArray = jsonDoc.array();
    //qDebug()<<rootArray;
    //    MenuWindowUI->tableWidget_set_method->setCellWidget(0,1,MenuWindowUI->spinBox_total_cycle);
    //    MenuWindowUI->tableWidget_set_method->setCellWidget(1,1,MenuWindowUI->spinBox_rf);

    //    MenuWindowUI->tableWidget_set_method->setCellWidget(2,1,MenuWindowUI->spinBox_rn);
    //    MenuWindowUI->tableWidget_set_method->setCellWidget(3,1,MenuWindowUI->spinBox_ion_cool_rf_voltage);

    //    MenuWindowUI->tableWidget_set_method->setCellWidget(4,1,MenuWindowUI->spinBox_low_mass_number);
    //    MenuWindowUI->tableWidget_set_method->setCellWidget(5,1,MenuWindowUI->spinBox_hight_mass_number);

    //    MenuWindowUI->tableWidget_set_method->setCellWidget(6,1,MenuWindowUI->spinBox_ion_cold_zone_time);

    //    MenuWindowUI->tableWidget_set_method->setCellWidget(7,1,MenuWindowUI->spinBox_rf_scanning_time);

    //    MenuWindowUI->tableWidget_set_method->setCellWidget(8,1,MenuWindowUI->spinBox_al);

    //    MenuWindowUI->tableWidget_set_method->setCellWidget(9,1,MenuWindowUI->spinBox_ah);

    //    MenuWindowUI->tableWidget_set_method->setCellWidget(10,1,MenuWindowUI->spinBox_af);

    //    MenuWindowUI->tableWidget_set_method->setCellWidget(11,1,MenuWindowUI->spinBox_clamp_valve_open_time);

    //    MenuWindowUI->tableWidget_set_method->setCellWidget(12,1,MenuWindowUI->spinBox_rf_on_time);

    //        MenuWindowUI->tableWidget_set_method->setCellWidget(0,1,MenuWindowUI->spinBox_total_cycle);
    // //qDebug()<<rootArray.size();
    // QMap<QString,bool> map;
    if(userAccount=="admin"){
        MenuWindowUI->tableWidget_set_method->setRowCount(18);
        MenuWindowUI->tableWidget_set_method->setCellWidget(0,1,MenuWindowUI->spinBox_total_cycle);
        MenuWindowUI->tableWidget_set_method->setItem(0,0,new QTableWidgetItem("总周期(0.1ms)"));
        MenuWindowUI->tableWidget_set_method->setCellWidget(1,1,MenuWindowUI->spinBox_rf);
        MenuWindowUI->tableWidget_set_method->setItem(1,0,new QTableWidgetItem("采样频率(kHz)"));
        MenuWindowUI->tableWidget_set_method->setCellWidget(2,1,MenuWindowUI->spinBox_rn);
        MenuWindowUI->tableWidget_set_method->setItem(2,0,new QTableWidgetItem("采样数量"));
        MenuWindowUI->tableWidget_set_method->setCellWidget(3,1,MenuWindowUI->spinBox_ion_cool_rf_voltage);
        MenuWindowUI->tableWidget_set_method->setItem(3,0,new QTableWidgetItem("离子冷却RF电压(V)"));
        MenuWindowUI->tableWidget_set_method->setCellWidget(4,1,MenuWindowUI->spinBox_low_mass_number);
        MenuWindowUI->tableWidget_set_method->setItem(4,0,new QTableWidgetItem("低质量数(amu)"));
        MenuWindowUI->tableWidget_set_method->setCellWidget(5,1,MenuWindowUI->spinBox_hight_mass_number);
        MenuWindowUI->tableWidget_set_method->setItem(5,0,new QTableWidgetItem("高质量数(amu)"));
        MenuWindowUI->tableWidget_set_method->setCellWidget(6,1,MenuWindowUI->spinBox_ion_cold_zone_time);
        MenuWindowUI->tableWidget_set_method->setItem(6,0,new QTableWidgetItem("离子冷却时间(0.1ms)"));
        MenuWindowUI->tableWidget_set_method->setCellWidget(7,1,MenuWindowUI->spinBox_rf_scanning_time);
        MenuWindowUI->tableWidget_set_method->setItem(7,0,new QTableWidgetItem("RF扫描时间(0.1ms)"));
        MenuWindowUI->tableWidget_set_method->setCellWidget(8,1,MenuWindowUI->spinBox_al);
        MenuWindowUI->tableWidget_set_method->setItem(8,0,new QTableWidgetItem("AC电压低幅值(mV)"));
        MenuWindowUI->tableWidget_set_method->setCellWidget(9,1,MenuWindowUI->spinBox_ah);
        MenuWindowUI->tableWidget_set_method->setItem(9,0,new QTableWidgetItem("AC电压高幅值(mV)"));
        MenuWindowUI->tableWidget_set_method->setCellWidget(10,1,MenuWindowUI->spinBox_af);
        MenuWindowUI->tableWidget_set_method->setItem(10,0,new QTableWidgetItem("AC电压频率(kHz)"));
        MenuWindowUI->tableWidget_set_method->setCellWidget(11,1,MenuWindowUI->spinBox_clamp_valve_open_time);
        MenuWindowUI->tableWidget_set_method->setItem(11,0,new QTableWidgetItem("夹管阀开启时长(0.1ms)"));
        MenuWindowUI->tableWidget_set_method->setCellWidget(12,1,MenuWindowUI->spinBox_rf_on_time);
        MenuWindowUI->tableWidget_set_method->setItem(12,0,new QTableWidgetItem("RF开启时刻(0.1ms)"));
        MenuWindowUI->tableWidget_set_method->setCellWidget(13,1,MenuWindowUI->line_clamp_valve_open_times);
        MenuWindowUI->tableWidget_set_method->setItem(13,0,new QTableWidgetItem("开启次数"));
        MenuWindowUI->tableWidget_set_method->setCellWidget(14,1,MenuWindowUI->line_clamp_valve_open_int);
        MenuWindowUI->tableWidget_set_method->setItem(14,0,new QTableWidgetItem("开启间隔时间(0.1ms)"));
        MenuWindowUI->tableWidget_set_method->setCellWidget(15,1,MenuWindowUI->spinBox_multiplier_tube_voltage);
        MenuWindowUI->tableWidget_set_method->setItem(15,0,new QTableWidgetItem("倍增管电压(V)"));
        MenuWindowUI->tableWidget_set_method->setCellWidget(16,1,MenuWindowUI->line_quick_scan_time);
        MenuWindowUI->tableWidget_set_method->setItem(16,0,new QTableWidgetItem("快速扫描时间(0.1ms)"));
        MenuWindowUI->tableWidget_set_method->setCellWidget(17,1,MenuWindowUI->line_low_ms_time);
        MenuWindowUI->tableWidget_set_method->setItem(17,0,new QTableWidgetItem("低质量数持续时间(0.1ms)"));
    }else {
        MenuWindowUI->action_switch->setVisible(false);

        MenuWindowUI->tableWidget_set_method->setRowCount(rootArray.size());
        for(int i=0;i<rootArray.size();i++){
            QJsonObject object = rootArray.at(i).toObject();
            //qDebug()<<object;
            if(object.value("name")=="总周期"){
                MenuWindowUI->tableWidget_set_method->setCellWidget(i,1,MenuWindowUI->spinBox_total_cycle);
                MenuWindowUI->tableWidget_set_method->setItem(i,0,new QTableWidgetItem("总周期(0.1ms)"));
            }

            else if(object.value("name")==("采样频率")){
                MenuWindowUI->tableWidget_set_method->setCellWidget(i,1,MenuWindowUI->spinBox_rf);
                MenuWindowUI->tableWidget_set_method->setItem(i,0,new QTableWidgetItem("采样频率(kHz)"));
            }

            else if(object.value("name")==("采样数据量")){
                MenuWindowUI->tableWidget_set_method->setCellWidget(i,1,MenuWindowUI->spinBox_rn);
                MenuWindowUI->tableWidget_set_method->setItem(i,0,new QTableWidgetItem("采样频率(kHz)"));
            }

            else if(object.value("name")==("离子冷却RF电压")){
                MenuWindowUI->tableWidget_set_method->setCellWidget(i,1,MenuWindowUI->spinBox_ion_cool_rf_voltage);
                MenuWindowUI->tableWidget_set_method->setItem(i,0,new QTableWidgetItem("离子冷却RF电压(V)"));
            }

            else if(object.value("name")==("低质量数")){
                MenuWindowUI->tableWidget_set_method->setCellWidget(i,1,MenuWindowUI->spinBox_low_mass_number);
                MenuWindowUI->tableWidget_set_method->setItem(i,0,new QTableWidgetItem("低质量数(amu)"));
            }

            else if(object.value("name")==("高质量数")){
                MenuWindowUI->tableWidget_set_method->setCellWidget(i,1,MenuWindowUI->spinBox_hight_mass_number);
                MenuWindowUI->tableWidget_set_method->setItem(i,0,new QTableWidgetItem("高质量数(amu)"));
            }

            else if(object.value("name")==("离子冷却时间")){
                MenuWindowUI->tableWidget_set_method->setCellWidget(i,1,MenuWindowUI->spinBox_ion_cold_zone_time);
                MenuWindowUI->tableWidget_set_method->setItem(i,0,new QTableWidgetItem("离子冷却时间(0.1ms)"));
            }

            else if(object.value("name")==("RF扫描时间")){
                MenuWindowUI->tableWidget_set_method->setCellWidget(i,1,MenuWindowUI->spinBox_rf_scanning_time);
                MenuWindowUI->tableWidget_set_method->setItem(i,0,new QTableWidgetItem("RF扫描时间(0.1ms)"));
            }

            else if(object.value("name")==("AC电压低幅值")){
                MenuWindowUI->tableWidget_set_method->setCellWidget(i,1,MenuWindowUI->spinBox_al);
                MenuWindowUI->tableWidget_set_method->setItem(i,0,new QTableWidgetItem("AC电压低幅值(mV)"));
            }

            else if(object.value("name")==("AC电压高幅值")){
                MenuWindowUI->tableWidget_set_method->setCellWidget(i,1,MenuWindowUI->spinBox_ah);
                MenuWindowUI->tableWidget_set_method->setItem(i,0,new QTableWidgetItem("AC电压高幅值(mV)"));
            }

            else if(object.value("name")==("AC电压频率")){
                MenuWindowUI->tableWidget_set_method->setCellWidget(i,1,MenuWindowUI->spinBox_af);
                MenuWindowUI->tableWidget_set_method->setItem(i,0,new QTableWidgetItem("AC电压频率(kHz)"));
            }

            else if(object.value("name")==("夹管阀开启时长")){
                MenuWindowUI->tableWidget_set_method->setCellWidget(i,1,MenuWindowUI->spinBox_clamp_valve_open_time);
                MenuWindowUI->tableWidget_set_method->setItem(i,0,new QTableWidgetItem("夹管阀开启时长(0.1ms)"));
            }

            else if(object.value("name")==("RF开启时刻")){

                MenuWindowUI->tableWidget_set_method->setCellWidget(i,1,MenuWindowUI->spinBox_rf_on_time);
                MenuWindowUI->tableWidget_set_method->setItem(i,0,new QTableWidgetItem("RF开启时刻(0.1ms)"));
            }

        }
        //    MenuWindowUI->tableWidget_set_method->setCellWidget(13,1,MenuWindowUI->spinBox_dc_loading_time);
        //    MenuWindowUI->tableWidget_set_method->setCellWidget(14,1,MenuWindowUI->spinBox_front_cover_electrode);
        //    MenuWindowUI->tableWidget_set_method->setCellWidget(15,1,MenuWindowUI->spinBox_back_cover_electrode);
        //<!----------------------end---------------->

    }






    //<!------------------------注射泵参数设置------------------------------>
    MenuWindowUI->tableWidget_parameter_control->horizontalHeader()->setStretchLastSection(true);
    MenuWindowUI->tableWidget_parameter_control->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    MenuWindowUI->tableWidget_parameter_control->setCellWidget(0,1,MenuWindowUI->spinBox_extract_speed);
    MenuWindowUI->tableWidget_parameter_control->setCellWidget(1,1,MenuWindowUI->spinBox_extract_volume);
    MenuWindowUI->tableWidget_parameter_control->setCellWidget(2,1,MenuWindowUI->spinBox_perform_speed);
    MenuWindowUI->tableWidget_parameter_control->setHorizontalHeaderLabels(QStringList()<<"参数名称"<<"数值");
    quickProgressBar = new QQuickWidget();
    // QQuickWidget quickProgressBar;
    quickProgressBar->setResizeMode(QQuickWidget::SizeRootObjectToView );
    quickProgressBar->setSource(QUrl("qrc:///QmlProgress.qml"));

    // 调用 QML 方法

    //QMetaObject::invokeMethod(pRoot, "onStart");
    //pRoot->setProperty("progress", 20);
    // MenuWindowUI->gridLayout_8->addWidget(quickProgressBar,0,0);

    MenuWindowUI->tableWidget_parameter_control->setCellWidget(3,1,quickProgressBar);

    //    quickProgressBar->show();

    // MenuWindowUI->progressBar->setMaximumHeight(15);
    // MenuWindowUI->progressBar->setMinimum(0);  // 最小值
    // quickProgressBar->setMaximum(MenuWindowUI->spinBox_extract_volume->text().toInt());  // 最大值
    // quickProgressBar->setValue(0);
    /* double dProgress = (MenuWindowUI->progressBar->value() - MenuWindowUI->progressBar->minimum()) * 100.0
            / (MenuWindowUI->progressBar->maximum() -MenuWindowUI-> progressBar->minimum()); // 百分比计算公式*/
    // quickProgressBar->setFormat(tr("%1%").arg(QString::number(dProgress, 'f', 1)));
    // quickProgressBar->setAlignment(Qt::AlignVCenter);
}


void MenuWindow::tableWidget_td_esi_set_init(){

    //<!-----------------------------TD-ESI参数设置------------------>
    MenuWindowUI->tableWidget_td_esi_set->horizontalHeader()->setStretchLastSection(true);
    MenuWindowUI->tableWidget_td_esi_set->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    MenuWindowUI->tableWidget_td_esi_set->setHorizontalHeaderLabels(QStringList()<<"参数名称"<<"设定值"<<"实际值");
    MenuWindowUI->tableWidget_td_esi_set->setCellWidget(0,1,MenuWindowUI->spinBox_temperature_set);
    MenuWindowUI->tableWidget_td_esi_set->setCellWidget(0,2,MenuWindowUI->spinBox__temperature_set_return);
    MenuWindowUI->tableWidget_td_esi_set->setCellWidget(1,1,MenuWindowUI->spinBox_high_voltage);
    MenuWindowUI->tableWidget_td_esi_set->setCellWidget(1,2,MenuWindowUI->spinBox_high_voltage_return);
    MenuWindowUI->tableWidget_td_esi_set->setCellWidget(3,1,MenuWindowUI->spinBox_pwm_scope_set);
    MenuWindowUI->tableWidget_td_esi_set->setCellWidget(2,2,MenuWindowUI->line_ion_trap_temp_return);
    MenuWindowUI->tableWidget_td_esi_set->setCellWidget(2,1,MenuWindowUI->line_ion_trap_temp);
    MenuWindowUI->tableWidget_td_esi_set->setColumnWidth(0,80);
    MenuWindowUI->tableWidget_td_esi_set->setColumnWidth(1,50);
    MenuWindowUI->tableWidget_td_esi_set->setColumnWidth(2,50);
    //<!-----------------------------end----------------------------->
}

void MenuWindow::loadStyleSheet(const QString &styleSheetFile)
{
    QFile file(styleSheetFile);
    file.open(QFile::ReadOnly|QFile::Text);
    if (file.isOpen())
    {
        QString styleSheet = this->styleSheet();
        styleSheet += file.readAll();//读取样式表文件
        this->setStyleSheet(styleSheet);//把文件内容传参
        file.close();
    }
    else
    {
        QMessageBox::information(this,"tip","cannot find qss file");
    }
}

void MenuWindow::menuBar_init(){
    //-----菜单栏
    QStyle* style = QApplication::style();
    QIcon icon = style->standardIcon(QStyle::SP_DialogApplyButton);
    MenuWindowUI->actiongasj->setIcon(icon);
    MenuWindowUI->actionri->setIcon(icon);
    MenuWindowUI->actionasd->setIcon(icon);
    MenuWindowUI->actionsad->setIcon(icon);
    MenuWindowUI->actiontuxa->setIcon(icon);
    MenuWindowUI->action_camera->setIcon(QPixmap(":/images/video.png"));
    MenuWindowUI->action_control_pancel->setIcon(QPixmap(":/images/controlpan.png"));
    MenuWindowUI->action_quit->setIcon(QPixmap(":/images/exit.png"));
    //MenuWindowUI->menumethod_set->setIcon(QPixmap(":/images/functions_arrays.png"));
    MenuWindowUI->actionhistory_note->setIcon(QPixmap(":/images/application_view_columns.png"));

    QDir *dir = new QDir(QDir::currentPath()+"/spectrumData");
    //    QStringList filter;
    //    filter<<"";
    //    dir->setNameFilters(filter);
    //    QFileInfoList fileInfoList = dir->entryInfoList(filter);
    spectrumDataCount = dir->count();
    qDebug()<<spectrumDataCount;


}

void MenuWindow::fileData_init(QString account){

    this->userAccount = account;
    QDir dir;
    if(!dir.exists("mapper")){
        dir.mkdir("mapper");
    }
    QDir spectrumDir;
    if(!spectrumDir.exists("spectrumData")){
        spectrumDir.mkdir("spectrumData");
    }
    QFile file(QDir::currentPath()+"/mapper/datafit.json");
    if(!file.exists()){
        file.open(QIODevice::ReadWrite);
        QJsonObject jsonObject;
        jsonObject.insert("data_fit_A", -249.888);
        jsonObject.insert("data_fit_B", 5.19346);
        jsonObject.insert("data_fit_C", 0.0003388);
        jsonObject.insert("data_fit_D", -2.47897e-07);
        // 使用QJsonDocument设置该json对象
        QJsonDocument jsonDocument;
        jsonDocument.setObject(jsonObject);

        // 将json以文本形式写入文件并关闭文件。
        // QJsonDocument jsonDoc
        file.write(jsonDocument.toJson());
        file.close();
    }



    QFile filePermission(QDir::currentPath()+"/mapper/filePermission.json");
    if(!filePermission.exists()){
        filePermission.open(QIODevice::ReadWrite);
        QJsonArray jsonObject;
        //        jsonObject.insert("data_fit_A", -249.888);
        //        jsonObject.insert("data_fit_B", 5.19346);
        //        jsonObject.insert("data_fit_C", 0.0003388);
        //        jsonObject.insert("data_fit_D", -2.47897e-07);
        //        // 使用QJsonDocument设置该json对象
        QJsonDocument jsonDocument;
        jsonDocument.setArray(jsonObject);

        //        // 将json以文本形式写入文件并关闭文件。
        // QJsonDocument jsonDoc;
        filePermission.write(jsonDocument.toJson());
        filePermission.close();
    }






}

void MenuWindow::connectList(){

    //<!--------------------建立tcp链接--------------------------------->
    waveFormWindow = new WaveFormWindow(this);
    MenuWindowUI->frame->addWidget(waveFormWindow);
    MenuWindowUI->dockWidget_2->setMinimumHeight(g_nActScreenY/10*7-80);
    waveFormWindow->show();

    chromatographicFormWindow = new ChromatographicFormWindow(this);
    MenuWindowUI->verticalLayout->addWidget(chromatographicFormWindow);
    chromatographicFormWindow->show();
    // waveFormWindow->setMinimumSize(0,0);

    //<!--------------------------------end------------------------>


    //<!---------------------------夹管阀气压值图-------------------->
    clipPipeValveWindow = new ClipPipeValveWindow(this);
    MenuWindowUI->verticalLayout_4->addWidget(clipPipeValveWindow);
    clipPipeValveWindow->show();


  //  connect( MenuWindowUI->action_quit, SIGNAL(triggered()), this, SLOT(windowQuit()) );
    //    // connect( MenuWindowUI->action_one_key_start, SIGNAL(triggered()), this, SLOT(one_key_start()) );
    connect( MenuWindowUI->action_control_pancel, SIGNAL(triggered()), this, SLOT(controlPancelWindowShow()) );
    connect(MenuWindowUI->dockWidget,SIGNAL(visibilityChanged(bool)),this,SLOT(setShowIconCheck_dock_1(bool)));
    connect(MenuWindowUI->actiongasj, SIGNAL(triggered()), this, SLOT(dockWidget_show()));
    connect(MenuWindowUI->action_create_method, SIGNAL(triggered()), this, SLOT(create_method()));
    connect(MenuWindowUI->action_select_method, SIGNAL(triggered()), this, SLOT(select_method()));
    //connect(MenuWindowUI->action_ms_db, SIGNAL(triggered()), this, SLOT(ms_db_window()));


    connect(MenuWindowUI->dockWidget_2,SIGNAL(visibilityChanged(bool)),this,SLOT(setShowIconCheck_dock_2(bool)));
    connect(MenuWindowUI->actiontuxa, SIGNAL(triggered()), this, SLOT(dockWidget_2_show()));
    connect(MenuWindowUI->dockWidget_3,SIGNAL(visibilityChanged(bool)),this,SLOT(setShowIconCheck_dock_3(bool)));
    connect(MenuWindowUI->actionri, SIGNAL(triggered()), this, SLOT(dockWidget_3_show()));
    //    // connect(MenuWindowUI->dockWidget_5,SIGNAL(visibilityChanged(bool)),this,SLOT(setShowIconCheck_dock_5(bool)));
    connect(MenuWindowUI->actionhistory_note, SIGNAL(triggered()), this, SLOT(waveHistoryWindowShow()));
    connect(MenuWindowUI->action_switch, SIGNAL(triggered()), this, SLOT(permissionWindowShow()));
    connect(MenuWindowUI->action_system_config,SIGNAL(triggered()),this,SLOT(system_configuration_window()));
    //    //    historyButton = new QToolButton(this);
    //    //    historyButton->setIcon(QPixmap(":/images/chart_curve_link.png"));
    //    //    historyButton->setToolTip("历史纪录");
    connect(MenuWindowUI->actionsad, SIGNAL(triggered()), this, SLOT(dockWidget_5_show()));
    connect(PulseTimer, &QTimer::timeout, this, &MenuWindow::PulseTimeOut);
    connect(MenuWindowUI->btn_start,&QPushButton::clicked, this, &MenuWindow::ExperimentStart);
    connect(MenuWindowUI->btn_method_edit,&QPushButton::clicked,this,&MenuWindow::setMethod);


    connect(vacTimer,&QTimer::timeout,this,&MenuWindow::vacRequest);
    connect(MenuWindowUI->btn_pump_start,&QPushButton::clicked,this,&MenuWindow::pumpStart_clicked);
    connect(MenuWindowUI->btn_end_point,&QPushButton::clicked,this,&MenuWindow::end_point_clicked);
    connect(MenuWindowUI->btn_extract_start,&QPushButton::clicked,this,&MenuWindow::extract_start_clicked);
    connect(MenuWindowUI->btn_perform_start,&QPushButton::clicked,this,&MenuWindow::startInject_clicked);
    connect(MenuWindowUI->btn_perform_stop,&QPushButton::clicked,this,&MenuWindow::stopInject_clicked);
    connect(MenuWindowUI->btn_query_volume,&QPushButton::clicked,this,&MenuWindow::queryVolume_clicked);


    //    //原始数据和取平均数据相关信号与槽
    connect(protocol,&Protocol::wave_data_change,this,&MenuWindow::wave_form_change);
    connect(protocol,&Protocol::multiplier_tube_voltage_signal,this,&MenuWindow::multiplier_tube_voltage_method);
    connect(protocol,&Protocol::avg_wave_data_change,this,&MenuWindow::avg_wave_form_change);
    connect(waveFormWindow->toolButton, &QPushButton::clicked, this, &MenuWindow::slotBtn_wave);//刷新信号与槽
    connect(chromatographicFormWindow->toolButton, &QPushButton::clicked, this, &MenuWindow::slotBtn_chromatographic);//刷新信号与槽
    connect(waveFormWindow->lookPeakButton,&QPushButton::clicked, this, &MenuWindow::searchPeakWindow);
    connect(waveFormWindow->checkButton,&QPushButton::clicked, this, &MenuWindow::checkAMSWindowShow);
    //connect(waveFormWindow->historyButton,&QPushButton::clicked, this, &MenuWindow::waveHistoryWindowShow);
    connect(waveFormWindow->saveButton,&QPushButton::clicked,this,&MenuWindow::SaveToggleWindow);

    connect(waveFormWindow->lockButton,&QPushButton::clicked, this, &MenuWindow::lockWaveWindowShow);
    //connect(waveFormWindow->insertToDB,&QPushButton::clicked, this, &MenuWindow::insertToDBWindowShow);
    connect(protocol,&Protocol::clip_pipe_data_change,this,&MenuWindow::clip_pipe_from_change);
    connect(protocol,&Protocol::sendNoTestSignal,this,&MenuWindow::reciveNoTestSignal);

    connect(wavePeakListWindow->btn_search_peak,&QPushButton::clicked,this,&MenuWindow::slot_search_peak);
    connect(protocol,&Protocol::getPeakListSignal,this,&MenuWindow::getPeakList);


    connect(thread,SIGNAL(started()),messageSendAndRevice,SLOT(doWork()));
    //    //  connect(thread,SIGNAL(started()),messageSendAndRevice,SLOT(diskMethod()));



    connect(this,&MenuWindow::pushDiskMethod,historyDataDisk,&HistoryDataToDisk::diskMethod,Qt::QueuedConnection);
    connect(messageSendAndRevice,&QMessageSendAndRevice::molecularPumpData,this,&MenuWindow::molecularPumpDataDeal,Qt::QueuedConnection);
    connect(messageSendAndRevice,&QMessageSendAndRevice::GUIData,this,&MenuWindow::GUIDataDeal,Qt::QueuedConnection);
    connect(messageSendAndRevice,&QMessageSendAndRevice::ESIData,this,&MenuWindow::ESIDataDeal,Qt::QueuedConnection);
    connect(messageSendAndRevice,&QMessageSendAndRevice::injectata,this,&MenuWindow::injectDataDeal,Qt::QueuedConnection);
    connect(this,&MenuWindow::pushQueue,messageSendAndRevice,&QMessageSendAndRevice::pushIntoQueue,Qt::QueuedConnection);
    connect(messageSendAndRevice,&QMessageSendAndRevice::injectataVolume,this,&MenuWindow::injectataVolumeDeal,Qt::QueuedConnection);
    //connect(chromatographicFormWindow->pCustomPlot, &QCustomPlot::mouseDoubleClick, this, &MenuWindow::slot_mouseDoubleClickTip);
    qRegisterMetaType<SerialPortData>("SerialPortData");
    qRegisterMetaType<HistorySortData>("HistorySortData");
    //thread->start();
    QString InjectPumpInit = "/1ZU11N2R\r\n";
    QByteArray array = InjectPumpInit.toLatin1();
    pushQueue(array,SerialPortData::InjectPumpData);

    server = new QTcpServer();
    server->listen(QHostAddress::Any, 11000);

    connect(server, SIGNAL(newConnection()), this, SLOT(acceptConnnection()));
   // vacTimer->start(1500);

}
// 读取单片机发来的数据

void MenuWindow::readMicrocontrollerToPc()
{
    PulseTimer->start(10000);
    QByteArray readdata = socket->readAll();
    protocol->readByteData(readdata);
    if(enlarge_and_lessen_flag)
    {
        // waveFormWindow->m_customPlot->xAxis->setRange(MenuWindowUI->spinBox_low_mass_number->text().toDouble(),MenuWindowUI->spinBox_hight_mass_number->text().toDouble());
        waveFormWindow->m_customPlot->yAxis->setRange(0,(protocol->max_vollage_copy)*1.3);
        waveFormWindow->m_customPlot->replot();
    }


}


//-----------------------方法设置-------------------------------

// 方法设置

void MenuWindow::setMethod()
{

    //main_menu_method_set = true;
    protocol->low_mass_number =MenuWindowUI->spinBox_low_mass_number->text().toDouble();
    protocol->hight_mass_number =MenuWindowUI->spinBox_hight_mass_number->text().toDouble();
    protocol->sum_count = MenuWindowUI->spinBox_rf->text().toInt()*
            MenuWindowUI->spinBox_rf_scanning_time->text().toInt()/10;
    protocol->x.resize(protocol->sum_count);
    protocol->y.resize(protocol->sum_count);
    protocol->avg_y.resize(protocol->sum_count);
    int times = 1;
    clip_sum = MenuWindowUI->spinBox_total_cycle->text().toInt()/10*times*5*10;
    protocol->clip_pipe_x.resize(clip_sum);
    protocol->clip_pipe_y.resize(clip_sum);
    int data[25]={0};
    data[0] = ionMoudle;
    data[1] = scanMoudle;
    data[2] = MenuWindowUI->spinBox_total_cycle->text().toUShort();
    data[3] = MenuWindowUI->spinBox_rf->text().toUShort();
    data[4] = MenuWindowUI->spinBox_rn->text().toUShort();
    data[5] = MenuWindowUI->spinBox_ion_cool_rf_voltage->text().toUShort();
    data[6] = MenuWindowUI->spinBox_low_mass_number->text().toUShort();
    data[7] = MenuWindowUI->spinBox_hight_mass_number->text().toUShort();
    data[8] = MenuWindowUI->spinBox_ion_cold_zone_time->text().toUShort();
    data[9] = MenuWindowUI->spinBox_rf_scanning_time->text().toUShort();
    data[10] = MenuWindowUI->spinBox_al->text().toUShort();
    data[11] = MenuWindowUI->spinBox_ah->text().toUShort();
    data[12] = MenuWindowUI->spinBox_af->text().toUShort();
    data[13] = MenuWindowUI->spinBox_clamp_valve_open_time->text().toUShort();
    data[14] = 55;
    data[15] = MenuWindowUI->spinBox_rf_on_time->text().toUShort();
    //    data[16] = MenuWindowUI->spinBox_dc_loading_time->text().toUShort();
    //    data[17] = MenuWindowUI->spinBox_front_cover_electrode->text().toUShort();
    //    data[18] = MenuWindowUI->spinBox_back_cover_electrode->text().toUShort();
    data[19] = 10;
    //    data[20] = 1;
    //    data[21] = 5000;
    data[20] = MenuWindowUI->line_clamp_valve_open_times->text().toUShort();;
    data[21] = MenuWindowUI->line_clamp_valve_open_int->text().toUShort();
    data[22] = MenuWindowUI->spinBox_multiplier_tube_voltage->text().toUShort();
    data[23] = MenuWindowUI->line_quick_scan_time->text().toUShort();
    data[24] = MenuWindowUI->line_low_ms_time->text().toUShort();

    //    double k = 3.566;
    //    double b = 266;
    //    double k = 4.85;
    //   double b = -236;

    //    checkAMS = readDataFromFile("D://checkAMS.txt");
    //    double k,b;
    //    if(checkAMS==nullptr||checkAMS=="")
    //    {
    //        k=3.566;
    //        b=266;
    //    }else {
    //        k =checkAMS.mid(2,5).toDouble();
    //        b = checkAMS.mid(10,3).toDouble();
    //    }
    int LowWeight=MenuWindowUI->spinBox_low_mass_number ->text().toInt();
    int HighWeight=MenuWindowUI->spinBox_hight_mass_number->text().toInt();
    data[5]=int(data[5]/2);



    //    QSqlQuery query =  getFitData("二次曲线拟合");


    //    while(query.next()) //一行一行遍历
    //    {
    //        data_fit_A=  query.value("data_fit_A").toString().toDouble();
    //        data_fit_B = query.value("data_fit_B").toString().toDouble();
    //        data_fit_C  =query.value("data_fit_C").toString().toDouble();
    //        // data_fit_D  =query.value("data_fit_D").toString().toDouble();
    //    }



    QFile file(QDir::currentPath()+"/mapper/datafit.json");
    if(file.open(QIODevice::ReadWrite|QIODevice::Text)){
        QByteArray allData = file.readAll();
        QJsonParseError jsonError;
        QJsonDocument jsonDoc(QJsonDocument::fromJson(allData,&jsonError));
        if(jsonError.error != QJsonParseError::NoError){
            //qDebug()<<"json Error";
            return;
        }
        QJsonObject object = jsonDoc.object();

        // file.resize(0);



        //        SQLList *sqlList = new SQLList();
        //        QSqlQuery query = sqlList->selectDataFitType("三次曲线拟合");
        //        query.next();
        double d = object.value("data_fit_A").toDouble();
        double c = object.value("data_fit_B").toDouble();
        double b = object.value("data_fit_C").toDouble();
        double a = object.value("data_fit_D").toDouble();
        //a = ((0-b)*1000*1000-c*1000-d+5094)*1.0/(1000*1000*1000);
        //qDebug()<<"a:"<<a;
        //printf("拟合方程为：y = %lf + %lfx + %lfx^2 \n", coefficient[1], coefficient[2], coefficient[3]);
        data[6]=int((d + c*LowWeight +pow(LowWeight,2)*b+pow(LowWeight,3)*a)/2);
        data[7]=int((d + c*HighWeight +pow(HighWeight,2)*b+pow(HighWeight,3)*a)/2);
        //qDebug()<<data[6]<<"-----"<<data[7];
        low_v =data[6];
        high_v =data[7];


        for(int i=0;i<protocol->sum_count;i++)
        {
            double temp = ((high_v-low_v)*2.0)/(protocol->sum_count-1)*(i)+low_v*2;
            QVector<double> X123;
            ShengJin(a,b,c,d-temp,X123);
            // //qDebug()<<"三次"<<"x1:"<<X123[0]<<"x2:"<<X123[1]<<"x2:"<<X123[2];
            if(X123[0]<1000&&X123[0]>0)
                protocol->x[i]=X123[0];
            else if(X123[1]<1000&&X123[1]>0)
                protocol->x[i]=X123[1];
            else if(X123[2]<1000&&X123[2]>0)
                protocol->x[i]=X123[2];
            // //qDebug()<<"shuchuzhi:"<<protocol->x[i];
        }



        SendInstrcution(protocol->menthodSet(data).toHex());
    }

}

//实验开始按钮
void MenuWindow::ExperimentStart()
{



    if (MenuWindowUI->btn_start->text()=="实验开始")
    {
        //        if(MenuWindowUI->line_vacuum->text().toDouble()>=2.00E-5)
        //        {
        //            QMessageBox msg;
        //            msg.setText("真空度需低于2.00E-5");
        //            msg.exec();
        //            return;
        //        }
        MenuWindowUI->btn_start->setText("实验结束");
        MenuWindowUI->btn_method_edit->setEnabled(false);
        //  MenuWindowUI->btn_method_edit->setStyleSheet(sheef);
        SendInstrcution(protocol->formStableInstruition(ParameterControl::ON, ParameterControl::TESTING_BEGAN).toHex());
        // QByteArray data =protocol->TDESIInstruction(SELF_TURN_ON_PROTOCOL_CODE::SCANNING_LIGHTING,1,SELF_TURN_ON_PROTOCOL_CODE::SELF_TURN_ON_COMMAND_CODE_DATA_AREA_CODE::ON);
        //QString result = sendVTDESIMessage(data);
        // data =protocol->TDESIInstruction(SELF_TURN_ON_PROTOCOL_CODE::SCANNING_LIGHTING,1,SELF_TURN_ON_PROTOCOL_CODE::SELF_TURN_ON_COMMAND_CODE_DATA_AREA_CODE::ON);
        //result = sendVTDESIMessage(data);

    }else {

        MenuWindowUI->btn_method_edit->setEnabled(true);
        // MenuWindowUI->btn_method_edit->setStyleSheet(afterSheef);
        MenuWindowUI->btn_start->setText("实验开始");
        SendInstrcution(protocol->formStableInstruition(ParameterControl::OFF, ParameterControl::TESTING_BEGAN).toHex());
        msgBox= new QMessageBox();
        msgBox->setWindowFlags(Qt::FramelessWindowHint);
        msgBox->setText("实验结束中，请稍候");
        msgBox->setStyleSheet("background-color:black;color:white");
        msgBox->addButton(QMessageBox::Ok);
        msgBox->button(QMessageBox::Ok)->hide();
        msgBox->setWindowOpacity(0.6);
        msgBox->show();
        //QByteArray data =protocol->TDESIInstruction(SELF_TURN_ON_PROTOCOL_CODE::SCANNING_LIGHTING,1,SELF_TURN_ON_PROTOCOL_CODE::SELF_TURN_ON_COMMAND_CODE_DATA_AREA_CODE::OFF);
        //  QString result = sendVTDESIMessage(data);
        // data =protocol->TDESIInstruction(SELF_TURN_ON_PROTOCOL_CODE::SCANNING_LIGHTING,1,SELF_TURN_ON_PROTOCOL_CODE::SELF_TURN_ON_COMMAND_CODE_DATA_AREA_CODE::OFF);
        //   result = sendVTDESIMessage(data);

    }
}


//-------------------------分子泵-------------------------------

//分子泵开启

void MenuWindow::pumpStart_clicked()
{
    vacTimer->stop();

    if (MenuWindowUI->btn_pump_start->text() == "分子泵开启")
    {

        MenuWindowUI->btn_pump_start->setText("分子泵关闭");
        //QTimer::singleShot(500, this, &MenuWindow::sendPumpON);

    }
    else
    {
        MenuWindowUI->btn_pump_start->setText("分子泵开启");
        // QTimer::singleShot(500, this, &MenuWindow::sendPumpOFF);
    }
    vacTimer->start();
}


void MenuWindow::sendPumpON()
{
    vacTimer->stop();
    // QString current2="0011070706006500033\r";
    //    current2=sendVacMessage(current2.toStdString().c_str());
    //    //qDebug()<<current2;
    //    QString current1="0011002603001126\r";
    //    current1=sendVacMessage(current1.toStdString().c_str());
    //    //qDebug()<<current1;
    //    QString message = "0011000206000000010\r";
    //    message=sendVacMessage(message.toStdString().c_str());
    //    //qDebug()<<message;
    QString PumpStart = "0011001006111111015\r";
    // QString PumpStart = "0011002306111111019\r";
    // sendVacMessage(PumpStart);
    vacTimer->start();

}


void MenuWindow::sendPumpOFF()
{
    vacTimer->stop();
    QString PumpStop = "0011001006000000009\r";
    //sendVacMessage(PumpStop);
    vacTimer->start();

}

//QString MenuWindow::sendVacMessage(QString message)
//{
//    comSendStatus = pumpflag;
//    QString res;

//    for (int i = 0; i < 2; i++)
//    {
//        vacrb.clear();
//        if (vacSerial->isOpen()) {
//            vacSerial->clear();
//            vacSerial->write(message.toStdString().c_str());
//        }
//        vacrb.waitforspinBox(1000);
//        if (vacrb.numspinBoxs() >= 1)
//        {
//            res = vacrb.getspinBox();

//            if (res != "") return res;
//        }
//    }
//    return res;
//}







void MenuWindow::vacRequest()
{




    QString pinamipre="@253PR1?;FF";
    QByteArray  array = pinamipre.toLatin1();
   // pushQueue(array,SerialPortData::MolecularPumpData);
    QString rspeed="0010039802=?115\r";
    QByteArray rspeedArray = rspeed.toLatin1();
    pushQueue(rspeedArray,SerialPortData::MolecularPumpData);
    QString current="0010031002=?099\r";
    array = current.toLatin1();
    pushQueue(array,SerialPortData::MolecularPumpData);
    QString voltage="0010031302=?102\r";
    array = voltage.toLatin1();
    pushQueue(array,SerialPortData::MolecularPumpData);
    QString electemperature="0010032602=?106\r";
    array = electemperature.toLatin1();
    pushQueue(array,SerialPortData::MolecularPumpData);
    //    QString bottomtemperature="0010033002=?101\r";
    //    array = bottomtemperature.toLatin1();
    //    pushQueue(array.data());
    //    QString motortemperature="0010034602=?108\r";
    //    array = motortemperature.toLatin1();
    //    pushQueue(array.data());
    //    QString returnMessage = "0010030602=?104\r";
    //    array = returnMessage.toLatin1();
    //    pushQueue(array.data());

    //    pinamipre=sendGauge(pinamipre.toStdString().c_str());


    //    rspeed=sendVacMessage(rspeed.toStdString().c_str());
    //    current=sendVacMessage(current.toStdString().c_str());
    //    voltage=sendVacMessage(voltage.toStdString().c_str());
    //    returnMessage=sendVacMessage(returnMessage.toStdString().c_str());
    //    // //qDebug()<<"返回值:"<<returnMessage;
    //    motortemperature=sendVacMessage(motortemperature.toStdString().c_str());
    //    bottomtemperature=sendVacMessage(bottomtemperature.toStdString().c_str());
    //    electemperature=sendVacMessage(electemperature.toStdString().c_str());


    //    rspeed=rspeed.mid(10,6);


    //    motortemperature=motortemperature.mid(10,6);
    //    bottomtemperature=bottomtemperature.mid(10,6);
    //    electemperature=electemperature.mid(10,6);
    //    current=current.mid(10,6);
    //    voltage=voltage.mid(10,6);

    //    bottomtemperature=tempDeleteZero(bottomtemperature);
    //    motortemperature=tempDeleteZero(motortemperature);
    //    electemperature=tempDeleteZero(electemperature);
    //    rspeed=spdDeleteZero(rspeed);
    //    voltage=voltageDeleteZero(voltage);
    //    current=currentDeleteZero(current);




    // line_vacuumString = pinamipre.mid(7,7);
    QString volume= "/1?0R\r\n";
    array = volume.toLatin1();
    pushQueue(array,SerialPortData::InjectPumpData);




    //    volume=volume.mid(3);
    //    volume=volume.left(volume.length()-2);
    //    double v=volume.toDouble()*1.0/1920;
    //    setVolumeProgree(v);
    QByteArray  data = protocol->TDESIInstruction(TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_ADDRESS_CODE::ESI_ADDRESS_CODE, TD_ESI_PROTOCOL_CODE::TEMPERATURE_ONE_MEASUREMENT,2,TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::ON);
    pushQueue(data,SerialPortData::EsiData);

    QByteArray data_trap_temp = protocol->TDESIInstruction(TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_ADDRESS_CODE::ESI_ADDRESS_CODE, TD_ESI_PROTOCOL_CODE::TEMPERATURE_TWO_MEASUREMENT,2,TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::ON);
    pushQueue(data_trap_temp,SerialPortData::EsiData);

    QByteArray  data_voltage = protocol->TDESIInstruction(TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_ADDRESS_CODE::ESI_ADDRESS_CODE,TD_ESI_PROTOCOL_CODE::HIGH_VOLTAGE_READING,2,TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::ON);
    pushQueue(data_voltage,SerialPortData::EsiData);



    //    QByteArray  dat_td_current = protocol->TDESIInstruction(TD_ESI_PROTOCOL_CODE::HIGH_CURRENT_READING,1,TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::ON);
    //    QString TDESI_current = sendVTDESIMessage(dat_td_current);
    //    // //qDebug()<<"电流："<<TDESI_current;
    //    QString signal_td_current = TDESI_current.mid(3,1);
    //    //    // //qDebug()<<"：长度"<<signal;
    //    QString data_area_td_current =  TDESI_voltage.mid(4,signal_td_current.toInt());
    //    // MenuWindowUI->line_td_current_return->setText(QString::number(data_area_td_current.toDouble()/100,'f',2));
    //    QString mesaage = "550133000201120031AA";
    //    // QByteArray messageSend = QBytemesaage
    //    SendInstrcution(mesaage);

}

QString MenuWindow::tempDeleteZero(QString message)
{


    while(message.startsWith("0"))
    {
        message=message.mid(1);

    }


    return message;
}

QString MenuWindow::spdDeleteZero(QString message)
{

    while(message.startsWith("0"))
    {
        message=message.mid(1);

    }

    if(message.isEmpty())

        message="0";

    return message;
}

QString MenuWindow::voltageDeleteZero(QString message)
{


    while(message.startsWith("0"))
    {
        message=message.mid(1);

    }
    message.insert(2,".");
    return message;
}

QString MenuWindow::currentDeleteZero(QString message)
{


    message.insert(4,".") ;

    while(message.startsWith("0"))
    {
        message=message.mid(1);

    }
    if(message.startsWith("."))
        message.insert(0,"0");
    return message;

}




QString MenuWindow::sendGauge(QString message)
{
    comSendStatus=gaugeflag;
    QString res;
    for(int i=0;i<1;i++)
    {
        gacrb.clear();
        if (vacSerial->isOpen()){
            vacSerial->clear();
            vacSerial->write(message.toStdString().c_str());
        }
        gacrb.waitforline(1000);
        if(gacrb.numLines() >= 1)
        {
            res = gacrb.getline();
            if(res != "") return res;
        }
    }
    return res;


}

void MenuWindow::readDataTovacrb(void)
{


    switch (comSendStatus)
    {
    case pumpflag:

        if (vacSerial->isOpen())
        {
            QByteArray data = vacSerial->readAll();
            for (int i = 0; i < data.size(); i++) vacrb.putch(data[i]);
        }
        break;

    case gaugeflag:

        if (vacSerial->isOpen())
        {
            QByteArray data = vacSerial->readAll();
            for (int i = 0; i < data.size(); i++) gacrb.putch(data[i]);
        }
        break;

    case injectflag:

        if (vacSerial->isOpen())
        {
            QByteArray data = vacSerial->readAll();
            for (int i = 0; i < data.size(); i++) ipcrb.putch(data[i]);
        }
        break;
    }


}

//-----------------------参数监控------------------------------


// 排废液

void MenuWindow::end_point_clicked()
{
    vacTimer->stop();
    //    QEventLoop loop;
    //    QTimer::singleShot(500,&loop,SLOT(quit()));
    //    loop.exec();
    MenuWindowUI->btn_extract_start->setEnabled(false);
    //  MenuWindowUI->btn_extract_start->setStyleSheet(sheef);
    MenuWindowUI->btn_end_point->setEnabled(false);
    //  MenuWindowUI->btn_end_point->setStyleSheet(sheef);
    MenuWindowUI->btn_perform_start->setEnabled(false);
    //   MenuWindowUI->btn_perform_start->setStyleSheet(sheef);
    //MenuWindowUI->btn_save_data->setEnabled(false);
    // MenuWindowUI->btn_save_data->setStyleSheet(sheef);
    QString end_point = "/1V20000I3A0R\r\n";
    QByteArray data = end_point.toLatin1();
    pushQueue(data,SerialPortData::InjectPumpData);
    vacTimer->start();
}


// 开始抽取

void MenuWindow::extract_start_clicked()
{
    vacTimer->stop();
    //    QEventLoop loop;
    //    QTimer::singleShot(500,&loop,SLOT(quit()));
    //    loop.exec();
    MenuWindowUI->btn_extract_start->setEnabled(false);
    //  MenuWindowUI->btn_extract_start->setStyleSheet(sheef);
    MenuWindowUI->btn_end_point->setEnabled(false);
    //   MenuWindowUI->btn_end_point->setStyleSheet(sheef);
    MenuWindowUI->btn_perform_start->setEnabled(false);
    //   MenuWindowUI->btn_perform_start->setStyleSheet(sheef);
    //MenuWindowUI->btn_save_data->setEnabled(false);
    // MenuWindowUI->btn_save_data->setStyleSheet(sheef);
    //DCDCDC
    double speed = MenuWindowUI->spinBox_extract_speed->value();
    double volume = MenuWindowUI->spinBox_extract_volume->value();
    int b = static_cast<int>(1920 * volume);
    int a = static_cast<int>(32 * speed);
    QString refill = "/1V" + QString::number(a) + "I1A" + QString::number(b) + "R\r\n";

    QByteArray data = refill.toLatin1();
    //qDebug()<<"chouqu:"<<data;
    pushQueue(data,SerialPortData::InjectPumpData);
    vacTimer->start();
}




// 开始执行

void MenuWindow::startInject_clicked()
{
    //MenuWindowUI->btn_perform_start->setDown(false);
    vacTimer->stop();
    //    QEventLoop loop;
    //    QTimer::singleShot(500,&loop,SLOT(quit()));
    //    loop.exec();
    MenuWindowUI->btn_extract_start->setEnabled(false);
    //  MenuWindowUI->btn_extract_start->setStyleSheet(sheef);
    MenuWindowUI->btn_end_point->setEnabled(false);
    //   MenuWindowUI->btn_end_point->setStyleSheet(sheef);
    MenuWindowUI->btn_perform_start->setEnabled(false);
    //   MenuWindowUI->btn_perform_start->setStyleSheet(sheef);
    // MenuWindowUI->btn_save_data->setEnabled(false);
    // MenuWindowUI->btn_save_data->setStyleSheet(sheef);
    double speed = MenuWindowUI->spinBox_perform_speed->text().toDouble();
    int a = static_cast<int>(32 * speed);
    QString start = "/1V" + QString::number(a) + "I2A0R\r\n";
    QByteArray data = start.toLatin1();
    pushQueue(data,SerialPortData::InjectPumpData);
    //    sendInjectPump(start);
    vacTimer->start();



}


// 停止执行
void MenuWindow::stopInject_clicked()
{
    vacTimer->stop();
    //    QEventLoop loop;
    //    QTimer::singleShot(500,&loop,SLOT(quit()));
    //    loop.exec();
    MenuWindowUI->btn_extract_start->setEnabled(true);
    // MenuWindowUI->btn_extract_start->setStyleSheet(afterSheef);
    MenuWindowUI->btn_end_point->setEnabled(true);
    // MenuWindowUI->btn_end_point->setStyleSheet(afterSheef);
    MenuWindowUI->btn_perform_start->setEnabled(true);
    //  MenuWindowUI->btn_perform_start->setStyleSheet(afterSheef);
    //MenuWindowUI->btn_save_data->setEnabled(true);
    // MenuWindowUI->btn_save_data->setStyleSheet(afterSheef);
    QString stop = "/1TR\r\n";
    QByteArray data = stop.toLatin1();
    pushQueue(data,SerialPortData::InjectPumpData);
    //    sendInjectPump("/1TR\r\n");
    vacTimer->start();
}


// 查询体积
void MenuWindow::queryVolume_clicked()
{
    QString volume = sendInjectPump("/1?0R\r\n");

    volume = volume.mid(3);
    volume = volume.left(volume.length() - 2);
    int v = volume.toInt() / 1920;
    // MenuWindowUI->spinBox_rest_volume->setText(QString::number(v));
}

//保存
//------------------------------------------------------------

void MenuWindow::acceptConnnection()
{
    //qDebug()<<"dsads";
    socket = server->nextPendingConnection();
    if(socket!=nullptr){
        connect(socket, SIGNAL(readyRead()), this, SLOT(readMicrocontrollerToPc()));
        connect(socket, SIGNAL(disconnected()), this, SLOT(socketdisconnect()));
        server->close();
        //qDebug() << "connected!";
        connectMessgae->setText("仪器连接成功！");
        connectMessgae->show();
    }


}

void MenuWindow::socketdisconnect()
{
    //qDebug()<<"远程socket连接已断开";
    server->listen(QHostAddress::Any,11000);
}

void MenuWindow::PulseTimeOut()
{
    socket->close();
    // ShowMessage("无心跳，socket连接已断开");
    PulseTimer->stop();
    server->listen(QHostAddress::Any,6000);
}

void MenuWindow::SendInstrcution(QString message)
{

    if (socket == nullptr)
    {
        QMessageBox msg;
        msg.setText("通讯超时");
        msg.exec();
        return;
    }
    QByteArray sendmessage = QByteArray::fromHex(message.toLatin1().data());
    if (socket->isOpen())
    {
        socket->write(sendmessage);
        if (!socket->waitForReadyRead(10000))
        {
            QMessageBox msg;
            msg.setText("通讯超时");
            msg.exec();
        }
    }
}


QString MenuWindow::sendInjectPump(QString message)
{
    comSendStatus = injectflag;
    QString res;
    for (int i = 0; i < 2; i++)
    {
        ipcrb.clear();
        if (vacSerial->isOpen()) {
            vacSerial->clear();
            vacSerial->write(message.toStdString().c_str());
        }
        ipcrb.waitforline(1000);
        if (ipcrb.numLines() >= 1)
        {
            res = ipcrb.getline();
            if (res != "") return res;
        }
    }
    return res;


}

void MenuWindow::setShowIconCheck_dock_1(bool str)
{

    if(!str)
    {
        MenuWindowUI->actiongasj->setIconVisibleInMenu(false);
    }
    else{
        MenuWindowUI->actiongasj->setIconVisibleInMenu(true);
    }
}
void MenuWindow::setShowIconCheck_dock_2(bool str)
{

    if(!str)
    {
        MenuWindowUI->actiontuxa->setIconVisibleInMenu(false);
    }else {
        MenuWindowUI->actiontuxa->setIconVisibleInMenu(true);
    }
}

void MenuWindow::setShowIconCheck_dock_3(bool str)
{

    if(!str)
    {
        MenuWindowUI->actionri->setIconVisibleInMenu(false);
    }
    else{
        MenuWindowUI->actionri->setIconVisibleInMenu(true);
    }
}
void MenuWindow::setShowIconCheck_dock_4(bool str)
{

    if(!str)
    {
        MenuWindowUI->actionasd->setIconVisibleInMenu(false);
    }else {
        MenuWindowUI->actionasd->setIconVisibleInMenu(true);
    }
}
void MenuWindow::setShowIconCheck_dock_5(bool str)
{

    if(!str)
    {
        MenuWindowUI->actionsad->setIconVisibleInMenu(false);

    }else{

        MenuWindowUI->actionsad->setIconVisibleInMenu(true);
    }
}
void MenuWindow::dockWidget_show()
{
    MenuWindowUI->dockWidget->show();
    MenuWindowUI->actiongasj->setIconVisibleInMenu(true);
    MenuWindowUI->dockWidget->raise();
}
void MenuWindow::dockWidget_2_show()
{
    MenuWindowUI->dockWidget_2->show();
    MenuWindowUI->actiontuxa->setIconVisibleInMenu(true);
    MenuWindowUI->dockWidget_2->raise();
}

void MenuWindow::dockWidget_3_show()
{
    MenuWindowUI->dockWidget_3->show();
    MenuWindowUI->actionri->setIconVisibleInMenu(true);
    MenuWindowUI->dockWidget_3->raise();
}
void MenuWindow::dockWidget_4_show()
{

}
void MenuWindow::dockWidget_5_show()
{
    //MenuWindowUI->dockWidget_5->show();
    // MenuWindowUI->actionsad->setIconVisibleInMenu(true);
    //  MenuWindowUI->dockWidget_5->raise();

}
void MenuWindow::setActiveDock(bool str)
{
    MenuWindowUI->dockWidget_2->setVisible(true);
    MenuWindowUI->dockWidget_2->raise();
}
MenuWindow::~MenuWindow()
{

    delete MenuWindowUI;
}


void MenuWindow::wave_form_change( QVector<double> x, QVector<double> y)
{


    waveFormWindow->pGraph->setData(x,y);


    //qDebug()<<protocol->y;
    // qDebug()<<protocol->y.length();
    qDeleteAll(waveFormWindow->tracerList);
    //    protocol->x.clear();
    //    protocol->y.clear();
    //protocol->spectrumData.clear();
    waveFormWindow->tracerList.clear();
    if(pushDisk){
        //qDebug()<<"sadas";
        // chromatographicFormWindow->curGraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc,Qt::red, 10));
        QCPItemTracer *groupTracer = new QCPItemTracer(chromatographicFormWindow->pCustomPlot);
        groupTracer->setGraph(chromatographicFormWindow->curGraph);
        groupTracer->setStyle(QCPItemTracer::tsCircle);
        groupTracer->setBrush(Qt::red);
        groupTracer->setSize(10);
        groupTracer->setGraphKey(i+(j++));
        pushDiskMethod(protocol->spectrumData);
        protocol->spectrumData.clear();
    }else {
        // chromatographicFormWindow->curGraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc,Qt::blue, 10));
        QCPItemTracer *groupTracer = new QCPItemTracer(chromatographicFormWindow->pCustomPlot);
        groupTracer->setGraph(chromatographicFormWindow->curGraph);
        groupTracer->setStyle(QCPItemTracer::tsCircle);
        groupTracer->setBrush(Qt::blue);
        groupTracer->setSize(10);
        groupTracer->setGraphKey(j+(i++));
        //        pushDiskMethod(protocol->spectrumData);
        //        protocol->spectrumData.clear();
    }


    for (int i=0;i<peak_max_count;i++) {
        waveFormWindow->tracerList.append( new MyTracer(waveFormWindow->m_customPlot, MyTracer::DataTracer));
        // //qDebug()<<"寻峰:"<<QString::number(protocol->peaKCount[i][0],'f',1).toDouble();
        waveFormWindow->tracerList[i]->updatePosition(QString::number(protocol->peaKCount[i][0],'f',1).toDouble()
                ,protocol->peaKCount[i][1]);
    }
    waveFormWindow->m_customPlot->replot();
    for (int i = 0; i < peak_max_count; ++i)
    {
        delete [] protocol->peaKCount[i];
    }
    //  //qDebug()<< QString::number(protocol->peaKCount[0][0]);
    delete [] protocol->peaKCount;
    protocol->peaKCount = nullptr;
    //qDeleteAll(protocol->peakCount);
    chromatographicFormWindow->curGraph->setData(protocol->HP_X, protocol->HP_Y);
    //chromatographicFormWindow->pCustomPlot->xAxis->setVisible(true);
    // chromatographicFormWindow->pCustomPlot->yAxis->setVisible(true);
    chromatographicFormWindow->pCustomPlot->replot();
}

void MenuWindow::clip_pipe_from_change()
{
    clipPipeValveWindow->pGraph->setData(protocol->clip_pipe_x, protocol->clip_pipe_y);
    //    qDeleteAll(clipPipeValveWindow->tracerType);
    //    clipPipeValveWindow->tracerType.clear();
    //    for (int i=0;i<protocol->peak_pipe_data.length();i++) {
    //        MenuWindowUI->textBrowser->append(QString::number(protocol->peak_pipe_data[i][0])
    //                +","+ QString::number(protocol->peak_pipe_data[i][1])
    //                );
    //    }
    clipPipeValveWindow-> m_customPlot->yAxis->setRange(0, 7);
    clipPipeValveWindow-> m_customPlot->xAxis->rescale(true);
    clipPipeValveWindow->m_customPlot->replot();
}


void MenuWindow::camera_window_open()
{
    if(cameraWindow==nullptr)
    {

        cameraWindow = new CameraWindow(this);
        cameraWindow->show();
    }else {
        cameraWindow->showNormal();
    }
}



void MenuWindow::readData2vacrb(void)
{
    // //qDebug()<<"sdfsd";

    //    switch (comSendStatus)
    //    {
    //    case pumpflag:

    //        if(vacSerial->isOpen())
    //        {
    //            QByteArray data = vacSerial->readAll();
    //            for(int i=0;i<data.size();i++) vacrb.putch(data[i]);
    //        }
    //        break;

    //    case gaugeflag:

    //        if(vacSerial->isOpen())
    //        {
    //            QByteArray data = vacSerial->readAll();
    //            for(int i=0;i<data.size();i++) gacrb.putch(data[i]);
    //        }
    //        break;

    //    case injectflag:

    //        if(vacSerial->isOpen())
    //        {
    //            QByteArray data = vacSerial->readAll();
    //            for(int i=0;i<data.size();i++) ipcrb.putch(data[i]);
    //        }
    //        break;
    //    case TDESIFlag:
    //        if(vacSerial->isOpen())
    //        {
    //            QByteArray data = vacSerial->readAll();
    //            for(int i=0;i<data.size();i++) tdesicrb.putch(data[i]);
    //        }
    //        break;
    //    }


}
void MenuWindow::windowQuit()
{
    if (!(QMessageBox::information(this,tr("exit tip"),tr("Do you really want exit ?"),tr("Yes"),tr("No"))))
    {
        QApplication* app;
        this->close();
        app->exit(0);
    }

}




void MenuWindow::setVolumeProgree(double dist)
{
    //    if(static_cast<int>(dist)==0||static_cast<int>(dist)==MenuWindowUI->spinBox_extract_volume->text().toInt())
    //    {
    //        MenuWindowUI->btn_extract_start->setEnabled(true);
    //        //  MenuWindowUI->btn_extract_start->setStyleSheet(afterSheef);
    //        MenuWindowUI->btn_end_point->setEnabled(true);
    //        //  MenuWindowUI->btn_end_point->setStyleSheet(afterSheef);
    //        MenuWindowUI->btn_perform_start->setEnabled(true);
    //        //  MenuWindowUI->btn_perform_start->setStyleSheet(afterSheef);
    //        //MenuWindowUI->btn_save_data->setEnabled(true);
    //        // MenuWindowUI->btn_save_data->setStyleSheet(afterSheef);
    //    }
    //    MenuWindowUI->progressBar->setMinimum(0);  // 最小值
    //    MenuWindowUI->progressBar->setMaximum(MenuWindowUI->spinBox_extract_volume->text().toInt());  // 最大值
    //    MenuWindowUI->progressBar->setValue(static_cast<int>(dist));
    //    double dProgress = (MenuWindowUI->progressBar->value() - MenuWindowUI->progressBar->minimum()) * 100.0
    //            / (MenuWindowUI->progressBar->maximum() -MenuWindowUI-> progressBar->minimum()); // 百分比计算公式
    //    MenuWindowUI->progressBar->setFormat(tr(" %1%").arg(QString::number(dProgress, 'f', 1)));
    //    MenuWindowUI->progressBar->setAlignment(Qt::AlignVCenter);
}

void MenuWindow::slotBtn_wave()
{
    waveFormWindow->m_customPlot->xAxis->setRange(MenuWindowUI->spinBox_low_mass_number->text().toDouble(),MenuWindowUI->spinBox_hight_mass_number->text().toDouble());
    waveFormWindow->m_customPlot->yAxis->setRange(0,(protocol->max_vollage_copy)*1.3);
    waveFormWindow->m_customPlot->replot();
    enlarge_and_lessen_flag = true;
}



void MenuWindow::avg_wave_form_change()
{
    waveFormWindow->pGraph->setData(protocol->x,protocol->avg_y);
    waveFormWindow->m_customPlot->replot();
}


QString MenuWindow::sendVTDESIMessage(QByteArray message)
{
    QString res;

    comSendStatus = TDESIFlag;
    for (int i = 0; i < 2; i++)
    {

        tdesicrb.clear();
        QString aa;
        if (vacSerial->isOpen()){
            vacSerial->clear();
            vacSerial->write(message);
        }

        tdesicrb.waitforline(1000);
        if (tdesicrb.numLines() >= 1)
        {
            res = tdesicrb.getline();

            if (res != "") return res;
        }
    }
    return res;
}
void MenuWindow::on_btn_indicator_light_clicked()
{
    vacTimer->stop();
    //    QEventLoop loop;
    //    QTimer::singleShot(500,&loop,SLOT(quit()));
    //    loop.exec();
    if(MenuWindowUI->btn_indicator_light->text()=="指示灯开启")
    {
        MenuWindowUI->btn_indicator_light->setText("指示灯关闭");

    }
    else {
        MenuWindowUI->btn_indicator_light->setText("指示灯开启");


    }
    vacTimer->start();
}



void MenuWindow::on_btn_pwm_scope_set_clicked()
{
    vacTimer->stop();
    //    QEventLoop loop;
    //    QTimer::singleShot(500,&loop,SLOT(quit()));
    //    loop.exec();
    int pwm = MenuWindowUI->spinBox_pwm_scope_set->text().toInt();
    QByteArray data = protocol->TDESIInstruction(TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_ADDRESS_CODE::ESI_ADDRESS_CODE, TD_ESI_PROTOCOL_CODE::SCOPE_OF_PWM,2,pwm);
    //    QString result = sendVTDESIMessage(data);
    //    //qDebug()<<"PWM:"<<result;
    //pushQueue(data);
    pushQueue(data,SerialPortData::EsiData);
    vacTimer->start();

}

void MenuWindow::on_btn_temperature_set_clicked()
{
    vacTimer->stop();
    //    QEventLoop loop;
    //    QTimer::singleShot(500,&loop,SLOT(quit()));
    //    loop.exec();
    int temperature = MenuWindowUI->spinBox_temperature_set->text().toInt();
    QByteArray data = protocol->TDESIInstruction(TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_ADDRESS_CODE::ESI_ADDRESS_CODE, TD_ESI_PROTOCOL_CODE::TEMPERATURE_ONE_SET,2,temperature);
    pushQueue(data,SerialPortData::EsiData);
    //    QString  result = sendVTDESIMessage(data);
    //    //qDebug()<<"gaowen:"<<result;
    //pushQueue(data);
    vacTimer->start();
}


void MenuWindow::on_btn_pwm_scope_close_clicked()
{
    vacTimer->stop();

    QByteArray data = protocol->TDESIInstruction(TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_ADDRESS_CODE::ESI_ADDRESS_CODE, TD_ESI_PROTOCOL_CODE::SCOPE_OF_PWM_CLOSE,1,TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::OFF);

    pushQueue(data,SerialPortData::EsiData);
    vacTimer->start();
}

void MenuWindow::on_btn_high_voltage_clicked()
{
    vacTimer->stop();

    int voltage = MenuWindowUI->spinBox_high_voltage->text().toInt();
    QByteArray data = protocol->TDESIInstruction(TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_ADDRESS_CODE::ESI_ADDRESS_CODE, TD_ESI_PROTOCOL_CODE::HIGH_VOLTAGE_SET,2,voltage);
    pushQueue(data,SerialPortData::EsiData);
    vacTimer->start();
}


void MenuWindow::getPeakList()
{

    wavePeakListWindow->table_seacrch_peak->setRowCount(0);
    wavePeakListWindow->table_seacrch_peak->clearContents();
    for(int i=0;i<peak_max_count;i++)
    {
        int count =  wavePeakListWindow->table_seacrch_peak->rowCount();
        wavePeakListWindow->table_seacrch_peak->insertRow(count);
        //double data =  (MenuWindowUI->spinBox_low_mass_number->text().toDouble()+(MenuWindowUI->spinBox_hight_mass_number->text().toDouble()-MenuWindowUI->spinBox_low_mass_number->text().toDouble())*1.0/(6000-1)
        //*protocol->peaKCount[i][0]);
        wavePeakListWindow->table_seacrch_peak->setItem(count,0,new QTableWidgetItem(QString::number(protocol->peaKCount[i][0])));
        wavePeakListWindow->table_seacrch_peak->setItem(count,1,new QTableWidgetItem(QString::number(protocol->peaKCount[i][1])));
    }
}

void MenuWindow::slot_search_peak()
{
    //qDebug()<<"sdfds";
    peak_max_count = wavePeakListWindow->QComboBox_seacrch_peak->currentText().toInt();
    qDeleteAll(waveFormWindow->tracerList);
    waveFormWindow->tracerList.clear();

}
void MenuWindow::controlPancelWindowShow()
{
    if(controlPancelWindow==nullptr){
        controlPancelWindow = new ControlPancelWindow(this);

        //高压指示灯
        //扫描指示灯
        //系统指示灯
        //真空指示灯
        //24V激光灯的状态
        QByteArray data = protocol->TDESIInstruction(TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_ADDRESS_CODE::ESI_ADDRESS_CODE, TD_ESI_PROTOCOL_CODE::INDICATOR_LIGHT_STATUS,1,TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::ON);
        pushQueue(data,SerialPortData::EsiData);
        // 进样指示灯
        data = protocol->TDESIInstruction(TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_ADDRESS_CODE::ESI_ADDRESS_CODE, TD_ESI_PROTOCOL_CODE::INJECT_SAMPLE_LIGHTING_STATUS,1,TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::ON);
        pushQueue(data,SerialPortData::EsiData);
        //隔膜泵指示灯
        data = protocol->TDESIInstruction(TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_ADDRESS_CODE::ESI_ADDRESS_CODE, TD_ESI_PROTOCOL_CODE::DIAPHRAGM_PUMP_POWER_STATUS,1,TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::ON);
        pushQueue(data,SerialPortData::EsiData);
        //分子泵
        if(MenuWindowUI->line_pump_current->text().toDouble()<1e-6){
            controlPancelWindow->findChild<QToolButton *>("toolButton_molecular_pump")->setIcon(QPixmap(":/images/molecular_pump_close.png"));
            toolButton_molecular_pump_open_flag = true;
        }else {
            controlPancelWindow->findChild<QToolButton *>("toolButton_molecular_pump")->setIcon(QPixmap(":/images/molecular_pump_open.png"));
            toolButton_molecular_pump_open_flag = false;
        }
        controlPancelWindow->show();

    }

    //获取仪器状态
    connect(controlPancelWindow->findChild<QToolButton *>("toolButton_pump"),&QToolButton::clicked, this, &MenuWindow::dipaphragm_pump_open);
    //connect(controlPancelWindow->findChild<QToolButton *>("toolButton_inject_sample"),&QToolButton::clicked, this, &MenuWindow::toolButton_inject_sample_open);
    connect(controlPancelWindow->findChild<QToolButton *>("toolButton_pinch_valve"),&QToolButton::clicked, this, &MenuWindow::toolButton_pinch_valve_open);
    connect(controlPancelWindow->findChild<QToolButton *>("toolButton_high_voltage"),&QToolButton::clicked, this, &MenuWindow::toolButton_high_voltage_open);
    connect(controlPancelWindow->findChild<QToolButton *>("toolButton_24_voltage"),&QToolButton::clicked, this, &MenuWindow::toolButton_24_voltage_open);

    connect(controlPancelWindow->findChild<QToolButton *>("toolButton_camera_lighting"),&QToolButton::clicked, this, &MenuWindow::toolButton_camera_lighting_open);
    connect(controlPancelWindow->findChild<QToolButton *>("toolButton_molecular_pump"),&QToolButton::clicked, this, &MenuWindow::toolButton_molecular_pump_open);
    controlPancelWindow->show();
}
void MenuWindow::searchPeakWindow()
{


    wavePeakListWindow->show();
}

void MenuWindow::checkAMSWindowShow()
{
    if(checkAMSWindow==nullptr)
    {
        checkAMSWindow->show();
        // initFile("D://checkAMS.txt");
    }else {
        checkAMSWindow->showNormal();
    }

}

void MenuWindow::dipaphragm_pump_open()
{
    vacTimer->stop();
    if(dipaphragm_pump_open_flag){
        controlPancelWindow->findChild<QToolButton *>("toolButton_pump")->setIcon(QPixmap(":/images/pump_open.png"));
        QByteArray data = protocol->TDESIInstruction(TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_ADDRESS_CODE::ESI_ADDRESS_CODE,TD_ESI_PROTOCOL_CODE::DIPAPHRAGM_PUMP,1,TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::ON);
        pushQueue(data,SerialPortData::EsiData);
        dipaphragm_pump_open_flag = false;
    }else {
        controlPancelWindow->findChild<QToolButton *>("toolButton_pump")->setIcon(QPixmap(":/images/gemo.png"));
        QByteArray data = protocol->TDESIInstruction(TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_ADDRESS_CODE::ESI_ADDRESS_CODE,TD_ESI_PROTOCOL_CODE::DIPAPHRAGM_PUMP,1,TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::OFF);
        pushQueue(data,SerialPortData::EsiData);
        dipaphragm_pump_open_flag = true;
    }


    vacTimer->start();
}

void MenuWindow::toolButton_inject_sample_open()
{
    vacTimer->stop();
    if(toolButton_inject_sample_open_flag){
        controlPancelWindow->findChild<QToolButton *>("toolButton_inject_sample")->setIcon(QPixmap(":/images/lighting_open.png"));
        QByteArray data = protocol->TDESIInstruction(TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_ADDRESS_CODE::ESI_ADDRESS_CODE,TD_ESI_PROTOCOL_CODE::INJECT_SAMPLE_LIGHTING,1,TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::ON);
        pushQueue(data,SerialPortData::EsiData);
        toolButton_inject_sample_open_flag = false;
    }else {
        controlPancelWindow->findChild<QToolButton *>("toolButton_inject_sample")->setIcon(QPixmap(":/images/lighting.png"));
        QByteArray data = protocol->TDESIInstruction(TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_ADDRESS_CODE::ESI_ADDRESS_CODE,TD_ESI_PROTOCOL_CODE::INJECT_SAMPLE_LIGHTING,1,TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::OFF);
        pushQueue(data,SerialPortData::EsiData);
        toolButton_inject_sample_open_flag = true;
    }

    vacTimer->start();
}

void MenuWindow::toolButton_pinch_valve_open(){

    if(toolButton_pinch_valve_open_flag){
        SendInstrcution(protocol->formStableInstruition(ParameterControl::OFF, ParameterControl::RELEASE_AIR).toHex());
        controlPancelWindow->findChild<QToolButton *>("toolButton_pinch_valve")->setIcon(QPixmap(":/images/valve_close.png"));
        toolButton_pinch_valve_open_flag = false;

    }else{
        SendInstrcution(protocol->formStableInstruition(ParameterControl::ON, ParameterControl::RELEASE_AIR).toHex());
        controlPancelWindow->findChild<QToolButton *>("toolButton_pinch_valve")->setIcon(QPixmap(":/images/valve_open.png"));
        toolButton_pinch_valve_open_flag=true;
    }

}

void MenuWindow::toolButton_high_voltage_open()
{
    vacTimer->stop();

    if(toolButton_high_voltage_open_flag){
        controlPancelWindow->findChild<QToolButton *>("toolButton_high_voltage")->setIcon(QPixmap(":/images/high_voltage_close.png"));
        //    //vacSerial->clear();
        SendInstrcution(protocol->formStableInstruition(ParameterControl::OFF, ParameterControl::HIGH_VOLTAGE_POWER).toHex());
        toolButton_high_voltage_open_flag = false;

    }else{
        controlPancelWindow->findChild<QToolButton *>("toolButton_high_voltage")->setIcon(QPixmap(":/images/high_voltage_open.png"));
        SendInstrcution(protocol->formStableInstruition(ParameterControl::ON, ParameterControl::HIGH_VOLTAGE_POWER).toHex());
        toolButton_high_voltage_open_flag=true;
    }



    vacTimer->start();
}

void MenuWindow::toolButton_24_voltage_open()
{

    if(toolButton_24_voltage_open_flag){
        SendInstrcution(protocol->formStableInstruition(ParameterControl::OFF, ParameterControl::RF_24_VOLTAGE_POWER).toHex());
        controlPancelWindow->findChild<QToolButton *>("toolButton_24_voltage")->setIcon(QPixmap(":/images/voltage_close.png"));
        toolButton_24_voltage_open_flag = false;

    }else{
        SendInstrcution(protocol->formStableInstruition(ParameterControl::ON, ParameterControl::RF_24_VOLTAGE_POWER).toHex());
        controlPancelWindow->findChild<QToolButton *>("toolButton_24_voltage")->setIcon(QPixmap(":/images/voltage_open.png"));
        toolButton_24_voltage_open_flag=true;
    }

}




void MenuWindow::toolButton_camera_lighting_open()
{

    if(toolButton_camera_lighting_open_flag){
        QByteArray data = protocol->TDESIInstruction(TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_ADDRESS_CODE::ESI_ADDRESS_CODE,TD_ESI_PROTOCOL_CODE::INDICATOR_LIGHT,1,TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::ON);

        pushQueue(data,SerialPortData::EsiData);
        controlPancelWindow->findChild<QToolButton *>("toolButton_camera_lighting")->setIcon(QPixmap(":/images/camera_lighting_open.png"));
        toolButton_camera_lighting_open_flag = false;
    }else {
        QByteArray data = protocol->TDESIInstruction(TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_ADDRESS_CODE::ESI_ADDRESS_CODE,TD_ESI_PROTOCOL_CODE::INDICATOR_LIGHT,1,TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::OFF);

        pushQueue(data,SerialPortData::EsiData);
        controlPancelWindow->findChild<QToolButton *>("toolButton_camera_lighting")->setIcon(QPixmap(":/images/camera_lighting_close.png"));
        toolButton_camera_lighting_open_flag = true;
    }


    vacTimer->start();
}

void MenuWindow::toolButton_molecular_pump_open()
{
    vacTimer->stop();
    if(toolButton_molecular_pump_open_flag){
        QString PumpStart = "0011001006111111015\r";
        QByteArray array = PumpStart.toLatin1();
        pushQueue(array,SerialPortData::MolecularPumpData);
        controlPancelWindow->findChild<QToolButton *>("toolButton_molecular_pump")->setIcon(QPixmap(":/images/molecular_pump_open.png"));
        toolButton_molecular_pump_open_flag = false;
    }else {
        QString PumpStart = "0011001006000000009\r";
        QByteArray array = PumpStart.toLatin1();
        pushQueue(array,SerialPortData::MolecularPumpData);
        controlPancelWindow->findChild<QToolButton *>("toolButton_molecular_pump")->setIcon(QPixmap(":/images/molecular_pump_close.png"));
        toolButton_molecular_pump_open_flag = true;
    }
    vacTimer->start();
}

void MenuWindow::setCheckAMS(){

    //qDebug()<<"asda";



    double sample_thoery_one = checkAMSWindow->findChild<QLineEdit *>("line_sample_theory_one")->text().toDouble();
    double sample_experiment_one = checkAMSWindow->findChild<QLineEdit *>("line_sample_experiment_one")->text().toDouble();
    double sample_theory_two = checkAMSWindow->findChild<QLineEdit *>("line_sample_theory_two")->text().toDouble();
    double sample_experiment_two = checkAMSWindow->findChild<QLineEdit *>("line_sample_experiment_two")->text().toDouble();
    //1、从文件中获取k，b的值
    checkAMS = readDataFromFile("D://checkAMS.txt");
    //k=3.566,b=266
    double k =checkAMS.mid(2,5).toDouble();
    double b = checkAMS.mid(10,3).toDouble();
    //qDebug()<<"k="<<k<<"b="<<b;

    // int x_real,x_theory;
    double k_new,b_new;
    // k*sample_experiment_one+b = k_new*sample_thoery_one+b_new;
    //  k*sample_experiment_two+b = k_new*sample_theory_two+b_new;

    k_new = k*(sample_experiment_one-sample_experiment_two)*1.0/(sample_thoery_one-sample_theory_two);
    b_new =k*sample_experiment_one+b - k_new*sample_thoery_one;
    QString new_k = QString::number(k_new,'f',3);
    QString new_b = QString::number(b_new,'f',0);




    //2、将
    writeDataToFile("D://checkAMS.txt","k="+new_k+",b="+new_b);

}
void MenuWindow::initFile(QString filePath)
{
    QFileInfo fileInfo(filePath);
    if(!fileInfo.exists())
    {
        QString data = "k=3.566,b=266";
        writeDataToFile(filePath,data);

    }

}
QString MenuWindow::readDataFromFile(QString filePath)
{
    QFile file(filePath);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray t = file.readAll();
    // ui->text_r->setText(QString(t));
    file.close();
    return QString(t);
}

void MenuWindow::writeDataToFile(QString filePath,QString data)
{
    //QString e = ui->text_e->toPlainText();
    QFile file(filePath);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    file.write(data.toUtf8());
    file.close();

}


void MenuWindow::setSpeed(QString text)
{

    //qDebug()<<text;

    if(text=="线性拟合")
    {
        double k,b;





    }else  if (text=="二次曲线拟合"){
        double a,b,c;




    }else if(text=="三次曲线拟合"){
        double a,b,c,d;



    }
}

void MenuWindow::waveHistoryWindowShow(){
    if(slidingWindow==nullptr){
        slidingWindow = new WaveHistoryData(this);
        connect(historyDataDisk,&HistoryDataToDisk::moveQStandardItem,slidingWindow,&WaveHistoryData::getStandardItem);
        slidingWindow->show();
    }else
        slidingWindow->showNormal();

}


QSqlQuery MenuWindow::getFitData(QString typeName){

    SQLList *sqlList = new SQLList();
    QSqlQuery SqlQuery = sqlList->getFitDataByType(typeName);
    return SqlQuery;
}

void MenuWindow::ShengJin(double a,double b,double c,double d,QVector<double> &X123)
{
    /************************************************************************/
    /* 盛金公式求解三次方程的解
       德尔塔f=B^2-4AC
           这里只要了实根，虚根需要自己再整理下拿出来
    */
    /************************************************************************/
    double A=b*b-3*a*c;
    double B=b*c-9*a*d;
    double C=c*c-3*b*d;
    double f=B*B-4*A*C;
    double i_value;
    double Y1,Y2;
    if (fabs(A)<1e-6 && fabs(B)<1e-6)//公式1
    {
        X123.push_back(-b/(3*a));
        X123.push_back(-b/(3*a));
        X123.push_back(-b/(3*a));
    }
    else if (fabs(f)<1e-6)   //公式3
    {
        double K=B/A;
        X123.push_back(-b/a+K);
        X123.push_back(-K/2);
        X123.push_back(-K/2);
    }
    else if (f>1e-6)      //公式2
    {
        Y1=A*b+3*a*(-B+sqrt(f))/2;
        Y2=A*b+3*a*(-B-sqrt(f))/2;
        double Y1_value=(Y1/fabs(Y1))*pow((double)fabs(Y1),1.0/3);
        double Y2_value=(Y2/fabs(Y2))*pow((double)fabs(Y2),1.0/3);
        X123.push_back((-b-Y1_value-Y2_value)/(3*a));//虚根我不要
        //虚根还是看看吧，如果虚根的i小于0.1，则判定为方程的一根吧。。。
        i_value=sqrt(3.0)/2*(Y1_value-Y2_value)/(3*a);
        if (fabs(i_value)<1e-1)
        {
            X123.push_back((-b+0.5*(Y1_value+Y2_value))/(3*a));
        }
    }
    else if (f<-1e-6)   //公式4
    {
        double T=(2*A*b-3*a*B)/(2*A*sqrt(A));
        double S=acos(T);
        X123.push_back((-b-2*sqrt(A)*cos(S/3))/(3*a));
        X123.push_back((-b+sqrt(A)*(cos(S/3)+sqrt(3.0)*sin(S/3)))/(3*a));
        X123.push_back((-b+sqrt(A)*(cos(S/3)-sqrt(3.0)*sin(S/3)))/(3*a));
    }
}

void MenuWindow::threadStartSlots(){
    ////qDebug()<<"asdasd";
    //StartThread();
    thread->start();
}
void MenuWindow::threadStopSlot(){
    ////qDebug()<<"asdas";
    //StopThread();
    thread->exit();
    thread->wait();
}

void MenuWindow::molecularPumpDataDeal( QString reviceData,SerialPortData type){
    //    switch (reviceData.mid(5,3)) {
    //    case "398":
    //        break;

    //    }
    QString data = reviceData.mid(5,3);
    // //qDebug()<<data;
    if(data=="398"){
        //转速
        QString rspeed=reviceData.mid(10,6);
        ////qDebug()<<"转速："<<rspeed;
        MenuWindowUI->line_pump_speed->setText(spdDeleteZero(rspeed));
    }else if(data=="310"){
        //电流
        QString current=reviceData.mid(10,6);
        MenuWindowUI->line_pump_current->setText(currentDeleteZero(current));
    }else if (data =="313") {
        //电压
        QString  voltage=reviceData.mid(10,6);
        MenuWindowUI->line_pump_voltage->setText(voltageDeleteZero(voltage));
    }else if (data =="326") {
        //温度
        QString electemperature=reviceData.mid(10,6);
        MenuWindowUI->line_pump_controller_temperature->setText(tempDeleteZero(electemperature));
    }
}
void MenuWindow::GUIDataDeal(QString data,SerialPortData type){
    //MenuWindowUI->line_vacuum->setText(data.mid(7,7));
   //MenuWindowUI->btn_pressure_show->setText(data.mid(7,7));

    //    if(data.mid(7,7).toDouble()<=2E-5){

    //        QByteArray data =protocol->TDESIInstruction(TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_ADDRESS_CODE::ESI_ADDRESS_CODE,SELF_TURN_ON_PROTOCOL_CODE::VACUUM_LIGHTING,1,SELF_TURN_ON_PROTOCOL_CODE::SELF_TURN_ON_COMMAND_CODE_DATA_AREA_CODE::ON);
    //        //QString result = sendVTDESIMessage(data);
    //        vacTimer->stop();
    //        pushQueue(data,SerialPortData::EsiData);
    //        vacTimer->start();
    //        MenuWindowUI->btn_pressure_show->setStyleSheet(mainPushButtonSheef);
    //        if(!toolButton_high_voltage_open_flag&&!toolButton_24_voltage_open_flag&&!toolButton_48_voltage_open_flag)
    //        {
    //            QByteArray data =protocol->TDESIInstruction(TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_ADDRESS_CODE::ESI_ADDRESS_CODE,SELF_TURN_ON_PROTOCOL_CODE::SYSTEM_LIGHTING,1,SELF_TURN_ON_PROTOCOL_CODE::SELF_TURN_ON_COMMAND_CODE_DATA_AREA_CODE::ON);
    //            // QString   result = sendVTDESIMessage(data);
    //            vacTimer->stop();
    //            pushQueue(data,SerialPortData::EsiData);
    //            vacTimer->start();
    //        }
    //    }
    //    else{
    //        QByteArray data =protocol->TDESIInstruction(TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_ADDRESS_CODE::ESI_ADDRESS_CODE,SELF_TURN_ON_PROTOCOL_CODE::VACUUM_LIGHTING,1,SELF_TURN_ON_PROTOCOL_CODE::SELF_TURN_ON_COMMAND_CODE_DATA_AREA_CODE::OFF);
    //        // QString result = sendVTDESIMessage(data);
    //        vacTimer->stop();
    //        pushQueue(data,SerialPortData::EsiData);
    //        vacTimer->start();
    //        // MenuWindowUI->btn_pressure_show->setStyleSheet(mainPushButtonAfterSheef);
    //    }
    //    if(toolButton_high_voltage_open_flag||toolButton_24_voltage_open_flag||toolButton_48_voltage_open_flag||data.mid(7,7).toDouble()>2E-5)
    //    {
    //        QByteArray data =protocol->TDESIInstruction(TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_ADDRESS_CODE::ESI_ADDRESS_CODE,SELF_TURN_ON_PROTOCOL_CODE::SYSTEM_LIGHTING,1,SELF_TURN_ON_PROTOCOL_CODE::SELF_TURN_ON_COMMAND_CODE_DATA_AREA_CODE::OFF);
    //        // QString   result = sendVTDESIMessage(data);
    //        vacTimer->stop();
    //        pushQueue(data,SerialPortData::EsiData);
    //        vacTimer->start();
    //    }


}
void MenuWindow::ESIDataDeal(QString data,SerialPortData type){


    // qDebug()<<"485::"<<data;
    QString actionCode = data.mid(4,2);
    int actionCodeByte = bytesToInt(QByteArray::fromHex(actionCode.toLatin1().data()));
    QString codeLength = data.mid(6,2);
    int codeLengthByte = bytesToInt(QByteArray::fromHex(codeLength.toLatin1().data()));
    switch (actionCodeByte) {
    case TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE::INDICATOR_LIGHT:
    { QString dataArea = data.mid(8,codeLengthByte*2);
        int result = bytesToInt(QByteArray::fromHex(dataArea.toLatin1().data()));
        if(result==TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::SUCCESS){//24V
            QString log = "the camera light is turned on sucessfully";
            MenuWindowUI->textBrowser_log->append(log);

        }
        ////qDebug()<<"成功";
        else if (result==TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::FAIL) {
            //qDebug()<<"失败";
            QString log = "the camera light is turned off sucessfully";
            MenuWindowUI->textBrowser_log->append(log);
        }
    }
        break;
    case TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE::TEMPERATURE_ONE_SET:{
        QString  dataArea = data.mid(8,codeLengthByte*2);
        int  result = bytesToInt(QByteArray::fromHex(dataArea.toLatin1().data()));
        if(result==TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::SUCCESS)
        {
            QString log = "temperture set sucessfully";
            MenuWindowUI->textBrowser_log->append(log);
        }
        else if (result==TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::FAIL) {
            QString log = "temperture set unsucessfully";
            MenuWindowUI->textBrowser_log->append(log);
        }
    }
        break;

    case TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE::TEMPERATURE_ONE_MEASUREMENT:{
        QString  dataArea = data.mid(8,codeLengthByte*2);

        bool ok;

        int  result = dataArea.toInt(&ok,16);

        MenuWindowUI->spinBox__temperature_set_return->setValue(result*1.00/100);
        if(result/100<=250)
            MenuWindowUI->btn_temp_show->setStyleSheet(mainPushButtonAfterSheef);
        else
            MenuWindowUI->btn_temp_show->setStyleSheet(mainPushButtonSheef);


        MenuWindowUI->btn_temp_show->setText(QString::number(result*1.0/100,'f',2));

    }
        break;

    case TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE::SCOPE_OF_PWM:{
        QString  dataArea = data.mid(8,codeLengthByte*2);
        int  result = bytesToInt(QByteArray::fromHex(dataArea.toLatin1().data()));
        if(result==TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::SUCCESS)
        {
            QString log = "["+QDateTime::currentDateTime().toString("yyyy:MM:dd hh:mm:ss:zzz")+"] "+"pwm set sucessfully";
            MenuWindowUI->textBrowser_log->append(log);
        }
        else if (result==TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::FAIL) {
            QString log = "["+QDateTime::currentDateTime().toString("yyyy:MM:dd hh:mm:ss:zzz")+"] "+"pwm set unsucessfully";
            MenuWindowUI->textBrowser_log->append(log);
        }

    }
        break;
    case TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE::HIGH_VOLTAGE_SET:{
        QString  dataArea = data.mid(8,codeLengthByte*2);
        bool ok;
        int result = dataArea.toInt(&ok,16);

        if(result==TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::SUCCESS)
        {
            QString log = "["+QDateTime::currentDateTime().toString("yyyy:MM:dd hh:mm:ss:zzz")+"] "+"high voltage set sucessfully";
            MenuWindowUI->textBrowser_log->append(log);
        }
        else if (result==TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::FAIL) {
            QString log = "["+QDateTime::currentDateTime().toString("yyyy:MM:dd hh:mm:ss:zzz")+"] "+"high voltage set unsucessfully";
            MenuWindowUI->textBrowser_log->append(log);
        }


    }
        break;
    case TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE::HIGH_VOLTAGE_READING:{
        QString  dataArea = data.mid(8,codeLengthByte*2);
        bool ok;

        int  result = dataArea.toInt(&ok,16);
        ////qDebug()<<"gaoya"<<result;
        MenuWindowUI->spinBox_high_voltage_return->setValue(result*1.0/10);

    }
        break;
    case TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE::HIGH_CURRENT_READING:{
        QString  dataArea = data.mid(8,codeLengthByte*2);
        int  result = bytesToInt(QByteArray::fromHex(dataArea.toLatin1().data()));
        //  //qDebug()<<result;

    }
        break;
    case TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE::SCOPE_OF_PWM_CLOSE:{
        QString  dataArea = data.mid(8,codeLengthByte*2);
        int  result = bytesToInt(QByteArray::fromHex(dataArea.toLatin1().data()));
        if(result==TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::SUCCESS)
        {
            QString log = "["+QDateTime::currentDateTime().toString("yyyy:MM:dd hh:mm:ss:zzz")+"] "+"pwm is closed sucessfully";
            MenuWindowUI->textBrowser_log->append(log);
        }
        else if (result==TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::FAIL) {
            QString log = "["+QDateTime::currentDateTime().toString("yyyy:MM:dd hh:mm:ss:zzz")+"] "+"pwm is closed unsucessfully";
            MenuWindowUI->textBrowser_log->append(log);
        }

    }
        break;
    case TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE::TEMPERATUR_ONE_CLOSE:{
        QString  dataArea = data.mid(8,codeLengthByte*2);
        int  result = bytesToInt(QByteArray::fromHex(dataArea.toLatin1().data()));
        if(result==TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::SUCCESS){
            QString log = "["+QDateTime::currentDateTime().toString("yyyy:MM:dd hh:mm:ss:zzz")+"] "+"heating off sucessfully";
            MenuWindowUI->textBrowser_log->append(log);
        }

        else if (result==TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::FAIL) {
            ////qDebug()<<"失败";
            QString log = "["+QDateTime::currentDateTime().toString("yyyy:MM:dd hh:mm:ss:zzz")+"] "+"heating off unsucessfully";
            MenuWindowUI->textBrowser_log->append(log);
        }

    }
        break;
    case TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE::INJECT_SAMPLE_LIGHTING:{
        QString  dataArea = data.mid(8,codeLengthByte*2);
        int  result = bytesToInt(QByteArray::fromHex(dataArea.toLatin1().data()));
        if(result==TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::SUCCESS)
        {
            QString log = "["+QDateTime::currentDateTime().toString("yyyy:MM:dd hh:mm:ss:zzz")+"] "+"the injection light is turned  sucessfully";
            MenuWindowUI->textBrowser_log->append(log);
        }
        else if (result==TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::FAIL) {
            QString log = "["+QDateTime::currentDateTime().toString("yyyy:MM:dd hh:mm:ss:zzz")+"] "+"the injection light is turned  sucessfully";
            MenuWindowUI->textBrowser_log->append(log);
        }

    }
        break;
    case TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE::TEMPERATURE_TWO_SET:{
        QString  dataArea = data.mid(8,codeLengthByte*2);
        int  result = bytesToInt(QByteArray::fromHex(dataArea.toLatin1().data()));
        if(result==TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::SUCCESS)
            //qDebug()<<"成功";
        {}
        else if (result==TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::FAIL) {
            //qDebug()<<"失败";
        }

    }
        break;
    case TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE::TEMPERATURE_THREE_SET:{
        QString  dataArea = data.mid(8,codeLengthByte*2);
        int  result = bytesToInt(QByteArray::fromHex(dataArea.toLatin1().data()));
        if(result==TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::SUCCESS)
            //qDebug()<<"成功";
        {}
        else if (result==TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::FAIL) {
            //qDebug()<<"失败";
        }

    }
        break;
    case TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE::TEMPERATURE_FOUR_SET:{
        QString  dataArea = data.mid(8,codeLengthByte*2);
        int  result = bytesToInt(QByteArray::fromHex(dataArea.toLatin1().data()));
        if(result==TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::SUCCESS)
            //qDebug()<<"成功";
        {}
        else if (result==TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::FAIL) {
            //qDebug()<<"失败";
        }

    }
        break;

    case TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE::DIAPHRAGM_PUMP_POWER:{
        QString  dataArea = data.mid(8,codeLengthByte*2);
        int  result = bytesToInt(QByteArray::fromHex(dataArea.toLatin1().data()));
        if(result==TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::SUCCESS)
        {
            QString log = "["+QDateTime::currentDateTime().toString("yyyy:MM:dd hh:mm:ss:zzz")+"] "+"the diaphragm pump is turned on sucessfully";
            MenuWindowUI->textBrowser_log->append(log);
        }
        else if (result==TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::FAIL) {
            QString log = "["+QDateTime::currentDateTime().toString("yyyy:MM:dd hh:mm:ss:zzz")+"] "+"the diaphragm pump is turned on unsucessfully";
            MenuWindowUI->textBrowser_log->append(log);
        }

    }
        break;

    case TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE::CONTROL_TWO:{
        QString  dataArea = data.mid(8,codeLengthByte*2);
        int  result = bytesToInt(QByteArray::fromHex(dataArea.toLatin1().data()));
        if(result==TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::SUCCESS)
            //qDebug()<<"成功";
        {}
        else if (result==TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::FAIL) {
            //qDebug()<<"失败";
        }

    }
        break;

    case TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE::CONTROL_THREE:{
        QString  dataArea = data.mid(8,codeLengthByte*2);
        int  result = bytesToInt(QByteArray::fromHex(dataArea.toLatin1().data()));
        if(result==TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::SUCCESS)
            //qDebug()<<"成功";
        {}
        else if (result==TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::FAIL) {
            //qDebug()<<"失败";
        }

    }
        break;

    case TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE::CONTROL_FOUR:{
        QString  dataArea = data.mid(8,codeLengthByte*2);
        int  result = bytesToInt(QByteArray::fromHex(dataArea.toLatin1().data()));
        if(result==TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::SUCCESS)
            //qDebug()<<"成功";
        {}
        else if (result==TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::FAIL) {
            //qDebug()<<"失败";
        }

    }
        break;
    case TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE::TEMPERATURE_TWO_MEASUREMENT:{
        QString  dataArea = data.mid(8,codeLengthByte*2);

        bool ok;

        int  result = dataArea.toInt(&ok,16);

        MenuWindowUI->line_ion_trap_temp_return->setText(QString::number(result*1.0/100,'f',2));

    }
        break;
    case TD_ESI_PROTOCOL_CODE::INDICATOR_LIGHT_STATUS:{
        QString  dataArea = data.mid(8,codeLengthByte*2);
        int  result = bytesToInt(QByteArray::fromHex(dataArea.toLatin1().data()));
        if(result==TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::OPEN)
        {
            controlPancelWindow->findChild<QToolButton *>("toolButton_camera_lighting")->setIcon(QPixmap(":/images/camera_lighting_open.png"));
            toolButton_camera_lighting_open_flag = false;
        }
        else if (result==TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::CLOSE) {
            controlPancelWindow->findChild<QToolButton *>("toolButton_camera_lighting")->setIcon(QPixmap(":/images/camera_lighting_close.png"));
            toolButton_camera_lighting_open_flag = true;
        }

    }
        break;
    case TD_ESI_PROTOCOL_CODE::INJECT_SAMPLE_LIGHTING_STATUS:{
        QString  dataArea = data.mid(8,codeLengthByte*2);
        int  result = bytesToInt(QByteArray::fromHex(dataArea.toLatin1().data()));
        if(result==TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::OPEN)
            //qDebug()<<"成功";
        {

            //controlPancelWindow->findChild<QToolButton *>("toolButton_inject_sample")->setIcon(QPixmap(":/images/lighting_open.png"));
           // toolButton_inject_sample_open_flag = false;
        }
        else if (result==TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::CLOSE) {
            //controlPancelWindow->findChild<QToolButton *>("toolButton_inject_sample")->setIcon(QPixmap(":/images/lighting.png"));
            //toolButton_inject_sample_open_flag = true;
        }

    }
        break;
    case TD_ESI_PROTOCOL_CODE::DIAPHRAGM_PUMP_POWER_STATUS:{
        QString  dataArea = data.mid(8,codeLengthByte*2);
        int  result = bytesToInt(QByteArray::fromHex(dataArea.toLatin1().data()));
        qDebug()<<result;
        if(result==TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::OPEN)
        {
            controlPancelWindow->findChild<QToolButton *>("toolButton_pump")->setIcon(QPixmap(":/images/pump_open.png"));
            dipaphragm_pump_open_flag = false;
        }
        else if (result==TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_DATA_AREA_CODE::CLOSE) {
            controlPancelWindow->findChild<QToolButton *>("toolButton_pump")->setIcon(QPixmap(":/images/gemo.png"));
            dipaphragm_pump_open_flag = true;
        }

    }
        break;
    }
}
int waste_times_even = 0;
int  clean_times_even = 0;
void MenuWindow::injectDataDeal(QString data,SerialPortData type){

    // //qDebug()<<data;
    QString flag = data.mid(4,2);

    QString result = data.mid(6);
    int length = result.length();
    QString volume = result.left(length-6);

    if(volume!=""){
        QByteArray array = QByteArray::fromHex(volume.toLatin1());
        double  v=array.toDouble()/1920;

        QObject *pRoot = (QObject*)quickProgressBar->rootObject();
        // QVariant msg = 0.08;  // 方法参数
        QVariant restVolume = QString::number(v*1.0/MenuWindowUI->spinBox_extract_volume->text().toDouble(),'f',4).toDouble();
        //qDebug()<<"注射泵"<<restVolume;
        QMetaObject::invokeMethod(pRoot, "setProgress",
                                  Q_ARG(QVariant, restVolume));
        //qDebug()<<"rest:"<<restVolume;

        bool pushPump = true;
        if(clean_inject_pump_flag){
            if(waste_times_even<waste_times){
                if(v<1e-6){
                    vacTimer->stop();

                    double speed = 200;
                    double volume = 100;
                    int b = static_cast<int>(1920 * volume);
                    int a = static_cast<int>(32 * speed);
                    QString refill = "/1V" + QString::number(a) + "I1A" + QString::number(b) + "R\r\n";

                    QByteArray data = refill.toLatin1();
                    //qDebug()<<"chouqu:"<<data;
                    pushQueue(data,SerialPortData::InjectPumpData);
                    vacTimer->start();

                }else{
                    if(pushPump){
                        QString end_point = "/1V20000I3A0R\r\n";
                        QByteArray data = end_point.toLatin1();
                        pushQueue(data,SerialPortData::InjectPumpData);
                        pushPump = false;
                    }
                }
                //qDebug()<<"剩余:"<<fabs(MenuWindowUI->spinBox_extract_volume->text().toDouble()-v);
                /// qDebug()<<v;
                if(fabs(MenuWindowUI->spinBox_extract_volume->text().toDouble()-v)<1e-6){
                    vacTimer->stop();

                    QString end_point = "/1V20000I3A0R\r\n";
                    QByteArray data = end_point.toLatin1();
                    pushQueue(data,SerialPortData::InjectPumpData);
                    vacTimer->start();
                    waste_times_even++;
                    systemConfigurationWindow->findChild<QLabel *>("label_5")->setText("废液次数："+QString::number(waste_times_even));
                }

            }
            if(waste_times_even == waste_times){
                if(clean_times_even<clean_times){
                    if(v<1e-6){
                        vacTimer->stop();

                        double speed = 200;
                        double volume = 100;
                        int b = static_cast<int>(1920 * volume);
                        int a = static_cast<int>(32 * speed);
                        QString refill = "/1V" + QString::number(a) + "I1A" + QString::number(b) + "R\r\n";

                        QByteArray data = refill.toLatin1();
                        //qDebug()<<"chouqu:"<<data;
                        pushQueue(data,SerialPortData::InjectPumpData);
                        vacTimer->start();

                    }
                    if(MenuWindowUI->spinBox_extract_volume->text().toDouble()-v<1e-6){

                        vacTimer->stop();

                        double speed = perform_rate;
                        int a = static_cast<int>(32 * speed);
                        QString start = "/1V" + QString::number(a) + "I2A0R\r\n";
                        QByteArray data = start.toLatin1();
                        pushQueue(data,SerialPortData::InjectPumpData);

                        vacTimer->start();
                        clean_times_even++;
                        systemConfigurationWindow->findChild<QLabel *>("label_5")->setText("清洗次数："+QString::number(clean_times_even));
                    }
                }

            }

        }
    }

}
QVariant restVolume;
void MenuWindow::injectataVolumeDeal(QString data,SerialPortData type){
    QString result = data.mid(6);
    int length = result.length();
    QString volume = result.left(length-6);


    QByteArray array = QByteArray::fromHex(volume.toLatin1());
    double  v=array.toDouble()/1920;
    ////qDebug()<<"注射泵"<<v;
    QObject *pRoot = (QObject*)quickProgressBar->rootObject();
    // QVariant msg = 0.08;  // 方法参数
    restVolume = QString::number(v*1.0/MenuWindowUI->spinBox_extract_volume->text().toDouble(),'f',4).toDouble();
    //qDebug()<<"rest:"<<restVolume;
    QMetaObject::invokeMethod(pRoot, "setProgress",
                              Q_ARG(QVariant, restVolume));
    if(clean_inject_pump_flag){
        if(waste_times_even<waste_times){
            if(v<1e-6){
                vacTimer->stop();

                double speed = 200;
                double volume = 100;
                int b = static_cast<int>(1920 * volume);
                int a = static_cast<int>(32 * speed);
                QString refill = "/1V" + QString::number(a) + "I1A" + QString::number(b) + "R\r\n";

                QByteArray data = refill.toLatin1();
                //qDebug()<<"chouqu:"<<data;
                pushQueue(data,SerialPortData::InjectPumpData);
                vacTimer->start();

            }
            //qDebug()<<"剩余:"<<fabs(MenuWindowUI->spinBox_extract_volume->text().toDouble()-v);
            // qDebug()<<v;
            if(fabs(MenuWindowUI->spinBox_extract_volume->text().toDouble()-v)<1e-6){
                vacTimer->stop();

                QString end_point = "/1V20000I3A0R\r\n";
                QByteArray data = end_point.toLatin1();
                pushQueue(data,SerialPortData::InjectPumpData);
                vacTimer->start();
                waste_times_even++;
                systemConfigurationWindow->findChild<QLabel *>("label_5")->setText("废液次数："+QString::number(waste_times_even));

            }

        }
        if(waste_times_even == waste_times){
            if(clean_times_even<clean_times){
                if(v<1e-6){
                    vacTimer->stop();

                    double speed = 200;
                    double volume = 100;
                    int b = static_cast<int>(1920 * volume);
                    int a = static_cast<int>(32 * speed);
                    QString refill = "/1V" + QString::number(a) + "I1A" + QString::number(b) + "R\r\n";

                    QByteArray data = refill.toLatin1();
                    //qDebug()<<"chouqu:"<<data;
                    pushQueue(data,SerialPortData::InjectPumpData);
                    vacTimer->start();

                }
                if(MenuWindowUI->spinBox_extract_volume->text().toDouble()-v<1e-6){

                    vacTimer->stop();

                    double speed = perform_rate;
                    int a = static_cast<int>(32 * speed);
                    QString start = "/1V" + QString::number(a) + "I2A0R\r\n";
                    QByteArray data = start.toLatin1();
                    pushQueue(data,SerialPortData::InjectPumpData);

                    vacTimer->start();
                    clean_times_even++;
                    systemConfigurationWindow->findChild<QLabel *>("label_5")->setText("清洗次数："+QString::number(clean_times_even));
                }

            }
        }


    }
}

int MenuWindow::bytesToInt(QByteArray bytes) {
    int addr = bytes[0] & 0x00000000000000FF;
    addr |= ((bytes[1] << 8) & 0x000000000000FF00);
    addr |= ((bytes[2] << 16) & 0x0000000000FF0000);
    addr |= ((bytes[3] << 24) & 0x00000000FF000000);
    addr |= ((bytes[4] << 32) & 0x000000FF00000000);
    addr |= ((bytes[5] << 40) & 0x0000FF0000000000);
    addr |= ((bytes[6] << 48) & 0x00FF000000000000);
    addr |= ((bytes[7] << 56) & 0xFF00000000000000);
    return addr;
}

void MenuWindow::lockWaveWindowShow(){

    if(lockWavaWindow==nullptr)
    {
        lockWavaWindow = new LockWaveWindow(this);
        connect(lockWavaWindow->findChild<QCheckBox *>("checkBox_lock"),&QCheckBox::stateChanged,this,&MenuWindow::spectrometry_lock);
        lockWavaWindow->show();
    }else {
        lockWavaWindow->showNormal();
    }

}

bool toggleButton = false;
void MenuWindow::SaveToggleWindow(){

    if(toggleButton){
        waveFormWindow->saveButton->setStyleSheet("background:#FFFFFF;");
        toggleButton = false;
        pushDisk=false;
        //qDebug()<<"sadsa";
    }
    else {
        waveFormWindow->saveButton->setStyleSheet("background:#FFCC66;");
        toggleButton = true;
        pushDisk=true;
    }

}

void MenuWindow::permissionWindowShow(){
    //qDebug()<<"asdas";
    if(permissionWindow==nullptr){
        permissionWindow = new PermissionWindow(this);
        //connect(permissionWindow->toolButton,&Q::)
        connect(permissionWindow->toolButton,&QPushButton::clicked, permissionWindow, &PermissionWindow::saveTreeItemSelected);
        permissionWindow->show();
    }
    else {
        permissionWindow->showNormal();
    }
}

void MenuWindow::spectrometry_lock(int state){

    if(state==2)
    {
        lockWavaWindow->findChild<QSpinBox *>("spinBox_spectrometry_x_from")->setEnabled(false);
        //MenuWindowUI->line_spectrometry_x_to->setStyleSheet("#line_spectrometry_x_to{background:#E0E0E0}");
        lockWavaWindow->findChild<QSpinBox *>("spinBox_spectrometry_x_to")->setEnabled(false);
        // MenuWindowUI->line_spectrometry_x_from->setStyleSheet("#line_spectrometry_x_from{background:#E0E0E0}");
        waveFormWindow->m_customPlot->xAxis->setRange(lockWavaWindow->findChild<QSpinBox *>("spinBox_spectrometry_x_from")->text().toDouble(),lockWavaWindow->findChild<QSpinBox *>("spinBox_spectrometry_x_to")->text().toDouble());

        lockWavaWindow->findChild<QSpinBox *>("spinBox_spectrometry_y_from")->setEnabled(false);
        //MenuWindowUI->line_spectrometry_x_to->setStyleSheet("#line_spectrometry_x_to{background:#E0E0E0}");
        lockWavaWindow->findChild<QSpinBox *>("spinBox_spectrometry_y_to")->setEnabled(false);
        // MenuWindowUI->line_spectrometry_x_from->setStyleSheet("#line_spectrometry_x_from{background:#E0E0E0}");
        waveFormWindow->m_customPlot->yAxis->setRange(lockWavaWindow->findChild<QSpinBox *>("spinBox_spectrometry_y_from")->text().toDouble(),lockWavaWindow->findChild<QSpinBox *>("spinBox_spectrometry_y_to")->text().toDouble());
        // slidingWindow.m_customPlot->yAxis->setRange(MenuWindowUI->line_spectrometry_y_to->text().toDouble(),MenuWindowUI->line_spectrometry_y_from->text().toDouble());
        //  slidingWindow.m_customPlot->replot();
        waveFormWindow->m_customPlot->replot();
        enlarge_and_lessen_flag = false;
    }else {
        //        MenuWindowUI->line_spectrometry_x_to->setEnabled(true);
        //        MenuWindowUI->line_spectrometry_x_to->setStyleSheet("#line_spectrometry_x_to{background:#FFFFFF}");
        //        MenuWindowUI->line_spectrometry_x_from->setEnabled(true);
        //        MenuWindowUI->line_spectrometry_x_from->setStyleSheet("#line_spectrometry_x_from{background:#FFFFFF}");
        //        MenuWindowUI->line_spectrometry_y_to->setEnabled(true);
        //        MenuWindowUI->line_spectrometry_y_to->setStyleSheet("#line_spectrometry_y_to{background:#FFFFFF}");
        //        MenuWindowUI->line_spectrometry_y_from->setEnabled(true);
        //        MenuWindowUI->line_spectrometry_y_from->setStyleSheet("#line_spectrometry_y_from{background:#FFFFFF}");
        //        waveFormWindow->m_customPlot->xAxis->setRange(MenuWindowUI->spinBox_low_mass_number->text().toDouble(),MenuWindowUI->spinBox_hight_mass_number->text().toDouble());
        //        waveFormWindow->m_customPlot->yAxis->setRange(0,(protocol->max_vollage_copy)*1.3);
        //        slidingWindow.m_customPlot->yAxis->setRange(MenuWindowUI->line_spectrometry_y_to->text().toDouble(),MenuWindowUI->line_spectrometry_y_from->text().toDouble());
        //        waveFormWindow->m_customPlot->replot();
        //        slidingWindow.m_customPlot->replot();
        //        enlarge_and_lessen_flag = true;

        lockWavaWindow->findChild<QSpinBox *>("spinBox_spectrometry_x_from")->setEnabled(true);
        //MenuWindowUI->line_spectrometry_x_to->setStyleSheet("#line_spectrometry_x_to{background:#E0E0E0}");
        lockWavaWindow->findChild<QSpinBox *>("spinBox_spectrometry_x_to")->setEnabled(true);
        // MenuWindowUI->line_spectrometry_x_from->setStyleSheet("#line_spectrometry_x_from{background:#E0E0E0}");
        waveFormWindow->m_customPlot->xAxis->setRange(MenuWindowUI->spinBox_low_mass_number->text().toDouble(),MenuWindowUI->spinBox_hight_mass_number->text().toDouble());

        lockWavaWindow->findChild<QSpinBox *>("spinBox_spectrometry_y_from")->setEnabled(true);
        //MenuWindowUI->line_spectrometry_x_to->setStyleSheet("#line_spectrometry_x_to{background:#E0E0E0}");
        lockWavaWindow->findChild<QSpinBox *>("spinBox_spectrometry_y_to")->setEnabled(true);
        // MenuWindowUI->line_spectrometry_x_from->setStyleSheet("#line_spectrometry_x_from{background:#E0E0E0}");
        waveFormWindow->m_customPlot->yAxis->setRange(0,(protocol->max_vollage_copy)*1.3);
        // slidingWindow.m_customPlot->yAxis->setRange(MenuWindowUI->line_spectrometry_y_to->text().toDouble(),MenuWindowUI->line_spectrometry_y_from->text().toDouble());
        //  slidingWindow.m_customPlot->replot();
        waveFormWindow->m_customPlot->replot();
    }

}
void MenuWindow::closeEvent(QCloseEvent *event) //根据不同的需求进行添加，比如：
{
    if(MenuWindowUI->btn_start->text()=="实验结束"){
        QMessageBox::information(this,"提示","关闭软件前，结束实验");
        event->ignore();
    }
}


void MenuWindow::insertToDBWindowShow(){

    if(sampleInfoInsertWindow==nullptr){
        sampleInfoInsertWindow = new SampleInfoInsertWindow();
        connect(sampleInfoInsertWindow->findChild<QPushButton *>("btn_sample_insert_ok"),&QPushButton::clicked,this,&MenuWindow::getInsertSampleInfo);
        sampleInfoInsertWindow->show();
    }else {
        sampleInfoInsertWindow->showNormal();
    }
}
void MenuWindow::getInsertSampleInfo(){
    QString sampleName = sampleInfoInsertWindow->findChild<QLineEdit *>("line_sample_name")->text();
    QString sample_MS = sampleInfoInsertWindow->findChild<QLineEdit *>("line_sample_ms")->text();

    qDebug()<<sampleName<<","<<sample_MS;

    QDir dir;
    if(!dir.exists("mapper")){
        dir.mkdir("mapper");
    }
    QFile file(QDir::currentPath()+"/mapper/sampleFactory.json");
    if(file.open(QIODevice::ReadWrite)){
        QByteArray allData = file.readAll();
        QJsonParseError jsonError;
        QJsonDocument jsonDoc(QJsonDocument::fromJson(allData,&jsonError));
        //        if(jsonError.error != QJsonParseError::NoError){
        //            //qDebug()<<"json Error";
        //            return;
        //        }
        QJsonArray rootArray = jsonDoc.array();

        file.resize(0);
        QJsonObject jsonObject;
        jsonObject.insert("id", rootArray.size()+1);
        jsonObject.insert("sample_name", sampleName);
        jsonObject.insert("sample_ms", sample_MS);
        rootArray.append(jsonObject);

        // 使用QJsonDocument设置该json对象
        QJsonDocument jsonDocument;
        jsonDocument.setArray(rootArray);

        // 将json以文本形式写入文件并关闭文件。
        // QJsonDocument jsonDoc
        file.write(jsonDocument.toJson());
        file.close();
    }
    QMessageBox msg;
    msg.setText("添加成功");
    msg.exec();
    return;

}

void MenuWindow::reciveNoTestSignal(QList<double> noTestSignal){

    // qDebug()<<"sadsa";

    /// signalNameList.clear();
    QFile file(QDir::currentPath()+"/mapper/sampleFactory.json");
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
        double sample_ms = rootArray[i].toObject().value("sample_ms").toString().toDouble();

        QString sample_name = rootArray[i].toObject().value("sample_name").toString();

        //qDebug()<<rootArray.size()<<"---"<<noTestSignal.size();
        for(int j = 0;j <noTestSignal.size();j++){
            // int id = rootArray[i].toObject().value("id").toInt();
            //qDebug()<<noTestSignal.at(j)<<"----"<<sample_ms;
            if((noTestSignal.at(j)>=(sample_ms-0.5))&&(noTestSignal.at(j)<(sample_ms+0.5))){
                qDebug()<<"asdsadad";
                signalNameList.append(sample_name);
            }

        }

    }
    //    MenuWindowUI->textBrowser_result->clear();
    //    for(int i=0;i<signalNameList.size();i++){
    //        MenuWindowUI->textBrowser_result->append(signalNameList.at(i));
    //    }

}
void MenuWindow::multiplier_tube_voltage_method(int multiplier_tube_voltage,double result,QByteArray stateArray,QByteArray systemCheck){
    //MenuWindowUI->label_multiplier_tube_voltage->setText(QString::number(multiplier_tube_voltage));
    double pressure = pow(10,(result-6.143)/1.286);
    MenuWindowUI->btn_pressure_show->setText(QString::number(pressure,'e',2).toUpper());
    //MenuWindowUI->line_vacuum->setText(QString::number(multiplier_tube_voltage));
    //line_vacuum
    //qDebug()<<QString::number(pressure,'e',3).toUpper();
    if(systemCheckWindow!=nullptr){
        if(systemCheck.at(0)==0){
            systemCheckWindow->findChild<QLabel *>("label_6")->setText("正常");
        }else {
            systemCheckWindow->findChild<QLabel *>("label_6")->setText("存在错误");
        }
//        if(pressure<6E-5){
//            systemCheckWindow->findChild<QLabel *>("label_5")->setText("正常");
//        }else {
//            systemCheckWindow->findChild<QLabel *>("label_5")->setText("存在错误");
//        }

//        if(pressure<6E-5&&systemCheck.at(0)==0){
//            systemCheckWindow->findChild<QLabel *>("label_2")->setText("正常");
//        }else {
//            systemCheckWindow->findChild<QLabel *>("label_2")->setText("存在错误");
//        }
    }

    if(controlPancelWindow!=nullptr){
        qDebug()<<stateArray.at(0);
        if(stateArray.at(0)==0x01){
            toolButton_high_voltage_open_flag=true;
            controlPancelWindow->findChild<QToolButton *>("toolButton_high_voltage")->setIcon(QPixmap(":/images/high_voltage_open.png"));
        }
        else {
            toolButton_high_voltage_open_flag=false;
            controlPancelWindow->findChild<QToolButton *>("toolButton_high_voltage")->setIcon(QPixmap(":/images/high_voltage_close.png"));
        }
        if(stateArray.at(2)==0x01){
            toolButton_pinch_valve_open_flag = true;
            controlPancelWindow->findChild<QToolButton *>("toolButton_pinch_valve")->setIcon(QPixmap(":/images/valve_open.png"));
        }
        else {
            toolButton_pinch_valve_open_flag = false;
            controlPancelWindow->findChild<QToolButton *>("toolButton_pinch_valve")->setIcon(QPixmap(":/images/valve_close.png"));
        }
        if(stateArray.at(3)==0x01){
            toolButton_24_voltage_open_flag = true;
            controlPancelWindow->findChild<QToolButton *>("toolButton_24_voltage")->setIcon(QPixmap(":/images/voltage_open.png"));
        }
        else {
            toolButton_24_voltage_open_flag = false;
            controlPancelWindow->findChild<QToolButton *>("toolButton_24_voltage")->setIcon(QPixmap(":/images/voltage_close.png"));
        }
    }



}
void MenuWindow::slot_mouseDoubleClickTip(QMouseEvent *event)
{
    double xx = chromatographicFormWindow->pCustomPlot->xAxis->pixelToCoord(event->x());
    //double yx = chromatographicFormWindow->pCustomPlot->yAxis->pixelToCoord(event->y());
    // pCustomPlot->xAxis->getPartAt(QPoint((int)xx,(int)yx))->setColor(Color::);
    postion= (int)(xx+0.5);
    //qDebug()<<"位置："<<postion;
    QDir *dir = new QDir(QDir::currentPath()+"/spectrumData");
    QStringList filter;
    // filter<<"";
    dir->setNameFilters(filter);
    QFileInfoList fileInfoList = dir->entryInfoList(filter);
    int count = (spectrumDataCount +postion);
    // int diskCount = count-i;
    if(count-i+1>=spectrumDataCount){
        QMessageBox msg;
        msg.setText("该文件未保存");
        msg.exec();
        return;
    }
    QString name = fileInfoList[count-i+1].fileName();
    QString fileName = name;

    QFile file(QDir::currentPath()+"/spectrumData/"+fileName);
    qDebug()<<fileName;

    int length = 0;
    if(file.exists()){
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug()<<"打开成功";
            QString line;
            QTextStream in(&file);  //用文件构造流

            line=in.readLine();//循环读取下行
            while(!line.isNull()||line!="")//字符串有内容
            {
                // qDebug() << line;
                QStringList buff = line.split(",");


                x.resize(++length);
                y.resize(length);
                x.append(buff[0].toDouble());
                y.append(buff[1].toDouble());
                line=in.readLine();//循环读取下行
            }

            waveFormWindow->pGraph->setData(x,y);

            waveFormWindow->m_customPlot->rescaleAxes(true);
            waveFormWindow->m_customPlot->replot();
            x.clear();
            y.clear();

            //qDebug()<<position;

            //    pCustomPlot->xAxis->setSelectedLabelColor(Qt::black);
            //    qDebug()<<"x:"<<xx<<"y:"<<yx;
            //    QString str,strToolTip;
            //    QString qsPoint("X:%1,Y:%2");
            //    qsPoint = qsPoint.arg(xx).arg(yx);
            //    //showTip under the mouse
            //    QToolTip::showText(cursor().pos(), qsPoint);
        }
    }else{
        QMessageBox msg;
        msg.setText("该文件未保存");
        msg.exec();
    }
}


void MenuWindow::create_method(){
    QString filename=QFileDialog::getSaveFileName(this, tr("新建方法"), QDir::currentPath()+"/method/unnamed.mth", tr("Method (*.mth)"));
    qDebug()<<filename;

    if(filename.isEmpty())

        return;

    QFile currentmenthod;
    currentmenthod.setFileName(filename);

    if(!currentmenthod.open(QFile::WriteOnly|QFile::Truncate)) //可以用QIODevice，Truncate表示清空原来的内容

        return;

    currentmenthod.close();



    this->show();




    methodInfoSave(filename);
}
void MenuWindow::methodInfoSave(QString fileName){



    QFile methodContentFile(fileName);
    if(methodContentFile.open(QIODevice::ReadWrite)){

        QJsonObject object;
        object.insert("total_cycle",MenuWindowUI->spinBox_total_cycle->text().toUShort()) ;
        object.insert("rf",MenuWindowUI->spinBox_rf->text().toUShort())  ;
        object.insert("rn",MenuWindowUI->spinBox_rn->text().toUShort());
        object.insert("ion_cool_rf_voltage",MenuWindowUI->spinBox_ion_cool_rf_voltage->text().toUShort());
        object.insert("low_mass_number",MenuWindowUI->spinBox_low_mass_number->text().toUShort()) ;
        object.insert("hight_mass_number",MenuWindowUI->spinBox_hight_mass_number->text().toUShort()) ;
        object.insert("ion_cold_zone_time",MenuWindowUI->spinBox_ion_cold_zone_time->text().toUShort());
        object.insert("rf_scanning_time",MenuWindowUI->spinBox_rf_scanning_time->text().toUShort());
        object.insert("al",MenuWindowUI->spinBox_al->text().toUShort());
        object.insert("ah",MenuWindowUI->spinBox_ah->text().toUShort());
        object.insert("af",MenuWindowUI->spinBox_af->text().toUShort());
        object.insert("clamp_valve_open_time",MenuWindowUI->spinBox_clamp_valve_open_time->text().toUShort());
        //dataSave[14] = 55;
        object.insert("rf_on_time",MenuWindowUI->spinBox_rf_on_time->text().toUShort()) ;
        //    dataSave[16] = MenuWindowUI->spinBox_dc_loading_time->text().toUShort();
        //    dataSave[17] = MenuWindowUI->spinBox_front_cover_electrode->text().toUShort();
        //    dataSave[18] = MenuWindowUI->spinBox_back_cover_electrode->text().toUShort();
        //dataSave[19] = 10;
        //    dataSave[20] = 1;
        //    dataSave[21] = 5000;
        object.insert("clamp_valve_open_times",MenuWindowUI->line_clamp_valve_open_times->text().toUShort());
        object.insert("clamp_valve_open_int",MenuWindowUI->line_clamp_valve_open_int->text().toUShort())  ;
        object.insert("multiplier_tube_voltage",MenuWindowUI->spinBox_multiplier_tube_voltage->text().toUShort());
        object.insert("low_ms_time",MenuWindowUI->line_low_ms_time->text().toUShort());

        //注射泵
        object.insert("extract_speed",MenuWindowUI->spinBox_extract_speed->value());
        object.insert("extract_volume",MenuWindowUI->spinBox_extract_volume->value());
        object.insert("perform_speed",MenuWindowUI->spinBox_perform_speed->value()) ;
        //TD-ESI

        object.insert("temperature_set",MenuWindowUI->spinBox_temperature_set->value());
        object.insert("high_voltage",MenuWindowUI->spinBox_high_voltage->value());
        object.insert("pwm_scope_set",MenuWindowUI->spinBox_pwm_scope_set->value());
        QJsonDocument jsonDocument;
        jsonDocument.setObject(object);

        // 将json以文本形式写入文件并关闭文件。
        // QJsonDocument jsonDoc
        // file.resize(0);
        methodContentFile.write(jsonDocument.toJson());
        methodContentFile.close();
        QMessageBox msg;
        msg.setText("保存成功");
        msg.exec();
        return;

    }

}

void MenuWindow::select_method(){


    QFileDialog *a=new QFileDialog(this);
    a->setDirectory(QDir::currentPath()+"/method/");
    a->setNameFilter("Method(*.mth)");
    \
    QString path;

    if(a->exec()==QDialog::Accepted)
    {

        // qDebug()<<a->selectedFiles()[0];

        path=a->selectedFiles()[0];
        qDebug()<<path;

        //  ChoseMth(path);
        QFile file(path);

        if(file.open(QIODevice::ReadWrite)){
            QByteArray allData = file.readAll();
            QJsonParseError jsonError;
            QJsonDocument jsonDoc(QJsonDocument::fromJson(allData,&jsonError));
            QJsonObject object = jsonDoc.object();
            MenuWindowUI->spinBox_total_cycle->setValue(object.value("total_cycle").toInt());
            MenuWindowUI->spinBox_rf->setValue(object.value("rf").toInt());
            MenuWindowUI->spinBox_rn->setValue(object.value("rn").toInt());
            MenuWindowUI->spinBox_ion_cool_rf_voltage->setValue(object.value("ion_cool_rf_voltage").toInt());
            MenuWindowUI->spinBox_low_mass_number->setValue(object.value("low_mass_number").toInt());
            MenuWindowUI->spinBox_hight_mass_number->setValue(object.value("hight_mass_number").toInt());
            MenuWindowUI->spinBox_ion_cold_zone_time->setValue(object.value("ion_cold_zone_time").toInt());
            MenuWindowUI->spinBox_rf_scanning_time->setValue(object.value("rf_scanning_time").toInt());
            MenuWindowUI->spinBox_al->setValue(object.value("al").toInt());
            MenuWindowUI->spinBox_ah->setValue(object.value("ah").toInt());
            MenuWindowUI->spinBox_af->setValue(object.value("af").toInt());
            MenuWindowUI->spinBox_clamp_valve_open_time->setValue(object.value("clamp_valve_open_time").toInt());
            MenuWindowUI->spinBox_rf_on_time->setValue(object.value("rf_on_time").toInt());
            MenuWindowUI->line_clamp_valve_open_times->setText(QString::number(object.value("clamp_valve_open_times").toInt()));

            MenuWindowUI->line_clamp_valve_open_int->setText(QString::number(object.value("clamp_valve_open_int").toDouble()));
            MenuWindowUI->spinBox_multiplier_tube_voltage->setValue(object.value("multiplier_tube_voltage").toInt());
            MenuWindowUI->line_low_ms_time->setText(QString::number(object.value("low_ms_time").toDouble()));
            MenuWindowUI->spinBox_extract_speed->setValue(object.value("extract_speed").toInt());
            MenuWindowUI->spinBox_extract_volume->setValue(object.value("extract_volume").toInt());
            MenuWindowUI->spinBox_perform_speed->setValue(object.value("perform_speed").toDouble());
            MenuWindowUI->spinBox_temperature_set->setValue(object.value("temperature_set").toInt());
            MenuWindowUI->spinBox_high_voltage->setValue(object.value("high_voltage").toInt());
            MenuWindowUI->spinBox_pwm_scope_set->setValue(object.value("pwm_scope_set").toInt());
        }

    }
}

void MenuWindow::on_btn_ion_trap_temp_clicked()
{
    vacTimer->stop();
    int temperature = MenuWindowUI->line_ion_trap_temp->text().toInt();
    QByteArray data = protocol->TDESIInstruction(TD_ESI_PROTOCOL_CODE::TD_ESI_COMMAND_CODE_ADDRESS_CODE::ESI_ADDRESS_CODE, TD_ESI_PROTOCOL_CODE::TEMPERATURE_TWO_SET,2,temperature);
    pushQueue(data,SerialPortData::EsiData);
    vacTimer->start();
}

void MenuWindow::ms_db_window(){
    if(libraryWindow==nullptr){
        libraryWindow = new LibraryWindow(this);
        libraryWindow->show();


    }else{
        libraryWindow->showNormal();
    }

}


void MenuWindow::inject_pump_auto_clean(){

}

void MenuWindow::system_configuration_window(){

    if(systemConfigurationWindow==nullptr){
        systemConfigurationWindow = new SystemConfigurationWindow(this);
        systemConfigurationWindow->show();
        connect(systemConfigurationWindow->findChild<QPushButton *>("btn_inject_pump_clean_perform"),&QPushButton::clicked, this, &MenuWindow::inject_pump_clean_perform);
connect(systemConfigurationWindow->findChild<QPushButton *>("btn_clean_stop"),&QPushButton::clicked, this, &MenuWindow::inject_pump_clean_stop);

    }
    else{
        systemConfigurationWindow->showNormal();
    }


}



void MenuWindow::inject_pump_clean_perform(){
    clean_times = systemConfigurationWindow->findChild<QLineEdit *>("line_inject_pump_clean_times")->text().toInt();
    waste_times= systemConfigurationWindow->findChild<QLineEdit *>("line_inject_pump_waster_clean_times")->text().toInt();
    perform_rate= systemConfigurationWindow->findChild<QLineEdit *>("line_inject_pump_clean_perform_rate")->text().toInt();

    clean_times_even = 0;
    waste_times_even = 0;
    clean_inject_pump_flag=true;

}


void MenuWindow::clean_inject_pump(){


}

void MenuWindow::slotBtn_chromatographic(){
    qDebug()<<"sdas";
    chromatographicFormWindow->pCustomPlot->xAxis->setRange(0, 10000);
    chromatographicFormWindow->pCustomPlot->yAxis->setRange(0, 100000);
    chromatographicFormWindow->pCustomPlot->replot();
}



void MenuWindow::on_action_report_create_triggered()
{
    chromatographicFormWindow->pCustomPlot->replot();

    chromatographicFormWindow->pCustomPlot->savePng("customPlot.png", 600, 300);

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

    html += "<p>Choromatograms</p>";

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

    QString filepath=QFileDialog::getSaveFileName(this,"生成报告","fdsf","报告文件(*.pdf)");

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

void MenuWindow::on_action_system_check_triggered()
{
    if(systemCheckWindow==nullptr){
        systemCheckWindow = new SystemCheckWindow(this);
        systemCheckWindow->show();
    } else{
        systemCheckWindow->showNormal();
    }
}

void MenuWindow::on_action_qualitative_param_triggered()
{
    if(qualitative_Param_Window==nullptr){
        qualitative_Param_Window =new Qualitative_Param_Window(this);

        connect(qualitative_Param_Window->findChild<QPushButton *>("btn_signal_set"),&QPushButton::clicked,this,&MenuWindow::signal_set);

        qualitative_Param_Window->show();
    }
    else{
        qualitative_Param_Window->showNormal();
    }
}

void MenuWindow::signal_set(int value){
    protocol->signalValue = value;
}

void MenuWindow::on_action_ms_db_triggered()
{
   ms_db_window();
}
void MenuWindow::inject_pump_clean_stop(){
    clean_inject_pump_flag = false;
    stopInject_clicked();
}
