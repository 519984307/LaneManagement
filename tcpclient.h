#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>

class TcpClient : public QTcpSocket
{
    Q_OBJECT

public:
    explicit TcpClient(QObject *parent=nullptr);

private:

    ///
    /// \brief channel_number 通道号
    ///
    int channel_number;


signals:

    ///
    /// \brief setClientChannelNumberSignal 设置通道号
    /// \param channel_number 通道号
    /// \param socktID 客户端ID
    ///
    void setClientChannelNumberSignal(int channel_number,qintptr socktID);

    ///
    /// \brief signalContainerData 箱号软件推送的数据
    /// \param data
    ///
    void signalContainerData(QString data);

public slots:

    ///
    /// \brief receiveClientDataSlot 接收数据
    ///
    void receiveDataSlot();
};

#endif // TCPCLIENT_H
