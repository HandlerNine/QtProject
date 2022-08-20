#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSize>
#include <QDateTime>
#include <QDebug>
#include "GUI/addfriend.h"
#include "GUI/chooseadd.h"

#include "./Entity/friendlist.h"
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
}

MainWindow::~MainWindow()
{
    delete myclient;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString msg = ui->textEdit->toPlainText();
    ui->textEdit->setText("");
    QString time = QString::number(QDateTime::currentDateTime().toTime_t()); //时间戳
    qDebug()<<"addMessage" << msg << time << ui->listWidget->count();
    if(ui->listWidget->count()%2) {
        show_sendMessage(msg);
    } else {
        show_recvMessage(msg);
    }
    ui->listWidget->setCurrentRow(ui->listWidget->count()-1);
}

//发送消息并显示
void MainWindow::show_sendMessage(QString msg)
{
    myclient->sendMsg(msg);
    ui->textEdit->setText("");
    QString time = QString::number(QDateTime::currentDateTime().toTime_t()); //时间戳
    qDebug()<<"addMessage" << msg << time << ui->listWidget->count();
    dealMessageTime(time);

    QNChatMessage* messageW = new QNChatMessage(ui->listWidget->parentWidget());
    QListWidgetItem* item = new QListWidgetItem(ui->listWidget);
    dealMessage(messageW, item, msg, time, QNChatMessage::User_Me);
}

// 接收消息并显示
void MainWindow::show_recvMessage(QString msg)
{
    QString time = QString::number(QDateTime::currentDateTime().toTime_t()); //时间戳
    if(msg != "") {
        dealMessageTime(time);

        QNChatMessage* messageW = new QNChatMessage(ui->listWidget->parentWidget());
        QListWidgetItem* item = new QListWidgetItem(ui->listWidget);
        dealMessage(messageW, item, msg, time, QNChatMessage::User_She);
    }
}

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
    ui->coverButton->setIcon(QIcon(":/img/Customer Copy.png"));
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
    ui->searchEdit->setGeometry(15,30,220,20);
    ui->friendList->setGeometry(0,90,250,mysize.height()-90);
    ui->listWidget->setGeometry(0,0,mysize.width()-325,mysize.height()-210);
    ui->emojiButton->setGeometry(0,mysize.height()-210,47,30);
    ui->picButton->setGeometry(47,mysize.height()-210,47,30);
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
        item->setIcon(QIcon(":/img/Customer Copy.png"));//图片
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
