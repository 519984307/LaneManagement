#include "postdata.h"

PostData::PostData(QObject *parent) : QObject(parent)
{
    this->setParent(parent);

//    QSslConfiguration config=QSslConfiguration::defaultConfiguration();
//    config.setPeerVerifyMode(QSslSocket::VerifyNone);
//    config.setProtocol(QSsl::TlsV1_1);
//    request.setSslConfiguration(config);
    pManager=new QNetworkAccessManager (this);

    connect(pManager, SIGNAL(finished(QNetworkReply*)),this, SLOT(replyFinishedSlot(QNetworkReply*)));

    //url.setPath( "http://61.182.236.74:8062/api/gateway");
    request.setUrl(QUrl::fromEncoded("http://61.182.236.74:8062/api/gateway"));
}

PostData::~PostData()
{
    if(nullptr!=pManager){
        pManager->deleteLater();
    }
}

void PostData::replyFinishedSlot(QNetworkReply *reply)
{
    if (reply && reply->error() != QNetworkReply::NoError) {
        qCritical().noquote()<<QString("Data transfer failure<errorCode=%1>").arg(reply->errorString());
    }
    reply->close();
    reply->abort();
    reply->deleteLater();
}

void PostData::slot_SslErrors(QList<QSslError> sslErr)
{
    foreach(auto err,sslErr){
        qCritical().noquote()<<QString("An error found during processing the request:%1").arg(err.errorString());
    }
}

void PostData::slot_Error(QNetworkReply::NetworkError err)
{
    qCritical().noquote()<<QString("An error found during processing the request:%1").arg(err);
}

void PostData::slot_finished()
{
    QNetworkReply *reply = (QNetworkReply*)sender();

    if (reply && reply->error() != QNetworkReply::NoError) {
        qCritical().noquote()<<QString("Data transfer failure<errorCode=%1>").arg(reply->errorString());
    }

    QByteArray arr=reply->readAll();
    QString str=QString::fromUtf8(arr);
    qDebug()<<str;

    reply->abort();
    reply->close();
    reply->deleteLater();
}

void PostData::slotPostData(QByteArray data)
{
//    foreach (auto key, arr.keys()) {
//        ject.insert(key,arr.value(key));
//    }
//    doc.setObject(ject);
//    QByteArray arr=doc.toJson(QJsonDocument::Compact);
    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("applocation/json"));
    QNetworkReply* reply=pManager->post(request,data);

    connect(reply, SIGNAL(finished()), this, SLOT(slot_finished()));
    connect(reply, SIGNAL(error(QNetworkReply::NetworkError)),this, SLOT(slot_Error(QNetworkReply::NetworkError)));
    connect(reply, SIGNAL(sslErrors(QList<QSslError>)),this, SLOT(slot_SslErrors(QList<QSslError>)));
}
