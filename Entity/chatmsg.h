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

    //下面是根据type来判断发送的content和接收的content怎么处理
    //type=0 注册  content储存账号+密码(暂时)
    void setType0(QString acount, QString pwd);
    int getID();

    //type=1 聊天  content储存聊天信息，直接获取即可
    void setType1(QString content);
    QString getChat(){return getContent();}

    //type=2 注册时判断  content储存账号+密码(暂时)
    void setType2(QString acount, QString pwd);
    bool getType2();


private:
    int _type;          //发送消息的类型
    int _sender;        //发送方id
    int _receiver;      //接收方id
    QString _send_time; //发送消息的时间
    QString _content;   //发送的内容
};

#endif // CHATMSG_H
