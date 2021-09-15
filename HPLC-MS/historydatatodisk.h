#ifndef HISTORYDATATODISK_H
#define HISTORYDATATODISK_H

#include <QObject>
#include <QDebug>
#include <QDateTime>
#include <QFile>
#include <QJsonDocument>
#include <QDir>
#include <QJsonArray>
#include <QJsonObject>
#include <fstream>

#include <iostream>
#include <string>
#include "CJsonObject.hpp"
#include <QIcon>
#include <QStandardItem>
#include "stdfix.h"
using namespace std;
using namespace neb;

class HistoryDataToDisk:public QObject
{
    Q_OBJECT
public:
    HistoryDataToDisk(QObject *parent = nullptr);
signals:
    void moveQStandardItem(QStandardItem* itemProject,HistorySortData sort);
public slots:
    void diskMethod(QString value);
};

#endif // HISTORYDATATODISK_H
