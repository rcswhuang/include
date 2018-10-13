#ifndef HKERNELEXPORT_H
#define HKERNELEXPORT_H

#if defined (_WIN32) || defined (WIN32)
    #if defined(KERNEL_DLL)
        #define KERNEL_EXPORT __declspec(dllexport)
    #else
        #define KERNEL_EXPORT __declspec(dllimport)
    #endif
#else
    #define KERNEL_EXPORT

#endif



#if defined (_WIN32) || defined (WIN32)
    #if defined(KERAPI_DLL)
        #define KERAPI_EXPORT __declspec(dllexport)
    #else
        #define KERAPI_EXPORT __declspec(dllimport)
    #endif
#else
    #define KERAPI_EXPORT

#endif


#endif // HKERNELEXPORT_H

