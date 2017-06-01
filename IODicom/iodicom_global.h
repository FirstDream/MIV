#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(IODICOM_LIB)
#  define IODICOM_EXPORT Q_DECL_EXPORT
# else
#  define IODICOM_EXPORT Q_DECL_IMPORT
# endif
#else
# define IODICOM_EXPORT
#endif
