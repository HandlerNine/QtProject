#ifndef CHATPRIVATE_H
#define CHATPRIVATE_H

#include <QObject>
#include <Entity./chatmsg.h>
#include <Entity./msg.h>

class ChatPrivate
{

public:
    ChatPrivate(){}
    // 发送消息（读入内容转msg转QByteArray发送）
    void sendContent();
    // 接收消息
    void recvContent();

    // friend class DataDB;
};

#endif // CHATPRIVATE_H
