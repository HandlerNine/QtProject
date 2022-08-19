#ifndef TESTUI_H
#define TESTUI_H

#include <QWidget>

//这个UI是用来测试各个类能否正常工作用的，啥都没有
namespace Ui {
class TestUI;
}

class TestUI : public QWidget
{
    Q_OBJECT

public:
    explicit TestUI(QWidget *parent = 0);
    ~TestUI();

private:
    Ui::TestUI *ui;
};

#endif // TESTUI_H
