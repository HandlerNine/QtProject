#include "addfriend.h"
#include "ui_addfriend.h"
#include "./GUI/mainwindow.h"
#include"./GUI/addsuccess.h"
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

void addfriend::on_pushButton_clicked()
{
    QString friendID = ui->add_num->text();
    //之后搜索好友进行添加，这里需要补充
    addsuccess *m = new addsuccess();
    m->show();
}
