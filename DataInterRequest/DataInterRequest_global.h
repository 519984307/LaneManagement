#ifndef DATAINTERREQUEST_GLOBAL_H
#define DATAINTERREQUEST_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include <QtNetwork/QSslError>
#include <QUrl>

#if defined(DATAINTERREQUEST_LIBRARY)
#  define DATAINTERREQUEST_EXPORT Q_DECL_EXPORT
#else
#  define DATAINTERREQUEST_EXPORT Q_DECL_IMPORT
#endif

#endif // DATAINTERREQUEST_GLOBAL_H
