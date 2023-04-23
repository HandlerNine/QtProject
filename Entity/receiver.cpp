#ifndef RECEIVER_H
#define RECEIVER_H


#include <Entity./userinfo.h>

class Receiver : public UserInfo
{
public:
    explicit Receiver(QString recv_ip = "",
                    quint32 recv_port = 0x0000);

private:
    QString recv_ip;
    quint32 recv_port;  // 发送者端口

};


#endif // RECEIVER_H
