#ifndef HSYSCONFIGEXPORT_H
#define HSYSCONFIGEXPORT_H

#if defined(WIN32)
#if defined(SYSCONIFG_DLL)
    #define SYSCONFIG_EXPORT __declspec(dllexport)
#else
    #define SYSCONFIG_EXPORT __declspec(dllimport)
#endif
#else
    #define SYSCONFIG_EXPORT
#endif
#endif // HNETWORKEXPORT_H
