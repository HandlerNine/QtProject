#include "msg.h"

Msg::Msg(MsgType _type,
    const QByteArray& _content)
    : type(_type)
    , content(_content)
{
}

QByteArray& Msg::getContent()
{
    return content;
}

/*
 * Msg的QByteArray格式:
 * quint32 datasize
 * quint32 head
 * quint16 type
 * QByteArray content
 */
// 接收QByteArray流并转化成Msg信息
Msg toMsg(const QByteArray& received_qbytearray)
{
    QDataStream in(received_qbytearray);
    in.setVersion(QDataStream::Qt_5_8);

    quint32 _datasize;
    in >> _datasize;
    quint32 _head;
    in >> _head;

    quint32 _type;
    in >> _type;
    QByteArray _content;
    in >> _content;

    return Msg((MsgType)(_type), _content);
}
