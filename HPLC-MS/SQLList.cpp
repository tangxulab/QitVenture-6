#include "SQLList.h"

SQLList::SQLList()
{

}
QSqlQuery SQLList::selectCheckSample(){

    QString sql = "select * from tb_sample";
    QSqlQuery query;
    query.exec(sql);
    return query;
}
int SQLList::insertCheckSample(QString sampleThoery,QString sampleExperience){

    QSqlQuery query;
    QString sql = "select count(*) from tb_sample";
    query.exec(sql);
    query.next();
    int count = query.value(0).toInt();
    QSqlQuery querySelect;
    querySelect.prepare( "insert into tb_sample (id,sample_thoery_value,sample_experience_value) values (?,?,?)");

    querySelect.bindValue(0, count+1);
    querySelect.bindValue(1, sampleThoery);
    querySelect.bindValue(2, sampleExperience);
    querySelect.exec();
    return  count+1;


}

void SQLList::updateDataFit(QString A,QString B,QString C,QString D,QString typeName){

    QSqlQuery querySelect;
    if(typeName=="线性拟合"){
        querySelect.prepare( "update tb_data_fit set data_fit_A=?,data_fit_B=? where type_name=?");
        querySelect.bindValue(0, A);
        querySelect.bindValue(1, B);
        querySelect.bindValue(2, typeName);
        querySelect.exec();
    }
    else if(typeName=="二次曲线拟合")
    {
        querySelect.prepare( "update tb_data_fit set data_fit_A=?,data_fit_B=?,data_fit_C=? where type_name=?");
        querySelect.bindValue(0, A);
        querySelect.bindValue(1, B);
        querySelect.bindValue(2, C);
        querySelect.bindValue(3, typeName);
        querySelect.exec();
    }else if(typeName=="三次曲线拟合"){
        querySelect.prepare( "update tb_data_fit set data_fit_A=?,data_fit_B=?,data_fit_C=?,data_fit_D=? where type_name=?");
        querySelect.bindValue(0, A);
        querySelect.bindValue(1, B);
        querySelect.bindValue(2, C);
        querySelect.bindValue(3, D);
        querySelect.bindValue(4, typeName);
        querySelect.exec();
    }
}
QSqlQuery SQLList::selectDataFitType(QString typeName){

    QString sql = "select data_fit_A,data_fit_B,data_fit_C,data_fit_D from tb_data_fit where type_name='"+typeName+"'";
    QSqlQuery query;
    query.exec(sql);
    return query;
}
void SQLList::deleteSampleById(int id)
{
    QSqlQuery querySelect;
    querySelect.prepare( "delete from tb_sample where id=?");
    querySelect.bindValue(0, id);
    querySelect.exec();

}
QSqlQuery SQLList::getFitDataByType(QString typeName){
    QString sql = "select data_fit_A,data_fit_B,data_fit_C,data_fit_D from tb_data_fit where type_name='"+typeName+"'";
    QSqlQuery query;
    query.exec(sql);
    return query;
}
void SQLList::inserSpectrumData(QStringList list,connectMYSQL *mySql){
    // qDebug()<<data;
    mySql->db.transaction();
    QSqlQuery query;
    query.prepare("insert into tb_spectrum_data (spectrum_data_x,spectrum_data_y,create_time) values (?,?,?)");
    query.addBindValue(spectrumData_x);
    query.addBindValue(spectrumData_y);
    query.addBindValue(createTime);
    query.execBatch();
    mySql->db.commit();
    spectrumData_x.clear();
    spectrumData_y.clear();
    createTime.clear();
//    for(int i=0;i<list.length();i++){
//        QSqlQuery query;
//        QString sql = "insert into tb_spectrum_data (spectrum_data_x,spectrum_data_y,create_time) values "+list.at(i);
//        query.exec();
//    }



}
