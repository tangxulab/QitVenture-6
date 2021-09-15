#include "libinfowindow.h"
#include "ui_libinfowindow.h"

LibInfoWindow::LibInfoWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LibInfoWindow)
{
    ui->setupUi(this);
    ui->photo_path->hide();
}

LibInfoWindow::~LibInfoWindow()
{
    delete ui;
}



void LibInfoWindow::on_tool_add_sub_ion_clicked()
{
    QLineEdit *sub_ion =new QLineEdit();
    QLineEdit *sub_energy = new QLineEdit();
    subIonList.append(sub_ion);
    subenergyList.append(sub_energy);
    sub_ion->setFixedSize(300,30);
    sub_energy->setFixedSize(300,30);
    count++;
    ui->gridLayout->addWidget(sub_ion,3,count);
    ui->gridLayout->addWidget(sub_energy,4,count);
    ui->tool_add_sub_ion->hide();
    ui->gridLayout->addWidget(ui->tool_add_sub_ion,3,count+1);

    ui->tool_add_sub_ion->show();
    //ui->gridLayout->addWidget(ui->tool_add_sub_ion,3,1+(count));


   // qDebug()<<count;
}

void LibInfoWindow::on_tool_ion_photo_clicked()
{
    QFileDialog *a=new QFileDialog(this);
    a->setDirectory(QDir::currentPath()+"/photo/");
    a->setNameFilter("photo (*.png *.jpg)");
    \
    QString path;

    if(a->exec()==QDialog::Accepted)
    {

        // qDebug()<<a->selectedFiles()[0];

        path=a->selectedFiles()[0];
       // qDebug()<<path;
        ui->photo_path->setText(path);

        //  ChoseMth(path);
        //        QFile file(path);

        //        if(file.open(QIODevice::ReadWrite)){
        //            QByteArray allData = file.readAll();

        //        }

    }
}


