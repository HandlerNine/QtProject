#include "GUI/login.h"
#include "GUI/testui.h"
#include <QApplication>

#include <./Entity/friendlist.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Login w;
//    w.show();
    //测试用
    TestUI w;
    w.show();
    return a.exec();
}
