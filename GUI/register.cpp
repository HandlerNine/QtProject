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

}

Register::~Register()
{
    delete ui;
}
void Register::LinkToServer(){
    //这里写连接到服务器的方法
}
bool Register::IsAccountExist(UserInfo m){
    //这里先将UserInfo转化为ChatMessage
    //再将ChatMessage发送到服务器判断账号是否已经存在
}
int Register::getIDFromServer(UserInfo m){
    return 1;//这里是服务器为符合注册条件的账号分配ID
}
void Register::SaveToServer(UserInfo m){

}
void Register::on_confirmbtn_clicked()
{
    QString nickname = this->ui->lineEdit->text();//昵称
    QString password1 = this->ui->lineEdit_2->text();//密码
    QString password2 = this->ui->lineEdit_3->text();//确认密码
//    QFile file0("./user.txt");
//    file0.open(QIODevice::ReadOnly);
//    QTextStream tread(&file0);
    //这里需要连接服务器
    LinkToServer();
    if(nickname==""){
        this->ui->label->setText("账号不能为空");
        return;//判断账号是否为空，在本地即可实现
    }

//    while(!tread.atEnd()){
//        QString tmp = tread.readLine();
//        if(nickname==tmp){
//            this->ui->label->setText("账号已存在");
//            file0.close();
//            return;
//        }
//    }
    qint32 tmp_ID = 0;//这里因为验证时还没有赋给User_Info m ID，所以先假设其ID为一默认值
    UserInfo m(tmp_ID,nickname,password1);
    if(IsAccountExist(m)){
        this->ui->label->setText("账号已存在");
        return;//返回
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

    //C:/Users/86150/Desktop/QtPro819_1/restore/user.txt"
//    else{//否则存入user.txt
//    QFile file("./user.txt");
//         if(file.open(QIODevice::WriteOnly|QIODevice::Append) == true) {
//                     QTextStream twrite(&file);
//                     twrite << nickname << endl << password1 << endl;
//                     this->ui->label->setText("注册成功！");
//         }

//    }
    else{//否则存入服务器端的数据库中
        int tt_ID = getIDFromServer(m);
        UserInfo SatisUser(tt_ID,nickname,password1);
        SaveToServer(SatisUser);
        this->ui->label->setText("注册成功！");
        return;
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

