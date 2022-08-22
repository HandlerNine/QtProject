#ifndef ADDFRIEND_H
#define ADDFRIEND_H

#include <./GUI/mainwindow.h>
#include <QWidget>

#include <./Entity/friendlist.h>
namespace Ui {
class addfriend;
}

class addfriend : public QWidget
{
    Q_OBJECT

public:
    explicit addfriend(QWidget *parent = 0);
    ~addfriend();
    friendlist frdlst;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::addfriend *ui;
};

#endif // ADDFRIEND_H
