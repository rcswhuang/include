#ifndef HNETWORKAPI_H
#define HNETWORKAPI_H
#include "hnetworkexport.h"
typedef unsigned char  uchar;
typedef unsigned short WORD;

typedef void(*Callback)(unsigned int msg_typd, const std::string& msg, const unsigned int msg_length);
typedef void(*TCPServerCallback)(unsigned int msg_typd, const std::string& msg, const unsigned int msg_length);

//导出函数
#ifdef __cplusplus
extern "C"
{
#endif

    //服务器主网络 对外接口

    bool NETWORK_EXPORT netInit();
    void NETWORK_EXPORT netExit();
    void NETWORK_EXPORT sendWfYk(ushort wStationIndex,ushort wYxIndex, uchar btExceptValue);
    void NETWORK_EXPORT sendReqYk(ushort wStationIndex,ushort wYxIndex,uchar btExceptValue);
    void NETWORK_EXPORT sendReqAllYx(ushort wStationIndex = (ushort)-1,ushort wYxIndex = (ushort)-1);
    void NETWORK_EXPORT sendYkCheckBack(ushort wStationIndex,ushort wYxIndex,uchar btValue,bool bCheckStatus);
    void NETWORK_EXPORT sendLockAll(ushort wStationIndex,uchar btLockType);
    void NETWORK_EXPORT sendLockOne(ushort wStationIndex,ushort wYxIndex,uchar btLockType);
    void NETWORK_EXPORT sendMeasureYx(ushort* wStationIndex,ushort *wYxIndex,ushort* btYxValue,ushort wYxNum);
    
    ushort NETWORK_EXPORT stationIndex2Addr(ushort wStationIndex);
    ushort NETWORK_EXPORT stationAddr2Index(ushort wStaitonAddr);

#ifdef __cplusplus
}
#endif


/********************************************************五防主备机通讯接口*********************************************/



#endif // HNETWORKAPI_H
