#include "CameraWindow.h"
#include "ui_CameraWindow.h"

CameraWindow::CameraWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CameraWindow)
{
    camera = new QCamera();
    cameraViewFinder = new QCameraViewfinder();
    cameraImageCapture = new QCameraImageCapture(camera);
    displayLabel = new QLabel();
    displayLabel->setFixedSize(160, 120);
    displayLabel->setScaledContents(true);



    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(cameraViewFinder);
    connect(cameraImageCapture, SIGNAL(imageCaptured(int,QImage)), this, SLOT(cameraImageCaptured(int,QImage)));
    cameraImageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
    camera->setCaptureMode(QCamera::CaptureStillImage);
    camera->setViewfinder(cameraViewFinder);
    camera->start();
    QWidget *widget = new QWidget(this);
    widget->setLayout(mainLayout);
    this->setCentralWidget(widget);
    this->translateLanguage();
}
void CameraWindow::translateLanguage()
{
    this->setWindowTitle(tr("摄像头"));
    //        captureBtn->setText(tr("截图"));
    //        saveBtn->setText(tr("保存"));
    //        exitBtn->setText(tr("退出"));
}

void CameraWindow::captureBtnResponded()
{
    cameraImageCapture->capture();
}

void CameraWindow::saveBtnResponded()
{
    const QPixmap *pixmap = displayLabel->pixmap();
    QString path=  "D:/images/image/aa.jpg";
    if(pixmap) {
        //
        QFile file(path);
        file.open(QIODevice::WriteOnly);
        if(pixmap->save(&file,"JPG"))
        {
            bool flag =pixmap->save(path);
            //qDebug()<<flag;
            QMessageBox msg;
            msg.setText("保存成功");
            msg.exec();
        }
    }
}

void CameraWindow::exitBtnResponded()
{
    camera->stop();
    this->close();
}

void CameraWindow::cameraImageCaptured(int id, QImage image)
{
    displayLabel->setPixmap(QPixmap::fromImage(image));
}
CameraWindow::~CameraWindow()
{
    delete ui;
}
