#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//用户主界面暂时废弃
#include <QMainWindow>
#include <QMainWindow>
#include <QtWidgets/QWidget>
#include <QDesktopWidget>
#include "WaveFormWindow.h"
#include "clippipevalvewindow.h"
#include "CameraWindow.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void setBtnQss(QPushButton *btn, QString normalColor, QString normalTextColor, QString hoverColor, QString hoverTextColor, QString pressedColor, QString pressedTextColor);
    void setTxtQss(QLineEdit *txt, QString normalColor, QString focusColor);
    ~MainWindow();
public:
    WaveFormWindow *waveMainFormWindow;
    ClipPipeValveWindow *clipPipeValveWindow;
     CameraWindow *cameraWindow;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
