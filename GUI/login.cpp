#include "login.h"
#include "ui_login.h"
#include "register.h"
#include "mainwindow.h"

Login::Login(QWidget *parent, TcpClient* myclient) :
    QMainWindow(parent),myclient(myclient),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    //按钮ui优化
    ui->logbtn->setStyleSheet("QPushButton{border:2px groove blue;border-radius:20px}"
                              "QPushButton:hover{background-color:rgb(231, 241, 251); color: black;}"
                              "QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}"
                             );
    ui->registerbtn->setStyleSheet("QPushButton{border:2px groove blue;border-radius:20px}"
                              "QPushButton:hover{background-color:rgb(231, 241, 251); color: black;}"
                              "QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}"
                             );
    //设置界面边框
    this->setWindowFlags(this->windowFlags()|Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
    //设置图片
    QPixmap *pic = new QPixmap(":/img/log.png");
    QSize sz = ui->label_image->size();
    ui->label_image->setPixmap(pic->scaled(sz));
    //设置图片阴影效果
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    shadow->setOffset(-3, 0);
    shadow->setColor(QColor("#888888"));
    shadow->setBlurRadius(30);
    ui->label_image->setGraphicsEffect(shadow);

    LinkToServer();//连接到服务器

}

Login::~Login()
{
    delete myclient;
    delete ui;
}
void Login::LinkToServer(){
    //这里写连接到服务器
    if(myclient == 0){
        myclient = new TcpClient(this);
        if(myclient->connectToServer())
            qDebug() << "已连接到服务器！" ;
        else
            qDebug() << "未连接服务器！" ;
    }
    connect(myclient, SIGNAL(readyRead()),this, SLOT(recvMsg()));

}

void Login::recvMsg(){
    QString myarray = myclient->readAll();
    mymsg.toChatMsg(myarray);

    int id = mymsg.getReceiver();
    QString content = mymsg.getContent();

    qDebug() << "登录时的id：" << id;

    //对应登录
    if(mymsg.getType() == 3){
        //如果成功
        if(id){
            MainWindow *mw = new MainWindow(0,id,content,myclient);
            mw->show();
            this->close();
            return;
        }
        //如果不成功
        //如果是用户名错误
        if(mymsg.getContent().compare(QString::fromLocal8Bit("name"))==0){
            this->ui->Welcome->setText("账号不存在！");
        }
        else{
            this->ui->Welcome->setText("密码错误！");
        }
    }

}


void Login::on_logbtn_clicked()
{
    QString log_name = this->ui->accountNum->text();
    QString password = this->ui->passwordNum->text();
//    QFile file0("./user.txt");
//    file0.open(QIODevice::ReadOnly);
//    QTextStream tread(&file0);
//    while(!tread.atEnd()){
//        QString tmp = tread.readLine();
//        if(log_name==tmp){
//            QString tmp1 = tread.readLine();
//            if(password!=tmp1){
//                this->ui->Welcome->setText("密码错误！");
//                return;
//            }
//            else{
//                MainWindow *mw = new MainWindow();
//                mw->show();
//                this->close();
//                return;
//            }
//        }
//    }
//    this->ui->Welcome->setText("账号不存在！");

    QString content = QString("%1 %2").arg(log_name).arg(password);
    myclient->sendMsg(ChatMsg(3,0,0,content).toQString());

}

void Login::on_registerbtn_clicked()
{
    Register *r = new Register(0,myclient);
    r->show();
    this->close();
}

void Login::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton)
    {
        m_point = event->globalPos() - pos(); //计算移动量
        event->accept();
    }
}

void Login::mouseMoveEvent(QMouseEvent *event){
    if(event->buttons() & Qt::LeftButton)
    {
        move(event->globalPos() - m_point);
        event->accept();
    }
}

void Login::on_minimizedbtn_clicked()
{
    this->showMinimized();
}

void Login::on_closebtn_clicked()
{
    this->close();
}
