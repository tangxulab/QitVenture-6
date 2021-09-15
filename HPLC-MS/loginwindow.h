//登陆界面类
#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "MenuWindow.h"
#include <QDebug>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    void show_frame(QImage &image);//界面图片显示
    ~LoginWindow();
private slots:
    void validate();
private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
