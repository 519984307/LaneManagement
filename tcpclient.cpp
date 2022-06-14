#include "tcpclient.h"

TcpClient::TcpClient(QObject *parent):QTcpSocket(parent)
{
    this->setParent(parent);
}

void TcpClient::receiveDataSlot()
{
    QByteArray buf=readAll();

    QList<QByteArray> tmp=buf.split(',');
    if(tmp.count()==4){
        emit signalContainerData(buf);
        //qDebug()<<QString::fromLocal8Bit(buf);
    }
    buf.clear();
}
