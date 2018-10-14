#ifndef HCONFIGEXPORT_H
#define HCONFIGEXPORT_H

#if defined(WIN32) || defined(_WIN32)
    #if defined (SYSCONIFG_DLL)
        #define SYSCONFIG_EXPORT __declspec(dllexport)
    #else
        #define SYSCONFIG_EXPORT __declspec(dllimport)
    #endif
#else
    #define SYSCONFIG_EXPORT
#endif
#endif // HSYSCONFIGEXPORT_H
