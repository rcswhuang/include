#ifndef RULEEDITAPI_H
#define RULEEDITAPI_H
#include <QtGlobal>
#include "hkernelexport.h"
#ifdef __cplusplus
extern "C"
{
#endif

typedef struct _tagDBHANDLE
{
    void* pSt;//station
    void* pPt;//point
}DBHANDLE;


#define TYPE_DB_REALTIME  0x01 //实时库
#define TYPE_DB_PREVIEW   0x02 //预演库
#define TYPE_DB_TEMPLATE  0x03 //模板库





/***************************************************有关插件部分定义****************************************************/
//回调函数接口
//定义回调函数声明
typedef bool (*PLUGINPROC)(int type,unsigned int param1,long param2);

typedef struct _tagUpdataPoint
{
    quint16 wStation;
    quint16 wPoint;
    quint16 wAttr;
    quint8 btType;
    void* pData;
}UPDATAPOINT;

//先定义插件基本功能
#define PLG_PROCNAME           0x01  //名称
#define PLG_LOADDATA           0x02  //加载数据
#define PLG_SAVEDATA           0x03  //保存数据
#define PLG_INITPROC           0x04  //启动
#define PLG_EXITPROC           0x05  //退出
#define PLG_CHANGEDYX          0x06  //遥信变位
#define PLG_SHOWMSGWIN         0x07  //报文窗口
#define PLG_SHOWCONFIGWIN      0x08  //配置窗口


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
#ifdef __cplusplus
}
#endif

#endif // RULEEDITAPI_H

