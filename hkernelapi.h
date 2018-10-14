#ifndef HKERNELAPI_H
#define HKERNELAPI_H
#include "hkernelexport.h"
#include <QtGlobal>
#include <QtWidgets/QWidget>
#include <QFlags>
#include <QEvent>
#include "hfileapi.h"
#include "hnamespace.h"

//实时库内部的数据类型
#define TYPE_NULL            0
#define TYPE_STATION         1
#define TYPE_ANALOGUE        2
#define TYPE_DIGITAL         3
#define TYPE_RELAY           4//遥控
#define TYPE_GROUP           5//间隔
#define TYPE_GROUPIP         6
#define TYPE_SETPOINT        7 //遥调
#define TYPE_PULSE           8 //遥脉

//实时库相关数据类型
//厂站
#define     ATTR_ST_NO           0x001
#define     ATTR_ST_ADDR         0x002
#define     ATTR_ST_NAME         0x003
#define     ATTR_ST_SLOCK        0x004
#define     ATTR_ST_TOTALANA     0x005
#define     ATTR_ST_TOTALDGT     0x006
#define     ATTR_ST_TOTALEGROUP  0x007
#define     ATTR_ST_TOTALLOCK    0x008

//遥信
#define     ATTR_DGT_SNO               0x032 //50
#define     ATTR_DGT_NO                0x033
#define     ATTR_DGT_COMBONAME         0x034
#define     ATTR_DGT_ORINAME           0x035
#define     ATTR_DGT_POINTTERMID       0x036
#define     ATTR_DGT_EQUIPMENTID       0x037
#define     ATTR_DGT_GROUPID           0x038
#define     ATTR_DGT_POWERGRADE        0x039
#define     ATTR_DGT_OPTERMID          0x040
#define     ATTR_DGT_RULEFENID         0x041
#define     ATTR_DGT_RULEHEID          0x042
#define     ATTR_DGT_RULEJXFENID       0x043
#define     ATTR_DGT_RULEJXHEID        0x044
#define     ATTR_DGT_LOCKNO            0x045
#define     ATTR_DGT_HELOCKNO          0x046
#define     ATTR_DGT_FENLOCKNO         0x047
#define     ATTR_DGT_SENDFLAG          0x048
#define     ATTR_DGT_DOUBLEDGTID       0x049
#define     ATTR_DGT_OPFLAG            0x050
#define     ATTR_DGT_FORMULAID         0x051
#define     ATTR_DGT_VALUE             0x052
#define     ATTR_DGT_RSNO              0x053
#define     ATTR_DGT_RNO               0x054
#define     ATTR_DGT_MEASURE           0x055
#define     ATTR_DGT_4_STATE_VALUE     0x056 //4态遥信
#define     ATTR_DGT_TOTALNORMALCLOSE  0x030D   //正常合闸总数
#define     ATTR_DGT_TOTALNORMALOPEN   0x030E //,       "正常分闸总数"},
#define     ATTR_DGT_TOTALFAULTSWITCH  0x030F //,      "事故变位总数"},

#define     ATTR_DGT_TOTALFAULTSWITCH  0x030F //,      "事故变位总数"},
#define     ATTR_DGT_DAYNORMALCLOSE    0x0310 //,        "日正常合闸次数"},
#define     ATTR_DGT_DAYNORMALOPEN     0x0311 //         "日正常分闸次数"},
#define     ATTR_DGT_DAYFAULTSWITCH    0x0312 //,		"日事故变位次数"},
#define     ATTR_DGT_MONNORMALCLOSE    0x0313 //,        "月正常合闸次数"},
#define     ATTR_DGT_MONNORMALOPEN     0x0314 //,         "月正常分闸次数"},
#define     ATTR_DGT_MONFAULTSWITCH    0x0315 //,		"月事故变位次数"},
#define     ATTR_DGT_YEARNORMALCLOSE   0x0316 //,       "年正常合闸次数"},
#define     ATTR_DGT_YEARNORMALOPEN    0x0317 //,        "年正常分闸次数"},
#define     ATTR_DGT_YEARFAULTSWITCH   0x0318 //,       "年事故变位次数"},
   
//遥测
#define     ATTR_ANA_SNO           0x096 //150
#define     ATTR_ANA_NO            0x097
#define     ATTR_ANA_NAME          0x098
#define     ATTR_ANA_ORINAME       0x099
#define     ATTR_ANA_TYPE          0x100
#define     ATTR_ANA_UINT          0x101
#define     ATTR_ANA_CC1           0x102
#define     ATTR_ANA_CC2           0x103
#define     ATTR_ANA_CC3           0x104
#define     ATTR_ANA_DIFF          0x105
#define     ATTR_ANA_GRADE         0x106
#define     ATTR_ANA_SENDFLAG      0x107
#define     ATTR_ANA_GROUPID       0x108
#define     ATTR_ANA_POWERGRADE    0x109
#define     ATTR_ANA_RELDIGITALID  0x110
#define     ATTR_ANA_VALUE         0x111

#define     ATTR_ANA_DAYMAXVALUE          0x120
#define     ATTR_ANA_DAYMINVALUE          0x121
#define     ATTR_ANA_DAYAVEVALUE          0x122
#define     ATTR_ANA_MONMAXVALUE          0x123
#define     ATTR_ANA_MONMINVALUE          0x124
#define     ATTR_ANA_MONAVEVALUE          0x125
#define     ATTR_ANA_YEARMAXVALUE         0x126
#define     ATTR_ANA_YEARMINVALUE         0x127
#define     ATTR_ANA_YEARAVEVALUE         0x128
#define     ATTR_VOLTAGE_DAYNORMALTIME    0x153
#define     ATTR_VOLTAGE_DAYLOWTIME       0x154
#define     ATTR_VOLTAGE_DAYHIGHTIME      0x155
#define     ATTR_VOLTAGE_MONNORMALTIME    0x156
#define     ATTR_VOLTAGE_MONLOWTIME       0x157
#define     ATTR_VOLTAGE_MONHIGHTIME      0x158
#define     ATTR_VOLTAGE_DAYQUALIFIEDRATE 0x159
#define     ATTR_VOLTAGE_MONQUALIFIEDRATE 0x160


//pulse
#define     ATTR_PUL_RAW            0x532     //"原始值"},
#define     ATTR_PUL_COUNTERVALUE   0x50F   //,    "工程值"},
#define     ATTR_PUL_COUNTERMIN     0x509   //,      "分钟电量"},
#define     ATTR_PUL_COUNTERHOUR    0x50A   //,     "小时电量"},
#define     ATTR_PUL_COUNTERDAY     0x50B   //,      "日总电量"},
#define     ATTR_PUL_COUNTERMON     0x50D   //,      "月总电量"},


#define     ATTR_POWER_DAYPEKVALUE  0x0610  //,   "日峰电量"},
#define     ATTR_POWER_DAYVOLVALUE  0x0611  //,   "日谷电量"},
#define     ATTR_POWER_DAYPINVALUE  0x0612  //,   "日平电量"},
#define     ATTR_POWER_MONPEKVALUE  0x0617  //,   "月峰电量"},
#define     ATTR_POWER_MONVOLVALUE  0x0618  //,   "月谷电量"},
#define     ATTR_POWER_MONPINVALUE  0x0619  //,   "月平电量"},




#ifdef __cplusplus
extern "C"
{
#endif

typedef struct _tagDBHANDLE
{
    void* pSt;//station
    void* pPt;//point
}DBHANDLE;

typedef struct _tagEvent
{
        ushort wStation;
        uchar btType;
        ushort wPoint;
        ushort wAttrib;

        struct tm tmTime;

        DBHANDLE hHandle;
        void* pValue;
        ushort wValue;

        const char* pFileName;
        time_t lTime;
        uchar btHstType;
        struct tm tmTimeEnd;
        ushort wOffset;
        uchar btLength;
        ushort wReserved1;
        ushort wReserved2;

}KEREVENT;


#define TYPE_DB_REALTIME  0x01 //实时库
#define TYPE_DB_PREVIEW   0x02 //预演库
#define TYPE_DB_TEMPLATE  0x03 //模板库

/***************************************************实时库接口***************************************************************/

bool KERNEL_EXPORT dbDataInit();

//关闭数据
void  KERNEL_EXPORT dbDataEnd();

//写入数据到数据库
void KERNEL_EXPORT writeRdbData(const char* lpData);

//获取相关数目
ushort KERNEL_EXPORT getStationNum();

ushort KERNEL_EXPORT getGlossaryGroupNum();
ushort KERNEL_EXPORT getGlossaryNum();

//获取当前厂站和测点
DBHANDLE KERNEL_EXPORT getDbHandle(ushort wStation,uchar btType,ushort wNo,uchar btDBType);

//同上
DBHANDLE KERNEL_EXPORT findDbHandle(ushort wStationID,uchar btType,ushort wIndex);

//当前厂站测点是否有效
bool KERNEL_EXPORT isValidDbHandle(DBHANDLE dbHandle);


//人工置数部分
void KERNEL_EXPORT analogueManualSet(DBHANDLE dbHandle,float fValue);

void KERNEL_EXPORT digitalManualSet(DBHANDLE dbHandle,uchar btValue);

void KERNEL_EXPORT deManualSet(DBHANDLE dbHandle);


//更改允许标志
void KERNEL_EXPORT enableFalg(DBHANDLE dbHandle,ushort wFlag,bool bEnable);

//确认信息
void KERNEL_EXPORT ack(DBHANDLE dbHandle);

//获取数据
bool KERNEL_EXPORT getAttr(DBHANDLE dbHandle,ushort wAttrib,void* pValue);

//设置数据
bool KERNEL_EXPORT setAttr(DBHANDLE dbHandle,ushort wAttrib,void* pValue);

//写入到实时库
void KERNEL_EXPORT kernelEnterDB(uchar btType,ushort wStationIndex,ushort wPointIndex,void *pData);

ushort KERNEL_EXPORT stationIndex2Addr(ushort wStationIndex);

ushort KERNEL_EXPORT stationAddr2Index(ushort wStationAddr);



/******************************************给外部插件调用的接口********************************************************************/
/*
 * 注：应用程序动态调用dll,是无法直接和dll相互通讯的（应该是两个独立的进程）？通讯的方法有很多种，进程间的通讯方法都可以用。
 * 回调函数是一种好方法（插件和组态工具之间的通讯方法）。另外Windows的消息传递也可以，为了跨平台，采用Qt的事件方法。
 * Qt的事件方法，只能是将dll的请求转发给主进程(五防操作系统)，由主进程和其他dll打交道然后再返回给请求dll
*/

//获取当前厂站和测点
DBHANDLE KERAPI_EXPORT getDbHandleEx(QWidget* pWidget,ushort wStation,uchar btType,ushort wNo,uchar btDBType);
//同上
DBHANDLE KERAPI_EXPORT findDbHandleEx(QWidget* pWidget,ushort wStationID,uchar btType,ushort wIndex);
//当前厂站测点是否有效
bool KERAPI_EXPORT isValidDbHandleEx(QWidget* pWidget,DBHANDLE dbHandle);

//人工置数部分
void KERAPI_EXPORT analogueManualSetEx(QWidget* pWidget,DBHANDLE dbHandle,float fValue);
void KERAPI_EXPORT digitalManualSetEx(QWidget* pWidget,DBHANDLE dbHandle,uchar btValue);

//获取数据
bool KERAPI_EXPORT getAttrEx(QWidget* pWidget,DBHANDLE dbHandle,ushort wAttrib,void* pValue,int length);
//设置数据
bool KERAPI_EXPORT setAttrEx(QWidget* pWidget,DBHANDLE dbHandle,ushort wAttrib,void* pValue,int length);
//写入到实时库
//void KERNEL_EXPORT kernelEnterDB(QWidget* pWidget,uchar btType,ushort wStationIndex,ushort wPointIndex,void *pData);

#ifdef __cplusplus
}
#endif

//事件消息定义
const int kerEventUser = QEvent::User + 9000; //插件向五防系统发送消息

//定义事件类型
class KERAPI_EXPORT HKerEvent : public QEvent
{
public:
    enum event
    {
        GetDBHandle       = kerEventUser+1,
        FindDBHandle      = kerEventUser+2,
        IsValidDBHandle   = kerEventUser+3,
        AnalogueManualSet = kerEventUser+4,
        DigitalManualSet  = kerEventUser+5,
        GetAttr           = kerEventUser+6,
        SetAttr           = kerEventUser+7
    };
    Q_ENUM(event)

    static const Type kerType;
public:
    HKerEvent(Type type,HLPARAM hLParam) : QEvent(type)
    {
        kerEvent = (KEREVENT*)hLParam;
    }
private:
    KEREVENT *kerEvent;
};


#endif // RULEEDITAPI_H

