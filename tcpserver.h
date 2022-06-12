#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>

#include "tcpclient.h"

class TcpServer : public QTcpServer
{
    Q_OBJECT

public:
    explicit TcpServer(QObject *parent=nullptr);
    ~TcpServer();

    ///
    /// \brief incomingConnection 重写客户端接入
    /// \param handle
    ///
    void incomingConnection(qintptr socketID);

public slots:

    ///
    /// \brief disconnectedSlot 客户端断开信号(从客户端列表删除断开的客户端)
    ///
    void disconnectedSlot();

    ///
    /// \brief setClientChannelNumberSlot 设置通道号
    /// \param channel_number 通道号
    /// \param socktID 客户端ID
    ///
    void setClientChannelNumberSlot(int channel_number, qintptr socketID);

private:

    ///
    /// \brief clientSocketIdMap 客户端字典
    ///
    QMap<qintptr,TcpClient*> clientSocketIdMap;

    ///
    /// \brief clientChannelMap 通道字典
    ///
    QMultiMap<int,qintptr> clientChannelMap;

signals:

    ///
    /// \brief signalContainerData 箱号软件推送的数据
    /// \param data
    ///
    void signalContainerData(QString data);
};

#endif // TCPSERVER_H
