#include "register.h"
#include "ui_register.h"

Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);

    //优化按钮ui
    ui->confirmbtn->setStyleSheet("QPushButton{border:2px groove blue;border-radius:20px}"
                              "QPushButton:hover{background-color:rgb(231, 241, 251); color: black;}"
                              "QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}"
                             );
    ui->backbtn->setStyleSheet("QPushButton{border:2px groove blue;border-radius:20px}"
                              "QPushButton:hover{background-color:rgb(231, 241, 251); color: black;}"
                              "QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}"
                             );
    //设置界面边框
    this->setWindowFlags(this->windowFlags()|Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
    //设置图片
    QPixmap *pic = new QPixmap(":/img/register.png");
    QSize sz = ui->registerImage->size();
    ui->registerImage->setPixmap(pic->scaled(sz));
    //设置图片阴影效果
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    shadow->setOffset(-3, 0);
    shadow->setColor(QColor("#888888"));
    shadow->setBlurRadius(30);
    ui->registerImage->setGraphicsEffect(shadow);
    //服务器相关
    LinkToServer();

}

Register::~Register()
{
    delete myclient;
    delete ui;
}

void Register::LinkToServer(){
    //这里写连接到服务器
    if(!myclient)
        myclient = new TcpClient(this);
    connect(myclient, SIGNAL(readyRead()),this, SLOT(recvMsg()));
    if(myclient->connectToServer())
        qDebug() << "已连接到服务器！" ;
    else
        qDebug() << "未连接服务器！" ;
}

//需要写一个接收信息的槽
void Register::recvMsg(){
    QString myarray = myclient->readAll();
    mymsg.toChatMsg(myarray);

    int id = mymsg.getReceiver();

    qDebug()<<"注册时获取到 type：" << mymsg.getType() << "  send:" << mymsg.getSender() << "  recv:" << mymsg.getReceiver()
           <<"  time" << mymsg.getSendTime() << "  content:" <<mymsg.getContent();

    if(mymsg.getType() == 2){
        //如果成功
        if(id){
            this->ui->label->setText("注册成功！");
        }
        //否则，就是账号已存在
        else{
            this->ui->label->setText("账号已存在");
        }
    }
}

void Register::on_confirmbtn_clicked()
{
    QString nickname = this->ui->lineEdit->text();//昵称
    QString password1 = this->ui->lineEdit_2->text();//密码
    QString password2 = this->ui->lineEdit_3->text();//确认密码

    if(nickname==""){
        this->ui->label->setText("账号不能为空");
        return;//判断账号是否为空，在本地即可实现
    }

    if(nickname.contains(" ")){
        this->ui->label->setText("账号不能有空格");
        return;
    }
    if(password1.contains(" ")){
        this->ui->label->setText("密码不能有空格");
        return;
    }

    if(password1.length()<6){
        this->ui->label->setText("密码长度小于六位");
        return;//本地可判断
    }

    if(password1!=password2){
        this->ui->label->setText("两次密码输入不一致");
        this->ui->lineEdit_2->setText("");
        this->ui->lineEdit_3->setText("");
        return;//本地可判断
    }

    //可以发消息了
    QString content = QString("%1 %2").arg(nickname).arg(password1);
    myclient->sendMsg(ChatMsg(Chat_Register,0,0,content).toQString());
}

void Register::on_backbtn_clicked()
{
    Login *l = new Login;
    l->show();
    this->close();
}


void Register::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton)
    {
        m_point = event->globalPos() - pos(); //计算移动量
        event->accept();
    }
}

void Register::mouseMoveEvent(QMouseEvent *event){
    if(event->buttons() & Qt::LeftButton)
    {
        move(event->globalPos() - m_point);
        event->accept();
    }
}

void Register::on_toolButton_clicked()
{
    this->showMinimized();
}

void Register::on_toolButton_2_clicked()
{
    this->close();
}

