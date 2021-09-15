#ifndef SQLLIST_H
#define SQLLIST_H
#include <QString>
#include<QSqlQuery>
#include <QSqlDatabase>
#include <QSql>
#include <QDebug>
#include "connectMYSQL.h"
extern QVariantList  spectrumData_x;
extern QVariantList  spectrumData_y;
extern QVariantList  createTime;
class SQLList
{
public:
    SQLList();


    //获取校验样品数据
    QSqlQuery selectCheckSample();
    int insertCheckSample(QString sampleThoery,QString sampleExperience);
    void updateDataFit(QString A,QString B,QString C,QString D,QString typeName);
    QSqlQuery selectDataFitType(QString typeName);
    void deleteSampleById(int id);
    QSqlQuery getFitDataByType(QString typeName);
    void inserSpectrumData(QStringList list,connectMYSQL *mySql);
};

#endif // SQLLIST_H
