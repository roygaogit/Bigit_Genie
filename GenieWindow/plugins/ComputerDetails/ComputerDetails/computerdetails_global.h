#ifndef COMPUTERDETAILS_GLOBAL_H
#define COMPUTERDETAILS_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef COMPUTERDETAILS_LIB
# define COMPUTERDETAILS_EXPORT Q_DECL_EXPORT
#else
# define COMPUTERDETAILS_EXPORT Q_DECL_IMPORT
#endif

#endif // COMPUTERDETAILS_GLOBAL_H
