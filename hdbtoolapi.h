#ifndef HDBTOOLAPI_H
#define HDBTOOLAPI_H
#include "hfileapi.h"
//多个类型 --树形结构 厂站  间隔 电压等级 遥信 遥测
//每个类型的列 厂站--值 间隔(名称和电压等级) 电压等级(名称和电压等级) 单个间隔(名称和电压等级)

//组态工具左边树形列表
#define TREEPARAM_STATION             1  //厂站
#define TREEPARAM_EQUIPMENTGROUPLIST  2  //大间隔
#define TREEPARAM_POWERGRADE          3  //电压等级
#define TREEPARAM_EQUIPMENTGROUP      4  //间隔
#define TREEPARAM_DIGITAL             5  //遥信
#define TREEPARAM_ANALOGUE            6  //遥测

#define TREEPARAM_SCADASYSTEM         7 //监控数据
#define TREEPARAM_DIGITALFROMSCADA    8  //从scada接受
#define TREEPARAM_DIGITALTOSCADA      9  //送scada
#define TREEPARAM_ANALOGUEFROMSCADA   10
#define TREEPARAM_ANALOGUETOSCADA     11 //送第二模拟屏


#define TREEPARAM_DIGITALTOSIM        12 //送模拟屏遥信
#define TREEPARAM_ANALOGUETOSIM       13 //送模拟屏遥测


//操作术语树结构
#define TREEPARAM_OPTERMLIST        14 //开关 刀闸 信号 缺省
#define TREEPARAM_OPTERM           15 //分 合 提示
#define TREEPARAM_OPTERM_OPEN       16 //分
#define TREEPARAM_OPTERM_CLOSE      17 //合
#define TREEPARAM_OPTERM_TISHI      18//提示

//插件部分
#define TREEPARAM_USERDBROOT          20
#define TREEPARAM_USERDB              21 //用户定义

//遥信内部类型
#define TYPE_DIGITAL_START        0
#define TYPE_DIGITAL_XINHAO       0
#define TYPE_DIGITAL_KAIGUAN      1
#define TYPE_DIGITAL_DAOZHA       2
#define TYPE_DIGITAL_ALL          3
#define TYPE_DIGITAL_END          3


//定义组态工具 全厂站闭锁状态
#define STATION_FLAG_UNLOCK       0x01 //解锁
#define STATION_FLAG_LOCK         0x02 //闭锁

//定义组态工具 遥信 操作标志列定义
#define DIGITAL_OPERAFLAG_NOOPERA   0x00  //无
#define DIGITAL_OPERAFLAG_LOCAL     0x01  //就地
#define DIGITAL_OPERAFLAG_REMOTE    0x02  //远方

//定义组态工具 遥测  类型定义
#define ANALOGUE_TYPE_CURRENT     10 //电流
#define ANALOGUE_TYPE_VOLTAGE     11 //电压
#define ANALOGUE_TYPE_ACTIVE      12 //有功
#define ANALOGUE_TYPE_REACTIVE    13 //无功
#define ANALOGUE_TYPE_FREQUENCY   14 //周波
#define ANALOGUE_TYPE_TEMPERATURE 15 //温度
#define ANALOGUE_TYPE_PROTCURRENT 16 //保护电流
#define ANALOGUE_TYPE_PROTVOLTAGE 17 //保护电压
#define ANALOGUE_TYPE_PROTANGLE   18 //保护角度

//定义组态工具 遥测 单位定义
#define ANALOGUE_UINT_V           111 //伏
#define ANALOGUE_UINT_KV          112 //千伏
#define ANALOGUE_UINT_A           113 //安
#define ANALOGUE_UINT_KA          114 //千安
#define ANALOGUE_UINT_W           115 //瓦
#define ANALOGUE_UINT_KW          116 //千瓦
#define ANALOGUE_UINT_MW          117 //兆瓦
#define ANALOGUE_UINT_VA          118 //伏安
#define ANALOGUE_UINT_KVA         119 //千伏安

//定义组态工具 遥信 转发标志
#define TRANS_DIGITAL_TOSCADA     0x01 //送监控
#define TRANS_DIGITAL_FROMSCADA   0x02 //从监控接受
//#define TRANS_DIGITAL_FROMUT      0x04 //从优特接受
//#define TRANS_DIGITAL_TOMNP       0x08 //送模拟屏


//定义组态工具 遥测 转发标志
//#define TRANS_ANALOGUE_TOMNP      0x10
#define TRANS_ANALOGUE_FROMSCADA  0x20
#define TRANS_ANALOGUE_TOSCADA    0x40

//定义电脑钥匙设置
#define KEYSET_NOKEY			0  //无钥匙
#define KEYSET_GC26				1  //共创26版
#define KEYSET_GC27				2  //共创27版
#define KEYSET_NRUSB			3  //南瑞继保USB

//定义测点类型(开关、刀闸、信号、其他、默认)
#define TYPE_POINT_KAIGUAN    1
#define TYPE_POINT_DAOZHA     2
#define TYPE_POINT_XINHAO     0
#define TYPE_POINT_OTHER      254
#define TYPE_POINT_DEFAULT    255

//定义测点操作术语
#define TYPE_OPTERM_HE    0x01
#define TYPE_OPTERM_FEN   0x00
#define TYPE_OPTERM_TISHI 0x03

//特别的操作术语符号
#define STRING_OPTERM_STATIONNAME "$" //遥信厂站符号
#define STRING_OPTERM_GROUPNAME   "~" //遥信间隔符号
#define STRING_OPTERM_DIGITALNAME "@" //遥信组合符号
#define STRING_OPTERM_DIGITALORINAME "%" //遥信原始名称
#define STRING_OPTERM_DIGITALEQUIPNO "!"//遥信设备编号
#define STRING_OPTERM_AUTOCHECK "&" //自动检测
#define STRING_OPTERM_OPENCLOSE "^" //分合操作


enum def_station_column
{
     COL_STATION_STATIONNO = 0,
     COL_STATION_NAME  = 1,
     COL_STATION_LOCK  = 2,
     COL_STATION_TOTAL = 3
};

//定义大间隔
enum def_equipmentgroup_column
{
    COL_EQUIPGL_NAME = 0,
    COL_EQUIPGL_ORINAME = 1,
    COL_EQUIPGL_POWERGRADE = 2,
    COL_EQUIPGL_TOTAL = 3
};

//定义电压等级
enum def_powergrade_column
{
    COL_POWERGRADE_NAME = 0,
    COL_POWERGRADE_ORINAME = 1,
    COL_POWERGRADE_POWERGRADE = 2,
    COL_POWERGRADE_TOTAL = 3
};

//定义间隔对象
enum def_equipment_column
{
    COL_EQUIPG_NAME = 0,
    COL_EQUIPG_ORINAME = 1,
    COL_EQUIPG_POWERGRADE = 2,
    COL_EQUIPG_TOTAL = 3
};


//遥信列定义
enum def_digital_column
{
    COL_DIGITAL_NAME             = 0,//组合名称
    COL_DIGITAL_DNAME            = 1,//自定义名称
    COL_DIGITAL_TYPE             = 2,//测点类型
    COL_DIGITAL_DEVICENO         = 3,//设备编号
    COL_DIGITAL_TRANSFLAG        = 4,//转发标志
    COL_DIGITAL_OPERATERM        = 5,//操作术语
    COL_DIGITAL_OPENRULE         = 6,//分规则
    COL_DIGITAL_CLOSERULE        = 7,//合规则
    COL_DIGITAL_JXOPENRULE       = 8,//检修分规则
    COL_DIGITAL_JXCLOSERULE      = 9,//检修合规则
    COL_DIGITAL_LOCKTYPE         = 10,//锁类型
    COL_DIGITAL_MAINLOCKNO       = 11,//主锁号
    COL_DIGITAL_OPENLOCKNO       = 12,//分锁号
    COL_DIGITAL_CLOSELOCKNO      = 13,//合锁号
    COL_DIGITAL_DOUBLEDIGITAL    = 14,//双位置遥信
    COL_DIGITAL_CALCULTE         = 15,//计算单元
    COL_DIGITAL_POWERGRADE       = 16,//电压等级
    COL_DIGITAL_EQUIPMENTGROUP   = 17,//间隔
    COL_DIGITAL_OPERAFALG        = 18,//操作标志
    COL_DIGITAL_TOTAL            = 19
};

//遥测列定义
enum def_analogue_column
{
    COL_ANALOGUE_NAME            = 0,//组合名称
    COL_ANALOGUE_DNAME           = 1,//自定义名称
    COL_ANALOGUE_TYPE            = 2,//测点类型
    COL_ANALOGUE_UNIT            = 3,//单位
    COL_ANALOGUE_DEVICENO        = 4,//设备编号
    COL_ANALOGUE_TRANSFLAG       = 5,//转发标志
    COL_ANALOGUE_RELATEDIGITAL   = 6,//相关遥信
    COL_ANALOGUE_CC1             = 7,//cc1
    COL_ANALOGUE_CC2             = 8,//cc2
    COL_ANALOGUE_CC3             = 9,//cc3
    COL_ANALOGUE_RESIDUAL        = 10,//残差
    COL_ANALOGUE_GRADIENT        = 11,//梯度
    COL_ANALOGUE_POWERGRADE       = 12,//电压等级
    COL_ANALOGUE_EQUIPMENTGROUP   = 13,//间隔
    COL_ANALOGUE_TOTAL            = 14
};

//定义Tab页面
#define TYPE_TAB_STATION    0x00
#define TYPE_TAB_TRANS_SIM  0x01
#endif
