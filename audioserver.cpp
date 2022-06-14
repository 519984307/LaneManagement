#include "audioserver.h"

AudioServer::AudioServer(QObject *parent, QString addr, int port,int channel) : QObject(parent)
{
    this->setParent(parent);

    this->addr=addr;
    this->port=port;
    this->channel=channel;

    pTcpClient=new QTcpSocket(this);
    connect(pTcpClient,&QIODevice::readyRead,this,&AudioServer::receiveDataSlot);
    connect(pTcpClient,&QAbstractSocket::connected,this,&AudioServer::connectedSlot);
    connect(pTcpClient,&QAbstractSocket::disconnected,this,&AudioServer::disconnectedSlot);
    connect(pTcpClient,QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),this,&AudioServer::displayErrorSlot);

    pTimerLinkState=new QTimer(this);
    pTimerAutoLink= new QTimer(this);
    connect(pTimerLinkState,&QTimer::timeout,this,&AudioServer::heartbeatSlot);
    connect(pTimerAutoLink,&QTimer::timeout,this,&AudioServer::startLinkSlot);

    isConnected=false;
    this->addr=addr;
    this->port=port;

    startLinkSlot();
}

AudioServer::~AudioServer()
{
    if(pTcpClient != nullptr && pTcpClient->isOpen()){
        pTcpClient->disconnected();
        pTcpClient->close();
        pTcpClient->abort();
    }

    isConnected=false;

    if(pTimerLinkState!=nullptr){
        pTimerLinkState->stop();
    }
    if(pTimerAutoLink!=nullptr){
        pTimerAutoLink->stop();
    }

    delete pTimerLinkState;
    pTimerLinkState=nullptr;

    delete  pTimerAutoLink;
    pTimerAutoLink=nullptr;
}

void AudioServer::startLinkSlot()
{
    if(!isConnected){
        pTcpClient->close();
        pTcpClient->abort();
        pTcpClient->connectToHost(addr,port);
    }
}

void AudioServer::heartbeatSlot()
{
    if(pTcpClient->isOpen()){
        pTcpClient->write("[H]");/* 心跳包数据 */
    }
}

void AudioServer::connectedSlot()
{
    isConnected=true;

    if(!pTimerLinkState->isActive()){
        pTimerLinkState->start(15000);
    }

    qDebug().noquote()<<QString("IP:%1:%2 link successful").arg(addr).arg(port);
}

void AudioServer::receiveDataSlot()
{
    /*****************************
    * @brief:服务器主动取结果
    ******************************/
    QByteArray buf=pTcpClient->readAll();
    qDebug()<<QString("The internal socket receives data:%1").arg(buf.data());
    buf.clear();
}

void AudioServer::disconnectedSlot()
{
    isConnected=false;
}

void AudioServer::displayErrorSlot(QAbstractSocket::SocketError socketError)
{
    isConnected=false;

    pTimerAutoLink->start(15000);
    qWarning().noquote()<<QString("IP:%1:%3  link error<errorCode=%2>").arg(addr).arg(socketError).arg(port);
}

void AudioServer::toSendDataSlot(int channel_number,const QString &data)
{
    if(channel_number==channel){
        if(!pTcpClient->isOpen()){
            startLinkSlot();
            pTcpClient->waitForConnected(3000);
        }
        if(pTcpClient->isOpen()){
                 pTcpClient->write(data.toLocal8Bit());
        }
//        qDebug()<<data;
//        qDebug()<<data.toLocal8Bit();
    }
}
