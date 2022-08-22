#include "register.h"
#include "ui_register.h"
#include "login.h"

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
    myclient = new TcpClient(this);
    connect(myclient, SIGNAL(readyRead()),this, SLOT(recvMsg()));

    if(myclient->connectToServer())
        qDebug() << "已连接到服务器！" ;
    else
        qDebug() << "未连接服务器！" ;

}

Register::~Register()
{
    delete myclient;
    delete ui;
}

void Register::on_confirmbtn_clicked()
{
    QString nickname = this->ui->lineEdit->text();//昵称
    QString password1 = this->ui->lineEdit_2->text();//密码
    QString password2 = this->ui->lineEdit_3->text();//确认密码
    QFile file0("./user.txt");
    file0.open(QIODevice::ReadOnly);
    QTextStream tread(&file0);

    if(nickname==""){
        this->ui->label->setText("账号不能为空");
        return;
    }

    while(!tread.atEnd()){
        QString tmp = tread.readLine();
        if(nickname==tmp){
            this->ui->label->setText("账号已存在");
            file0.close();
            return;
        }
    }

    if(password1.length()<6){
        this->ui->label->setText("密码长度小于六位");
        return;
    }
    if(password1!=password2){
        this->ui->label->setText("两次密码输入不一致");
        this->ui->lineEdit_2->setText("");
        this->ui->lineEdit_3->setText("");
        return;
    }
    //C:/Users/86150/Desktop/QtPro819_1/restore/user.txt"
    else{//否则存入user.txt
    QFile file("./user.txt");
         if(file.open(QIODevice::WriteOnly|QIODevice::Append) == true) {
                     QTextStream twrite(&file);
                     twrite << nickname << endl << password1 << endl;
                     this->ui->label->setText("注册成功！");
         }

    }
}

void Register::on_backbtn_clicked()
{
    Login *l = new Login();
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

