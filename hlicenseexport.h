#ifndef HLICENSEEXPORT_H
#define HLICENSEEXPORT_H

#if defined (_WIN32) || defined (WIN32)
    #if defined(LICENSE_DLL)
        #define LICENSE_EXPORT __declspec(dllexport)
    #else
        #define LICENSE_EXPORT __declspec(dllimport)
    #endif
#else
    #define LICENSE_EXPORT

#endif
#endif // HLICENSEEXPORT_H

