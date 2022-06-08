#include "audioserver.h"

AudioServer::AudioServer(QObject *parent) : QObject(parent)
{
    this->setParent(parent);

    client=new QWebSocket();

//    QNetworkRequest request=QNetworkRequest(QUrl("wss://127.0.0.1:8088/ws"));
//    QSslConfiguration config=QSslConfiguration::defaultConfiguration();
//    config.setPeerVerifyMode(QSslSocket::VerifyNone);
//    config.setProtocol(QSsl::TlsV1SslV3);
//    request.setSslConfiguration(config);

    QSslConfiguration conf=client->sslConfiguration();
    conf.setPeerVerifyMode(QSslSocket::VerifyNone);
    conf.setProtocol(QSsl::TlsV1SslV3);
    client->setSslConfiguration(conf);

//    QList<QSslCertificate>cerlist=QSslCertificate::fromPath("C:\\cert\\");
//    QSslError error(QSslError::SelfSignedCertificate,cerlist.at(0));
//    QList<QSslError> expectedErrors;
//    expectedErrors.append(error);
//    client->ignoreSslErrors(expectedErrors);


//    QList<QSslCertificate> cert = QSslCertificate::fromPath(QLatin1String("C:\\cert\\cert.pem"));
//    QSslError error(QSslError::SelfSignedCertificate, cert.at(0));
//    QList<QSslError> expectedSslErrors;
//    expectedSslErrors.append(error);

//    //QWebSocket socket;
//    client->ignoreSslErrors(expectedSslErrors);
//    //socket.open(QUrl(QStringLiteral("ws://myserver.at.home")));


    connect(client,&QWebSocket::connected,this,&AudioServer::slotConnected);
    connect(client,&QWebSocket::disconnected,this,&AudioServer::slotDisconnected);
    connect(client,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(slotError(QAbstractSocket::SocketError)));

//    client->open(QUrl(QStringLiteral("https://127.0.0.1:8088")));

//    connect(client, &QWebSocket::connected, this, &AudioServer::slotConnected);
//    connect(client, QOverload<const QList<QSslError>&>::of(&QWebSocket::sslErrors),
//            this, &AudioServer::onSslErrors);
    client->open(QUrl("wss://127.0.0.1:8088/ws"));
    //client->open(request);
}

void AudioServer::slotConnected()
{
    qDebug()<<"sucess";
}

void AudioServer::slotDisconnected()
{
    qDebug()<<"failed";
}

void AudioServer::slotError(QAbstractSocket::SocketError error)
{
    qDebug()<<error;
}

void AudioServer::onSslErrors(const QList<QSslError> &errors)
 {
     //Q_UNUSED(errors);

     // WARNING: Never ignore SSL errors in production code.
     // The proper way to handle self-signed certificates is to add a custom root
     // to the CA store.

    qDebug()<<errors.at(0);
    client->ignoreSslErrors();
 }
