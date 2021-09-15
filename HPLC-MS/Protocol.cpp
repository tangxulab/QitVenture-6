
#include "Protocol.h"


static int count;//当前质谱字节流长度
static int count_ss;//当前气压字节流长度
static int HP_count;//求平均质谱数据计数
static int flag;
static int clip_pipe_flag;
extern double low_v;
extern double high_v;
static int all_count;//质谱图总字节流长度
static int clip_pipe_all_count;//气压图总字节流长度
static int sum ;//10张质谱图数据之和
static int times;//10张质谱图数据
extern bool mode_flag;
extern int clip_sum;
int count_ss_times;//当气压图一个周期生成5个峰的寻求5个峰的最大值
bool  count_ss_times_flag = false;
//bool ss_start = false;
extern int total_cycle;
int cycle_total_count;
bool methodSendRsult = false;
QVariantList  spectrumData_x;
QVariantList  spectrumData_y;
QVariantList  createTime;


//extern QMessageBox *closeMessgae;
extern QMessageBox *msgBox;


QByteArray readdata_all("");
QByteArray readdata_ss_all("");
extern int peak_max_count;
Protocol::Protocol()
{
    check=new crcCheckSum();
}

Protocol::~Protocol()
{


}


void Protocol::readByteData(QByteArray readdata)
{
    arrayList.append(readdata);
    int length = ((arrayList[3]<<8)&(0xFF<<8))+(arrayList[4]&0xFF);
    QByteArray readdata1 = arrayList.left(5+length+3);
    while ((readdata1.size()==length+8)&&!arrayList.isEmpty()) {
        arrayList = arrayList.mid(5+length+3);
        length = ((arrayList[3]<<8)&(0xFF<<8))+(arrayList[4]&0xFF);
        justifyData(readdata1);
        readdata1 = arrayList.left(5+length+3);
    }
}


void Protocol::justifyData(QByteArray readdata)
{

    if (readdata.at(0)!= this->getFrameHead()){

        //qDebug() << "WaringCode:";
        return;
    }
    switch (readdata.at(1))
    {
    case DATA_ACTIVE_REQUEST:
        switch (readdata.at(2)&0XFF)
        {
        case DataActiveRequest::READ_VOLTAGE:
            //电压读取
            break;
        case DataActiveRequest::READ_ERROR_CODE:
            //错误码读取
            break;
        case DataActiveRequest::READ_INSTRUMENT_SERIAL_NUMBER:
            //仪器序列号读取
            break;
        case DataActiveRequest::READ_SYSTEM_SELF_CHECK_RESULT:
            //系统自检结果读取
            break;
        case DataActiveRequest::TUNING:
            //调谐
            break;
        default:
            break;
        }
        break;
    case PARAMETER_CONTROL:
        switch (readdata.at(2)&0xff)
        {
        case ParameterControl::READ_VOLTAGE:
            //电压设定
            break;
        case ParameterControl::TESTING_BEGAN:
            //检测开始
            switch(readdata.at(7)&0xFF){

            case ParameterControl::SUCCESS:{
                //closeMessgae->hide();
                // closeMessgae->hide();
                if(msgBox!=nullptr)
                    msgBox->hide();
            }
            }
            break;
        case ParameterControl::FIRST_SWIFT:
            break;
        case ParameterControl::SECOND_SWIFT:
            break;
            //
        case ParameterControl::METHOD_SET:
            switch(readdata.at(7)&0XFF)
            {
            case ParameterControl::SUCCESS:
            {

                //                if(main_menu_method_set)
                //                {

                QMessageBox msg;
                msg.setText("设置成功");
                msg.exec();
                //                }

                break;

            }
            case ParameterControl::FAIL:

                break;
            }
            break;
            //方法设定
        default:
            break;
        }
        break;
    case MICROCONTROLLER_ACTIVE_UPLOAD:
        switch (readdata.at(2)&0XFF)
        {
        case MicrocontrollerActiveUpload::ALARM_CODE:
            break;
        case MicrocontrollerActiveUpload::ION_INFORMATION:
        {
            count= ((readdata.at(3)<<8)&(0xFF<<8))+(readdata.at(4)&0xFF)-2;
            // qDebug()<<count;
            // //qDebug()<<"数据1:"<<readdata.toHex().toUpper();
            readdata_all=readdata;
            //qDebug()<<"数据2:"<<readdata_all.toHex().toUpper();
            ShowOneMS();
        }

            break;
        case MicrocontrollerActiveUpload::SS:
        {
            count_ss= ((readdata.at(3)<<8)&(0xFF<<8))+(readdata.at(4)&0xFF)-2;
            readdata_ss_all=readdata;
            ShowOneSS();
        }
            break;
        case MicrocontrollerActiveUpload::MULTIPLIER_TUBE_VOLTAGE:
        {
            //  qDebug()<<readdata.toUpper().toHex();
            emit clip_pipe_data_change();
            if(count_ss_times==5){
                for(int i=0;i<clip_pipe_all_count;i++)
                {
                    clip_pipe_x[i] = 0;
                    clip_pipe_y[i] =0;
                }

                count_ss_times = 0;
                clip_pipe_flag=0;
                clip_pipe_all_count=0;
            }
            count_ss_times++;
            //qDebug()<<readdata.toHex();
            int multiplier_tube_voltage= ((readdata.at(7)<<8)&(0xFF<<8))+(readdata.at(8)&0xFF);
            int pressure= ((readdata.at(9)<<8)&(0xFF<<8))+(readdata.at(10)&0xFF);
            QByteArray stateByte = readdata.mid(11,7);
            QByteArray systemCheck = readdata.mid(18,2);

            // qDebug()<<pressure;
            double result = (pressure*1.0/65536)*2.5*5.7;

            emit multiplier_tube_voltage_signal(multiplier_tube_voltage,result,stateByte,systemCheck);
        }
            break;
        default:
            break;
        }
        break;
    }

}
//static double data_fit_A =-195.632;
//static double data_fit_B =4.42986;
//static double data_fit_C =0.000818204 ;
//static double data_fit_A =-191.983868154610633;
//static double data_fit_B =4.387367436869516;
//static double data_fit_C =0.000897860478619 ;
//static double data_fit_A =-258.341907396291504;
//static double data_fit_B =5.269369074709471;
//static double data_fit_C =0.000085797977850 ;
static int _count=0;
void Protocol::ShowOneMS()
{

    //QSqlQuery query =  getFitData("二次曲线拟合");

    HP_X.resize(HP_count+1);
    HP_Y.resize(HP_count+1);


    for(int i=0;i<count/2;i++)
    {
        this->y[i+all_count]=((readdata_all.at(7+2*i)<<8)&(0XFF<<8))+(readdata_all.at(7+2*i+1)&0XFF);
        //this->y.replace(i+flag*count/2,((readdata_all.at(7+2*i)<<8)&(0XFF<<8))+(readdata_all.at(7+2*i+1)&0XFF));
        // qDebug()<<this->y[i+all_count];
        // qDebug()<<i+flag*count/2;
        //_count++;
        // qDebug()<<_count;
        //        if((i+flag*count/2)==444)
        //            y[i+flag*count/2] = 3000;
        //        else {
        //            y[i+flag*count/2] =0;
        //        }
        sum+=y[i+all_count];

        if(max_vollage< this->y[i+flag*count/2])
            max_vollage =  this->y[i+flag*count/2];

    }
    all_count +=count/2;
    flag++;
    QString time = QDateTime::currentDateTime().toString();
    // qDebug()<<_count;

    if(all_count==sum_count)
    {
        //        qDebug()<<this->y;
        // qDebug()<<"-------------------------";
        //        for (int i=0;i<y.length();i++) {
        //               qDebug()<<y[i];

        //        }
        //         qDebug()<<"-------------------------";
        //        _count =0;
        //        qDebug()<<"asdasdsad";
        HP_X[HP_count] =HP_count;
        HP_Y[HP_count] = sum;
        HP_count++;
        times++;
        //        if(HP_count==10)
        //            HP_count = 0;
        flag=0;
        sum=0;
        all_count=0;
        if(peak_max_count>0)
        {
            peaKCount = new double*[peak_max_count];
            for(int i=0;i<peak_max_count;i++)
            {
                peaKCount[i] = new double[2];
            }
            double peakData = 0;
            bool flagPeak =false;
            for(int i =0;i<sum_count-1;i++)
            {

                //                QString data = "("+QString::number(this->x[i])+","+QString::number(y[i])+","+time+")";
                //                spectrumData<<data;

                //               spectrumData_x<<QString::number(this->x[i]);
                //               spectrumData_y<<QString::number(y[i]);
                //               createTime<<time;

                spectrumData+=QString::number(this->x[i])+","+QString::number(y[i])+"\r\n";
                if(y[i]<y[i+1])
                {
                    flagPeak =false;
                }
                else if(y[i]>y[i+1])
                {
                    if(y[i]>signalValue){ //设置默认值，判定信号

                        noTestSignal.append(x[i]);
                    }
                    //                    double MIDI = 0;
                    //                    double MI = 0;
                    //                    double x;

                    //                    if(i>=2&&i<=sum_count-3){
                    //                        MIDI = y[i-2]*(this->x[i-2])+y[i-1]*(this->x[i-1])+y[i]*(this->x[i])+y[i+1]*(this->x[i+1])+y[i+2]*(this->x[i+2]);
                    //                        MI=y[i-2]+y[i-1]+y[i]+y[i+1]+y[i+2];
                    //                        x=(MIDI/MI);
                    //                        this->x[i]=x;
                    //                    }
                    if(!flagPeak)
                    {
                        //peakData = y[i];
                        if(y[i]>peaKCount[0][1])
                        {
                            for(int k =peak_max_count-1;k>0;k--){
                                peaKCount[k][1] = peaKCount[k-1][1];
                                peaKCount[k][0] = peaKCount[k-1][0];
                            }
                            peaKCount[0][1]=y[i];
                            peaKCount[0][0]=this->x[i];
                        }
                        else {
                            for (int k=0;k<peak_max_count;k++) {
                                if(peaKCount[k][1]<y[i])
                                {
                                    for(int j=peak_max_count-1;j>k;j--)
                                    {
                                        peaKCount[j][1] = peaKCount[j-1][1];
                                        peaKCount[j][0] = peaKCount[j-1][0];
                                    }
                                    peaKCount[k][1] = y[i];
                                    peaKCount[k][0]=this->x[i];
                                    break;
                                }
                            }
                        }
                        flagPeak  = true;
                    }

                }
            }
            emit sendNoTestSignal(noTestSignal);
            noTestSignal.clear();
        }
        emit getPeakListSignal();
        if(mode_flag)
        {
            // //qDebug()<<"dsf";
            ////qDebug()<<spectrumData.join(",");
            emit wave_data_change(x,y);

            emit mock_none();
        }else {
            if(times>=10)
            {

                double aa=0;
                for(int i=0;i<sum_count;i++)
                {
                    for(int j=0;j<=9;j++)
                    {
                        aa += map_array.find(j).value().at(i);
                    }
                    avg_y[i]=aa/10;
                    aa=0;
                }
                emit avg_wave_data_change();
                emit mock_none();
            }
            else {

                emit wave_data_change(x,y);
            }

        }

        max_vollage_copy = max_vollage;
        max_vollage=0;
    }

}

void Protocol::ShowOneSS()
{

    for(int i=0;i<count_ss/2;i++)
    {
        clip_pipe_x[i+clip_pipe_all_count]=(i+clip_pipe_all_count);
        clip_pipe_y[i+clip_pipe_all_count]=(((readdata_ss_all.at(7+2*i)<<8)&(0XFF<<8))+(readdata_ss_all.at(7+2*i+1)&0XFF))*1.0/65535*2.5*4;
    }
    clip_pipe_all_count+=(count_ss/2);
    clip_pipe_flag++;
}
QByteArray Protocol::temperatureSet(int* data)
{
    QByteArray Instruction;
    actionCode = static_cast<int>(ActionCode::PARAMETER_CONTROL);
    commandCode = 0x01;
    length = 10 + 2;
    Instruction = formInstruction(actionCode, commandCode, length, data);
    return Instruction;
}

QByteArray Protocol::LTMSet(int x, int* data)
{
    QByteArray Instruction;
    actionCode = static_cast<int>(ActionCode::PARAMETER_CONTROL) ;
    commandCode = 0x02;
    length = 4 * x + 3;
    Instruction.append(char(frameHead));
    Instruction.append(char(actionCode));
    Instruction.append(char(commandCode));
    QString temp = "%1";
    Instruction.append(QByteArray::fromHex(temp.arg(length, 4, 16, QLatin1Char('0')).toLatin1().data()));
    Instruction.append(0x01);
    Instruction.append(0x01);
    Instruction.append(char(x));
    for (int i = 0; i < (length - 3) / 2; i++)
        Instruction.append(QByteArray::fromHex(temp.arg(data[i + 1], 4, 16, QLatin1Char('0')).toLatin1().data()));
    crcCheck = crc.crc16ForModbus(Instruction.mid(1));
    Instruction.append(QByteArray::fromHex(temp.arg(crcCheck, 4, 16, QLatin1Char('0')).toLatin1().data()));
    Instruction.append(char(frameTail));
    return Instruction;

}

QByteArray Protocol::voltageSet(int* data)
{
    QByteArray Instruction;
    actionCode = static_cast<int>(ActionCode::PARAMETER_CONTROL);
    commandCode = 0x03;
    length = 6 + 2;
    Instruction = formInstruction(actionCode, commandCode, length, data);
    return Instruction;
}

QByteArray Protocol::flowSet(int* data)
{
    QByteArray Instruction;
    actionCode = static_cast<int>(ActionCode::PARAMETER_CONTROL);
    commandCode = 0x04;
    length = 4 + 2;
    Instruction = formInstruction(actionCode, commandCode, length, data);
    return Instruction;
}

QByteArray Protocol::menthodSet(int* data)
{
    QByteArray Instruction;
    actionCode = static_cast<int>(ActionCode::PARAMETER_CONTROL);
    commandCode = 0x81;
    length = 40 + 2 +2+2+2;
    Instruction.append(char(frameHead));
    Instruction.append(char(actionCode));
    Instruction.append(char(commandCode));
    QString temp = "%1";
    Instruction.append(QByteArray::fromHex(temp.arg(length, 4, 16, QLatin1Char('0')).toLatin1().data()));
    Instruction.append(0x01);
    Instruction.append(0x01);
    Instruction.append(char(data[0]));
    Instruction.append(char(data[1]));
    for (int i = 0; i < 12; i++)
        Instruction.append(QByteArray::fromHex(temp.arg(data[i + 2], 4, 16, QLatin1Char('0')).toLatin1().data()));
    Instruction.append(char(data[14]));
    Instruction.append(QByteArray::fromHex(temp.arg(data[15], 4, 16, QLatin1Char('0')).toLatin1().data()));
    Instruction.append(QByteArray::fromHex(temp.arg(data[16], 4, 16, QLatin1Char('0')).toLatin1().data()));
    Instruction.append(QByteArray::fromHex(temp.arg(data[17], 4, 16, QLatin1Char('0')).toLatin1().data()));
    Instruction.append(QByteArray::fromHex(temp.arg(data[18], 4, 16, QLatin1Char('0')).toLatin1().data()));
    Instruction.append(QByteArray::fromHex(temp.arg(data[19], 4, 16, QLatin1Char('0')).toLatin1().data()));
    Instruction.append(char(data[20]));
    Instruction.append(QByteArray::fromHex(temp.arg(data[21],4,16,QLatin1Char('0')).toLatin1().data()));
    Instruction.append(QByteArray::fromHex(temp.arg(data[22],4,16,QLatin1Char('0')).toLatin1().data()));
    Instruction.append(QByteArray::fromHex(temp.arg(data[23],4,16,QLatin1Char('0')).toLatin1().data()));
    Instruction.append(QByteArray::fromHex(temp.arg(data[24],4,16,QLatin1Char('0')).toLatin1().data()));
    crcCheck = crc.crc16ForModbus(Instruction.mid(1));
    Instruction.append(QByteArray::fromHex(temp.arg(crcCheck, 4, 16, QLatin1Char('0')).toLatin1().data()));
    Instruction.append(char(frameTail));
    //qDebug()<<"设置发送："<<Instruction.toHex().toUpper();
    return Instruction;
}

QByteArray Protocol::formInstruction(int action, int command, int length, int* data)
{
    QByteArray Instruction;
    Instruction.append(char(frameHead));
    Instruction.append(char(action));
    Instruction.append(char(command));
    QString temp = "%1";
    Instruction.append(QByteArray::fromHex(temp.arg(length, 4, 16, QLatin1Char('0')).toLatin1().data()));
    Instruction.append(0x01);
    Instruction.append(0x01);
    for (int i = 0; i < (length - 2) / 2; i++)
        Instruction.append(QByteArray::fromHex(temp.arg(data[i], 4, 16, QLatin1Char('0')).toLatin1().data()));
    crcCheck = crc.crc16ForModbus(Instruction.mid(1));
    Instruction.append(QByteArray::fromHex(temp.arg(crcCheck, 4, 16, QLatin1Char('0')).toLatin1().data()));
    Instruction.append(char(frameTail));
    return Instruction;
}
QByteArray Protocol::formStableInstruition(int sta, int command)
{
    QByteArray Instruction;
    actionCode = static_cast<int>(ActionCode::PARAMETER_CONTROL);
    //commandCode = static_cast<int>(MicrocontrollerActiveUpload::ION_INFORMATION);
    Instruction.append(char(frameHead));
    Instruction.append(char(actionCode));
    Instruction.append(char(command));
    QString temp = "%1";
    Instruction.append(char(0x00));
    Instruction.append(0x03);
    Instruction.append(0x01);
    Instruction.append(0x01);
    Instruction.append(char(sta));
    crcCheck = crc.crc16ForModbus(Instruction.mid(1));
    Instruction.append(QByteArray::fromHex(temp.arg(crcCheck, 4, 16, QLatin1Char('0')).toLatin1().data()));
    Instruction.append(char(frameTail));
    return Instruction;

}
//TD-ESI 模块
QByteArray Protocol::TDESIInstruction(int address, int command,int length,int data)
{
    QByteArray array;
    array.append(char(frameHead));
    array.append(char(address));
    array.append(char(command));
    array.append(char(length));
    // for (int i=0;i<length;i++) {
    QString temp = "%1";
    array.append(QByteArray::fromHex(temp.arg(data, length*2, 16, QLatin1Char('0')).toLatin1().data()));
    array.append(char(frameTail));
    return array;
}
void Protocol::readData()
{


}
QSqlQuery Protocol::getFitData(QString typeName){

    SQLList *sqlList = new SQLList();
    QSqlQuery SqlQuery = sqlList->getFitDataByType(typeName);
    return SqlQuery;
}
