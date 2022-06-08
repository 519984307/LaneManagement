#ifndef POSTDATA_H
#define POSTDATA_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>

class PostData : public QObject
{
    Q_OBJECT

public:
    explicit PostData(QObject *parent = nullptr);
    ~PostData();

    QNetworkAccessManager* pManager;
    QNetworkRequest request;
    QJsonObject ject;
    QJsonDocument doc;
    QUrl url;

    QString remotePath;

signals:

private slots:

    ///
    /// \brief replyFinishedSlot 上传完成
    ///
    void replyFinishedSlot(QNetworkReply* reply);

    ///
    /// \brief slot_SslErrors SSL/TLS会话在设置过程中遇到错误，包括证书验证错误
    ///
    void slot_SslErrors(QList<QSslError> sslErr);

    ///
    /// \brief slot_Error 应答在处理过程中检测到错误
    ///
    void slot_Error(QNetworkReply::NetworkError err);

    ///
    /// \brief slot_finished 应答完成
    ///
    void slot_finished();

public slots:

    ///
    /// \brief slotPostData 请求数据
    /// \param data
    ///
    void slotPostData(QByteArray data);

};

#endif // POSTDATA_H
