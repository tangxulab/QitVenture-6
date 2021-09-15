#ifndef CAMERAWINDOW_H
#define CAMERAWINDOW_H

/**
  照相机类
  **/
#include <QMainWindow>
#include <QMainWindow>
#include <QCamera>
#include <QCameraViewfinder>
#include <QPushButton>
#include <QCameraImageCapture>
#include <QLabel>
#include <QVBoxLayout>
#include <QDateTime>
#include <QMessageBox>
#include <QException>
#include <QFile>
#include <QBuffer>
namespace Ui {
class CameraWindow;
}

class CameraWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    //（拍照等功能，暂时未使用到)
    void captureBtnResponded();
    void saveBtnResponded();
    void exitBtnResponded();
    void cameraImageCaptured(int id, QImage image);

private:
    // 系统摄像设备（摄像头）
    QCamera *camera;
    // 摄像取景器部件
    QCameraViewfinder *cameraViewFinder;
    // 截图部件
    QCameraImageCapture *cameraImageCapture;
    //   （拍照等功能，暂时未使用到)
    //    QPushButton *captureBtn;
    //    QPushButton *saveBtn;
    //    QPushButton *exitBtn;

    QLabel *displayLabel;

    void translateLanguage();

public:
    explicit CameraWindow(QWidget *parent = nullptr);
    ~CameraWindow();


private:
    Ui::CameraWindow *ui;
};

#endif // CAMERAWINDOW_H
