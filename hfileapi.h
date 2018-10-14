#ifndef HFILEAPI_H_
#define HFILEAPI_H_
#include "hfileexport.h"
#include <QtGlobal>
#include <QString>
#include "time.h"
/*
 * 命名规则:类型统一采用qt定义的方式，对于变量bt表示1个字节,w表示2个字节,n表示4个字节,dw表示8个字节,sz表示字符串数组,str表示QString类
 * quint8 <-> BYTE<->uchar  quint16 <-> WORD <-> ushort  ulong <-> DWORD  uint <-> UINT <-> quint32
*/
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
    ushort wPointType;
    ushort wOpTerm;
    ushort wOpTermGroup;
    ushort wDigitalLockNo;
    ushort wStationID;
    ushort wAnalogueID;
    ushort wDigitalID;
    ushort wRelayID;
    ushort wEquipmentGroupID;
    ushort wLockTypeID;
    ushort wPowerGradeID;
    ushort wRuleID;
    ushort wPointTypeID;
    ushort wOpTermID;
    ushort wOpTermGroupID;
    ushort wDigitalLockNoID;
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
    ushort  wTypeLen;//所需保存的数据结构的长度
    ushort  wReserved;
    ushort  wReserved1;
} DATAFILEHEADER;

#define HEADER_SIZE   (sizeof(DATAFILEHEADER) )

//#define MAX_PATH 256
//各种文件路径 多余的部分一律删除 ---huangw
#define DFPATH_DATA 		0//数据
#define DFPATH_GRAPH		1//图形
#define DFPATH_ICON		    2//图符
#define DFPATH_BITMAP	    3//位图
//#define DFPATH_MACRO	        4//图元组合
#define DFPATH_MEDIA		5//媒体
#define DFPATH_OPSHEET		6//操作票
#define DFPATH_WORKNOTE		7//工作票
#define DFPATH_EVENT		8//事件
#define DFPATH_REPORT		9//报表
#define DFPATH_SIGNPAD 		10//接地牌
#define DFPATH_FIL	        11
#define DFPATH_INI              12
#define DFPATH_PLUGIN           13
#define DFPATH_LAST 		13


// 五防各种数据文件类型的定义
#define FILE_TYPE_FIRST 	      0x00 //
#define FILE_TYPE_STATION	      0x00 //厂站
#define FILE_TYPE_DIGITAL	      0x01 //遥信
#define FILE_TYPE_ANALOGUE	      0x02
#define FILE_TYPE_EQUIPMENTGROUP      0x03
#define FILE_TYPE_EQUIPMENT	      0x04
#define FILE_TYPE_POWERGRADE	      0x05
#define FILE_TYPE_POINTTERM	      0x06
#define FILE_TYPE_LOCKTYPE	      0x07
#define FILE_TYPE_RULE	              0x08
#define FILE_TYPE_OPSHEETINFO         0x09
#define FILE_TYPE_RELAY 	      0x0A
#define FILE_TYPE_OPTERM	      0x0B
#define FILE_TYPE_OPTERMGROUP	      0x0C
#define FILE_TYPE_EVENTTICKETDATA     0x0D
#define FILE_TYPE_OPSHEET	      0x0E
#define FILE_TYPE_WORKNOTEHEAD	      0x0F
#define FILE_TYPE_REPORT	      0x10
#define FILE_TYPE_MEASURE	      0x20
#define FILE_TYPE_LIMIT 	      0x21
#define FILE_TYPE_SYMBOL	      0x22
#define FILE_TYPE_PASSWD	      0x23
#define FILE_TYPE_FORMULA	      0x24
#define FILE_TYPE_ITEM		      0x25
#define FILE_TYPE_GRAPH	              0x26
#define FILE_TYPE_STATECHANGEINFO     0x27
#define FILE_TYPE_DIGITALLOCKNO	      0x28 //扩展锁类型
#define FILE_TYPE_DIGITALEXT	      0x29 //遥信转发 来此优特
#define FILE_TYPE_STEPJDX	      0x2A
#define FILE_TYPE_ANALOGEXT	      0x2B //遥测转发
#define FILE_TYPE_JDPAD		      0x2C
#define FILE_TYPE_OPWF                0x2D
#define FILE_TYPE_LAST		      0x2E

#define PATH_DATA            "data"
#define PATH_GRAPH           "graph"
#define PATH_ICON            "icon"
#define PATH_BITMAP          "bitmap"
#define PATH_MACRO           "macro"
#define PATH_MEDIA           "media"
#define PATH_OPERATETICKET   "ticket"
#define PATH_WORKNOTE        "worknote"
#define PATH_EVENT	         "event"
#define PATH_REPORT          "report"
#define PATH_SIGNPAD         "signpad"
#define PATH_FIL             "fil"
#define PATH_INI             "ini"
#define PATH_PLUGIN          "plugin"
#define PATH_BIN             "bin"
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


//定义画面结构
typedef struct _tagGRAPHINFO
{
    QString strGraphName;
    int nGraphID;//画面ID
    int nGraphWidth; //长度，
    int nGraphHeight; //高度
    int nRefreshInterval; //刷新间隔
    QString strFillColor;//背景填充颜色
    QString strFillPicture;//填充图片路径
    bool bStartGraph;//是不是启动画面
    uchar btType;//画面类型
    ushort wStationNo;//厂站ID
    int nReserver1;
    int nReserver2;
    int nReserver3;
    int nReserver4;
}GRAPHINFO;



//备注：等到测试结束以后，该结构还是需要进行扩展。但不用扩展很多。
//有关五防厂站遥信遥测等数据结构定义
//
#define PTNAMELEN 256
#define STATIONNAMELEN      64
#define DIGITALNAMELEN      256
#define ANALOGUENAMELEN     256
#define RELAYNAMELEN        256
#define EQUIPMENTLEN        64
#define POWERGRADENAMELEN   64
#define POINTTERMLEN        64
#define OPTERMLEN     128
#define LOCKTYPENAMELEN     64

//应该移到Online 头文件中
#define OPERASHEETNAMELEN	       256 //操作票标题
#define OPERASHEETDESCRIBELEN      768 //任务描述
#define OPERASHEETTASKLEN          768 //任务定义
//#define	REPORTNAMELEN				64  //操作票模板名称
//#define	FRONTDESCLEN				128 //前景点描述
#define	OPERASHEETCONTENTLEN	       512 //操作票语句
#define	OPERASHEETREMARKLEN            1024//操作票备注
#define OPERATORLEN                    64 //操作人员长度


//操作步骤
#define STEP_TYPE_FEN  				0	//拉开，工作转试验
#define STEP_TYPE_HE  				1	//合上，试验转工作
#define STEP_TYPE_SJ				2	//试验转检修
#define STEP_TYPE_JS				3	//检修转试验
#define STEP_TYPE_GJ				4	//工作转检修
#define STEP_TYPE_JG				5	//检修转工作
#define STEP_TYPE_JL				6	//检查在分
#define STEP_TYPE_JH				7	//检查在合
#define STEP_TYPE_TISHI				8	//提示



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
    ulong   ulEquipmentID;//待定
    char    szEquipmentID[EQUIPMENTLEN];//设备编号
    ushort  wGroupID;//设备组
    int     nPowerGrade;//电压等级
    ushort  wOpTermID;//操作术语组
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
    ushort  wReserved1;
    ushort  wReserved2;
    ushort  wReserved3;
    ushort  wReserved4;
    ushort  wReserved5;
    ushort  wReserved6;
    ushort  wReserved7;
    ushort  wReserved8;
    ushort  wReserved9;
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
    ushort  wStationID;
    ushort  wAnalogueID;
    char   szAnalogueName[ANALOGUENAMELEN];
    char   szAnalogueOriginalName[ANALOGUENAMELEN];
    uchar   btAnalogueType;//类型 电压电流
    uchar   btUint;//单位
    float   fCC1;
    float   fCC2;
    float   fCC3;
    float   fDifference;//残差
    float   fGrades;//梯度
    ushort  wSendFlag;//转发标志
    ulong   dwEquipmentID;
    char   szEquipmentID[EQUIPMENTLEN];
    ushort  wGroupID;
    int     nPowerGrade;
    ushort  wRelDigitalID;//相关遥信
    ushort  wPFlag; //允许标志 遥控、遥调、取反、计算等允许标志
    ushort  wRFlag; //结果标志 正常变位等
    quint8  btFUN;
    quint8  btINF;
    float   fValue;
    ushort  wToScadaIndex; //转发索引 到监控
    ushort  wFromScadaIndex; //从监控
    ushort  wSendIndex;
    ushort  wReserved1;
    ushort  wReserved2;
    ushort  wReserved3;
    ushort  wReserved4;
    ushort  wReserved5;
    ushort  wReserved6;
    ushort  wReserved7;
    ushort  wReserved8;
    ushort  wReserved9;
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
    char    szGloassaryGroup[OPTERMLEN];
    uchar   btGlossaryGroupType;//开关、刀闸等类型
    ushort  wGlossaryID;
    uchar   btType;//合、分、提示
    char   szGlossary[OPTERMLEN];//具体术语
}POINTTERMGLOSSARY;

//操作术语重新定义
//操作术语组
typedef struct _tagOpTermGroup
{
    ushort  wOpTermGroupID;
    char    szOpTermGroup[OPTERMLEN];
    uchar   btOpTermGroupType;//开关、刀闸等类型
	ushort  wOpTermCounts; //管理的操作术语的个数
}OPTERMGROUP;

//操作术语项
typedef struct _tagOpTerm
{
    ushort wOpTermGroupID;
    ushort wOpTermID;
    uchar  btOpTermType;//合、分、提示
    char   szOpTerm[OPTERMLEN];//具体术语
}OPTERM;

//包含遥信、测点类型以及操作术语的结构
typedef struct _tagDgtToTerm
{
    ushort wSTNo;
    ushort wDgtNo;
    ushort wTermID;
    ushort wGlossaryNum;
    ushort wGlossaryID[1];//array 0 open 1 close 
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

//////////////////////////////////////////////////操作票相关结构//////////////////////////////////////////////////////////////////////
//操作票信息类
typedef struct _tagOperaSheetInfo
{
    ushort wStationID;//厂站
    ushort wGroupID;//设置
    ushort wOpSheetID;//操作票id
    ushort wOpSheetNo;//操作票号
    char szOpSheetTitle[OPERASHEETNAMELEN];//标题
    char szOpSheetDescripe[OPERASHEETDESCRIBELEN];//描述
    char szOpSheetTask[OPERASHEETTASKLEN];//任务
    uchar btOpSheetTaskType;//操作票任务类型/停/送/检修...
    uchar btOpSheetType;//操作票类型
    int   nOpSheetSteps;//操作票总步骤
    char  szOperator[OPERATORLEN];//操作人
    char  szGuardian[OPERATORLEN];//监护人
    char  szEditor[OPERATORLEN];//编辑人
    time_t tOperTime;//操作时间

}OPSHEETINFO;


//操作票步骤类
typedef struct _tagOperatorSheetStep
{
    ushort wOpSheetID; //操作票号
    int    nStepIndex;  //当前操作票步序号
    int    nPreStepIndex; //前一步序号
    int    nNextStepIndex; //后一步序号

    ushort wOpStID;
    ushort wOpPtID;
    uchar  btOpType;
    ushort wOpTerm; //操作术语
    uchar  btLockType;//锁类型
    ulong  dwMainLockNo;
    ulong  dwOpenLockNo;
    ulong  dwCloseLockNo;
    char   szContent[OPERASHEETCONTENTLEN];
    time_t tOpTime;
    char   szRemark[OPERASHEETREMARKLEN];
    ushort wOpFlag;

}OPSHEETSTEP;

////////////////////////////////////////////////////////////////重写了
//typedef bool (*LPFORMULAPROC)(int nMsgType,long wParam,long lParam,int nDBID);
/////////////////////////////////////////对外接口///////////////////////////////////////
#ifdef __cplusplus
extern "C"
{
#endif

    //文件数据库 对外接口

    int  FILE_EXPORT createDBFile(const char* szFile);
    int  FILE_EXPORT openDBFile(const char* szFile);
    void FILE_EXPORT closeDBFile(int fd);
    int FILE_EXPORT createDB( int uFileType );
    int FILE_EXPORT openDB( int uFileType );
    void FILE_EXPORT closeDB( int uFileType );
    
    int FILE_EXPORT loadDataFileHeader( int fd, DATAFILEHEADER* pHeader );
    int FILE_EXPORT saveDataFileHeader( int fd, DATAFILEHEADER* pHeader );
    int FILE_EXPORT loadDBRecord( int nFileType, quint16 wRec, void* pRecord );
    int FILE_EXPORT saveDBRecord( int nFileType, quint16 wRec, void* pRecord );
    int FILE_EXPORT loadDataFileRecord( int fd, quint16 wRec, void* pRecord );
    int FILE_EXPORT saveDataFileRecord( int fd, quint16 wRec, void* pRecord );

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
#endif

#endif
