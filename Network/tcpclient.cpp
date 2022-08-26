#include "tcpclient.h"

TcpClient::TcpClient(QObject *parent):QTcpSocket(parent)
{
}

//连接
bool TcpClient::connectToServer(QString ip, quint16 port){
    disconnectFromHost();
    abort();
    connectToHost(ip,port);

    if (waitForConnected(3000))  // 连接成功
    {
        return true;
    }else{
        return false;
    }
}

//发送数据(接收数据在mainwindow.cpp)
void TcpClient::sendMsg(QString msg){
    waitForBytesWritten();
    QByteArray send_msg = msg.toUtf8();
    write(send_msg);
    qDebug()<< "发送数据:"+msg;
}

