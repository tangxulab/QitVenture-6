#include "librarywindow.h"
#include "ui_librarywindow.h"

LibraryWindow::LibraryWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LibraryWindow)
{
    ui->setupUi(this);
    connect(ui->tool_add_lib, SIGNAL(clicked()), this, SLOT(add_lib_window()));


    QStringList headerText;
    headerText<<"目标物"<<"分子式"<<"母离子"<<"子离子"<<"碰撞能量"<<"分子结构"<<"操作";  //表头标题用QStringList来表示
    this->setWindowTitle("谱库");

    ui->tableWidget->setColumnCount(headerText.count());//列数设置为与 headerText的行数相等
    ui->tableWidget->setHorizontalHeaderLabels(headerText);


    QFile file1(QDir::currentPath()+"/mapper/Spectral-Library.json");
    if(file1.open(QIODevice::ReadWrite)){
        QByteArray allData = file1.readAll();
        QJsonParseError jsonError;
        QJsonDocument jsonDoc(QJsonDocument::fromJson(allData,&jsonError));

        QJsonArray rootArray = jsonDoc.array();
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


        int count =0;

        //qDebug()<<rootArray.size();
        for (int i=0;i<rootArray.size();i++) {
            // qDebug()<<i;
            int row = ui->tableWidget->rowCount();
            qDebug()<<row;
            ui->tableWidget->insertRow(row);
            QJsonArray array_ms = rootArray.at(i).toObject().value("object_sub_ion_ms").toArray();
            QJsonArray array_energy = rootArray.at(i).toObject().value("object_sub_ion_energy").toArray();
            QString object_id = rootArray.at(i).toObject().value("object_id").toString();



            int rowSize = 0;
            //            if(array_ms.size()==0){
            //                rowSize = 2;
            //                //ui->tableWidget->insertRow(row+0);
            //                ui->tableWidget->setItem(row+0,3,new QTableWidgetItem("无"));
            //                // ui->tableWidget->item(row+j,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            //                ui->tableWidget->setItem(row+0,4,new QTableWidgetItem("无"));

            //                ui->tableWidget->insertRow(row+1);
            //                ui->tableWidget->setItem(row+1,3,new QTableWidgetItem("无"));
            //                // ui->tableWidget->item(row+j,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            //                ui->tableWidget->setItem(row+1,4,new QTableWidgetItem("无"));

            //            }

            //            else {
            rowSize = array_ms.size();
            for(int j=0;j<array_ms.size();j++){


                ui->tableWidget->setItem(row+j,3,new QTableWidgetItem(array_ms.at(j).toObject().value("sub_ion_ms").toString()));
               // ui->tableWidget->item(row+j,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                ui->tableWidget->setItem(row+j,4,new QTableWidgetItem(array_energy.at(j).toObject().value("sub_ion_energy").toString()));
               // ui->tableWidget->item(row+j,4)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            }
            //            }
            ui->tableWidget->setItem(count,0,new QTableWidgetItem(rootArray.at(i).toObject().value("obejct_name").toString()));
            //ui->tableWidget->item(count,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            ui->tableWidget->setSpan(count,0,2,1);
            ui->tableWidget->setItem(count,1,new QTableWidgetItem(rootArray.at(i).toObject().value("obejct_formula").toString()));
           // ui->tableWidget->item(count,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            ui->tableWidget->setSpan(count,1,2,1);
            ui->tableWidget->setItem(count,2,new QTableWidgetItem(rootArray.at(i).toObject().value("object_precursor_ion").toString()));
           // ui->tableWidget->item(count,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            ui->tableWidget->setSpan(count,2,2,1);

            QToolButton *btn_toolButton = new QToolButton();
            btn_toolButton->setIconSize(QSize(60, 60));
            btn_toolButton->setIcon(QIcon(QDir::currentPath()+rootArray.at(i).toObject().value("photo").toString()));
            ui->tableWidget->setCellWidget(count,5, btn_toolButton);
          //  ui->tableWidget->item(i,5)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            ui->tableWidget->setSpan(count,5,2,1);
            QHBoxLayout *layout = new QHBoxLayout();
            //            QPushButton *btn_modify = new QPushButton();
            //            // btn_modify->setProperty("info",time);
            //            btn_modify->setText("修改");
            //connect(btn_info,&QPushButton::clicked,this,&SelectMethodWindow::acceptMethodInfo);
            QPushButton *btn_del= new QPushButton(this);
            btn_del->setText("删除");
            btn_del->setProperty("del",object_id);
            //layout->addWidget(btn_modify);
            layout->addWidget(btn_del);
            QWidget *w = new QWidget();
            w->setFixedSize(100,50);
            w->setLayout(layout);
            ui->tableWidget->setCellWidget(count,6, w);
            ui->tableWidget->setSpan(count,6,2,1);
            connect(btn_del,&QPushButton::clicked,this,&LibraryWindow::delLib);

            //  ui->tableWidget->setItem(i,3,new QTableWidgetItem(rootArray.at(i).toObject().value("obejct_name").toString()));
            //  ui->tableWidget->setItem(i,4,new QTableWidgetItem(rootArray.at(i).toObject().value("obejct_name").toString()));
            //            rowCount+=array_ms.size();

            count = ui->tableWidget->rowCount();
            qDebug()<<"行:"<<count;
        }
        //        ui->tableWidget->setRowCount(rowCount);
    }
}

LibraryWindow::~LibraryWindow()
{
    delete ui;
}
void LibraryWindow::add_lib_window(){
    if(libInfoWindow==nullptr){
        libInfoWindow = new LibInfoWindow();
        libInfoWindow->show();
        connect(libInfoWindow->findChild<QPushButton *>("btn_ok"),&QPushButton::clicked, this, &LibraryWindow::addLibInfo);
    }else {
        libInfoWindow->showNormal();
    }


}
void LibraryWindow::addLibInfo(){
    QJsonObject object;
    QString object_id = QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
    QString object_name = libInfoWindow->findChild<QLineEdit *>("line_object_name")->text();
    QString object_formula = libInfoWindow->findChild<QLineEdit *>("line_object_formula")->text();
    QString object_ion =libInfoWindow->findChild<QLineEdit *>("line_precursor_ion")->text();
    QString photo_path =libInfoWindow->findChild<QLabel *>("photo_path")->text();
    object.insert("object_id",object_id);
    object.insert("obejct_name",object_name);
    object.insert("obejct_formula",object_formula);
    object.insert("object_precursor_ion",object_ion);

    QJsonArray ion_ms_array,ion_energy_array;
    for (int i=0;i<libInfoWindow->subIonList.length();i++) {
        QJsonObject sub_ion_object;
        sub_ion_object.insert("sub_ion_ms",libInfoWindow->subIonList[i]->text());
        ion_ms_array.append(sub_ion_object);
        QJsonObject sub_energy_object;
        sub_energy_object.insert("sub_ion_energy",libInfoWindow->subenergyList[i]->text());
        ion_energy_array.append(sub_energy_object);
    }
    object.insert("object_sub_ion_ms",ion_ms_array);
    object.insert("object_sub_ion_energy",ion_energy_array);
    QString  imagePath = libInfoWindow->findChild<QLabel *>("photo_path")->text();
    QString split = imagePath.split(".").last();
    QString  currentPath = "/photo/"+object_id+"."+split;
    QString dirPath = QDir::currentPath()+currentPath;

    //QFile::setPermissions(dirPath, QFileDevice::ReadOwner|QFileDevice::WriteOwner);
    qDebug()<<photo_path;
    qDebug()<<dirPath;
    QFile::copy(photo_path,dirPath);

    object.insert("photo",currentPath);

    QFile file1(QDir::currentPath()+"/mapper/Spectral-Library.json");
    if(file1.open(QIODevice::ReadWrite)){
        QByteArray allData = file1.readAll();
        file1.resize(0);
        QJsonParseError jsonError;
        QJsonDocument jsonDoc(QJsonDocument::fromJson(allData,&jsonError));

        QJsonArray rootArray = jsonDoc.array();
        rootArray.append(object);
        QJsonDocument jsonDocument;
        jsonDocument.setArray(rootArray);

        // 将json以文本形式写入文件并关闭文件。
        // QJsonDocument jsonDoc
        file1.write(jsonDocument.toJson());
        file1.close();

        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        //int row = ui->tableWidget->rowCount();
        for(int i=ui->tableWidget->rowCount()-1;i>=0;i--){
            ui->tableWidget->removeRow(i);
        }

        //int count =0;
        for (int i=0;i<rootArray.size();i++) {
            // qDebug()<<i;
            int row = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(row);
            QJsonArray array_ms = rootArray.at(i).toObject().value("object_sub_ion_ms").toArray();
            QJsonArray array_energy = rootArray.at(i).toObject().value("object_sub_ion_energy").toArray();
            QString object_id = rootArray.at(i).toObject().value("object_id").toString();


            ui->tableWidget->setItem(row,0,new QTableWidgetItem(rootArray.at(i).toObject().value("obejct_name").toString()));
            // ui->tableWidget->item(count,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            int rowSize = 0;
            if(array_ms.size()==0){
                rowSize = 2;
                //ui->tableWidget->insertRow(row+0);
                ui->tableWidget->setItem(row+0,3,new QTableWidgetItem("无"));
                // ui->tableWidget->item(row+j,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                ui->tableWidget->setItem(row+0,4,new QTableWidgetItem("无"));

                ui->tableWidget->insertRow(row+1);
                ui->tableWidget->setItem(row+1,3,new QTableWidgetItem("无"));
                // ui->tableWidget->item(row+j,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                ui->tableWidget->setItem(row+1,4,new QTableWidgetItem("无"));

            }

            else {
                rowSize = array_ms.size();
                for(int j=0;j<array_ms.size();j++){


                    ui->tableWidget->setItem(row+j,3,new QTableWidgetItem(array_ms.at(j).toObject().value("sub_ion_ms").toString()));
                    // ui->tableWidget->item(row+j,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                    ui->tableWidget->setItem(row+j,4,new QTableWidgetItem(array_energy.at(j).toObject().value("sub_ion_energy").toString()));
                    // ui->tableWidget->item(row+j,4)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                }
            }
            ui->tableWidget->setSpan(row,0,rowSize,1);
            ui->tableWidget->setItem(row,1,new QTableWidgetItem(rootArray.at(i).toObject().value("obejct_formula").toString()));
            /// ui->tableWidget->item(count,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            ui->tableWidget->setSpan(row,1,rowSize,1);
            ui->tableWidget->setItem(row,2,new QTableWidgetItem(rootArray.at(i).toObject().value("object_precursor_ion").toString()));
            //ui->tableWidget->item(count,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            ui->tableWidget->setSpan(row,2,rowSize,1);

            QToolButton *btn_toolButton = new QToolButton();
            btn_toolButton->setIconSize(QSize(60, 60));
            btn_toolButton->setIcon(QIcon(QDir::currentPath()+rootArray.at(i).toObject().value("photo").toString()));
            ui->tableWidget->setCellWidget(row,5, btn_toolButton);
            //  ui->tableWidget->item(i,5)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            ui->tableWidget->setSpan(row,5,rowSize,1);
            QHBoxLayout *layout = new QHBoxLayout();
            //            QPushButton *btn_modify = new QPushButton();
            //            // btn_modify->setProperty("info",time);
            //            btn_modify->setText("修改");
            //connect(btn_info,&QPushButton::clicked,this,&SelectMethodWindow::acceptMethodInfo);
            QPushButton *btn_del= new QPushButton(this);
            btn_del->setText("删除");
            btn_del->setProperty("del",object_id);
            //layout->addWidget(btn_modify);
            layout->addWidget(btn_del);
            QWidget *w = new QWidget();
            w->setFixedSize(100,50);
            w->setLayout(layout);
            ui->tableWidget->setCellWidget(row,6, w);
            ui->tableWidget->setSpan(row,6,rowSize,1);
            connect(btn_del,&QPushButton::clicked,this,&LibraryWindow::delLib);

            //  ui->tableWidget->setItem(i,3,new QTableWidgetItem(rootArray.at(i).toObject().value("obejct_name").toString()));
            //  ui->tableWidget->setItem(i,4,new QTableWidgetItem(rootArray.at(i).toObject().value("obejct_name").toString()));
            //            rowCount+=array_ms.size();

            //count = ui->tableWidget->rowCount();
            //qDebug()<<"行:"<<count;
        }
        //        ui->tableWidget->setRowCount(rowCount);
    }

}

void LibraryWindow::delLib(){

    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if(button)
    {
        QString currentFileName = button->property("del").toString();
        qDebug()<<currentFileName;

        QFile file1(QDir::currentPath()+"/mapper/Spectral-Library.json");
        if(file1.open(QIODevice::ReadWrite)){
            QByteArray allData = file1.readAll();
            QJsonParseError jsonError;
            QJsonDocument jsonDoc(QJsonDocument::fromJson(allData,&jsonError));

            QJsonArray rootArray = jsonDoc.array();
            file1.resize(0);
            QJsonArray  array;
            for (int i=0;i<rootArray.size();i++) {
                QString object_id = rootArray.at(i).toObject().value("object_id").toString();
                if(object_id==currentFileName){
                    continue;
                }else {
                    array.append(rootArray.at(i).toObject());

                }
            }
            QJsonDocument jsonDocument;
            jsonDocument.setArray(array);
            file1.write(jsonDocument.toJson());
            file1.close();
            ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
            //int row = ui->tableWidget->rowCount();
            for(int i=ui->tableWidget->rowCount()-1;i>=0;i--){
                ui->tableWidget->removeRow(i);
            }
            ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


            int count =0;
            for (int i=0;i<array.size();i++) {
                // qDebug()<<i;
                int row = ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(row);
                QJsonArray array_ms = rootArray.at(i).toObject().value("object_sub_ion_ms").toArray();
                QJsonArray array_energy = rootArray.at(i).toObject().value("object_sub_ion_energy").toArray();
                QString object_id = rootArray.at(i).toObject().value("object_id").toString();


                ui->tableWidget->setItem(count,0,new QTableWidgetItem(rootArray.at(i).toObject().value("obejct_name").toString()));
                // ui->tableWidget->item(count,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                int rowSize = 0;
                if(array_ms.size()==0){
                    rowSize = 2;
                    //ui->tableWidget->insertRow(row+0);
                    ui->tableWidget->setItem(row+0,3,new QTableWidgetItem("无"));
                    // ui->tableWidget->item(row+j,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                    ui->tableWidget->setItem(row+0,4,new QTableWidgetItem("无"));

                    ui->tableWidget->insertRow(row+1);
                    ui->tableWidget->setItem(row+1,3,new QTableWidgetItem("无"));
                    // ui->tableWidget->item(row+j,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                    ui->tableWidget->setItem(row+1,4,new QTableWidgetItem("无"));

                }

                else {
                    rowSize = array_ms.size();
                    for(int j=0;j<array_ms.size();j++){


                        ui->tableWidget->setItem(row+j,3,new QTableWidgetItem(array_ms.at(j).toObject().value("sub_ion_ms").toString()));
                        // ui->tableWidget->item(row+j,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                        ui->tableWidget->setItem(row+j,4,new QTableWidgetItem(array_energy.at(j).toObject().value("sub_ion_energy").toString()));
                        // ui->tableWidget->item(row+j,4)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

                    }
                }
                ui->tableWidget->setSpan(count,0,rowSize,1);
                ui->tableWidget->setItem(count,1,new QTableWidgetItem(rootArray.at(i).toObject().value("obejct_formula").toString()));
                /// ui->tableWidget->item(count,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                ui->tableWidget->setSpan(count,1,rowSize,1);
                ui->tableWidget->setItem(count,2,new QTableWidgetItem(rootArray.at(i).toObject().value("object_precursor_ion").toString()));
                //ui->tableWidget->item(count,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                ui->tableWidget->setSpan(count,2,rowSize,1);

                QToolButton *btn_toolButton = new QToolButton();
                btn_toolButton->setIconSize(QSize(60, 60));
                btn_toolButton->setIcon(QIcon(QDir::currentPath()+rootArray.at(i).toObject().value("photo").toString()));
                ui->tableWidget->setCellWidget(count,5, btn_toolButton);
                //  ui->tableWidget->item(i,5)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                ui->tableWidget->setSpan(count,5,rowSize,1);
                QHBoxLayout *layout = new QHBoxLayout();
                //            QPushButton *btn_modify = new QPushButton();
                //            // btn_modify->setProperty("info",time);
                //            btn_modify->setText("修改");
                //connect(btn_info,&QPushButton::clicked,this,&SelectMethodWindow::acceptMethodInfo);
                QPushButton *btn_del= new QPushButton(this);
                btn_del->setText("删除");
                btn_del->setProperty("del",object_id);
                //layout->addWidget(btn_modify);
                layout->addWidget(btn_del);
                QWidget *w = new QWidget();
                w->setFixedSize(100,50);
                w->setLayout(layout);
                ui->tableWidget->setCellWidget(count,6, w);
                ui->tableWidget->setSpan(count,6,rowSize,1);
                //connect(btn_del,&QPushButton::clicked,this,&LibraryWindow::delLib);

                //  ui->tableWidget->setItem(i,3,new QTableWidgetItem(rootArray.at(i).toObject().value("obejct_name").toString()));
                //  ui->tableWidget->setItem(i,4,new QTableWidgetItem(rootArray.at(i).toObject().value("obejct_name").toString()));
                //            rowCount+=array_ms.size();

                count = ui->tableWidget->rowCount();
                qDebug()<<"行:"<<count;
            }
            //        ui->tableWidget->setRowCount(rowCount);
        }
    }
}
