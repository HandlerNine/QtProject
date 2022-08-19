#ifndef FRIENDCENTER_H
#define FRIENDCENTER_H

#include <QObject>
#include <QList>
#include <Entity./userinfo.h>

class FriendCenter
{
public:
    QList<UserInfo> * getFriendList();
    void requestAddFriend(quint32 receiver, QString verifyMsg = "");
    void agreeFriendRequest(quint32 sender, quint32 receiver, QString s = "");
    void refuseFriendRequest(quint32 sender, quint32 receiver, QString s = "");

private:
    QList<UserInfo> friendlist;

};

#endif // FRIENDCENTER_H
