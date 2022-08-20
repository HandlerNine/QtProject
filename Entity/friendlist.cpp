#include "friendlist.h"

friendlist::friendlist()
{
    frdlist.clear();
    frdnum=0;
}

void friendlist::Add_Fd(const added_friend& m){
    frdlist.append(m);
    frdnum++;
}
int friendlist::shownum(){
    return frdnum;
}
friendlist::~friendlist(){
    frdnum = 0;
    frdlist.clear();
}
