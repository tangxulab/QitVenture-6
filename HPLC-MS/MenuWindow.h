#ifndef MENUWINDOW_H
#define MENUWINDOW_H
//测试人员主界面类
#include <QMainWindow>
#include <QtWidgets/QWidget>
#include <QtNetwork>
#include <QSerialPort>
#include "Protocol.h"
#include "RingBuffer.h"
#include "GaugeRingBuffer.h"
#include "InjectPumpRingbuffer.h"
#include "TDESIRingBuffer.h"
#include <QVBoxLayout>
#include "WaveFormWindow.h"
#include "ChromatographicFormWindow.h"
#include "clippipevalvewindow.h"
#include <QByteArray>
#include <CameraWindow.h>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include <QIODevice>
//#include "MyWidget.h"
#include <QString>
#include "MainWindow.h"
#include "controlpancelwindow.h"
#include "wavepeaklistwindow.h"
#include  "CheckAMSWindow.h"
#include "connectMYSQL.h"
#include "SQLList.h"
#include<QSqlDatabase>
#include <QSqlQuery>
#include "slidingwindow.h"
#include <QSqlQuery>
//#include <QSqlList>
#include "QMessageSendAndRevice.h"
#include "LockWaveWindow.h"
#include <QQuickWidget>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QProgressBar>
#include <QMetaObject>
#include "ToggleWindow.h"
#include "WaveHistoryData.h"
#include <fstream>
#include <QCloseEvent>
#include <iostream>
#include <string>
#include "historydatatodisk.h"
#include "permissionwindow.h"
#include "stdfix.h"
#include "SampleInfoInsertWindow.h"
#include "librarywindow.h"
#include "systemconfigurationwindow.h"
#include <QLineEdit>
#include "systemcheckwindow.h"
#include "qualitative_param_window.h"
using namespace std;

namespace Ui {
class MenuWindow;
}
class MyWidget : public QWidget
{
public:
    QSize sizeHint() const
    {
        return QSize(270, 300); /* 在这里定义dock的初始大小 */
    }
};



class MenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = nullptr);
    void loadStyleSheet(const QString &styleSheetFile);//对样式文本文件进行加载
    void closeEvent(QCloseEvent *event);


    void PulseTimeOut();//网口连接超时动作
    void setMethod();//方法设置
    void ExperimentStart();//实验开始

    void readDataTovacrb(void);//485数据分类
    QString sendVacMessage(QString message);//485数据发送至下位机

    void pumpStart_clicked();//分子泵开启


    void sendPumpON();//分子泵开关实现
    void sendPumpOFF();


    void end_point_clicked();//排废液

    QString sendInjectPump(QString message);//注射泵数据传送
    QString sendGauge(QString message); //真空规数据传送
    QString sendVTDESIMessage(QByteArray message);//TD-ESI数据传送


    void setVolumeProgree(double dist);//根据注射泵剩余体积对注射泵的其他按钮的设置

    void extract_start_clicked();//开始抽取

    void startInject_clicked();//开始执行
    void stopInject_clicked();//停止执行
    void queryVolume_clicked();//查询剩余体积

    void SendInstrcution(QString message);//网口数据传送

    //以下4个方法是对分子泵返回数据的处理
    QString tempDeleteZero(QString message);
    QString spdDeleteZero(QString message);
    QString voltageDeleteZero(QString message);
    QString currentDeleteZero(QString message);

    //读写文件数据
    QString readDataFromFile(QString filePath);
    void writeDataToFile(QString filePath,QString data);
    void initFile(QString filePath);
    int bytesToInt(QByteArray bytes);

    void clean_inject_pump();





    void paramSet_init();
    void dockWidget_init();
    void paramTree_init();
    void tableWidget_td_esi_set_init();
    void menuBar_init();
    void fileData_init(QString account);
    void connectList();
    void ms_db_window();

    ~MenuWindow();
signals:
    void sigalWork();
    void pushQueue(QByteArray array,SerialPortData type);
    void pushDiskMethod(QString value);
public slots:
    //    void get_x_y_value();
    void acceptConnnection();//仪器连接
    void readMicrocontrollerToPc();//读取单片机发至PC段的数据
    void wave_form_change(QVector<double> x, QVector<double> y);//质谱图的图像数据显示
    void socketdisconnect();//断开通讯
    void vacRequest();//定时器返回值
    void readData2vacrb(void);
    void windowQuit();//关闭主窗口
    void clip_pipe_from_change();//夹管阀图像数据显示
    void avg_wave_form_change();//质谱图求平均过后的图像数据显示
    // void tempData();

    void getPeakList();//寻峰界面表格数据展示事件
    void slot_search_peak();//寻峰界面上的寻峰按钮事件


    void controlPancelWindowShow();//控制面板界面
    void searchPeakWindow();

    void checkAMSWindowShow();
    void setCheckAMS();

    void create_method();
    void select_method();
    void methodInfoSave(QString fileName);

    //以下是自动的相关事件
    void dipaphragm_pump_open();//隔膜泵
    void toolButton_inject_sample_open();//注射泵
    void toolButton_pinch_valve_open();//放气（待定）
    void toolButton_high_voltage_open();//高压
    void toolButton_24_voltage_open();//RF-24v
//    void toolButton_48_voltage_open();//RF-48v
    void toolButton_camera_lighting_open();//探头灯
    void toolButton_molecular_pump_open();//分子泵

    /////////////////////////////////////

    void  camera_window_open();//打开照相机界面

    void slotBtn_wave();//质谱图刷新按钮事件
    //void on_line_spectrometry_lock_stateChanged(int arg1);//指定XY轴范围
    //void on_spe_clicked();//原始数据
    //void on_cen_clicked();//取平均数据

    //以下是做测试所用方法（暂保留）
    void on_btn_indicator_light_clicked();
    void on_btn_pwm_scope_set_clicked();
    void on_btn_temperature_set_clicked();
    void on_btn_pwm_scope_close_clicked();
//    void on_btn_temp_close_clicked();
    void on_btn_high_voltage_clicked();
    //以下是浮动窗口图标和显隐设置
    void setShowIconCheck_dock_1(bool str);
    void setShowIconCheck_dock_2(bool str);
    void setShowIconCheck_dock_3(bool str);
    void setShowIconCheck_dock_4(bool str);
    void setShowIconCheck_dock_5(bool str);
    void dockWidget_show();
    void dockWidget_2_show();
    void dockWidget_3_show();
    void dockWidget_4_show();
    void dockWidget_5_show();
    void setActiveDock(bool str);

    void inject_pump_clean_stop();
    void setSpeed(QString text);
    void waveHistoryWindowShow();
    QSqlQuery getFitData(QString typeName);
    void ShengJin(double a,double b,double c,double d,QVector<double> &X123);
    void threadStartSlots();
    void threadStopSlot();
    void lockWaveWindowShow();
    void SaveToggleWindow();
    void insertToDBWindowShow();
    void permissionWindowShow();
    void spectrometry_lock(int state);
    void getInsertSampleInfo();
    void reciveNoTestSignal(QList<double> noTestSignal);
    void multiplier_tube_voltage_method(int,double,QByteArray,QByteArray);

    void system_configuration_window();
    void inject_pump_clean_perform();


    //485 输出处理
    void molecularPumpDataDeal(QString data,SerialPortData type);
    void GUIDataDeal(QString data,SerialPortData type);
    void ESIDataDeal(QString data,SerialPortData type);
    void injectDataDeal(QString data,SerialPortData type);
    void injectataVolumeDeal(QString data,SerialPortData type);

    void slot_mouseDoubleClickTip(QMouseEvent *event);
    // void pushIntoQueue(char *array);
    void inject_pump_auto_clean();
    void slotBtn_chromatographic();

public:
    int postion=0;
    MainWindow *mainWindow;
    ControlPancelWindow *controlPancelWindow=nullptr;
    connectMYSQL *mySql;

private slots:
    void on_btn_ion_trap_temp_clicked();


    void on_action_report_create_triggered();

    void on_action_system_check_triggered();

    void on_action_qualitative_param_triggered();
    void signal_set(int);

    void on_action_ms_db_triggered();

private:
    Ui::MenuWindow *MenuWindowUI;
    //网口接口
    QTcpServer* server;
    QTcpSocket* socket=nullptr;
    QMessageBox* connectMessgae;
    // QQuickWidget  *quickProgressBar;

    //五秒钟超时时间的心跳定时器
    QTimer* PulseTimer;
    QTimer* ShowMSTimer;
    QTimer *useData;
    Protocol *protocol;

    //已废弃
    GaugeRingBuffer gacrb;
    InjectPumpRingbuffer ipcrb;
    TDESIRingBuffer tdesicrb;


    //分子泵串口相关声明定义
    QSerialPort* vacSerial;
    QTimer* vacTimer;
    QTimer* tempTimer;

    //已废弃
    RingBuffer vacrb;
    enum COMSwitcn { pumpflag, gaugeflag, injectflag,TDESIFlag };
    COMSwitcn comSendStatus = pumpflag;
    QToolBox *toolBox_1;


    //主界面当中涉及到界面
    WaveFormWindow* waveFormWindow;
    ChromatographicFormWindow  *chromatographicFormWindow;
    ClipPipeValveWindow *clipPipeValveWindow;
    CameraWindow *cameraWindow=nullptr;
    WavePeakListWindow *wavePeakListWindow=nullptr;
    CheckAMSWindow *checkAMSWindow=nullptr;
    WaveHistoryData *slidingWindow=nullptr;
    LockWaveWindow *lockWavaWindow=nullptr;
    LibraryWindow *libraryWindow=nullptr;
    SystemCheckWindow *systemCheckWindow =nullptr;
    QMessageSendAndRevice *messageSendAndRevice;
    HistoryDataToDisk *historyDataDisk;
    ToggleWindow *toggleWindow;
    QThread *thread;

    QQuickWidget *quickProgressBar;

    PermissionWindow *permissionWindow=nullptr;
    SampleInfoInsertWindow *sampleInfoInsertWindow=nullptr;
    SystemConfigurationWindow *systemConfigurationWindow = nullptr;

    QString userAccount;
    int spectrumDataCount;

    int i=0,j=0;
    QVector<double> x, y;//质谱图XY

    int clean_times=0;//清洗次数
    int waste_times=0;//排废液次数
    double perform_rate;//执行速度
    bool clean_inject_pump_flag = false;
    bool pushDisk = false;

    QList<QString> signalNameList;
    Qualitative_Param_Window *qualitative_Param_Window=nullptr;

};

#endif // MENUWINDOW_H
