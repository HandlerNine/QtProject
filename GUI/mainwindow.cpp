#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSize>
#include <QDateTime>
#include <QDebug>
#include "GUI/addfriend.h"
#include "GUI/chooseadd.h"
#include "Entity/userinfo.h"

#include "./Entity/friendlist.h"
#include "chatmessage/qnchatmessage.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1150,800);
    this->setWindowFlags(this->windowFlags()|Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
    ui->pushButton->setStyleSheet("QPushButton{border:2px groove black;border-radius:8px}"
                              "QPushButton:hover{background-color:rgb(231, 241, 251); color: black;}"
                              "QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}"
                             );
    //开始连接
    myclient = new TcpClient(this);
    connect(myclient, SIGNAL(readyRead()),this, SLOT(recvMsg()));

    if(myclient->connectToServer())
        qDebug() << "已连接到服务器！" ;
    else
        qDebug() << "未连接服务器！" ;
    //这里显示此id值和account值
    //ui->label_id->setText();
    //ui->label_account->setText();
}

MainWindow::~MainWindow()
{
    delete myclient;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //测试发消息专用
    QString msg = ui->textEdit->toPlainText();
    if(ui->listWidget->count()%2 == 0) {
        sendMsg();
    } else {
        show_recvMessage(msg);
    }
    //实际发消息
//    sendMsg();
    ui->listWidget->setCurrentRow(ui->listWidget->count()-1);
    ui->textEdit->clear();
}

//显示发送的消息
void MainWindow::show_sendMessage(QString msg)
{
    //先放这
    QString time = QString::number(QDateTime::currentDateTime().toTime_t()); //时间戳
    ui->textEdit->setText("");


    qDebug()<<"addMessage" << msg << time << ui->listWidget->count();
    dealMessageTime(time);

    QNChatMessage* messageW = new QNChatMessage(ui->listWidget->parentWidget());
    QListWidgetItem* item = new QListWidgetItem(ui->listWidget);
    dealMessage(messageW, item, msg, time, QNChatMessage::User_Me);
}

// 显示接收的消息
void MainWindow::show_recvMessage(QString msg)
{
    //时间先放这
    QString time = QString::number(QDateTime::currentDateTime().toTime_t()); //时间戳
    if(msg != "") {
        dealMessageTime(time);

        QNChatMessage* messageW = new QNChatMessage(ui->listWidget->parentWidget());
        QListWidgetItem* item = new QListWidgetItem(ui->listWidget);
        dealMessage(messageW, item, msg, time, QNChatMessage::User_She);
    }
}

//发送消息
void MainWindow::sendMsg(){
    QString msg = ui->textEdit->toPlainText();
    ui->textEdit->setText("");
    QString time = QString::number(QDateTime::currentDateTime().toTime_t()); //时间戳

    myclient->sendMsg(msg);
    show_sendMessage(msg);
}

//接收消息
void MainWindow::recvMsg(){
    QByteArray myarray = myclient->readAll();
    qDebug()<< myarray;
    show_recvMessage(myarray);
}

void MainWindow::dealMessage(QNChatMessage *messageW, QListWidgetItem *item, QString text, QString time,  QNChatMessage::User_Type type)
{
    messageW->setFixedWidth(this->width()-330);
    QSize size = messageW->fontRect(text);
    item->setSizeHint(size);
    messageW->setText(text, time, size, type);
    ui->listWidget->setItemWidget(item, messageW);
}

void MainWindow::dealMessageTime(QString curMsgTime)
{
    bool isShowTime = false;
    if(ui->listWidget->count() > 0) {
        QListWidgetItem* lastItem = ui->listWidget->item(ui->listWidget->count() - 1);
        QNChatMessage* messageW = (QNChatMessage*)ui->listWidget->itemWidget(lastItem);
        int lastTime = messageW->time().toInt();
        int curTime = curMsgTime.toInt();
        qDebug() << "curTime lastTime:" << curTime - lastTime;
        isShowTime = ((curTime - lastTime) > 60); // 两个消息相差一分钟
//        isShowTime = true;
    } else {
        isShowTime = true;
    }
    if(isShowTime) {
        QNChatMessage* messageTime = new QNChatMessage(ui->listWidget->parentWidget());
        QListWidgetItem* itemTime = new QListWidgetItem(ui->listWidget);

        QSize size = QSize(this->width()-330, 40);
        messageTime->resize(size);
        itemTime->setSizeHint(size);
        messageTime->setText(curMsgTime, curMsgTime, size, QNChatMessage::User_Time);
        ui->listWidget->setItemWidget(itemTime, messageTime);
    }
}


//自己设置大小
void MainWindow::resizeEvent(QResizeEvent *event){
    Q_UNUSED(event);

    QSize mysize = this->size();
    //设置几个frame
    ui->frame->setGeometry(0,0,75,mysize.height());
    ui->frame_2->setGeometry(75,0,250,mysize.height());
    ui->frame_3->setGeometry(325,0,mysize.width()-325,mysize.height());
    //设置各个控件
    //头像
    ui->coverButton->setIcon(QIcon(":/img/me.png"));
    ui->coverButton->setIconSize(QSize(ui->coverButton->width(),ui->coverButton->height()));
    ui->coverButton->setStyleSheet("border:none;");
    //私聊
    ui->singleButton->setIcon(QIcon(":/img/chat.png"));
    ui->singleButton->setIconSize(QSize(ui->coverButton->width(),ui->coverButton->height()));
    ui->singleButton->setStyleSheet("border:none;");
    //群聊
    ui->moreButton->setIcon(QIcon(":/img/cc-chat.png"));
    ui->moreButton->setIconSize(QSize(ui->coverButton->width(),ui->coverButton->height()));
    ui->moreButton->setStyleSheet("border:none;");
    //设置按钮
    ui->settingButton->setGeometry(12,mysize.height()-80,50,50);
    ui->settingButton->setIcon(QIcon(":/img/add.png"));
    ui->settingButton->setIconSize(QSize(ui->coverButton->width(),ui->coverButton->height()));
    ui->settingButton->setStyleSheet("border:none;");
    //
    ui->friendList->setGeometry(0,90,250,mysize.height()-90);
    ui->listWidget->setGeometry(0,0,mysize.width()-325,mysize.height()-210);;
    ui->textEdit->setGeometry(0,mysize.height()-180,mysize.width()-325,180);
    ui->pushButton->setGeometry(mysize.width()-460,mysize.height()-50,93,28);
    //设置信息
    for(int i = 0; i < ui->listWidget->count(); i++) {
        QNChatMessage* messageW = (QNChatMessage*)ui->listWidget->itemWidget(ui->listWidget->item(i));
        QListWidgetItem* item = ui->listWidget->item(i);

        dealMessage(messageW, item, messageW->text(), messageW->time(), messageW->userType());
    }
}


void MainWindow::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton)
    {
        m_point = event->globalPos() - pos(); //计算移动量
        event->accept();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event){
    if(event->buttons() & Qt::LeftButton)
    {
        move(event->globalPos() - m_point);
        event->accept();
    }
}


//窗口最小化
void MainWindow::on_toolButton_2_clicked()
{
    this->showMinimized();
}

//关闭窗口
void MainWindow::on_toolButton_clicked()
{
    this->close();
    QApplication *app;
    app->quit();//关闭整个程序 code by xwb
}

void MainWindow::on_settingButton_clicked()
{
    chooseadd *l = new chooseadd();
    l->show();//进入选择页面
}

void MainWindow::on_singleButton_clicked()//显示好友列表
{
    ui->friendList->clear();
    ui->friendList->setFixedWidth(300);
    QFile file0("./added_friend.txt");
    file0.open(QIODevice::ReadOnly);
    QTextStream tread(&file0);
    while(!tread.atEnd()){
        QString tmp = tread.readLine();
        QListWidgetItem *item = new QListWidgetItem(tmp);//创建一个item
        item->setSizeHint(QSize(300,75));//item大小
        item->setText(tmp);//内容
        item->setFont(QFont("ZYSong18030",12));//字体及大小
        item->setIcon(QIcon(":/img/his.png"));//图片
        item->setTextAlignment(Qt::AlignCenter);//字体位置
        item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);//效果
        ui->friendList->addItem(item);
    }

}

void MainWindow::on_moreButton_clicked()//显示群聊列表
{
    ui->friendList->clear();
    ui->friendList->setFixedWidth(300);
    QFile file0("./added_group.txt");
    file0.open(QIODevice::ReadOnly);
    QTextStream tread(&file0);
    while(!tread.atEnd()){
        QString tmp = tread.readLine();
        QListWidgetItem *item = new QListWidgetItem(tmp);//创建一个item
        item->setSizeHint(QSize(300,75));//item大小
        item->setText(tmp);//内容
        item->setFont(QFont("ZYSong18030",12));//字体及大小
        item->setIcon(QIcon(":/img/grouphead.jpg"));//图片
        item->setTextAlignment(Qt::AlignCenter);//字体位置
        item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);//效果
        ui->friendList->addItem(item);
    }
}

void MainWindow::on_shakebtn_clicked()
{
    pShakeAnimation= new QPropertyAnimation(this,"pos");
    QPoint pos = this->pos();
      //动画还没有结束就先立马停止，防止用户不停的点击
      if(pShakeAnimation->state() == QPropertyAnimation::Running)
        {
          pShakeAnimation->stop();
        }
      pShakeAnimation->setDuration(600);
      pShakeAnimation->setStartValue(pos);

      int offset =0;
      double dOffset = (double)1/30;
      double dIndex =dOffset;
      for(int i=1;i<30;i++){
          offset = i%2==0?-10:10;
          dIndex += dOffset;
          pShakeAnimation->setKeyValueAt(dIndex,pos + QPoint((int)offset,(int)offset));
        }

      pShakeAnimation->setEndValue(pos);
      pShakeAnimation->start();
}

void MainWindow::on_FixHeadbtn_clicked()
{
    if(this->i == 5)
    {
        this->i = 0;
    }
    if(this->i == 0)
    {
        this->ui->textEdit->setText("我是爸妈捡来的，现在18岁，不是亲生的自己也知道。我姐今年27了读研读博所以现在还没谈男朋友，"
                                    "我妈突然就跟我说，等你毕业了，你姐姐要还没有对象你就跟你姐结婚吧。我当时还在看书听到这话吓得我魂都丢了，"
                                    "果断说不行，我妈就说先别急听我讲完!你要和你姐结婚了，不用担心你姐对你不好，第二你姐姐也不会有婆媳矛盾，"
                                    "第三也不会因为任何原因离开你离开家。第四你不用养双方父母，将来爸妈生病了你们可以一起照顾，"
                                    "第五知根知底你姐姐还没谈过对象是干净的。她讲完我就沉默了，确实除了不相爱以外全是利没有弊，我找不出任何反驳的理由，"
                                    "本来想说我们没有那种感情只有亲情，母亲后来就说你以后也不一定就能遇到爱你爱的死去活来的人，"
                                    "大家相亲结婚不就是奔着凑合着过的念头才在一起吗？我现在就挺乱的吧，也不知道咋整不知道该怎么办才好……"
                                    "正当我打字到这里的时候，我有点饿了想吃肯德基，今天疯狂星期四，请我吃");
    }
    if(this->i == 1)
    {
        this->ui->textEdit->setText("我都明白 我是选项E 我是planB 是分叉的头发 洗衣机流出的泡沫 超市里被捏碎的饼干 是吃腻的奶油 "
                                    "是落寞的城市 是地上的草 我是被踩踏的 是西装的备用扣 是被雨淋湿的小狗  是腐烂的橘子 是过期的牛奶 "
                                    "是断线的风筝 是被随意丢弃的向日葵 是沉默寡言的小朋友 所以能v我40吗 今天肯德基疯狂星期四");
    }
    if(this->i == 2)
    {
        this->ui->textEdit->setText("你好，我是奥特曼，我正在外星和敌人战斗！没有能量了！听说今天肯德基疯狂星期四，"
                                    "我现在需要有人给我带29.9块钱4个的吮指原味鸡补充能量。恢复后我请你来外星做客。");
    }
    if(this->i == 3)
    {
        this->ui->textEdit->setText("而生的，就算它们死了，立刻又会有同类补上，就算你一个朋友都没有，你还有三只鸡。"
                                    "今天是肯德基疯狂星期四，V我60，我帮你去谢谢鸡");
    }
    if(this->i == 4)
    {
        this->ui->textEdit->setText("你好我是乌克兰总统泽连斯基，俄军刚刚发动了对乌克兰的进攻，基辅机场已经被俄军控制。"
                                    "听说今天是肯德基疯狂星期四，我现在需要有人给我带29.9四个的吮指原味鸡作为军粮。"
                                    "等我打退俄军我请你来乌克兰做副总统。");
    }
    this->i++;
}
