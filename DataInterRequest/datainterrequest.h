#ifndef DATAINTERREQUEST_H
#define DATAINTERREQUEST_H

#include "DataInterRequest_global.h"
#include "datainterchangeinterface.h"

class DATAINTERREQUEST_EXPORT DataInterRequest:public DataInterchangeInterface
{
    Q_OBJECT
    Q_INTERFACES(DataInterchangeInterface)
    Q_PLUGIN_METADATA(IID DataInterchangeInterfaceIID)

public:
    DataInterRequest(QObject* parent=nullptr);
    ~DataInterRequest()Q_DECL_OVERRIDE;

    ///
    /// \brief InterfaceType 插件类型，多插件调用统一接口
    /// \return
    ///
    QString InterfaceType()Q_DECL_OVERRIDE;

public:

    ///
    /// \brief InitializationParameterSlot 初始化参数
    /// \param address 地址
    /// \param port 端口
    /// \param serviceType 服务类型
    /// \param heartBeat 心跳包 状态
    /// \param serviceMode 服务模式
    /// \param shortLink 短链接状态
    /// \param newline 换行符
    ///
    void  InitializationParameterSlot(const QString& address, const quint16& port, const int& serviceType,const bool& heartBeat, const int& serviceMode,const int& shortLink,const int& newline)Q_DECL_OVERRIDE;

    ///
    /// \brief toSendDataSlot 发送数据
    /// \param data 数据体
    ///
    void toSendDataSlot(int channel_number,const QString& data)Q_DECL_OVERRIDE;

    ///
    /// \brief releaseResourcesSlot 释放动资源
    ///
    void releaseResourcesSlot()Q_DECL_OVERRIDE;

private:

    QNetworkAccessManager* pManager;
    QNetworkRequest request;
    QJsonObject ject;
    QJsonDocument doc;
    QUrl url;

    QString address;

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

};

#endif // DATAINTERREQUEST_H
