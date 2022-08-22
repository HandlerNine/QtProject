#ifndef CHATMSG_H
#define CHATMSG_H

#include <QByteArray>
#include <QDataStream>
#include <QDateTime>
#include <QObject>

/* ChatMsg的QByteArray格式:
 * quint32 _sender
 * quint32 _receiver
 * quint32 size_send_time
 * QString _send_time
 * quint32 size_content
 * QString _content
 */
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
