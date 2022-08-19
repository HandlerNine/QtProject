#ifndef MSG_H
#define MSG_H

#include <QObject>
#include "msgtype.h"

class Msg
{
public:
    Msg(MsgType type, const QByteArray & content);

    // 接收QByteArray流并转化成Msg信息
    // static Msg fromFullQByteArray(const QByteArray & full_received); //包含开头8个字节
    static Msg toMsg(const QByteArray & received_qbytearray);

    // msg转换成QByteArray发送数据
    QByteArray toQByteArray();

    // get_content
    QByteArray & getContent();


private:
    quint32 dataSize;    // 要传输的数据长度
    MsgType type;   // 传输的数据类型
    QByteArray content;  // 传输的内容包括发送人等等信息
};

#endif // MSG_H
