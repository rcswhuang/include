#ifndef LICENSEAPI_H
#define LICENSEEAPI_H
#include <QtGlobal>
#include <QString>
#include "hlicenseexport.h"


#define MACHINECODELEN  12 //机器码
#define ACTIVATELEN     25 //激活码
#define TEMPACTIVATELEN 42 //临时激活码
#define ALPHABETLEN 35

#define ACTIVE_FAIL    0x00
#define ACTIVE_SUCCESS 0x01
#define ACTIVE_TEMP    0x02


#ifdef __cplusplus
extern "C"
{
#endif
	void LICENSE_EXPORT getMachineID(char* pMachineID);//机器码
    void LICENSE_EXPORT getActivateCode(char* pMachineID,char* pActCode,int len);//激活码
    void LICENSE_EXPORT getTempActivateCode(int year,int month,int day,char* pTempActCode,int len);
    bool LICENSE_EXPORT registerSystem(char* pActiveCode,quint16 wLen);
	quint8 LICENSE_EXPORT validActiveCode();

#ifdef __cplusplus
}
#endif

#endif // LICENSEAPI_H

