#ifndef GROUPCENTER_H
#define GROUPCENTER_H

#include <QObject>
#include <./Entity/group.h>

class GroupCenter
{
public:
    QList<Group> * getGroupList();
    void AddGroup(quint32 receiver, QString verifyMsg = "");
    // void agreeFriendGroup(quint32 sender, quint32 receiver, QString s = "");
    // void refuseFriendGroup(quint32 sender, quint32 receiver, QString s = "");

private:
    QList<Group> grouplist;
};

#endif // GROUPCENTER_H
