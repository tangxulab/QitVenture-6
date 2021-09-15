#ifndef CHECKAMSWINDOW_H
#define CHECKAMSWINDOW_H

#include <QMainWindow>
#include "AddSampleWindow.h"
#include <QPushButton>
#include <QLineEdit>
#include <QDebug>
#include <QCheckBox>
#include <QTableWidgetItem>
#include "DataFitting.h"
#include "SQLList.h"
#include<QtSql>
#include <QSqlQuery>
#include <QItemSelectionModel>
#include <QMessageBox>
#include <QLabel>

#define MaxElement  4
namespace Ui {
class CheckAMSWindow;
}

class CheckAMSWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CheckAMSWindow(QWidget *parent = nullptr);
    ~CheckAMSWindow();

    double coefficient[5];
    double a,b;
    int selectIndex=0;
    void solveResult(QVector<double> Vx, QVector<double> Vy,QString type);


private slots:

    void toolUndo();
  //  void addSample();
 //   void slotItemClicked(QTableWidgetItem* item);
    void sampleDataInsert();
 //   void comboBoxCurrentIndexChanged(int index);
    void toolDo();
    void tool_save();
 //   QSqlQuery getFitData(QString typeName);





private:
    Ui::CheckAMSWindow *ui;

    AddSampleWindow *addSampleWindow=nullptr;
    QList<QList<double>> dataFitList;
    QList<QList<double>> stackDataFitList;



    QLineEdit *edit_118_name;
    QLineEdit *edit_118_experience;
    QLineEdit *edit_118_thoery;

    QLineEdit *edit_322_name;
    QLineEdit *edit_322_experience;
    QLineEdit *edit_322_thoery;

    QLineEdit *edit_622_name;
    QLineEdit *edit_622_experience;
    QLineEdit *edit_622_thoery;

    QLineEdit *edit_922_name;
    QLineEdit *edit_922_experience;
    QLineEdit *edit_922_thoery;
    double data_fit_A=0,data_fit_B=0,data_fit_C=0,data_fit_D=0;
};

#endif // CHECKAMSWINDOW_H
