#include "login.h"
#include "ui_login.h"
#include "register.h"
#include "mainwindow.h"

Login::Login(QWidget *parent) :
    QMainWindow(parent),
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

}

Login::~Login()
{
    delete ui;
}

void Login::on_logbtn_clicked()
{
    QString log_name = this->ui->accountID->text();
    QString password = this->ui->passwordNum->text();
    QFile file0("C:/Users/86150/Desktop/QtPro819_1/restore/user.txt");
    file0.open(QIODevice::ReadOnly);
    QTextStream tread(&file0);
    while(!tread.atEnd()){
        QString tmp = tread.readLine();
        if(log_name==tmp){
            QString tmp1 = tread.readLine();
            if(password!=tmp1){
                this->ui->Welcome->setText("密码错误！");
                return;
            }
            else{
                MainWindow *mw = new MainWindow();
                mw->show();
                this->close();
                return;
            }
        }
    }
    this->ui->Welcome->setText("账号不存在！");
    return;
}

void Login::on_registerbtn_clicked()
{
    Register *r = new Register();
    r->show();
    this->close();
}
