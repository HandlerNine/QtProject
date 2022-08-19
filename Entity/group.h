#ifndef GROUP_H
#define GROUP_H

#include <QObject>
#include <Entity/userinfo.h>

class Group
{
public:
    explicit Group(QString gp_name = "",
            quint32 gp_id = 0x0000
            );

    // get_info


private:
    QString group_name;
    quint32 group_id;
    QList<UserInfo> group_member;

};

#endif // GROUP_H
