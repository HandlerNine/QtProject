#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <Qdebug>
#include <QWidget>
#include <QPushButton>
#include <QGraphicsDropShadowEffect>
#include <QMouseEvent>

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_logbtn_clicked();

    void on_registerbtn_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
