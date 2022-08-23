#ifndef TCPCLIENT_H
#define TCPCLIENT_H
#include<QTcpSocket>
#include <QHostAddress>
#include <QString>
#include<QDebug>


class TcpClient: public QTcpSocket
{
    Q_OBJECT

public:
    explicit TcpClient(QObject *parent = 0);

    //连接服务器,手动输入ip的端口
    bool connectToServer(QString ip = "192.168.188.128", quint16 port=8899);

    //发送消息
    void sendMsg(QString msg);

};

#endif // TCPCLIENT_H
