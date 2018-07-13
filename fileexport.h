#ifndef FILEEXPORT_H
#define FILEEXPORT_H

#if defined (_WIN32) || defined (WIN32)
    #if defined (DATAFILE_DLL)
        #define FILE_EXPORT __declspec(dllexport)
    #else
        #define FILE_EXPORT __declspec(dllimport)
    #endif
#else
    #define FILE_EXPORT

#endif
#endif // FILEEXPORT_H
//