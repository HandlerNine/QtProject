#ifndef GROUPLIST_H
#define GROUPLIST_H
#include <QObject>
#include <QList>
#include "Entity/added_group.h"
class grouplist
{
public:
    grouplist();
    void Add_Group(const added_group& m);
    ~grouplist();
    int shownum();
private:
    QList<added_group> grplist;
    int grdnum;
};

#endif // GROUPLIST_H
