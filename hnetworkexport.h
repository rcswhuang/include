#ifndef HNETWORKEXPORT_H
#define HNETWORKEXPORT_H

#if defined(WIN32)
#if defined(NETWORK_DLL)
    #define NETWORK_EXPORT __declspec(dllexport)
#else
    #define NETWORK_EXPORT __declspec(dllimport)
#endif
#else
    #define NETWORK_EXPORT
#endif
#endif // HNETWORKEXPORT_H
