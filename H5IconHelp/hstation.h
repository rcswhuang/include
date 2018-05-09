﻿#ifndef HSTATION_H
#define HSTATION_H
#include <QObject>
#include <QList>
#include "publicdata.h"
#include "h5iconhelpexport.h"
typedef struct _tagATTRINFO
{
    unsigned short wAttrib;
    char* szName;
}ATTRINFO;


//厂站类
//class HWord;
class HAnalogue;
class HDigital;
class HSetPoint;
class HPluse;
class HRelay;
class HGroup;
class HStation;

///////////////////////////测点基类///////////////////////////////
class H5ICONHELP_EXPORT HWord: public QObject
{
public:
    HWord(){}
    friend class HStation;

public:
    quint16 wNo;
    char szName[PTNAMELEN];

public:
    quint16 getNo(){return wNo;}
    const char* getName() {return szName;}
    virtual quint8 getType(){return (quint8)-1;}
    virtual quint32 getSaveFlag(){return 0;}
    virtual quint8 getWordType() = 0;
    virtual HWord* getNext() = 0;
};

/////////////////////////////////////遥测//////////////////////////////////////
class H5ICONHELP_EXPORT HAnalogue:public HWord
{
public:
    HAnalogue(){}
    friend class HStation;

public:
    quint8 getType(){return btType;}
    quint8 getWordType() {return TYPE_ANALOGUE;}
    quint16 getPFlag(){return wPFlag;}
    quint32 getSaveFlag(){return dwSFlag;}
    HWord* getNext(){return this+1;}
    quint16 getGroupID(){return wGroupID;}
public:
    quint8 btType;
    quint16 wPFlag;
    quint32 dwSFlag;
    quint16 wGroupID;
};

////////////////////////////////////遥调///////////////////////////////////////
class H5ICONHELP_EXPORT HSetPoint : public HWord
{
public:
    HSetPoint(){}
    friend class HStation;
public:
    quint8 getWordType(){return TYPE_SETPOINT;}
    HWord* getNext(){return this + 1;}
};

///////////////////////////////////遥信//////////////////////////////////////////
class H5ICONHELP_EXPORT HDigital : public HWord
{
public:
    HDigital(){wDoubleDNo = (ushort)-1;}
    friend class HStation;
public:
    quint8 getType(){return btType;}
    quint8 getWordType() {return TYPE_DIGITAL;}
    ushort getDoubleDNo(){return wDoubleDNo;}
    HWord* getNext(){return this+1;}
    quint16 getGroupID(){return wGroupID;}

public:
    quint8 btType;
    ushort wDoubleDNo;
    quint16 wGroupID;
};

/////////////////////////////////////遥控/////////////////////////////////////////
class H5ICONHELP_EXPORT HRelay : public HWord
{
public:
    HRelay(){}
    friend class HStation;
public:
    quint8 getType(){return btType;}
    quint8 getWordType() {return TYPE_RELAY;}
    quint16 getPFlag(){return wPFlag;}
    quint32 getSaveFlag(){return dwSFlag;}
    HWord* getNext(){return this+1;}
    quint16 getGroupID(){return wGroupID;}
public:
    quint8 btType;
    quint16 wPFlag;
    quint32 dwSFlag;
    quint16 wGroupID;

};

/////////////////////////////////////遥脉///////////////////////////////////////////
class H5ICONHELP_EXPORT HPulse : public HWord
{
public:
    HPulse(){}
    friend class HStation;
public:
    quint8 getType(){return btType;}
    quint8 getWordType() {return TYPE_PULSE;}
    quint16 getPFlag(){return wPFlag;}
    quint32 getSaveFlag(){return dwSFlag;}
    HWord* getNext(){return this+1;}
    quint16 getGroupID(){return wGroupID;}
public:
    quint8 btType;
    quint16 wPFlag;
    quint32 dwSFlag;
    quint16 wGroupID;

};

/////////////////////////////////////间隔///////////////////////////////////////////
class H5ICONHELP_EXPORT HGroup : public HWord
{
public:
    HGroup(){}
    friend class HStation;
public:
    quint8 getType(){return btType;}
    quint8 getWordType() {return TYPE_GROUP;}
    //quint16 getPFlag(){return wPFlag;}
    //quint32 getSaveFlag(){return dwSFlag;}
    HWord* getNext(){return this+1;}
    //quint16 getGroupID(){return wGroupID;}
public:
    quint8 btType;
    quint16 wPFlag;
    quint32 dwSFlag;
    quint16 wGroupID;
};

//////////////////////////////////////厂站////////////////////////////////////////////
class H5ICONHELP_EXPORT HStation
{
public:
    HStation();
    ~HStation();

public:
    quint16 getNo();
    quint16 getAddress();
    const char* getName();

    //bool loadData();
    bool loadData(FILEHANDLE& fileHandle);

    quint16 getWordCount(quint8 btType);
    quint16 getTotalAnalogue();
    quint16 getTotalDigital();
    quint16 getTotalSetPoint();
    quint16 getTotalRelay();
    quint16 getTotalPulse();
    quint16 getTotalGroup();

    HAnalogue* getAnalogue();
    HAnalogue* getAnalogue(quint16 wNo);

    HDigital* getDigital();
    HDigital* getDigital(quint16 wNo);

    HRelay*  getRelay();
    HRelay*  getRelay(quint16 wNo);

    HSetPoint* getSetPoint();
    HSetPoint* getSetPoint(quint16 wNo);

    HPulse* getPulse();
    HPulse* getPulse(quint16 wNo);

    HGroup* getGroup();
    HGroup* getGroup(quint16 wNo);
    HGroup* getGroupByDigital(quint16 wDigitalID);
    HGroup* getGroupByAnalogue(quint16 wAnaID);


    HAnalogue* findAnalogue(int nIndex);
    HDigital* findDigital(int nIndex);
    HRelay* findRelay(int nIndex);
    HSetPoint* findSetPoint(int nIndex);
    HPulse* findPulse(int nIndex);
    HGroup* findGroup(int nIndex);

    HWord* getWord(quint8 btType);
    HWord* getWord(quint8 btType,quint8 wNo);


    STATION station;

private:
    HAnalogue* pAnalogue;//遥测
    HDigital* pDigital;//遥信
    HRelay* pRelay;//遥控
    HSetPoint* pSetPoint;//遥调
    HPulse* pPulse;//遥脉
    HGroup* pGroup;

    quint16 wTotalAnalogue;
    quint16 wTotalDigital;
    quint16 wTotalRelay;
    quint16 wTotalSetPoint;
    quint16 wTotalPulse;
    quint16 wTotalGroup;
};

class H5ICONHELP_EXPORT HStationList
{
public:
    HStationList();
    ~HStationList();

public:

    //加载厂站信息
    void loadStation();

    //厂站ID获取厂站
    HStation* getStation(quint16 wStationID);

    //厂站地址获取厂站
    HStation* getRtu(quint16 wStationAddress);

    //索引厂站
    HStation* findStation(int nIndex);

    //获取厂站列表
    //QList<HStation*>* getStationList();

public:
    QList<HStation*> pStationList;
};

class H5ICONHELP_EXPORT HStationHelper
{
public:
    HStationHelper();
    ~HStationHelper();

public:
    static HStationHelper* m_pInstance;
    static HStationHelper* Instance();
    void loadStation();
    QList<HStation*> getStationList();
    HStation* getStation(quint16 wStationID);

public:
    HStationList stationList;
};




#endif // HSTATION_H
