
#ifndef QTSERVICE_EXPORT_H
#define QTSERVICE_EXPORT_H

#ifdef QTSERVICE_STATIC_DEFINE
#  define QTSERVICE_EXPORT
#  define QTSERVICE_NO_EXPORT
#else
#  ifndef QTSERVICE_EXPORT
#    ifdef QtService_EXPORTS
        /* We are building this library */
#      define QTSERVICE_EXPORT 
#    else
        /* We are using this library */
#      define QTSERVICE_EXPORT 
#    endif
#  endif

#  ifndef QTSERVICE_NO_EXPORT
#    define QTSERVICE_NO_EXPORT 
#  endif
#endif

#ifndef QTSERVICE_DEPRECATED
#  define QTSERVICE_DEPRECATED __declspec(deprecated)
#endif

#ifndef QTSERVICE_DEPRECATED_EXPORT
#  define QTSERVICE_DEPRECATED_EXPORT QTSERVICE_EXPORT QTSERVICE_DEPRECATED
#endif

#ifndef QTSERVICE_DEPRECATED_NO_EXPORT
#  define QTSERVICE_DEPRECATED_NO_EXPORT QTSERVICE_NO_EXPORT QTSERVICE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef QTSERVICE_NO_DEPRECATED
#    define QTSERVICE_NO_DEPRECATED
#  endif
#endif

#endif /* QTSERVICE_EXPORT_H */
