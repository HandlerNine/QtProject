#ifndef CHATMSG_H
#define CHATMSG_H

#include <QDateTime>
#include <QString>

typedef enum{
    Fake,               //非法类型
    Chat_SingleChat,    //好友聊天
    Chat_Register,      //注册
    Chat_Load,          //登录
    Chat_AddFriend,     //加好友
    Chat_AddGroup,      //加群
    Chat_WebCheck,      //网络分配
    Chat_Shake,         //窗口抖动
    Chat_GroupChat      //群聊天
}Chat_Type;

class ChatMsg {
public:
    //初始化用这两个
    ChatMsg();
    explicit ChatMsg(
            Chat_Type type,
            int sender,
            int receiver,
            const QString content);

    ChatMsg(Chat_Type type, int sender, int receiver);

    //设置成员变量
    void setAll(Chat_Type type, int sender, int receiver, QString content);
    void setType(Chat_Type type);

    // 获取相应的成员变量
    Chat_Type getType() const;
    int getSender() const;
    int getReceiver() const;
    QString getContent();
    QString getSendTime();
    void writeSendTime(QString now_time);

    //用于数据传输
    QString toQString();
    void toChatMsg(QString str);



private:
    Chat_Type _type;          //发送消息的类型
    int _sender;        //发送方id
    int _receiver;      //接收方id
    QString _send_time; //发送消息的时间
    QString _content;   //发送的内容
};

#endif // CHATMSG_H
