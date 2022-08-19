#include "testui.h"
#include "ui_testui.h"


//这个UI是用来测试各个类能否正常工作用的，啥都没有
TestUI::TestUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestUI)
{
    ui->setupUi(this);
}

TestUI::~TestUI()
{
    delete ui;
}
