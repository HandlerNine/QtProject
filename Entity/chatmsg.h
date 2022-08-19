#ifndef CHATMSG_H
#define CHATMSG_H

#include "msg.h"
#include <QByteArray>
#include <QDateTime>
#include <QObject>

class ChatMsg {

public:
    ChatMsg() { }
    explicit ChatMsg(quint32 sender,
        quint32 receiver,
        const QString& content);
    // get_info
    quint32 getSender() const;
    quint32 getReceiver() const;
    QString& getContent();
    QString getSendTime();
    // friend class DataDB;

    // ChatMsg QByteArray 之间的转换
    static ChatMsg fromQByteArray(QByteArray chat_msg);
    QByteArray toQByteArray();

private:
    quint32 _sender;
    quint32 _receiver;
    QString _send_time; //发送消息的时间
    QString _content;
};

#endif // CHATMSG_H
