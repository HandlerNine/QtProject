#include "addgroup.h"
#include "ui_addgroup.h"
#include "./GUI/addsuccess.h"
addgroup::addgroup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addgroup)
{
    ui->setupUi(this);
    //按钮ui优化
    ui->pushButton_5->setStyleSheet("QPushButton{border:2px groove black;border-radius:20px}"
                              "QPushButton:hover{background-color:rgb(231, 241, 251); color: black;}"
                              "QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}"
                             );
    ui->pushButton_6->setStyleSheet("QPushButton{border:2px groove black;border-radius:20px}"
                              "QPushButton:hover{background-color:rgb(231, 241, 251); color: black;}"
                              "QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}"
                             );
     this->setWindowFlags(this->windowFlags()|Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
    //设置图片
    QPixmap *pic = new QPixmap(":/img/addgroup.jpg");
    QSize sz = ui->label_2->size();
    ui->label_2->setPixmap(pic->scaled(sz));
}

addgroup::~addgroup()
{
    delete ui;
}

void addgroup::on_pushButton_6_clicked()
{
    QString GroupID = ui->add_num->text();
    //之后搜索群号进行添加，这里需要补充
    addsuccess *m = new addsuccess();
    m->show();
}

void addgroup::on_pushButton_5_clicked()
{
    this->close();
}
