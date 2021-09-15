#include "CheckAMSWindow.h"
#include "ui_CheckAMSWindow.h"


CheckAMSWindow::CheckAMSWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CheckAMSWindow)
{
    ui->setupUi(this);
    selectIndex=0;


    ui->tableWidget->setColumnCount(3);
    // ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    // ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"分子式"<<"理论值"<<"实验值");
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);  //整行选中的方式
    //ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //禁止修改
    ui->tableWidget->setSelectionMode(QAbstractItemView::MultiSelection);
    //  ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);  //设置为可以选中单

    //connect(ui->tableWidget,SIGNAL(itemPressed(QTableWidgetItem*)),this,SLOT(slotItemClicked(QTableWidgetItem*)));
    //connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(comboBoxCurrentIndexChanged(int)));



    //表头

    //设置表头
    // ui->tableWidget->setHorizontalHeaderLabels(horHeaderStr);
    //    this->toolb->addWidget(ui->tool_undo);
    //    toolBar->addWidget(ui->btn_sample_insert);
    //    toolBar->addWidget(ui->tool_do);
    ui->toolBar->addWidget(ui->tool_undo);
    ui->toolBar->addWidget(ui->tool_do);
    ui->toolBar->addWidget(ui->tool_sample_insert);
    ui->toolBar->addWidget(ui->tool_save);


    connect(ui->tool_undo,&QToolButton::clicked, this, &CheckAMSWindow::toolUndo);
    connect(ui->tool_sample_insert,&QPushButton::clicked,this,&CheckAMSWindow::sampleDataInsert);
    connect(ui->tool_do,&QToolButton::clicked,this,&CheckAMSWindow::toolDo);
    connect(ui->tool_save,&QToolButton::clicked,this,&CheckAMSWindow::tool_save);
    ui->tool_undo->setDisabled(true);
    ui->tool_do->setDisabled(true);

    // sqlList = new SQLList();
    // int rowCount =  ui->tableWidget->rowCount();

    QFile file(QDir::currentPath()+"/mapper/sample.json");
    if(!file.open(QIODevice::ReadOnly)){

        //qDebug()<<"not";
        return;
    }
    QByteArray allData = file.readAll();
    file.close();
    QJsonParseError jsonError;
    QJsonDocument jsonDoc(QJsonDocument::fromJson(allData,&jsonError));
    //    if(jsonError.error != QJsonParseError::NoError){
    //        //qDebug()<<"json Error";
    //        return;
    //    }
    QJsonArray rootArray = jsonDoc.array();
    QString sample_name = rootArray[0].toObject().value("sample_name").toString();
    double sample_thoery_value = rootArray[0].toObject().value("sample_thoery_value").toDouble();
    double sample_experience_value = rootArray[0].toObject().value("sample_experience_value").toDouble();
    edit_118_name = new QLineEdit();
    edit_118_name->setText(sample_name);
    edit_118_thoery = new QLineEdit();
    edit_118_thoery->setText(QString::number(sample_thoery_value));
    edit_118_experience = new QLineEdit();
    edit_118_experience->setText(QString::number(sample_experience_value));

    ui->tableWidget->setCellWidget(0,0,edit_118_name);
    ui->tableWidget->setCellWidget(0,1,edit_118_thoery);
    ui->tableWidget->setCellWidget(0,2,edit_118_experience);


    sample_name = rootArray[1].toObject().value("sample_name").toString();
    sample_thoery_value = rootArray[1].toObject().value("sample_thoery_value").toDouble();
    sample_experience_value = rootArray[1].toObject().value("sample_experience_value").toDouble();

    edit_322_name = new QLineEdit();
    edit_322_name->setText(sample_name);
    edit_322_thoery = new QLineEdit();
    edit_322_thoery->setText(QString::number(sample_thoery_value));
    edit_322_experience = new QLineEdit();
    edit_322_experience->setText(QString::number(sample_experience_value));
    ui->tableWidget->setCellWidget(1,0,edit_322_name);
    ui->tableWidget->setCellWidget(1,1,edit_322_thoery);
    ui->tableWidget->setCellWidget(1,2,edit_322_experience);



    sample_name = rootArray[2].toObject().value("sample_name").toString();
    sample_thoery_value = rootArray[2].toObject().value("sample_thoery_value").toDouble();
    sample_experience_value = rootArray[2].toObject().value("sample_experience_value").toDouble();
    edit_622_name = new QLineEdit();
    edit_622_name->setText(sample_name);
    edit_622_thoery = new QLineEdit();
    edit_622_thoery->setText(QString::number(sample_thoery_value));
    edit_622_experience = new QLineEdit();
    edit_622_experience->setText(QString::number(sample_experience_value));
    ui->tableWidget->setCellWidget(2,0,edit_622_name);
    ui->tableWidget->setCellWidget(2,1,edit_622_thoery);
    ui->tableWidget->setCellWidget(2,2,edit_622_experience);

    sample_name = rootArray[3].toObject().value("sample_name").toString();
    sample_thoery_value = rootArray[3].toObject().value("sample_thoery_value").toDouble();
    sample_experience_value = rootArray[3].toObject().value("sample_experience_value").toDouble();
    edit_922_name = new QLineEdit();
    edit_922_name->setText(sample_name);
    edit_922_thoery = new QLineEdit();
    edit_922_thoery->setText(QString::number(sample_thoery_value));
    edit_922_experience = new QLineEdit();
    edit_922_experience->setText(QString::number(sample_experience_value));
    ui->tableWidget->setCellWidget(3,0,edit_922_name);
    ui->tableWidget->setCellWidget(3,1,edit_922_thoery);
    ui->tableWidget->setCellWidget(3,2,edit_922_experience);

    // double data_fit_A=0,data_fit_B=0,data_fit_C=0,data_fit_D=0;
    // double k,d;
    //    while(query.next()) //一行一行遍历
    //    {

    QFile file1(QDir::currentPath()+"/mapper/datafit.json");
    if(file1.open(QIODevice::ReadWrite)){
        QByteArray allData = file1.readAll();
        QJsonParseError jsonError;
        QJsonDocument jsonDoc(QJsonDocument::fromJson(allData,&jsonError));
        //        if(jsonError.error != QJsonParseError::NoError){
        //            //qDebug()<<"json Error";
        //            return;
        //        }
        QJsonObject rootObject = jsonDoc.object();
        data_fit_A=  rootObject.value("data_fit_A").toDouble();
        data_fit_B = rootObject.value("data_fit_B").toDouble();
        data_fit_C  =rootObject.value("data_fit_C").toDouble();
        data_fit_D  =rootObject.value("data_fit_D").toDouble();

        QList<double> list;
        list.append(data_fit_A);
        list.append(data_fit_B);
        list.append(data_fit_C);
        list.append(data_fit_D);
        dataFitList.append(list);

        QLabel* pLable; //创建QLable
        QString paramStatus;
        paramStatus="a:"+QString::number(data_fit_D)+"; b:"+QString::number(data_fit_C)+"; c:"+QString::number(data_fit_B)+"; d:"+QString::number(data_fit_A);
        pLable= new QLabel(paramStatus);
        statusBar()->addWidget(pLable); //永久展示文字
        file1.close();


    }
}

void CheckAMSWindow::tool_save(){
    QFile file(QDir::currentPath()+"/mapper/datafit.json");
    if(file.open(QIODevice::ReadWrite)){


        file.resize(0);

        QJsonObject jsonObject;
        jsonObject.insert("data_fit_A", data_fit_A);
        jsonObject.insert("data_fit_B", data_fit_B);
        jsonObject.insert("data_fit_C", data_fit_C);
        jsonObject.insert("data_fit_D", data_fit_D);
        //   rootArray.append(jsonObject);

        // 使用QJsonDocument设置该json对象
        QJsonDocument jsonDocument;
        jsonDocument.setObject(jsonObject);

        // 将json以文本形式写入文件并关闭文件。
        // QJsonDocument jsonDoc
        file.write(jsonDocument.toJson());
        file.close();

        //    QLabel* pLable; //创建QLable



    }
}

void CheckAMSWindow::toolUndo(){
    if(dataFitList.size()>1){
        QList<double> list;
        list = dataFitList.back();
        dataFitList.pop_back();
        stackDataFitList.push_back(list);
         list = dataFitList.back();
        QString paramStatus;
        paramStatus="a:"+QString::number(list[3])+"; b:"+QString::number(list[2])+"; c:"+QString::number(list[1])+"; d:"+QString::number(list[0]);
        this->statusBar()->clearMessage();
        //  statusBar()->addWidget(pLable); //永久展示文字
        statusBar()->showMessage(paramStatus);
        if(stackDataFitList.size()>0){
            ui->tool_do->setDisabled(false);
            ui->tool_do->setIcon(QIcon(":/images/do-yes.png"));
        }else {

            ui->tool_do->setIcon(QIcon(":/images/do-no.png"));
            ui->tool_do->setDisabled(true);
        }

        if(dataFitList.size()>1){
            ui->tool_undo->setDisabled(false);
            ui->tool_undo->setIcon(QIcon(":/images/undo-yes.png"));

        }else {
            ui->tool_undo->setIcon(QIcon(":/images/undo-no.png"));
            ui->tool_undo->setDisabled(true);
        }
    }
}

void CheckAMSWindow::toolDo(){
    if(stackDataFitList.size()>0){
        QList<double> list;
        list = stackDataFitList.back();

        stackDataFitList.pop_back();
        //  list = dataFitList.back();
        QString paramStatus;
        paramStatus="a:"+QString::number(list[0])+"; b:"+QString::number(list[1])+"; c:"+QString::number(list[2])+"; d:"+QString::number(list[3]);
        this->statusBar()->clearMessage();
        //  statusBar()->addWidget(pLable); //永久展示文字
        statusBar()->showMessage(paramStatus);
        dataFitList.push_back(list);
        if(dataFitList.size()>1){
            ui->tool_undo->setDisabled(false);
            ui->tool_undo->setIcon(QIcon(":/images/undo-yes.png"));

        }else {
            ui->tool_undo->setIcon(QIcon(":/images/undo-no.png"));
            ui->tool_undo->setDisabled(true);
        }
        if(stackDataFitList.size()<=0){
            ui->tool_do->setDisabled(true);
            ui->tool_do->setIcon(QIcon(":/images/do-no.png"));
        }else {
            ui->tool_do->setDisabled(false);
            ui->tool_do->setIcon(QIcon(":/images/do-yes.png"));
        }
    }
}

bool checkState=false;
void CheckAMSWindow::sampleDataInsert(){


    int count = ui->tableWidget->rowCount();
    double  *data_sample_thoery=new   double[count];
    double  *data_sample_experiment=new   double[count];
    data_sample_thoery[0] = edit_118_thoery->text().toDouble();
    data_sample_experiment[0] = edit_118_experience->text().toDouble();
    data_sample_thoery[1] = edit_322_thoery->text().toDouble();
    data_sample_experiment[1] = edit_322_experience->text().toDouble();
    data_sample_thoery[2] = edit_622_thoery->text().toDouble();
    data_sample_experiment[2] = edit_622_experience->text().toDouble();
    data_sample_thoery[3] = edit_922_thoery->text().toDouble();
    data_sample_experiment[3] = edit_922_experience->text().toDouble();


    memset(coefficient, 0, sizeof(double) * 5);
    QVector<double> vx, vy;
    vx.resize(count);
    vy.resize(count);
    for (int i = 0; i < count; i++)
    {
        vx[i]=(data_sample_thoery[i]);
        //qDebug()<<"实验值:"<<data_sample_experiment[i];
        double value = (data_fit_A + data_fit_B*data_sample_experiment[i] +pow(data_sample_experiment[i],2)*data_fit_C+pow(data_sample_experiment[i],3)*data_fit_D);
        vy[i]=(value);
    }

    solveResult(vx, vy,"三次曲线拟合");

    QList<double> list;
    list.append(data_fit_A);
    list.append(data_fit_B);
    list.append(data_fit_C);
    list.append(data_fit_D);
    dataFitList.append(list);
    if(dataFitList.size()>1){

        ui->tool_undo->setDisabled(false);
        ui->tool_undo->setIcon(QIcon(":/images/undo-yes.png"));

    }else {
        ui->tool_undo->setDisabled(true);
        ui->tool_undo->setIcon(QIcon(":/images/undo-no.png"));

    }
    if(stackDataFitList.size()<=0){
        ui->tool_do->setDisabled(true);
        ui->tool_do->setIcon(QIcon(":/images/do-no.png"));
    }else {

        ui->tool_do->setDisabled(false);
        ui->tool_do->setIcon(QIcon(":/images/do-yes.png"));
    }

}

CheckAMSWindow::~CheckAMSWindow()
{
    delete ui;
}



void CheckAMSWindow::solveResult(QVector<double> Vx, QVector<double> Vy,QString type){


    if(type=="三次曲线拟合"){
        int n, m;
        double a[4][4 + 1] = {
            //3
            {pow(Vx.at(0),3),pow(Vx.at(0),2), Vx.at(0), 1, Vy.at(0)},
            {pow(Vx.at(1),3),pow(Vx.at(1),2),Vx.at(1), 1, Vy.at(1)},
            {pow(Vx.at(2),3),pow(Vx.at(2),2), Vx.at(2), 1, Vy.at(2)},
            {pow(Vx.at(3),3),pow(Vx.at(3),2), Vx.at(3), 1, Vy.at(3)},
            //        {100, 10, 1, 10},
            //        {400, 20, 1, 20},
            //        {900, 30, 1, 10},
            ////4
            //{1,1,1,1,0},
            //{1,2,3,4,-6},
            //{2,6,4,5,-3},
            //{3,4,-1,6,-12},
        };//第四列是增广矩阵
        int i, j;
        n = 4;


        for (j = 0; j < n; j++)
        {
            double max = 0;
            double imax = 0;
            for (i = j; i < n; i++)
            {
                if (imax < fabs(a[i][j])) {
                    imax = fabs(a[i][j]);
                    max = a[i][j];//得到各行中所在列最大元素
                    m = i;
                }
            }
            if (fabs(a[j][j]) != max)
            {
                double b = 0;
                for (int k = j; k < n + 1; k++) {
                    b = a[j][k];
                    a[j][k] = a[m][k];
                    a[m][k] = b;
                }
            }
            // print(a, MaxElement, MaxElement + 1);
            for (int r = j; r < n + 1; r++)
            {
                a[j][r] = a[j][r] / max;//让该行的所在列除以所在列的第一个元素，目的是让首元素为1
            }
            // print(a, MaxElement, MaxElement + 1);
            for (i = j + 1; i < n; i++)
            {
                double c = a[i][j];
                if (c == 0) continue;
                for (int s = j; s < n + 1; s++) {
                    double tempdata = a[i][s];
                    a[i][s] = a[i][s] - a[j][s] * c;//前后行数相减，使下一行或者上一行的首元素为0

                }

            }

        }
        for (i = n - 2; i >= 0; i--)
        {
            for (j = i + 1; j < n; j++)
            {
                double tempData = a[i][j];
                double data1 = a[i][n];
                double data2 = a[j][n];
                a[i][n] = a[i][n] - a[j][n] * a[i][j];

            }
        }

        data_fit_A = a[3][n];
        data_fit_B = a[2][n];
        data_fit_C = a[1][n];
        data_fit_D = a[0][n];
        QString paramStatus;
        paramStatus="a:"+QString::number(a[0][n])+"; b:"+QString::number(a[1][n])+"; c:"+QString::number( a[2][n])+"; d:"+QString::number(a[3][n]);
        this->statusBar()->clearMessage();
        //  statusBar()->addWidget(pLable); //永久展示文字
        statusBar()->showMessage(paramStatus);

    }
}















