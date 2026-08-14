#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(PROTOCOLPARSER_LIB)
#  define PROTOCOLPARSER_EXPORT Q_DECL_EXPORT
# else
#  define PROTOCOLPARSER_EXPORT Q_DECL_IMPORT
# endif
#else
# define PROTOCOLPARSER_EXPORT
#endif
