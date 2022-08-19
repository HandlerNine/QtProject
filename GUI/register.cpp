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

void Register::on_confirmbtn_clicked()
{
    QString nickname = this->ui->le_name->text();//昵称
    QString password1 = this->ui->le_setting->text();//密码
    QString password2 = this->ui->le_ensure->text();//确认密码
    QFile file0("C:/Users/86150/Desktop/QtPro819_1/restore/user.txt");
    file0.open(QIODevice::ReadOnly);
    QTextStream tread(&file0);
    while(!tread.atEnd()){
        QString tmp = tread.readLine();
        if(nickname==tmp){
            this->ui->label->setText("账号已存在");
            file0.close();
            return;
        }
    }

    if(nickname==""){
        this->ui->label->setText("昵称不能为空");
    }
    if(password1.length()<6){
        this->ui->label->setText("密码长度小于六位");
    }
    if(password1!=password2){
        this->ui->label->setText("两次密码输入不一致");
        this->ui->le_setting->setText("");
        this->ui->le_ensure->setText("");
    }
    //C:/Users/86150/Desktop/QtPro819_1/restore/user.txt"
    else{//否则存入user.txt
    QFile file("C:/Users/86150/Desktop/QtPro819_1/restore/user.txt");
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
