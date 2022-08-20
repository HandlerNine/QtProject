#include "grouplist.h"


grouplist::grouplist()
{
    grplist.clear();
    grdnum=0;
}

void grouplist::Add_Group(const added_group& m){
    grplist.append(m);
    grdnum++;
}
int grouplist::shownum(){
    return grdnum;
}
grouplist::~grouplist(){
    grdnum = 0;
    grplist.clear();
}
