#include "addsuccess.h"
#include "ui_addsuccess.h"

addsuccess::addsuccess(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addsuccess)
{
    ui->setupUi(this);
    ui->pushButton->setStyleSheet("QPushButton{border:2px groove black;border-radius:20px}"
                              "QPushButton:hover{background-color:rgb(231, 241, 251); color: black;}"
                              "QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}"
                             );
     this->setWindowFlags(this->windowFlags()|Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
    //设置图片
    QPixmap *pic = new QPixmap(":/img/addsuccess.jpg");
    QSize sz = ui->label_2->size();
    ui->label_2->setPixmap(pic->scaled(sz));
}

addsuccess::~addsuccess()
{
    delete ui;
}

void addsuccess::on_pushButton_clicked()
{
    this->close();
}
