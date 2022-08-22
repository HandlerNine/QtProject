#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <Qdebug>
#include <QWidget>
#include <QPushButton>
#include <QGraphicsDropShadowEffect>
#include <QMouseEvent>
#include <QPoint>
#include <./Entity/userinfo.h>
#include "Network/tcpclient.h"
#include "Entity/chatmsg.h"
namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0, TcpClient* myclient = 0);
    ~Login();
    void LinkToServer();//连接到服务器。
    bool IsAccountExit(UserInfo m);//判断账号是否存在
    bool IsPaWdCorrect(UserInfo m);//判断密码是否正确

protected:
    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

private slots:
    void on_logbtn_clicked();

    void on_registerbtn_clicked();

    void on_closebtn_clicked();

    void on_minimizedbtn_clicked();

    void recvMsg();

private:
    Ui::Login *ui;
    QPoint m_point;

    TcpClient* myclient; //记录本地服务器socket
    ChatMsg mymsg;
};

#endif // LOGIN_H
