#include "addfail.h"
#include "ui_addfail.h"

AddFail::AddFail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddFail)
{
    ui->setupUi(this);
    //按钮ui优化
    ui->pushButton->setStyleSheet("QPushButton{border:2px groove black;border-radius:20px}"
                              "QPushButton:hover{background-color:rgb(231, 241, 251); color: black;}"
                              "QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}"
                             );

     this->setWindowFlags(this->windowFlags()|Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
    //设置图片
    QPixmap *pic = new QPixmap(":/img/addfail.jpg");
    QSize sz = ui->label_2->size();
    ui->label_2->setPixmap(pic->scaled(sz));
}

AddFail::~AddFail()
{
    delete ui;
}

void AddFail::on_pushButton_clicked()
{
    this->close();
}
