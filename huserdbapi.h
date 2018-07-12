#ifndef USERDBAPI_H
#define USERDBAPI_H
#include <QtGlobal>
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
#define PLG_PLUGINCONFIG       0x07  //插件配置
#define PLG_SHOWMSGWIN         0x08  //报文窗口
#define PLG_SHOWCONFIGWIN      0x09  //配置窗口


#endif // USERDBAPI_H

