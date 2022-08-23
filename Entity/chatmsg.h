#ifndef CHATMSG_H
#define CHATMSG_H

#include <QDateTime>
#include <QString>
#include <iostream>
#include <string>
#include <sstream>

class ChatMsg {
public:
    //初始化用这两个
    ChatMsg();
    explicit ChatMsg(
            int type,
            int sender,
            int receiver,
            const QString content);

    ChatMsg(int type, int sender, int receiver);

    //设置成员变量
    void setAll(int type, int sender, int receiver, QString content);

    // 获取相应的成员变量
    int getType() const;
    int getSender() const;
    int getReceiver() const;
    QString getContent();
    QString getSendTime();
    void writeSendTime(QString now_time);

    //用于数据传输
    QString toQString();
    void toChatMsg(QString str);



private:
    int _type;          //发送消息的类型
    int _sender;        //发送方id
    int _receiver;      //接收方id
    QString _send_time; //发送消息的时间
    QString _content;   //发送的内容
};

#endif // CHATMSG_H
