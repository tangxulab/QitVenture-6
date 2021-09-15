#include "permissionwindow.h"
#include "ui_permissionwindow.h"

PermissionWindow::PermissionWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PermissionWindow)
{
    ui->setupUi(this);

    treeView = new QTreeView();
    treeView->setStyle(QStyleFactory::create("windows"));
    //  treeView->resize(200,500);
    treeView->setHeaderHidden(true);
    toolBar = new QToolBar(this); //添加工具栏
    toolButton = new QToolButton(this);
    toolButton->setToolTip("保存");
    toolButton->setIcon(QPixmap(":/images/file_save_as.png"));

    toolBar->addWidget(toolButton);
    //leftToolBar->addWidget(deleteToolButton);

    QWidget *w = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(w);


    connect(treeView,SIGNAL(doubleClicked ( const QModelIndex)),this,SLOT(OnlineTreeViewDoubleClick(const QModelIndex)));

    QIcon treeitemicon(QPixmap(":/images/plant.png"));
    QIcon treerooticon(QPixmap(":/images/tree.png"));
    QIcon treeleaficon(QPixmap(":/images/green.png"));

    QStandardItemModel *model = new QStandardItemModel(treeView);
    connect(model,&QStandardItemModel::itemChanged,this,&PermissionWindow::getItemChanged,Qt::QueuedConnection);
    connect(model,SIGNAL(itemChanged(QStandardItem*)),this,SLOT(treeItemChanged(QStandardItem*)));
    QStandardItem *root = new QStandardItem(treerooticon,"权限列表");

    //    data[2] = MenuWindowUI->spinBox_total_cycle->text().toUShort();
    //    data[3] = MenuWindowUI->spinBox_rf->text().toUShort();
    //    data[4] = MenuWindowUI->spinBox_rn->text().toUShort();
    //    data[5] = MenuWindowUI->spinBox_ion_cool_rf_voltage->text().toUShort();
    //    data[6] = MenuWindowUI->spinBox_low_mass_number->text().toUShort();
    //    data[7] = MenuWindowUI->spinBox_hight_mass_number->text().toUShort();
    //    data[8] = MenuWindowUI->spinBox_ion_cold_zone_time->text().toUShort();
    //    data[9] = MenuWindowUI->spinBox_rf_scanning_time->text().toUShort();
    //    data[10] = MenuWindowUI->spinBox_al->text().toUShort();
    //    data[11] = MenuWindowUI->spinBox_ah->text().toUShort();
    //    data[12] = MenuWindowUI->spinBox_af->text().toUShort();
    //    data[13] = MenuWindowUI->spinBox_clamp_valve_open_time->text().toUShort();
    //    data[14] = 55;
    //    data[15] = MenuWindowUI->spinBox_rf_on_time->text().toUShort();


    QFile filePermission(QDir::currentPath()+"/mapper/filePermission.json");
    // if(filePermission.exists()){
    filePermission.open(QIODevice::ReadWrite);

    QByteArray allData = filePermission.readAll();
    filePermission.close();
    QJsonParseError jsonError;
    QJsonDocument jsonDoc(QJsonDocument::fromJson(allData,&jsonError));
    if(jsonError.error != QJsonParseError::NoError){
        ////qDebug()<<"json Error";
        return;
    }
    QJsonArray rootArray = jsonDoc.array();
    for (int i =0;i<rootArray.size();i++) {
        list.append(rootArray.at(i).toObject().value("name").toString());
    }

    QStandardItem *item = new QStandardItem(treeitemicon,"方法设置");
    item->setCheckable(true);
    QStandardItem *total_cycle = new QStandardItem(treeleaficon,"总周期");
    total_cycle->setCheckable(true);
    if(list.contains("总周期")){
        // list.append("总周期");
        total_cycle->setCheckState(Qt::CheckState::Checked);
    }

    item->appendRow(total_cycle);
    QStandardItem *rf = new QStandardItem(treeleaficon,"采样频率");
    rf->setCheckable(true);
    if(list.contains("采样频率")){
        //     list.append("采样频率");
        rf->setCheckState(Qt::CheckState::Checked);
    }

    item->appendRow(rf);
    QStandardItem *rn = new QStandardItem(treeleaficon,"采样数据量");
    rn->setCheckable(true);
    if(list.contains("采样数据量")){
        //      list.append("采样数据量");
        rn->setCheckState(Qt::CheckState::Checked);
    }

    item->appendRow(rn);
    QStandardItem *ion_cool_rf_voltage = new QStandardItem(treeleaficon,"离子冷却RF电压");
    ion_cool_rf_voltage->setCheckable(true);
    if(list.contains("离子冷却RF电压")){
        //      list.append("离子冷却RF电压");
        ion_cool_rf_voltage->setCheckState(Qt::CheckState::Checked);
    }

    item->appendRow(ion_cool_rf_voltage);
    QStandardItem *low_mass_number = new QStandardItem(treeleaficon,"低质量数");
    low_mass_number->setCheckable(true);
    if(list.contains("低质量数")){
        //     list.append("低质量数");
        low_mass_number->setCheckState(Qt::CheckState::Checked);
    }

    item->appendRow(low_mass_number);
    QStandardItem *hight_mass_number = new QStandardItem(treeleaficon,"高质量数");
    hight_mass_number->setCheckable(true);
    if(list.contains("高质量数"))
    {
        //      list.append("高质量数");
        hight_mass_number->setCheckState(Qt::CheckState::Checked);
    }

    item->appendRow(hight_mass_number);
    QStandardItem *ion_cold_zone_time = new QStandardItem(treeleaficon,"离子冷却时间");
    ion_cold_zone_time->setCheckable(true);
    if(list.contains("离子冷却时间")){
        //    list.append("离子冷却时间");
        ion_cold_zone_time->setCheckState(Qt::CheckState::Checked);
    }

    item->appendRow(ion_cold_zone_time);
    QStandardItem *rf_scanning_time = new QStandardItem(treeleaficon,"RF扫描时间");
    rf_scanning_time->setCheckable(true);
    if(list.contains("RF扫描时间")){
        //      list.append("RF扫描时间");
        rf_scanning_time->setCheckState(Qt::CheckState::Checked);
    }

    item->appendRow(rf_scanning_time);
    QStandardItem *al = new QStandardItem(treeleaficon,"AC电压低幅值");
    al->setCheckable(true);
    if(list.contains("AC电压低幅值")){
        //     list.append("AC电压低幅值");
        al->setCheckState(Qt::CheckState::Checked);
    }

    item->appendRow(al);
    QStandardItem *ah = new QStandardItem(treeleaficon,"AC电压高幅值");
    ah->setCheckable(true);
    if(list.contains("AC电压高幅值")){
        //      list.append("AC电压高幅值");
        ah->setCheckState(Qt::CheckState::Checked);
    }

    item->appendRow(ah);
    QStandardItem *af = new QStandardItem(treeleaficon,"AC电压频率");
    af->setCheckable(true);
    if(list.contains("AC电压频率")){
        //     list.append("AC电压频率");
        af->setCheckState(Qt::CheckState::Checked);
    }

    item->appendRow(af);
    QStandardItem *clamp_valve_open_time = new QStandardItem(treeleaficon,"夹管阀开启时长");
    clamp_valve_open_time->setCheckable(true);
    if(list.contains("夹管阀开启时长")){
        //     list.append("夹管阀开启时长");
        clamp_valve_open_time->setCheckState(Qt::CheckState::Checked);
    }

    item->appendRow(clamp_valve_open_time);
    QStandardItem *rf_on_time = new QStandardItem(treeleaficon,"RF开启时刻");
    rf_on_time->setCheckable(true);
    if(list.contains("RF开启时刻")){
        //      list.append("RF开启时刻");
        rf_on_time->setCheckState(Qt::CheckState::Checked);
    }

    item->appendRow(rf_on_time);


    root->appendRow(item);

    root->setCheckable(true);
    model->appendRow(root);
    treeView->setModel(model);


    layout->addWidget(toolBar);
    layout->addWidget(treeView);
    this->setCentralWidget(w);
    ////qDebug()<<list;


}

void PermissionWindow::treeItemChanged(QStandardItem *item)
{  // ////qDebug()<<"item changed trigger";
    //如果节点可选并且含有子节点
    if ( item->isCheckable()&&item->hasChildren())
    {

        Qt::CheckState state = item->checkState (); //获取当前的选择状态
        //同步父子节点的状态
        for(int i = 0;i<item->rowCount();++i)
        {

            QStandardItem* childItems = item->child(i);
            //////qDebug()<<childItems->text();
            childItems->setCheckState(state);
        }
    }
}

void PermissionWindow::saveTreeItemSelected(){


    QFile filePermission(QDir::currentPath()+"/mapper/filePermission.json");
    if(filePermission.exists()){
        filePermission.open(QIODevice::ReadWrite);

        //        QByteArray allData = filePermission.readAll();
        //        filePermission.close();
        //        QJsonParseError jsonError;
        //        QJsonDocument jsonDoc(QJsonDocument::fromJson(allData,&jsonError));
        //        if(jsonError.error != QJsonParseError::NoError){
        //            ////qDebug()<<"json Error";
        //            return;
        //        }
        //        QJsonArray rootArray = jsonDoc.array();;

        QJsonArray array;

        //        QHashIterator<QString, bool> i(map);
        //        while (i.hasNext()) {
        //            i.next();
        //            QJsonObject object;
        //            object.insert(i.key(),i.value());
        //            array.append(object);
        //            //i;
        //        }
        for(int i=0;i<list.size();i++){
            QJsonObject object;
            object.insert("name",list.at(i));
            array.append(object);
        }
        //    QMap<QString, bool>::const_iterator i;
        // for(i = map.constBegin();)
        filePermission.resize(0);
        QJsonDocument jsonDocument;
        jsonDocument.setArray(array);

        // 将json以文本形式写入文件并关闭文件。
        // QJsonDocument jsonDoc
        filePermission.write(jsonDocument.toJson());
        filePermission.close();

        QMessageBox::information(this,"tip","软件重启生效");
    }


    //    QModelIndexList selected = treeView->selectionModel()->selectedRows(1);
    //    ////qDebug()<<selected;
    //    QList<QModelIndex>::const_iterator cit;
    //    QModelIndex temp;
    //    QString strSelect;

    //    for (cit = selected.begin(); cit != selected.end(); ++cit)
    //    {
    //        temp = *cit;
    //        strSelect = treeView->model()->itemData(temp).values()[0].toString();
    //        ////qDebug()<<strSelect;
    //    }
}


void PermissionWindow::getItemChanged(QStandardItem *item){

    // ////qDebug()<<item->checkState();
      ////qDebug()<<item->text();
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
    ////qDebug()<<list;
}

void PermissionWindow::OnlineTreeViewDoubleClick(const QModelIndex){}
PermissionWindow::~PermissionWindow()
{
    delete ui;
}
