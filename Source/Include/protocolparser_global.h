#pragma once
#include <QtCore/qglobal.h>

#if defined(PROTOCOLPARSER_LIB)
#  define PROTOCOLPARSER_EXPORT Q_DECL_EXPORT
#else
#  define PROTOCOLPARSER_EXPORT Q_DECL_IMPORT
#endif