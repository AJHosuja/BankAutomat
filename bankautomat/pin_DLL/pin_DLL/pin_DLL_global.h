#ifndef PIN_DLL_GLOBAL_H
#define PIN_DLL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PIN_DLL_LIBRARY)
#  define PIN_DLL_EXPORT Q_DECL_EXPORT
#else
#  define PIN_DLL_EXPORT Q_DECL_IMPORT
#endif

#endif // PIN_DLL_GLOBAL_H
