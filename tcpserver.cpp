#include "tcpserver.h"

TcpServer::TcpServer(QObject *parent):QTcpServer (parent)
{
    this->setParent(parent);
    this->listen(QHostAddress::AnyIPv4,65000);
}

TcpServer::~TcpServer()
{
        foreach (auto tcp, clientSocketIdMap.values()) {
            tcp->disconnected();
            tcp->abort();
            tcp->close();
            delete tcp;
            tcp=nullptr;
        }

        clientChannelMap.clear();
        clientSocketIdMap.clear();
}

void TcpServer::incomingConnection(qintptr socketID)
{
    TcpClient* pClient=new TcpClient (this);
    pClient->setSocketDescriptor(socketID);
    clientSocketIdMap.insert(socketID,pClient);
    qDebug().noquote()<<QString("New client in join<IP:%1 PORT:%2>").arg(pClient->peerAddress().toString()).arg(pClient->peerPort());

    connect(pClient,&TcpClient::signalContainerData,this,&TcpServer::signalContainerData);
    connect(pClient,&QIODevice::readyRead,pClient,&TcpClient::receiveDataSlot);
    connect(pClient,&TcpClient::disconnected,this,&TcpServer::disconnectedSlot);
    connect(pClient,&TcpClient::setClientChannelNumberSignal,this,&TcpServer::setClientChannelNumberSlot);
}

void TcpServer::disconnectedSlot()
{
    TcpClient* pClient=qobject_cast<TcpClient*>(sender());

    qDebug().noquote()<<QString("Client offline <IP:%1 PORT:%2>").arg(pClient->peerAddress().toString()).arg(pClient->peerPort());

    qintptr socketID= clientSocketIdMap.key(pClient);
    clientSocketIdMap.remove(socketID);
    clientChannelMap.remove(clientChannelMap.key(socketID));
}

void TcpServer::setClientChannelNumberSlot(int channel_number, qintptr socketID)
{
    clientChannelMap.insert(channel_number,socketID);
}
