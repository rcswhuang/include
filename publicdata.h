#ifndef PUBLICDATA_H_
#define PUBLICDATA_H_
#include <QtGlobal>
#include <QString>
#include "time.h"

#include "fileexport.h"
/*
 * 命名规则:类型统一采用qt定义的方式，对于变量bt表示1个字节,w表示2个字节,n表示4个字节,dw表示8个字节,sz表示字符串数组,str表示QString类
 * quint8 <-> BYTE<->uchar  quint16 <-> WORD <-> ushort  ulong <-> DWORD  uint <-> UINT <-> quint32
*/

//定义各种文件夹的路径
extern "C"
{

//文件个数标志
typedef struct _tagDBFILEHANDLE
{
    ushort wStation;
    ushort wAnalogue;
    ushort wDigital;
    ushort wRelay;
    ushort wEquipmentGroup;
    ushort wLockType;
    ushort wPowerGrade;
    ushort wRule;
    ushort wPointTerm;
    ushort wGlossary;
    ushort wGlossaryGroup;
    ushort wDigitalLockNo;
    ushort wReserved3;
    ushort wReserved4;
    ushort wReserved5;
    ushort wReserved6;
    ushort wReserved7;
    ushort wReserved8;
}FILEHANDLE;

typedef struct _tagDATAFILEHEADER
{
    uchar   btMagic[2]; //魔数
    uchar   btVersion[2];//版本
    uchar   btType;
    ushort  wTotal; //保存的数据结构的个数
    ushort  wRecLength;//所需保存的数据结构的长度
    ushort  wReserved;
    ushort  wReserved1;
} DATAFILEHEADER;

#define HEADER_SIZE   (sizeof(DATAFILEHEADER) )

//#define MAX_PATH 256
//各种文件路径
#define DFPATH_DATA 				0//数据
#define DFPATH_GRAPH				1//图形
#define DFPATH_SYMBOL				2//图符
#define DFPATH_BITMAP				3//位图
#define DFPATH_MACRO				4//图元组合
#define DFPATH_MEDIA				5//媒体
#define DFPATH_OPERATETICKET		6//操作票
#define DFPATH_WORKNOTE				7//工作票
#define DFPATH_EVENT				8//事件
#define DFPATH_REPORT				9//报表
#define DFPATH_SIGNPAD 				10//接地牌
#define DFPATH_FIL					11
#define DFPATH_INI                  12
#define DFPATH_PLUGIN               13
#define DFPATH_LAST 				13

#define DFPATH_EXECUTE				1001 //当前执行路径
#define DFPATH_SYSTEM				1002 //系统路径


// 五防各种数据文件类型的定义
#define FILE_TYPE_FIRST 			0x00 //
#define FILE_TYPE_STATION			0x00 //厂站
#define FILE_TYPE_DIGITAL			0x01 //遥信
#define FILE_TYPE_ANALOGUE		    0x02
#define FILE_TYPE_EQUIPMENTGROUP	0x03
#define FILE_TYPE_EQUIPMENT			0x04
#define FILE_TYPE_POWERGRADE		0x05
#define FILE_TYPE_POINTTERM		    0x06
#define FILE_TYPE_LOCKTYPE			0x07
#define FILE_TYPE_OPERATERULE	    0x08
#define FILE_TYPE_OPERATETICKETHEAD 0x09
#define FILE_TYPE_RELAY 			0x0A
#define FILE_TYPE_GLOSSARY	        0x0B
#define FILE_TYPE_GLOSSARYGROUP		0x0C
#define FILE_TYPE_EVENTTICKETDATA	0x0D
#define FILE_TYPE_REPORTHEAD		0x0E
#define FILE_TYPE_WORKNOTEHEAD		0x0F
#define FILE_TYPE_REPORT			0x10
#define FILE_TYPE_MEASURE			0x20
#define FILE_TYPE_LIMIT 			0x21
#define FILE_TYPE_SYMBOL			0x22
#define FILE_TYPE_PASSWD			0x23
#define FILE_TYPE_FORMULA			0x24
#define FILE_TYPE_ITEM				0x25
#define FILE_TYPE_GRAPHDB			0x26
#define FILE_TYPE_STATECHANGEINFO	0x27
#define FILE_TYPE_DIGITALLOCKNO	    0x28 //扩展锁类型
#define FILE_TYPE_DIGITALEXT		0x29 //遥信转发 来此优特
#define FILE_TYPE_STEPJDX			0x2A
#define FILE_TYPE_ANALOGEXT			0x2B //遥测转发
#define FILE_TYPE_JDPAD				0x2C
#define FILE_TYPE_OPWF              0x2D 
#define FILE_TYPE_LAST				0x2E
/*
uchar == unsigned char == BYTE == quint8
uint  == unsigned int  == UINT = quint32
ulong == unsigned long == DWORD
ushort == unsigned short == WORD == quint16 
qlonglong == unsinged long long int == quint64
*/
//画面
typedef struct _tagSYSDBINFO  
{
	ushort usVersion;   //画面库的版本 1.00
	ushort usTotalGraphs; //目前所有的画面的个数
	ushort usNextGraphID; //下一个可用的ID 注意这个值是一直增加的，但不用担心溢出
	ushort usRootGraphID;//根画面ID
}SYSDBINFO;


//多个类型 --树形结构 厂站  间隔 电压等级 遥信 遥测
//每个类型的列 厂站--值 间隔(名称和电压等级) 电压等级(名称和电压等级) 单个间隔(名称和电压等级)
//遥信

#define TREEPARAM_STATION             1  //厂站
#define TREEPARAM_EQUIPMENTGROUPLIST  2  //大间隔
#define TREEPARAM_POWERGRADE          3  //电压等级
#define TREEPARAM_EQUIPMENTGROUP      4  //间隔
#define TREEPARAM_DIGITAL             5  //遥信
#define TREEPARAM_ANALOGUE            6  //遥测

#define TREEPARAM_DIGITALFROMSCADA    7  //从scada接受
#define TREEPARAM_DIGITALTOSCADA      8  //送scada
#define TREEPARAM_DIGITALTOSIM        10 //送模拟屏遥信

#define TREEPARAM_ANALOGUEFROMSCADA   9
#define TREEPARAM_ANALOGUETOSIM       11 //送模拟屏遥测
#define TREEPARAM_ANALOGUETOSCADA     12 //送第二模拟屏


//操作术语树结构
#define TREEPARAM_GLOSSARYLIST        14 //开关 刀闸 信号 缺省
#define TREEPARAM_GLOSSARY            15 //分 合 提示
#define TREEPARAM_GLOSSARY_OPEN       16 //分
#define TREEPARAM_GLOSSARY_CLOSE      17 //合
#define TREEPARAM_GLOSSARY_TISHI      18//提示
#define TREEPARAM_USERDB              20 //用户定义

//备注：等到测试结束以后，该结构还是需要进行扩展。但不用扩展很多。
//有关五防厂站遥信遥测等数据结构定义
//
#define STATIONNAMELEN      64
#define DIGITALNAMELEN      256
#define ANALOGUENAMELEN     256
#define RELAYNAMELEN        256
#define EQUIPMENTLEN        64
#define POWERGRADENAMELEN   64
#define POINTTERMLEN        64
#define TERMGLOSSARYLEN     128
#define LOCKTYPENAMELEN     64

//实时库内部的数据类型
#define TYPE_NULL            0
#define TYPE_STATION         1
#define TYPE_ANALOGUE        2
#define TYPE_DIGITAL         3
#define TYPE_RELAY           4
#define TYPE_GROUP           5
#define TYPE_GROUPIP         6

//实时库相关数据类型
//厂站
#define     ATTR_ST_NO          0x001
#define     ATTR_ST_ADDR         0x002
#define     ATTR_ST_NAME         0x003
#define     ATTR_ST_SLOCK        0x004
#define     ATTR_ST_TOTALANA     0x005
#define     ATTR_ST_TOTALDGT     0x006
#define     ATTR_ST_TOTALEGROUP  0x007
#define     ATTR_ST_TOTALLOCK    0x008

//遥信
#define     ATTR_DGT_SNO         0x032 //50
#define     ATTR_DGT_NO          0x033
#define     ATTR_DGT_COMBONAME   0x034
#define     ATTR_DGT_ORINAME     0x035
#define     ATTR_DGT_POINTTERMID 0x036
#define     ATTR_DGT_EQUIPMENTID 0x037
#define     ATTR_DGT_GROUPID     0x038
#define     ATTR_DGT_POWERGRADE  0x039
#define     ATTR_DGT_GLOSSARYID  0x040
#define     ATTR_DGT_RULEFENID   0x041
#define     ATTR_DGT_RULEHEID    0x042
#define     ATTR_DGT_RULEJXFENID 0x043
#define     ATTR_DGT_RULEJXHEID  0x044
#define     ATTR_DGT_LOCKNO      0x045
#define     ATTR_DGT_HELOCKNO    0x046
#define     ATTR_DGT_FENLOCKNO   0x047
#define     ATTR_DGT_SENDFLAG    0x048
#define     ATTR_DGT_DOUBLEDGTID 0x049
#define     ATTR_DGT_OPFLAG      0x050
#define     ATTR_DGT_FORMULAID   0x051
#define     ATTR_DGT_VALUE       0x052
#define     ATTR_DGT_RSNO        0x053
#define     ATTR_DGT_RNO         0x054
#define     ATTR_DGT_MEASURE     0x055
#define     ATTR_DGT_4_VALUE     0x056 //4态遥信

//遥测
#define     ATTR_ANA_SNO          0x096 //150
#define     ATTR_ANA_NO           0x097
#define     ATTR_ANA_NAME         0x098
#define     ATTR_ANA_ORINAME      0x099
#define     ATTR_ANA_TYPE         0x100
#define     ATTR_ANA_UINT         0x101
#define     ATTR_ANA_CC1          0x102
#define     ATTR_ANA_CC2          0x103
#define     ATTR_ANA_CC3          0x104
#define     ATTR_ANA_DIFF         0x105
#define     ATTR_ANA_GRADE        0x106
#define     ATTR_ANA_SENDFLAG     0x107
#define     ATTR_ANA_GROUPID      0x108
#define     ATTR_ANA_POWERGRADE   0x109
#define     ATTR_ANA_RELDIGITALID 0x110
#define     ATTR_ANA_VALUE        0x111

//标志
#define ENABLE_ABS         ((ushort)0x0001) //模拟量 绝对值
#define ENABLE_INE         ((ushort)0x0001) //数字量 取反
#define ENABLE_SETPOINT    ((ushort)0x0002) //模拟量 遥调允许
#define ENABLE_RELAY       ((ushort)0x0002) //数字量 遥控允许
#define ENABLE_WARNING     ((ushort)0x0004) //模拟量 越限告警
#define ENABLE_CHANGE      ((ushort)0x0004) //数字量 变位告警
#define ENABLE_SOUND       ((ushort)0x0008) //语音告警
#define ENABLE_FORMULA     ((ushort)0x0010) //计算点
#define ENABLE_REPAIR      ((ushort)0x0020) //数字量 检修
#define ENABLE_SCAN        ((ushort)0x0040) //扫描

#define ENABLE_ANALOGUE  (ENABLE_ABS | ENABLE_SETPOINT | ENABLE_WARNING | ENABLE_SOUND | ENABLE_FORMULA | ENABLE_SCAN)
#define ENABLE_DIGITAL   (ENABLE_INE | ENABLE_RELAY | ENABLE_CHANGE | ENABLE_SOUND | ENABLE_REPAIR | ENABLE_FORMULA | ENABLE_SCAN)
//结果
#define RESULT_MANUAL      ((ushort)0x0001) //人工置数
#define RESULT_ACK         ((ushort)0x0002) //确认
#define ENABLE_WARNINGHI   ((ushort)0x0004) //模拟量 越上限
#define ENABLE_WARNINGLO   ((ushort)0x0008) //数字量 越下线
#define ENABLE_STOP        ((ushort)0x00010) //无效值
#define RESULT_CHANGE      ((ushort)0x0004) //数字量 正常变位
#define ENABLE_ACCIDENT    ((ushort)0x0008) //数字量 事故变位



//厂站结构
typedef struct _tagStation
{
    ushort wStationID;//厂站ID
    char   szStationName[STATIONNAMELEN];//厂站名称
    ushort wStationAddress;//装置地址
    uchar  btStationLock; //厂站解闭锁状态
	
    //厂站内部各种类型对象的个数
    ushort wDigitalCounts;
    ushort wAnalogueCounts;
    ushort wRelayCounts;
    ushort wEquipmentGroupCounts;
    ushort wLockTypeCounts;
    ushort wPowerGradeCounts;
    ushort wRuleCounts;
}STATION;

//电压等级定义
typedef struct _tagPowerGrade
{
    ushort wStationID;
    int    nPowerGrade;//110000 35000具体数字 最大750000  必须是int 2个字节太小 不能表达
    char   szPowerGradeName[POWERGRADENAMELEN];
}POWERGRADE;

//定义间隔
typedef struct _tagEquipmentGroup
{
    ushort wStationID;
    ushort wGroupID;
    ushort wGroupIndex;
    char   szGroupName[EQUIPMENTLEN];
    char   szGroupOriginalName[EQUIPMENTLEN];
    int    nPowerGrade;
}EQUIPMENTGROUP;


typedef struct _tagDigital
{
    ushort  wStationID;
    ushort  wDigitalID;
    char    szDigitalName[DIGITALNAMELEN];
    char    szDigitalOriginalName[DIGITALNAMELEN];
    ushort  wPointTermID;//在测点类型全局表中的ID
    ulong   ulEuipmentID;//待定
    char    szEquipmentID[EQUIPMENTLEN];//设备编号
    ushort  wGroupID;//设备组
    int     nPowerGrade;//电压等级
    ushort  wGlossaryID;//操作术语组
    ushort  wRuleFenID;//分规则
    ushort  wRuleHeID;//合规则
    ushort  wRuleJXFenID;//检修分规则
    ushort  wRuleJXHeID;//检修合规则
    ushort  wLockTypeID;//锁类型
    ulong   dwLockNo;//主锁号
    ulong   dwHeLockNo;//分锁号
    ulong   dwFenLockNo;//合锁号
    ushort  wSendFlag;//转发标志
    ushort  wDoubleDgtID;//双点遥信
    uchar   btOPFlag;//操作标志 遥控/就地
    ushort  wFormulaID;//公式ID
    ushort  wPFlag; //允许标志 遥控、遥调、取反、计算等允许标志
    ushort  wRFlag; //结果标志 正常变位等
    uchar   btFUN;
    uchar   btINF;
    uchar   btRunValue; //实际运行值
	time_t  tLastRunChange;//最后一次实际运行值改变时间
    uchar   btPreviewValue;
	time_t  tLastPreviewChange;
    ushort  wRSNo; //相关遥控点厂ID
    ushort  wRNo; //相关遥控点ID
    ushort  wDigitalLock;//遥信闭锁标志
    ushort  wToScadaIndex; //转发索引 到监控
    ushort  wFromScadaIndex; //从监控
    ushort  wToSimIndex; //发给第三方
	
}DIGITAL;


typedef struct _tagDigitalExt
{
    ushort wStationID;
    ushort wDigitalID;
    ushort wFromUTWFIndex;
    ushort wSendIndex;//"发送"到模拟屏2的序号  多个模拟屏发送的情况下
    ushort wGroupTT;//间隔投入
    ushort wReserve1;
    ushort wReserve2;
    ushort wReserve3;
    ushort wReserve4;
    ushort wReserve5;
    ushort wReserve6;
    ushort wReserve7;
    ushort wReserve8;
    ushort wReserve9;
    ushort wReserve10;
    ushort wReserve11;
    ushort wReserve12;
    ushort wReserve13;
    ushort wReserve14;
    ushort wReserve15;
    ushort wReserve16;
}StructDigitalExt;


//遥测结构
typedef struct _tagAnalogue
{
    ushort wStationID;
    ushort wAnalogueID;
    char   szAnalogueName[ANALOGUENAMELEN];
    char   szAnalogueOriginalName[ANALOGUENAMELEN];
    uchar  btAnalogueType;//类型 电压电流
    uchar  btUint;//单位
    float  fCC1;
    float  fCC2;
    float  fCC3;
    float  fDifference;//残差
    float  fGrades;//梯度
    ushort wSendFlag;//转发标志
    ulong  dwEquipmentID;
    char   szEquipmentID[EQUIPMENTLEN];
    ushort wGroupID;
    int    nPowerGrade;
    ushort wRelDigitalID;//相关遥信
    ushort  wPFlag; //允许标志 遥控、遥调、取反、计算等允许标志
    ushort  wRFlag; //结果标志 正常变位等
    quint8 btFUN;
    quint8 btINF;
	float fValue;
    ushort  wToScadaIndex; //转发索引 到监控
    ushort  wFromScadaIndex; //从监控
    ushort  wToSimIndex; //发给第三方
}ANALOGUE;

typedef struct _tagAnalogueExt
{
    ushort  wStationID;
    ushort  wAnalogueID;
    ushort  wToSimulatorIndex2;
    ushort  wSendIndex;
    ushort  wReserve2;
    ushort  wReserve3;
    ushort  wReserve4;
    ushort  wReserve5;
    ushort  wReserve6;
    ushort  wReserve7;
    ushort  wReserve8;
    ushort  wReserve9;
    ushort  wReserve10;
}StructAnalogueExt;


typedef struct _tagRELAY
{
    char   szName[RELAYNAMELEN];
    ushort wNo;
    ushort wFlag;
    ushort wFormula;
    uchar  btType;
    uchar  btReserved;
}RELAY;

//测点类型定义
//每种测点类型都有一个ID号 遥信遥测结构需要保存这个ID号以对应
typedef struct _tagPointTerm
{
    ushort wTermID;
    char   szTermName[POINTTERMLEN];//测点名称：开关、刀闸
    uchar  btType;
    char   szTermAttr[POINTTERMLEN];//属性 K,D
}POINTTERM;

//操作术语定义 老的操作术语 抛弃
typedef struct _tagPointTermGlossary
{
    ushort  wGlossaryGroupID;
    char    szGloassaryGroup[TERMGLOSSARYLEN];
    uchar   btGlossaryGroupType;//开关、刀闸等类型
    ushort  wGlossaryID;
    uchar   btType;//合、分、提示
    char   szGlossary[TERMGLOSSARYLEN];//具体术语
}POINTTERMGLOSSARY;

//操作术语重新定义
//操作术语组
typedef struct _tagGlossaryGroup
{
    ushort  wGlossaryGroupID;
    char    szGloassaryGroup[TERMGLOSSARYLEN];
    uchar   btGlossaryGroupType;//开关、刀闸等类型

    ushort  wGlossaryCounts; //管理的操作术语的个数
}GLOSSARYGROUP;

//操作术语项
typedef struct _tagGlossary
{
    ushort wGlossaryGroupID;
    ushort wGlossaryID;
    uchar  btGlossaryType;//合、分、提示
    char   szGlossary[TERMGLOSSARYLEN];//具体术语
}GLOSSARY;

//包含遥信、测点类型以及操作术语的结构
typedef struct _tagDgtToTerm
{
    ushort wSTNo;
    ushort wDgtNo;
    ushort wTermID;
    ushort wGlossaryNum;
    ushort wGlossaryID[1];
}DGTToTERM;


//五防锁类型
typedef struct _tagLockType
{
    ushort wStationID;
    ushort wLockTypeID;
    char  szLockTypeName[LOCKTYPENAMELEN];//锁名称 上机遥控
    char  szLockType[LOCKTYPENAMELEN];//锁类型 J
    char  szLockAttr[LOCKTYPENAMELEN];//锁属性 E A
}WFLOCKTYPE;

//五防操作规则
typedef struct _tagOperateRule
{
    ushort wRuleID;
    ushort wOpStationID;
    ushort wOpYXID;
    uchar  btOpType;
    int    nGroupIndex;
    int    nStepIndex;
    ushort wCondStationID;
    ushort wCondYXID;
    uchar  btYXStat;
}RULE;

//接地牌
typedef struct _tagJDXPad
{
    ushort wStationID;
    ushort wJDXID;
    ushort wJDPadID;
    int    nDBID;
    ushort wReserve1;
    ushort wReserve2;
    ushort wReserve3;
    ushort wReserve4;
}JDXPAD;

//单个遥信五防投入功能
typedef struct _tagOnePointOnOff
{
	ushort usStationID;
	ushort usDigitalID;
	ushort usOnePointInfo;//-1表示该点已经投入
	ushort usReserve1;
}StructOnePointOnOff;


typedef struct _tagWfDigitalLockNo
{
    ushort  wStationID;//厂站编号(关键字)
    ushort	wDigitalID;//遥信编号(关键字)
    ushort  wLockTypeID;//锁类型编号
    ulong	dwLockNo1;   //锁号1
    ulong	dwLockNo2;   //锁号2
    ulong	dwLockNo3;   //锁号3
    ulong	dwLockNo4;   //锁号4
    ulong	dwLockNo5;   //锁号5
    ulong	dwLockNo6;   //锁号6
    ulong	dwLockNo7;   //锁号7
    ulong	dwLockNo8;   //锁号8
    ulong	dwLockNo9;   //锁号9
    ulong	dwReserved10;   //备份10
    ulong	dwReserved11;   //备份11
    ulong	dwReserved12;   //备份12
    ulong	dwReserved13;   //备份13
    ulong	dwReserved14;   //备份14
    ulong	dwReserved15;   //备份15
}DIGITALLOCKNO;

////////////////////////////////////////////////////////////////重写了

/////////////////////////////////////////对外接口///////////////////////////////////////
#ifdef __cplusplus
extern "C"
{
#endif

    //文件数据库 对外接口

    bool FILE_EXPORT createDB( int uFileType );
    bool FILE_EXPORT openDB( int uFileType );
    void FILE_EXPORT closeDB( int uFileType );
    //bool FILE_EXPORT loadDBRecord( int uFileType, int wRec, void* pRecord );
    bool FILE_EXPORT loadDataFileHeader( int nFileType, DATAFILEHEADER* pHeader );
    bool FILE_EXPORT saveDataFileHeader( int nFileType, DATAFILEHEADER* pHeader );
    bool FILE_EXPORT loadDBRecord( int nFileType, quint16 wRec, void* pRecord );
    bool FILE_EXPORT saveDBRecord( int nFileType, quint16 wRec, void* pRecord );

    void FILE_EXPORT getDataFilePath(int nPath,char* filename);

    //bool FILE_EXPORT createDataFile(int nFileType,const char* lpszFile );
    //bool FILE_EXPORT openDataFile(int nFileType, const char* lpszFile );
    //void FILE_EXPORT closeDataFile( int nFileType );

    //bool FILE_EXPORT loadDataFileHeader( int nFileType, DATAFILEHEADER* pHeader );
    //bool FILE_EXPORT saveDataFileHeader( int nFileType, DATAFILEHEADER* pHeader );
   // bool FILE_EXPORT loadDataFileRecord( int nFileType, int wRec, void* pBuffer, int uLength = -1);
   // bool FILE_EXPORT saveDataFileRecord( int nFileType, int wRec, void* pBuffer, int uLength = -1 );



    /////////////////////
    //事件
//	BOOL WriteEventToFile(EventData* pEventData);// 将事件写入文件
//	BOOL GetEventDataFile( int nYear,int nMonth,char* szEventFile); //得到事件文件的名称

//	BOOL GetEventTicketDataFile(time_t tEventTime,char* szEventTicketFile); //得到操作票事件文件的名称
//	BOOL WriteEventTicketToFile(time_t tEventTime,EventTicketData* pEventTicketData);// 将操作票事件写入文件
#ifdef __cplusplus
}
#endif*/

}
#endif
