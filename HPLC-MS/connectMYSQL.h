#ifndef CONNECTMYSQL_H
#define CONNECTMYSQL_H
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>

class connectMYSQL
{
public:
    connectMYSQL();
    QSqlDatabase  db;
};

#endif // CONNECTMYSQL_H
