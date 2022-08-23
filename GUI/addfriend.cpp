#include "addfriend.h"
#include "ui_addfriend.h"
#include "./GUI/mainwindow.h"
#include"./GUI/addsuccess.h"
#include "mainwindow.h"
#include "./Entity/friendlist.h"
#include "./Entity/added_friend.h"
#include <./GUI/login.h>

addfriend::addfriend(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addfriend)
{
    ui->setupUi(this);
    //按钮ui优化
    ui->pushButton->setStyleSheet("QPushButton{border:2px groove black;border-radius:20px}"
                              "QPushButton:hover{background-color:rgb(231, 241, 251); color: black;}"
                              "QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}"
                             );
    ui->pushButton_2->setStyleSheet("QPushButton{border:2px groove black;border-radius:20px}"
                              "QPushButton:hover{background-color:rgb(231, 241, 251); color: black;}"
                              "QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}"
                             );
     this->setWindowFlags(this->windowFlags()|Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
    //设置图片
    QPixmap *pic = new QPixmap(":/img/addfd.jpg");
    QSize sz = ui->label_2->size();
    ui->label_2->setPixmap(pic->scaled(sz));
}

addfriend::~addfriend()
{
    delete ui;
}

void addfriend::on_pushButton_2_clicked()
{
    this->close();//返回
}
qint32 addfriend::GetIdFromName(QString u_name){
    //这里需要实现通过名字查找ID
    return 0;
}
void addfriend::on_pushButton_clicked()
{
    QString friendName = ui->add_num->text();//名字
    //之后搜索好友进行添加，这里需要补充
//    added_friend lm(friendID);
//    frdlst.Add_Fd(lm);
    //需要发送消息
    ChatMsg msg = ChatMsg(4,0,0,friendName);
    qint32 tt_ID = GetIdFromName(friendName);
    QFile file("./added_friend.txt");
    if(file.open(QIODevice::WriteOnly|QIODevice::Append) == true) {
                     QTextStream twrite1(&file);
                     twrite1 << friendName << endl << tt_ID << endl;
    }
    addsuccess *m = new addsuccess();
    m->show();
}
