#include "datainterrequest.h"

DataInterRequest::DataInterRequest(QObject *parent)
{
    this->setParent(parent);

    pManager=nullptr;
}

DataInterRequest::~DataInterRequest()
{

}

QString DataInterRequest::InterfaceType()
{
    return QString("HTTP");
}

void DataInterRequest::InitializationParameterSlot(const QString &address, const quint16 &port, const int &serviceType, const bool &heartBeat, const int &serviceMode, const int &shortLink, const int &newline)
{
    Q_UNUSED(port)
    Q_UNUSED(serviceType)
    Q_UNUSED(heartBeat)
    Q_UNUSED(serviceMode)
    Q_UNUSED(shortLink)
    Q_UNUSED(newline)

    if(address.indexOf("https")){
        QSslConfiguration config=QSslConfiguration::defaultConfiguration();
        config.setPeerVerifyMode(QSslSocket::VerifyNone);
        config.setProtocol(QSsl::TlsV1_1);
        request.setSslConfiguration(config);
    }

    pManager=new QNetworkAccessManager (this);

    connect(this,&DataInterRequest::toSendDataSignal,this,&DataInterRequest::toSendDataSlot);
    connect(pManager, SIGNAL(finished(QNetworkReply*)),this, SLOT(replyFinishedSlot(QNetworkReply*)));
    QString path=address;
    request.setUrl(QUrl::fromEncoded(path.toUtf8()));
}

void DataInterRequest::toSendDataSlot(int channel_number, const QString &data)
{
    Q_UNUSED(channel_number)

    //[标志|时间戳|通道号(2位)|逻辑|车牌|颜色|拖箱状态]
    //[U|20020919114100|01|-1|粤B050CS|黄]
    //[C|20220606004231|01|0|WDFU1234567|N|22G1|粤B050CS]
    //[C|20220606004231|01|0|WDFU1234567|N|22G1|粤B050CS|黄]
    //[C|20020919114100|01|2|MGLU2872320|Y|MGLU2782249|Y|22G1|22G1|粤B050CS]
    //[C|20020919114100|01|2|MGLU2872320|Y|MGLU2782249|Y|22G1|22G1|粤B050CS|黄]


    //[C|20220608112014|01|0||N|22G1|_无_|未知]
    //[C|20220608112111|01|2||N||N|22G1|22G1|_无_|未知]

    if(!data.endsWith("黄]")){
        return;
    }

    QJsonDocument jsonDoc;
    QJsonObject jsonObj,jsonObjChild;

    jsonObj.insert("action", "InOutAction");
    jsonObj.insert("method", "Verification");
    jsonObj.insert("service", "container");

    QString tmp=data;
    QStringList tmpL=tmp.split("|");

    jsonObjChild.insert("currentDate", QDateTime::fromString(tmpL.at(1), "yyyyMMddhhmmss").toString("yyyy-MM-dd hh:mm:ss"));
    jsonObjChild.insert("doorNumber","2");
    jsonObjChild.insert("laneNumber",tmpL.at(2));
    jsonObjChild.insert("goodsType",tmpL.at(3).toInt());
    jsonObjChild.insert("goodsList","");
    if(tmp.indexOf("[U")!=-1){
        jsonObjChild.insert("carNumber",tmpL.at(3).toUtf8().data());
        jsonObjChild.insert("goodsType",-1);
    }
    else if (tmp.indexOf("[C")!=-1 && tmpL.at(3).toInt()<2 && tmpL.length()>=8) {
        jsonObjChild.insert("goodsList",tmpL.at(4));
        jsonObjChild.insert("carNumber",tmpL.at(7).toUtf8().data());
    }
    else if (tmp.indexOf("[C")!=-1 && tmpL.at(3).toInt()==2 && tmpL.length()>=11) {
        jsonObjChild.insert("goodsList",QString("%1,%2").arg(tmpL.at(4),tmpL.at(6)));
        jsonObjChild.insert("carNumber",tmpL.at(10).toUtf8().data());
    }

    jsonObj.insert("dto",QJsonValue(jsonObjChild));
    jsonDoc.setObject(jsonObj);

    qInfo().noquote()<<QString("[%1] HTTP request data<%2>").arg(this->metaObject()->className(),QString(jsonDoc.toJson()));

    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("applocation/json"));
    QNetworkReply* reply=pManager->post(request,jsonDoc.toJson(QJsonDocument::Compact));
    connect(reply, SIGNAL(finished()), this, SLOT(slot_finished()));
    connect(reply, SIGNAL(error(QNetworkReply::NetworkError)),this, SLOT(slot_Error(QNetworkReply::NetworkError)));
    connect(reply, SIGNAL(sslErrors(QList<QSslError>)),this, SLOT(slot_SslErrors(QList<QSslError>)));
}

void DataInterRequest::releaseResourcesSlot()
{
    if(nullptr!=pManager){
        pManager->deleteLater();
    }
}

void DataInterRequest::replyFinishedSlot(QNetworkReply *reply)
{
    if (reply && reply->error() != QNetworkReply::NoError) {
        qCritical().noquote()<<QString("[%1] Data transfer failure<errorCode=%2>").arg(this->metaObject()->className(),reply->errorString());
    }
    reply->close();
    reply->abort();
    reply->deleteLater();
}

void DataInterRequest::slot_SslErrors(QList<QSslError> sslErr)
{
    foreach(auto err,sslErr){
        qCritical().noquote()<<QString("[%1] An error found during processing the request:%2").arg(this->metaObject()->className(),err.errorString());
    }
}

void DataInterRequest::slot_Error(QNetworkReply::NetworkError err)
{
    qCritical().noquote()<<QString("[%1] An error found during processing the request:%2").arg(this->metaObject()->className(),err);

}

void DataInterRequest::slot_finished()
{
    QNetworkReply *reply = (QNetworkReply*)sender();

    if (reply && reply->error() != QNetworkReply::NoError) {
        qCritical().noquote()<<QString("[%1] Data transfer failure<errorCode=%2>").arg(this->metaObject()->className(),reply->errorString());
    }

    QByteArray arr=reply->readAll();
    QString str=QString::fromUtf8(arr);
    qDebug()<<str;

    reply->abort();
    reply->close();
    reply->deleteLater();
}
