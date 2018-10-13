#ifndef RULEEDITAPI_H
#define RULEEDITAPI_H
#include <QtGlobal>
#include <QtWidgets/QWidget>
#include <QFlags>
#include <QEvent>
#include "publicdata.h"
#include "hkernelexport.h"

const int kerEventUser = QEvent::User + 9000; //from 10000
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

    //Q_DECLARE_FLAGS(kerEvents, kerEvent)
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

