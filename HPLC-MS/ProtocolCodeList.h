//协议列表
#include <iostream>
namespace ProtocolCode {



//动作码
enum ActionCode
{
    DATA_ACTIVE_REQUEST = 0x01,	 //数据主动请求：0x01；
    PARAMETER_CONTROL = 0x10,//参数控制：0x10；
    MICROCONTROLLER_ACTIVE_UPLOAD = 0x20//单片机主动上传：0x20；
};


//---------------------数据主动请求-------------------------------------
namespace DataActiveRequest {
//命令码
enum DataActiveRequestCommandCode {

    READ_VOLTAGE = 0x03,//读取电压
    READ_ERROR_CODE = 0x06,//错误码读取
    READ_INSTRUMENT_SERIAL_NUMBER = 0x80,//仪器序列号读取
    READ_SYSTEM_SELF_CHECK_RESULT = 0x90,//系统自检结果读取
    TUNING = 0x10,//调谐
};
enum DataActiveRequestDataAreaCode
{
    SUCCESS = 0x11,//成功
    FAIL= 0x12//失败
};
}
//----------------------参数控制----------------------------------------
namespace ParameterControl {
enum ParameterControlCommandCode
{
    //PC->单片机:PC向单片机主动发送参数设置命令
    //第一组命令
    READ_VOLTAGE = 0x03,//读取电压
    //第二组命令
    TESTING_BEGAN = 0x15,//检测开始
    TUNING = 0x20,//调谐
    RELEASE_AIR = 0x22,//放空
    //自启动相关指令
    DIAPHRAGM_PUMP_POWER = 0x30,//隔膜泵电源开启
    RF_24_VOLTAGE_POWER = 0x31,//RF板24v电源开关
    RF_48_VOLTAGE_POWER = 0x32,//RF板48v电源开关
    HIGH_VOLTAGE_POWER = 0x33,//高压板电源开关
    //第八组命令
    FIRST_SWIFT = 0x71,
    SECOND_SWIFT = 0x72,
    METHOD_SET = 0x81,//方法设定
};

enum ParameterControlDataAreaCode
{
    SUCCESS = 0x11,//成功
    FAIL = 0x12,//失败
    ON = 0x22,
    OFF = 0x23,


    FIXED= 0x01,
    AGC= 0x02,

    FULLSCAN= 0x01,
    MS_N= 0x02,
    SIM= 0x03,
    SIS= 0x04
};

}
//-----------------单片机主动上传----------------------------
namespace MicrocontrollerActiveUpload{
enum  MicrocontrollerActiveUploadCommandcode
{
    MULTIPLIER_TUBE_VOLTAGE = 0x01,//电子倍增管
    ION_INFORMATION = 0x81,//离子信息
    SS = 0x82,
    ALARM_CODE = 0xA0//报警码
    // TIME =0x01
};
enum MicrocontrollerActiveUploadDataAreaCode
{
    SUCCESS = 0x11,//成功
    FAIL = 0x12,//失败
};
}


}

//TD_ESI 协议
namespace TD_ESI_PROTOCOL_CODE{
//命令码
enum TD_ESI_COMMAND_CODE
{
    INDICATOR_LIGHT = 0x01,//24V 指示灯
    TEMPERATURE_ONE_SET = 0x02,//温度1设置
    TEMPERATURE_ONE_MEASUREMENT = 0x03,//测温
    SCOPE_OF_PWM = 0x04,// PWM范围
    HIGH_VOLTAGE_SET = 0x05,//高压设置
    HIGH_VOLTAGE_READING = 0x06,//高压读取
    HIGH_CURRENT_READING =0x07,//电流读取
    SCOPE_OF_PWM_CLOSE = 0x08,//PWM关闭
    TEMPERATUR_ONE_CLOSE = 0x09,//加热1关闭
    HIGH_VOLTAGE_LIGTHING= 0x10,

    INJECT_SAMPLE_LIGHTING = 0x14,//进样照明灯
    DIPAPHRAGM_PUMP = 0x15,//隔膜泵
    TEMPERATURE_TWO_SET =0x22,
    TEMPERATURE_THREE_SET =0x32,
    TEMPERATURE_FOUR_SET =0x42,
    TEMPERATUR_TWO_CLOSE = 0x29,//加热2关闭
    TEMPERATUR_THREE_CLOSE = 0x39,//加热3关闭
    TEMPERATUR_FOUR_CLOSE = 0x49,//加热4关闭
    DIAPHRAGM_PUMP_POWER=0x15,//隔膜泵
    CONTROL_TWO=0x16,
    CONTROL_THREE=0x17,
    CONTROL_FOUR=0x18,
    TEMPERATURE_TWO_MEASUREMENT=0x53,
    TEMPERATURE_THREE_MEASUREMENT=0x63,
    TEMPERATURE_FOUR_MEASUREMENT=0x73,
    INDICATOR_LIGHT_STATUS=0x80,
    TEMPERATURE_ONE_SET_STATUS=0x81,
    TEMPERATURE_TWO_SET_STATUS=0x82,
    TEMPERATURE_THREE_SET_STATUS=0x83,
    TEMPERATURE_FOUR_SET_STATUS=0x84,
    HIGH_VOLTAGE_LIGHTING_STATUS=0x85,
    SCANNING_LIGHTING_STATUS=0x86,
    SYSTEM_LIGHTING_STATUS=0x87,
    VACUUM_LIGHTING_STATUS=0x88,
    INJECT_SAMPLE_LIGHTING_STATUS=0x89,
    DIAPHRAGM_PUMP_POWER_STATUS=0x90,
    CONTROL_TWO_STATUS=0x91,
    CONTROL_THREE_STATUS=0x92,
    CONTROL_FOUR_STATUS=0x93,






};

namespace  TD_ESI_COMMAND_CODE_ADDRESS_CODE{
enum ADDRESS_CODE{
    ESI_ADDRESS_CODE = 0x88
};

}

namespace  TD_ESI_COMMAND_CODE_DATA_AREA_CODE{

enum DATA_AREA_CODE
{
    SUCCESS = 0x11,
    FAIL = 0x12,
    ON = 0x01,
    OFF = 0x02,
    SCOPE_OF_PWM_OFF=0x44,
    OPEN = 0xEE,
    CLOSE = 0xFF

};
}
}

//自启动
namespace SELF_TURN_ON_PROTOCOL_CODE{
//命令码
enum SELF_TURN_ON_COMMAND_CODE
{
    HIGH_VOLTAGE_LIGHTING = 0x10,//高压指示灯
    SCANNING_LIGHTING = 0x11,//扫描指示灯
    SYSTEM_LIGHTING = 0x12,//系统（真空，高压）指示灯
    VACUUM_LIGHTING = 0x13,// 真空度指示灯

};
namespace  SELF_TURN_ON_COMMAND_CODE_DATA_AREA_CODE{

enum DATA_AREA_CODE
{
    SUCCESS = 0x11,
    FAIL = 0x12,
    ON = 0x01,
    OFF = 0x02,
    // SCOPE_OF_PWM_OFF=0x44
};
}

}
