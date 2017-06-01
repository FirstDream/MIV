#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(MIVQT_LIB)
#  define MIVQT_EXPORT Q_DECL_EXPORT
# else
#  define MIVQT_EXPORT Q_DECL_IMPORT
# endif
#else
# define MIVQT_EXPORT
#endif
