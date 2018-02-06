#ifndef H5ICONHELP_EXPORT_H
#define H5ICONHELP_EXPORT_H


#if defined(WIN32)
#if defined(H5ICONHELP_DLL)
    #define H5ICONHELP_EXPORT __declspec(dllexport)
#else
    #define H5ICONHELP_EXPORT __declspec(dllimport)
#endif
#else
    #define H5ICONHELP_EXPORT
#endif
//
#endif 
