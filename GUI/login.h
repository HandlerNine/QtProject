#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <Qdebug>
#include <QWidget>
#include <QPushButton>
#include <QGraphicsDropShadowEffect>
#include <QMouseEvent>
#include <QPoint>

#include "Network/tcpclient.h"

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

protected:
    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

private slots:
    void on_logbtn_clicked();

    void on_registerbtn_clicked();

    void on_closebtn_clicked();

    void on_minimizedbtn_clicked();

private:
    Ui::Login *ui;
    QPoint m_point;

    TcpClient* myclient; //记录本地服务器socket
};

#endif // LOGIN_H
