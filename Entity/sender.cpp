#ifndef SENDER_H
#define SENDER_H

#include <Entity./userinfo.h>

class Sender : public UserInfo
{
public:
    explicit Sender(QString send_ip = "",
                    quint32 send_port = 0x0000);

private:
    QString send_ip;
    quint32 send_port;  // 发送者端口

};


#endif // SENDER_H
