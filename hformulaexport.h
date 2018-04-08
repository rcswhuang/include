#ifndef HFORMULAEXPORT_H
#define HFORMULAEXPORT_H

#if defined (_WIN32) || defined (WIN32)
#if defined(FORMULA_DLL)
    #define FORMULA_EXPORT __declspec(dllexport)
#else
    #define FORMULA_EXPORT __declspec(dllimport)
#endif
#else
    #define FORMULA_EXPORT
#endif
#endif // HFORMULAEXPORT_H
