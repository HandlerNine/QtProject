#ifndef CHATGROUP_H
#define CHATGROUP_H

#include <QObject>
#include "userinfo.h"
#include "groupcenter.h"
#include "chatmsg.h"
#include "msg.h"

class ChatGroup
{
public:
    explicit ChatGroup(const ChatMsg& _chatmsg, const UserInfo& _userinfo);

    // get_info
    ChatMsg& getChatMessage();
    UserInfo& getUserInfo();

    // 发送消息（读入内容转msg转QByteArray发送）
    void sendGroupContent();
    // 接收消息
    void recvGroupContent();

private:
    ChatMsg chatmsg;
    UserInfo userinfo;
};

#endif // CHATGROUP_H
