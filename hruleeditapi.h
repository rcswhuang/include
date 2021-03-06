﻿#ifndef HRULEEDITAPI_H
#define HRULEEDITAPI_H
#include <QtGlobal>
#include <QString>
#include "hruleexport.h"
#define MAXSTRINGLEN 256

enum DRAWSHAPE
{
    enumSelection,
    enumConnect,

    //logic
    enumLogicAND,
    enumLogicOR,
    enumLogicNOT,
    enumLogicXOR,
    enumLogicCONST,

    //arithmetic
    enumArithADD,
    enumArithSUB,
    enumArithMUL,
    enumArithDIV,
    enumArithPOW,
    enumArithMAX,
    enumArithMIN,
    enumArithAVE,
    enumArithAVG,
    enumArithSUM,
    enumArithCONST,

    //compare
    enumCompMORE,
    enumCompLESS,
    enumCompEQU,
    enumCompNOEQU,
    enumCompMOREEQU,
    enumCompLESSEQU,

    //mix multiply
    enumMixMULTIPLY,

    //result
    enumInputDIGITAL,
    enumInputCOMP,
    enumInputANALOGUE,
    enumOutRESUTL,
    enumTEXT

};

enum SELECTMODE
{
    enumNone, //空
    enumRectSelect,//这个是矩形框选择
    enumMove,//选择  移动
    enumSize //选择 改变大小
};

//定义规则应用对象，后台，五防本身，装置连锁
//后台，五防而言是测点，装置而言一般是GIN号
#define TYPE_APP_JK   0
#define TYPE_APP_WF   1
#define TYPE_APP_LOCK 2

#define TYPE_RULE_GENERAL  0  //普通规则 适用大部分
#define TYPE_RULE_SECOND   1 //二级规则 暂时不用

//类型定义
#define TYPE_NONE     0
#define TYPE_INPUT    1 //遥信遥测类型
#define TYPE_RESULT   2//输出类型
#define TYPE_LOGICOR  3
#define TYPE_LOGICAND 4

//TYPE_INPUT的子类型
#define TYPE_INPUT_DIGITAL  102
#define TYPE_INPUT_COMP     103


//遥控:分 合 检修分 检修合 规则
#define CTRL_OPEN    0x00
#define CTRL_CLOSE   0x01
#define CTRL_JXOPEN  0x02
#define CTRL_JXCLOSE 0x03

#define COND_OPEN  0x00 //遥信分
#define COND_CLOSE 0x01 //遥信合

//定义内部测点类型
#define TYPE_INSID_NULL       0
#define TYPE_INSIDE_ANALOGUE  1
#define TYPE_INSIDE_DIGITAL   2
#define TYPE_INSIDE_SELPOINT  3
#define TYPE_INSIDE_RELAY     4
#define TYPE_INSIDE_PULSE     5
#define TYPE_INSIDE_TUNE      6

//回调函数消息类型
#define WM_SEL_POINT     0  //对话框选择测点
#define WM_ID_GETDBINFO  1  //通过ID来获取测点信息
#define WM_GIN_GETDBINFO 2  //通过GIN来获取测点信息


//比较符定义
/*
#define OP_RGREATER      0x01 //>
#define OP_RLOWER        0x02  // <
#define OP_REQUAL        0x03 // =
#define OP_RGEQUAL       0x04 //>=
#define OP_RLEQUAL       0x05 //<=
#define OP_RNEQUAL       0x06 // !=
*/
#define TYPE_COMPARE_ANALOGUE 0x01
#define TYPE_COMPARE_CONST    0x02
//规则文件接口类型
/*
 * 主要是接收外部接口传递过来的站内相关参数信息
*/
typedef struct _tagRuleApiParam
{
    //QString strStationName;
    //QString strDeviceName;//装置/间隔
    //QString strPointName;
    quint16 wStationNo;
    quint16 wDeviceNo;
    quint16 wPointNo;
    quint8  btPointType;//测点类型 遥测 遥信 遥控
    quint8  btYKType;
    quint8  btFormulaType;//规则类型
    quint16 wFormulaID;//测点分/合等规则ID号
    quint16 wReserve1;
    quint16 wReserve2;
    quint16 wReserve3;
}RULEAPIPARAM;

/*
 * 规则模块采用此参数去组态模块或者运行模块获取测点信息
 不能memset()
*/
typedef struct _tagRuleInfo
{
    //
    quint16 wStationNo;//站号
    quint16 wDeviceNo; //装置ID 联锁组态用
    quint8  btPointType; //测点类型 五防用
    quint16 wPointNo;//当联锁组态时为GIN号，当是测点类型时为点号
    quint16 wAttr;

    quint8 btInsideType;
    quint16 wOpenFormulaID;
    quint16 wCloseFormulaID;
    quint16 wOpenJXFormulaID;
    quint16 wCloseJXFormulaID;

    QString strStationName;
    QString strProtectName;
    QString strPointName;
    QString strAttr;
    //float fRating;//额定值
}RULEINFO;
//对外接口

/*
 * 规则重要说明：对于后台监控来说，规则是对应到厂站/装置/测点/分、合等等
 * 对于独立五防来说，没有装置一说，测点信息都是全站唯一的。所以获取后台监控的规则和独立五防的规则原理是一致，但做法有点区别
*/
//定义回调函数 去获取实时库的当前测点的信息，包含当前值 当前状态等等
#ifdef __cplusplus
extern "C"
{
#endif
typedef RULE_EXPORT  bool (* LPRULEDATACALLBACK)(int msgType,RULEINFO *ruleParam);

bool RULE_EXPORT initRuleFiles(quint8 btType,LPRULEDATACALLBACK lpDataCallBack);

void RULE_EXPORT exitRuleFiles();

bool RULE_EXPORT saveRuleFiles();

bool RULE_EXPORT openRuleWindow(quint16 wStationNo, //厂站ID
                                quint16 wPointType, //测点类型 （如果有装置就是装置的地址)
                                quint16 wPointNo,  //测点ID
                                quint8  btRelayType, //分，合，检修分，检修合
                                quint16 wRuleID, //规则ID
                                quint8 btType, //规则类型
                                QString &strFormula //公式字符串
                                );


//导出规则 wStationNo = -1,所有规则，否则某个厂站规则
//组态工具
void RULE_EXPORT exportAllRule();

//规则是否存在
bool RULE_EXPORT isRuleFileExist(quint16 wStationNo, //厂站ID
                     quint16 wPointType, //测点类型 （如果有装置就是装置的地址)
                     quint16 wPointNo,  //测点ID
                     quint8  btYKType //控制类型:分，合，检修分，检修合
                     );
//导入规则（待定）
//拷贝规则（待定）
//删除规则
bool RULE_EXPORT delRuleFile(quint16 wStationNo, //厂站ID
                    quint16 wPointType, //测点类型 （如果有装置就是装置的地址)
                    quint16 wPointNo,  //测点ID
                    quint8  btYKType //控制类型:分，合，检修分，检修合
                    );
//保存厂站规则（待定）

//改变厂站ID
void RULE_EXPORT changeStationID(quint16 wStNo,quint16 wNewStNo);

//改变装置ID（待定，如果是后台规则对象就是装置，但对五防，规则对象就是测点）

//设置规则修改标志
void RULE_EXPORT setRuleModify(bool modify);

//规则查看  wStationNo和wPointNo都是-1,查看所有规则，wPointNo=-1,查看某个厂站规则，否则查看某个点规则
//online上查看
void RULE_EXPORT lookRuleReport(quint16 wStationNo = (quint16)-1,quint16 wPointNo = (quint16)-1);

#ifdef __cplusplus
}
#endif

#endif // RULEEDITAPI_H

