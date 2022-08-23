#include "chooseadd.h"
#include "ui_chooseadd.h"
#include"addfriend.h"
#include "addgroup.h"
#include "login.h"
#include "ui_login.h"
#include "register.h"
#include "mainwindow.h"
chooseadd::chooseadd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chooseadd)
{
    ui->setupUi(this);
    ui->pushButton->setStyleSheet("QPushButton{border:2px groove black;border-radius:20px}"
                              "QPushButton:hover{background-color:rgb(231, 241, 251); color: black;}"
                              "QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}"
                             );
    ui->pushButton_2->setStyleSheet("QPushButton{border:2px groove black;border-radius:20px}"
                              "QPushButton:hover{background-color:rgb(231, 241, 251); color: black;}"
                              "QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}"
                             );
    ui->pushButton_3->setStyleSheet("QPushButton{border:2px groove black;border-radius:20px}"
                              "QPushButton:hover{background-color:rgb(231, 241, 251); color: black;}"
                              "QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}"
                             );
    this->setWindowFlags(this->windowFlags()|Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
    QPixmap *pic = new QPixmap(":/img/choose.jpg");
    QSize sz = ui->label->size();
    ui->label->setPixmap(pic->scaled(sz));
}

chooseadd::~chooseadd()
{
    delete ui;
}

void chooseadd::on_pushButton_clicked()
{
    emit sendChooseAddSignal(0);
    this->close();
}

void chooseadd::on_pushButton_2_clicked()
{
    emit sendChooseAddSignal(1);
    this->close();
}

void chooseadd::on_pushButton_3_clicked()
{
    this->close();
}
