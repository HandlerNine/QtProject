#ifndef FRIENDLIST_H
#define FRIENDLIST_H

#include <QObject>
#include <QList>
#include "Entity/added_friend.h"

class friendlist
{
public:
    friendlist();
    void Add_Fd(const added_friend& m);
    ~friendlist();
    int shownum();
private:
    QList<added_friend> frdlist;
    int frdnum;
};

#endif // FRIENDLIST_H
