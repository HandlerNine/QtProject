#include "GUI/login.h"
#include "GUI/testui.h"
#include <QApplication>

#include <./Entity/friendlist.h>

//测试
#include "GUI/register.h"
#include "GUI/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login w;
    w.show();
    //测试用
//    TestUI w;
//    w.show();
    return a.exec();
}
