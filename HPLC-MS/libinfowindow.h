#ifndef LIBINFOWINDOW_H
#define LIBINFOWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFileDialog>
#include <QLineEdit>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

namespace Ui {
class LibInfoWindow;
}

class LibInfoWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LibInfoWindow(QWidget *parent = nullptr);
    ~LibInfoWindow();

private slots:

    void on_tool_add_sub_ion_clicked();

    void on_tool_ion_photo_clicked();


public:
    QList<QLineEdit*> subIonList;
    QList<QLineEdit*> subenergyList;

private:
    Ui::LibInfoWindow *ui;
    int count =0;

};

#endif // LIBINFOWINDOW_H
