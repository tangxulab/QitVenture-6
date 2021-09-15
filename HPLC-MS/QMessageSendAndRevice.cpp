#include "QMessageSendAndRevice.h"
QList<char*> messageQueue;
QMutex m_mutex;//互斥量
QMessageSendAndRevice::QMessageSendAndRevice(QObject *parent)
{



}
void QMessageSendAndRevice::init(){
    //    vacSerial = new QSerialPort(this);
    //    //vacSerial->moveToThread(this);
    //    //vacTimer = new QTimer;

    //    vacSerial->setPortName("COM4");
    //    vacSerial->setBaudRate(QSerialPort::Baud9600);
    //    vacSerial->setDataBits(QSerialPort::Data8);
    //    vacSerial->setParity(QSerialPort::NoParity);
    //    vacSerial->setStopBits(QSerialPort::OneStop);
    //    vacSerial->setFlowControl(QSerialPort::NoFlowControl);
    //    vacSerial->open(QIODevice::ReadWrite);
    //   // vacSerial->moveToThread(this->thread());
    //   // vacSerial->thread()->moveToThread(this->thread());
    //    if(vacSerial->open(QIODevice::ReadWrite)){
    //        //vacSerial->setDataTerminalReady(true);
    //    }
    // connect(vacSerial, &QSerialPort::readyRead, this, &QMessageSendAndRevice::readData2vacrb);
}
void QMessageSendAndRevice::doWork()
{

    ////qDebug()<<"线程1"<<QThread::currentThread();
    vacSerial = new QSerialPort();
    vacSerial->setPortName("COM4");
    vacSerial->setBaudRate(QSerialPort::Baud9600);
    vacSerial->setDataBits(QSerialPort::Data8);
    vacSerial->setParity(QSerialPort::NoParity);
    vacSerial->setStopBits(QSerialPort::OneStop);
    vacSerial->setFlowControl(QSerialPort::NoFlowControl);
    vacSerial->open(QIODevice::ReadWrite);


}


QByteArray QMessageSendAndRevice::getQueue(){
    //    QEventLoop loop;
    //    QTimer::singleShot(500,&loop,SLOT(quit()));
    //    loop.exec();
    // m_mutex.lock();
    if(!messageQueue.isEmpty()){
        // //qDebug()<<"空"<<messageQueue.isEmpty()<<"大小"<<messageQueue.length();
        QByteArray  array = messageQueue.first();
        messageQueue.removeFirst();
        // //qDebug()<<"S实际数据"<<array.toHex().toLower();
        return array;
    }
    return nullptr;

    // m_mutex.unlock();


}

void QMessageSendAndRevice::readData2vacrb(void){
    // vacSerial->waitForReadyRead(1000);
    //  //qDebug()<<messageQueue.isEmpty();
    ////qDebug()<<"是否在运行："<<QThread::isRunning();
    if(this->vacSerial->isOpen())
    {

        QByteArray array = this->vacSerial->readAll();
        //for(int i=0;i<data.size();i++) vacrb.putch(data[i]);
        if(!array.isEmpty()){
            QString data = array.toHex().toUpper();
            midArray+=data;

        }

        //  reviceDataDeal(array);
        // emit startThread();
    }
}
void QMessageSendAndRevice::threadStart(){


    //this->start();
}
void QMessageSendAndRevice::StopThread(){
    isStop = true;
}

void QMessageSendAndRevice::StartThread(){
    //qDebug()<<"asdasdda";
    isStop = false;
}
void QMessageSendAndRevice::reviceDataDeal(QByteArray data){
    int midData = data.at(0);


    switch(midData) {
    case 0x2F:{
        //qDebug()<<"注射泵";
    };break;
    case 0x40:{
        //qDebug()<<"真空规";
    };break;
    case 0x01:{
        //qDebug()<<"分子泵";
    };break;
    case 0x55:{
        //qDebug()<<"ESI";
    };break;

    }
}
void QMessageSendAndRevice::pushIntoQueue(QByteArray array,SerialPortData type){
    //    while(1){
    //       // m_mutex.lock();
    //        QByteArray array =  getQueue();


    if(!array.isEmpty()){
        // midArray.clear();

        //        if(type==SerialPortData::MolecularPumpData)
        //            QThread::msleep(200);
        //QByteArray temp;
        // StringToHex(array, temp);
        //  //qDebug()<<"fasong"<<array.toHex();
        vacSerial->write(array);
        vacSerial->waitForBytesWritten(500);
        QByteArray reviceData;
        bool revice=false;
        while (!revice) {
            if(!vacSerial->waitForReadyRead(300)){
                break;
            }
            QByteArray array = this->vacSerial->readAll();
            reviceData = reviceData+array;
            QString reviceQString;
            if(type==SerialPortData::EsiData||type==SerialPortData::InjectPumpData){
                reviceQString =   reviceData.toHex().toUpper();
            }else {
                reviceQString = QString(reviceData);
            }

            //  QByteArray result = mid.toLatin1().data();
            //  QString  reviceQString =QByteArray::fromHex(result.data());
            // //qDebug()<<reviceQString;
            if(reviceQString.endsWith("\r")){
                emit molecularPumpData( reviceQString,type);
                revice = true;
            }else if(reviceQString.endsWith(";FF")){
                emit GUIData( reviceQString,type);
                revice = true;
            }else if (reviceQString.endsWith("AA")) {

                emit ESIData( reviceQString,type);
                revice = true;
            }else if (reviceQString.endsWith("0A")) {
                // //qDebug()<<data;
                QString flag = reviceQString.mid(4,2);
                if(flag=="60"){
                    emit injectataVolume( reviceQString,type);
                }else {
                    emit injectata( reviceQString,type);
                }

                revice = true;
            }

        }
    }
    //   QThread::sleep(1);
    // m_mutex.unlock();
    //    }
}

char QMessageSendAndRevice::ConvertHexChar(char ch)
{
    if((ch >= '0') && (ch <= '9'))
        return ch-0x30;
    else if((ch >= 'A') && (ch <= 'F'))
        return ch-'A'+10;
    else if((ch >= 'a') && (ch <= 'f'))
        return ch-'a'+10;
    else return (-1);
}


void QMessageSendAndRevice::StringToHex(QString str, QByteArray &senddata)
{
    int hexdata,lowhexdata;
    int hexdatalen = 0;
    int len = str.length();
    senddata.resize(len/2);
    char lstr,hstr;
    for(int i=0; i<len; )
    {
        //char lstr,
        hstr=str[i].toLatin1();
        if(hstr == ' ')
        {
            i++;
            continue;
        }
        i++;
        if(i >= len)
            break;
        lstr = str[i].toLatin1();
        hexdata = ConvertHexChar(hstr);
        lowhexdata = ConvertHexChar(lstr);
        if((hexdata == 16) || (lowhexdata == 16))
            break;
        else
            hexdata = hexdata*16+lowhexdata;
        i++;
        senddata[hexdatalen] = (char)hexdata;
        hexdatalen++;
    }
    senddata.resize(hexdatalen);
}


