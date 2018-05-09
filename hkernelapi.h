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


bool KERNEL_EXPORT dbDataInit();

//关闭数据
void  KERNEL_EXPORT dbDataEnd();

//写入数据到数据库
void KERNEL_EXPORT writeRdbData(const char* lpData);

//获取相关数目
ushort KERNEL_EXPORT getStationNum();

ushort KERNEL_EXPORT getGlossaryGroupNum();
ushort KERNEL_EXPORT getGlossaryNum();

//获取当前厂站和测点 信息   存疑
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

