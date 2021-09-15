#include "connectMYSQL.h"

connectMYSQL::connectMYSQL()
{

    db =  QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("127.0.0.1");      //如果填入localhost,则表示链接本地的数据库
    db.setDatabaseName("hplc");       //要连接的数据库名
    db.setUserName("root");
    db.setPassword("123456");
    db.setPort(3306);

    if(db.open())
    {
        qDebug() << "连接数据库ok";
        db.exec("SET NAMES 'UTF-8'"); ///设置utf-8编码

        return;
    }
    //  db.close();


}
