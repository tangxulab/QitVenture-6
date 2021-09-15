#ifndef LIBRARYWINDOW_H
#define LIBRARYWINDOW_H

#include <QMainWindow>
#include "libinfowindow.h"
#include <QIcon>
#include <QLabel>
#include <QPushButton>
#include <QDateTime>
#include <QFile>
#include <QComboBox>
namespace Ui {
class LibraryWindow;
}

class LibraryWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LibraryWindow(QWidget *parent = nullptr);
    ~LibraryWindow();
private slots:
    void add_lib_window();
    void addLibInfo();


    //void on_comboBox_currentTextChanged(const QString &arg1);
    void delLib();

private:
    Ui::LibraryWindow *ui;
    LibInfoWindow *libInfoWindow = nullptr;

};

#endif // LIBRARYWINDOW_H
