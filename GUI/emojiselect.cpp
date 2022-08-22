#include "emojiselect.h"
#include "ui_emojiselect.h"

EmojiSelect::EmojiSelect(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EmojiSelect)
{
    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags()|Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
    ui->confirmbtn->setStyleSheet("QPushButton{border:1px groove gray;border-radius:8px}"
                              "QPushButton:hover{background-color:rgb(231, 241, 251); color: black;}"
                              "QPushButton:pressed{background-color:rgb(204, 228, 247);border-style: inset;}"
                             );
}

EmojiSelect::~EmojiSelect()
{
    delete ui;
}

void EmojiSelect::on_toolButton_clicked()
{
    this->close();
}

void EmojiSelect::on_selectbtn_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                 "/home"
                 );//tr("Images (*.png *.xpm *.jpg *.txt *.gz)")
    //fileName = QFileDialog::getOpenFileName(this);
    qDebug() << "fileName:" << fileName;
    ui->lineEdit->setText(fileName);
    ui->lineEdit->setCursorPosition(0);
}

void EmojiSelect::on_confirmbtn_clicked()
{
    //这里需要发送图片给对方
}
