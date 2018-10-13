#ifndef USERDBAPI_H
#define USERDBAPI_H
#include <QtGlobal>
#include "publicdata.h"
#include "hpluginexport.h"
/***************************************************有关插件部分定义****************************************************/
#define PM_GETDBINFO       0 //获取点或者厂站信息
#define PM_FINDDBINFO      1 //根据index获取点或者厂站信息

//回调函数接口
//定义回调函数声明
typedef bool (*PLUGINPROC)(int type,unsigned int param1,long long param2);//数据库调插件的回调函数
typedef bool (*LPPLUGINPROC)(int nMsgType,HWPARAM wParam,HLPARAM lParam);//插件调数据库的回调函数

typedef struct _tagUpdataPoint
{
    quint16 wStation;
    quint16 wPoint;
    quint16 wAttr;
    quint8 btType;
    void* pData;
}UPDATAPOINT;

typedef struct _tagPLUGINPARAM
{
    ushort wStation;
    uchar btType;
    ushort wPoint;
    ushort wAttrib;
    void* pBuffer;
}PLUGINPARAM;

//先定义插件基本功能
#define PLG_PROCNAME           0x01  //名称
#define PLG_LOADDATA           0x02  //加载数据
#define PLG_SAVEDATA           0x03  //保存数据
#define PLG_INITPROC           0x04  //启动
#define PLG_EXITPROC           0x05  //退出
#define PLG_CHANGEDYX          0x06  //遥信变位
#define PLG_PLUGINCONFIG       0x07  //插件配置
#define PLG_SHOWMSGWIN         0x08  //报文窗口
#define PLG_SHOWCONFIGWIN      0x09  //配置窗口
#define PLG_PARENT             0x0A  //Event窗口


//导出函数
#ifdef __cplusplus
extern "C"
{
#endif
    bool PLUGIN_EXPORT pluginProc(int type,unsigned int param1,long long param2);

#ifdef __cplusplus
}
#endif


#endif // USERDBAPI_H

