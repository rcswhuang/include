#ifndef HPLUGINEXPORT_H
#define HPLUGINEXPORT_H

#if defined (_WIN32) || defined (WIN32)
    #if defined(PLUGIN_DLL)
        #define PLUGIN_EXPORT __declspec(dllexport)
    #else
        #define PLUGIN_EXPORT __declspec(dllimport)
    #endif
#else
    #define PLUGIN_EXPORT

#endif
#endif // HPLUGINEXPORT_H

