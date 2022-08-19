#include "chatmsg.h"

ChatMsg::ChatMsg(quint32 sender,
    quint32 receiver,
    const QString& content)
    : _sender(sender)
    , _receiver(receiver)
    , _content(content)
{
    _send_time = (QDateTime::currentDateTime()).toString("yyyy-mm-dd hh:mm:ss");
}

quint32 ChatMsg::getSender() const
{
    return _sender;
}

quint32 ChatMsg::getReceiver() const
{
    return _receiver;
}

QString& ChatMsg::getContent()
{
    return _content;
}

QString ChatMsg::getSendTime()
{
    return _send_time;
}

/* ChatMsg的QByteArray格式:
 * quint32 _sender
 * quint32 _receiver
 * quint32 size_send_time
 * QString _send_time
 * quint32 size_content
 * QString _content
 */
ChatMsg ChatMsg::fromQByteArray(QByteArray chat_msg)
{
    QDataStream in(chat_msg);
    in.setVersion(QDataStream::Qt_5_8);

    quint32 sender;
    in >> sender;
    quint32 receiver;
    in >> receiver;

    // send_time
    quint32 size_send_time;
    in >> size_send_time;
    QByteArray qba; // 截取_send_time内容
    qba.resize(size_send_time);
    in >> qba;
    QString send_time = QString(qba);

    // content
    quint32 size_content;
    in >> size_content;
    QByteArray qba2;
    qba2.resize(size_content);
    in >> qba2;
    QString content = QString(qba2);

    ChatMsg tmp(sender, receiver, content); //创建的时候会自动为_send_time赋值,需要更改赋值
    tmp._send_time = send_time;
    return tmp;
}
/* ChatMsg的QByteArray格式:
 * quint32 _sender
 * quint32 _receiver
 * quint32 size_send_time
 * QString _send_time
 * quint32 size_content
 * QString _content
 */
QByteArray ChatMsg::toQByteArray()
{
    QByteArray qba;

    QDataStream out(&qba, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_8);
    out << quint32(_sender);
    out << quint32(_receiver);

    out << quint32(0); //为size_send_time预留空间
    out << _send_time.toUtf8();
    out.device()->seek(8); //定位到_receiver后面准备修改size_send_time
    out << quint32(qba.size() - sizeof(quint32) * 3);
    int index = qba.size();
    out.device()->seek(index);

    out << quint32(0); //为size_content留空间
    out << _content.toUtf8();
    out.device()->seek(index);
    out << quint32(qba.size() - index - sizeof(quint32));
    out.device()->seek(qba.size());

    return qba;
}
