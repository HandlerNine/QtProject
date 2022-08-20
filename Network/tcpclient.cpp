#include "tcpclient.h"
#include "qhostaddress.h"
#include <QDataStream>
#include <QString>


TcpClient::TcpClient(QObject *parent):QTcpSocket(parent)
{
    connect(this, SIGNAL(readyRead()),this, SLOT(recvMsg()));
}

//连接
bool TcpClient::connectToServer(QString ip, quint16 port){
    disconnectFromHost();
    abort();
    connectToHost(ip,port);

    if (waitForConnected(30000))  // 连接成功
    {
        return true;
    }else{
        return false;
    }
}

//发送数据
void TcpClient::sendMsg(QString msg){
    waitForBytesWritten();
    QByteArray send_msg = msg.toUtf8();
    write(send_msg);
    qDebug()<<"发送数据:"+msg;
}

//接收数据
void TcpClient::recvMsg(){
    QByteArray myarray = readAll();
    qDebug()<< myarray;
}
