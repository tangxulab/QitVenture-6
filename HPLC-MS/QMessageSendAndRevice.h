#ifndef QMESSAGESENDANDREVICE_H
#define QMESSAGESENDANDREVICE_H
#include <QDebug>
#include <QThread>
#include <QMutex>
#include <QQueue>
#include <QSerialPort>
#include <QObject>

#include <QThread>
#include <QEventLoop>
#include <QTimer>
enum SerialPortData{

    GSCPump,
    MolecularPumpData,
    InjectPumpData,
    EsiData,
    InjectPumpVolume
};
class QMessageSendAndRevice:public QObject
{
    Q_OBJECT
public:
    QMessageSendAndRevice(QObject *parent = nullptr);

   // void pushQueue(char* array);
    QByteArray getQueue();
    void threadStart();

    void init();
    void StopThread();
    void StartThread();
    void reviceDataDeal(QByteArray data);
    char ConvertHexChar(char ch);
    void StringToHex(QString str, QByteArray &senddata);




    QSerialPort *vacSerial;

    QString midArray;
    // QByteArray array;
private:


    bool isStop;
    //QSerialPort *port;
    QThread *thread;
signals:
    void startThread();
    void threadStop();
    void molecularPumpData(QString data,SerialPortData type);
    void GUIData(QString data,SerialPortData type);
    void ESIData(QString data,SerialPortData type);
    void injectata(QString data,SerialPortData type);
    void injectataVolume(QString data,SerialPortData type);
public slots:
    void readData2vacrb();
    void doWork();
    void pushIntoQueue(QByteArray array,SerialPortData type);
};

#endif // QMESSAGESENDANDREVICE_H
