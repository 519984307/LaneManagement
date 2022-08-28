#include "postdata.h"

PostData::PostData(QObject *parent, QString httpAddr)
{
    this->setParent(parent);

    if(httpAddr.indexOf("https")){
        QSslConfiguration config=QSslConfiguration::defaultConfiguration();
        config.setPeerVerifyMode(QSslSocket::VerifyNone);
        config.setProtocol(QSsl::TlsV1_1);
        request.setSslConfiguration(config);
    }

    pManager=new QNetworkAccessManager (this);
    connect(pManager, SIGNAL(finished(QNetworkReply*)),this, SLOT(replyFinishedSlot(QNetworkReply*)));
    request.setUrl(QUrl::fromEncoded(httpAddr.toUtf8()));
}

PostData::~PostData()
{
    if(nullptr!=pManager){
        pManager->deleteLater();
    }
}

void PostData::replyFinishedSlot(QNetworkReply *reply)
{
    if(reply){
        if (reply->error() != QNetworkReply::NoError) {
            qCritical().noquote()<<QString("Data transfer failure<errorCode=%1>").arg(reply->errorString());
            emit signalPlateWhite(QStringList(""));
        }
        reply->close();
        reply->abort();
        reply->deleteLater();
    }
}

void PostData::slot_SslErrors(QList<QSslError> sslErr)
{
    foreach(auto err,sslErr){
        qCritical().noquote()<<QString("An error found during processing the request:%1").arg(err.errorString());
    }
    emit signalPlateWhite(QStringList(""));
}

void PostData::slot_Error(QNetworkReply::NetworkError err)
{
    qCritical().noquote()<<QString("An error found during processing the request:%1").arg(err);
    emit signalPlateWhite(QStringList(""));
}

void PostData::slot_finished()
{
    QNetworkReply *reply = (QNetworkReply*)sender();

    if (reply && reply->error() != QNetworkReply::NoError) {
        qCritical().noquote()<<QString("Data transfer failure<errorCode=%1>").arg(reply->errorString());
        emit signalPlateWhite(QStringList(""));
    }

    bool isRead=false;

    QByteArray arr=reply->readAll();
    QJsonDocument doc =QJsonDocument::fromJson(arr);
    if(!doc.isNull()){
        QJsonObject obj=doc.object();
        if(obj.contains("message")){
            QJsonValue val=obj.value("message");
            qInfo().noquote()<<QString("Pull the whitelist regularl:%1").arg(val.toString());
        }
        bool code=false;
        if(obj.contains("code")){
            QJsonValue val=obj.value("code");
            if(val.toInt()==0){
                code=true;
            }
        }
        if(code && obj.contains("code")){
            QJsonValue val=obj.value(QStringLiteral("data"));
            QJsonArray valArr=val.toArray();

            QStringList plateList;
            isRead=true;

            for(int i=0;i<valArr.size();i++){
                QJsonValue tmpVal=valArr.at(i);
                QJsonObject tmpObj=tmpVal.toObject();
                plateList.append(tmpObj.value("carNumber").toString());
            }
            emit signalPlateWhite(plateList);
        }
    }

    if(!isRead){
        emit signalPlateWhite(QStringList(""));
    }

    reply->abort();
    reply->close();
    reply->deleteLater();
}

void PostData::slotPostData(QByteArray data)
{
    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("applocation/json"));
    QNetworkReply* reply=pManager->post(request,data);

    connect(reply, SIGNAL(finished()), this, SLOT(slot_finished()));
    connect(reply, SIGNAL(error(QNetworkReply::NetworkError)),this, SLOT(slot_Error(QNetworkReply::NetworkError)));
    connect(reply, SIGNAL(sslErrors(QList<QSslError>)),this, SLOT(slot_SslErrors(QList<QSslError>)));
}
