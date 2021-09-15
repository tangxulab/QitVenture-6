//相关协议类
#pragma once
#include <QByteArray>
#include <QString>
#include "ProtocolCodeList.h"
#include "crcCheckSum.h"
#include <QTimer>
#include <QObject>
#include <QMessageBox>
#include <QMap>
#include <QDateTime>
#include <QSqlQuery>
#include "SQLList.h"
#include <QtMath>
using namespace ProtocolCode;
class Protocol:public QObject
{

    Q_OBJECT
private:
//协议格式
    const int frameHead = 0x55;
    int actionCode;
    int commandCode;
    int length;
    int frameCount;
    int currentCount;
    int dataSection;
    int crcCheck;
    const int frameTail = 0xAA;

    crcCheckSum *check;


public:
    Protocol();
    int getFrameHead()
    {
        return frameHead;
    }

    //FIRST COMMAND GROUP
    //以下6个方法暂时未使用
    QByteArray temperatureSet(int* data);
    QByteArray LTMSet(int x, int* data);
    QByteArray voltageSet(int* data);
    QByteArray flowSet(int* data);
    QByteArray formInstruction(int action, int command, int length, int* data);
    void readData();


    //扫描方法发送参数数据整合
    QByteArray menthodSet(int* data);
    //网口发送数据整合
    QByteArray formStableInstruition(int sta, int command);//实验开始初始化
   //TD-ESI发送数据整合
   QByteArray TDESIInstruction(int address, int command,int length,int data);
    ~Protocol();
    //网口数据接收入口
    void readByteData(QByteArray readdata);
    //网口数据判断识别
    void justifyData(QByteArray readdata);

    QSqlQuery getFitData(QString typeName);
public:
     QVector<double> HP_X,HP_Y;
    QVector<double> x, y;//质谱图XY
    QVector<double> clip_pipe_x,clip_pipe_y;//气压图XY
    QVector<double> avg_y;//质谱图求平均所对应的Y
    double low_mass_number;//低质量数
    double hight_mass_number;//高质量数
    int sum_count;
    QMap<int,QVector<double>> map_array;//求平均值所需临时缓冲区
    QList<double *> peak_pipe_data;//气压图峰值
    QList<double *> peak_pipe_data_time;
    QList<int> cycle_total_data_length;

    double max_vollage=0;//质谱图Y轴数据最大值
    double max_vollage_copy;
    double **peaKCount;
    QList<double> noTestSignal;

signals:
    //质谱图触发信号
    void wave_data_change(QVector<double> x, QVector<double> y);
    void avg_wave_data_change();
    //气压图触发信号
    void clip_pipe_data_change();

    void mock_none();
    void getPeakListSignal();
    void sendNoTestSignal(QList<double> noTestSignal);
    void multiplier_tube_voltage_signal(int,double,QByteArray,QByteArray);
public slots:
    void ShowOneMS();
    void ShowOneSS();


public:
    QByteArray arrayList;
    QString spectrumData="";
    int signalValue=600;
private:
    crcCheckSum crc;





};

