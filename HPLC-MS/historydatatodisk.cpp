#include "historydatatodisk.h"

HistoryDataToDisk::HistoryDataToDisk(QObject *parent)
{

}
void HistoryDataToDisk::diskMethod(QString value){

    //qDebug()<<value;
    QString fileNameList = QDateTime::currentDateTime().toString("yyyy_MM_dd_hh_mm_ss_zzz");
    //  //qDebug()<<QDir::currentPath()+"/spectrumData/"+time+".txt";
    QFile *file = new QFile(QDir::currentPath()+"/spectrumData/"+fileNameList+".txt");
    QFile historyDataFile(QDir::currentPath()+"/mapper/historyDataInventory.json");
    QIcon treeitemicon(QPixmap(":/images/script_text.png"));
    QIcon treerooticon(QPixmap(":/images/folder.png"));
    if(!historyDataFile.exists()){
        historyDataFile.open(QIODevice::ReadWrite);
        QJsonObject jsonObject;
        QString createTime =  QDateTime::currentDateTime().toString("yyyy-MM-dd");

        jsonObject.insert("size",1);
        QJsonObject jsonObjectChild;
        QJsonArray jsonArrayChild;
        jsonObjectChild.insert("dir",createTime);
        jsonObjectChild.insert("items",jsonArrayChild);

        QJsonArray array;
        array.append(jsonObjectChild);
        jsonObject.insert("array",array);

        // 使用QJsonDocument设置该json对象
        QJsonDocument jsonDocument;
        jsonDocument.setObject(jsonObject);

        // 将json以文本形式写入文件并关闭文件。
        // QJsonDocument jsonDoc
        QString newHistoryData = QDateTime::currentDateTime().toString("yyyy-MM-dd");
        QStandardItem* itemProject = new QStandardItem(treerooticon,newHistoryData);
        itemProject->setCheckable(true);
        QStandardItem* item = new QStandardItem(treeitemicon,fileNameList);
        itemProject->appendRow(item);
        item->setCheckable(true);
        moveQStandardItem(itemProject,HistorySortData::ITEM);
        historyDataFile.write(jsonDocument.toJson());
        historyDataFile.close();
    }






    if(file->open(QIODevice::Append|QIODevice::ReadWrite)){
        ////qDebug()<<"文件打开成功";
        QTextStream out(file);
        //file.write(protocol->map_array.find(postion).value());
        out<<value;

        out.flush();
        file->close();

    }else {
        //qDebug()<<"文件打开失败";
    }
    ifstream inf((QDir::currentPath()+"/mapper/historyDataInventory.json").toStdString(),ios::in);

    if(!inf.is_open()){
        //qDebug()<<"asdasd";
    }
    string content( (istreambuf_iterator<char>(inf) ),
                    (istreambuf_iterator<char>() ) );

    // cout<<content<<endl;
    inf.close();
    CJsonObject oJson(content);

    int size ;
    oJson.Get("size",size);
    // cout<<size<<endl;
    QString newHistoryData = QDateTime::currentDateTime().toString("yyyy-MM-dd");
    //    //qDebug()<<rootObject.value("array").toArray()[size-1].toObject().value("dir").toString()<<"----"<<newHistoryData;
    string lastDate;
    oJson["array"][size-1].Get("dir",lastDate);
   // cout<<lastDate <<"---"<<newHistoryData.toStdString()<<endl;

    if(lastDate==newHistoryData.toStdString()){

        ////qDebug()<<"add";
        CJsonObject object;
        object.Add("name",fileNameList.toStdString());
        oJson["array"][size-1]["items"].Add(object);

        QStandardItem* item = new QStandardItem(treeitemicon,fileNameList);

        item->setCheckable(true);
        moveQStandardItem(item,HistorySortData::LEAF);

    }else{
        CJsonObject object;

        // items.IsArray();
        object.Add("dir",newHistoryData.toStdString());
        object.AddEmptySubArray("items");
        oJson["array"].Add(object);
        oJson.Replace("size",size+1);



        QStandardItem* itemProject = new QStandardItem(treerooticon,newHistoryData);
        itemProject->setCheckable(true);
        QStandardItem* item = new QStandardItem(treeitemicon,fileNameList);
        itemProject->appendRow(item);
        item->setCheckable(true);

        itemProject->setCheckable(true);
        //  historyQStandardItem->appendRow(itemProject);
        moveQStandardItem(itemProject,HistorySortData::ITEM);


    }

    ofstream out((QDir::currentPath()+"/mapper/historyDataInventory.json").toStdString(),ios::out);
    out<<oJson.ToString();
    out.close();


}
