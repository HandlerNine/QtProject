#include "testui.h"
#include "ui_testui.h"

#include<string>


//这个UI是用来测试各个类能否正常工作用的，啥都没有
TestUI::TestUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestUI)
{
    ui->setupUi(this);

    ChatMsg msg = ChatMsg(Chat_SingleChat,1,2,QString::fromStdString("hello"));


    QString mid_msg = msg.toQString();

    msg.toChatMsg(mid_msg);

    qDebug()<< "type:" << msg.getType() << "recv:" << msg.getReceiver() << "  send:" << msg.getSender()
            << "  time:" <<msg.getSendTime() << "  context:" <<msg.getContent();

}

TestUI::~TestUI()
{
    delete ui;
}
