#ifndef VIEWERQGL_CONFIG_H
#define VIEWERQGL_CONFIG_H

#include <QtCore/qglobal.h>

#ifdef demo_framework_EXPORTS
#  define viewerqgl_EXPORTS
#endif

#ifdef viewerqgl_EXPORTS
#  define VIEWERQGL_EXPORT Q_DECL_EXPORT
#else
#  define VIEWERQGL_EXPORT Q_DECL_IMPORT
#endif

#endif // VIEWER_CONFIG_H
