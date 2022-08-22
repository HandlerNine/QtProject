#ifndef REGISTER_H
#define REGISTER_H

#include "Entity/chatmsg.h"
#include "Entity/userinfo.h"
#include <QGraphicsDropShadowEffect>
#include <QMouseEvent>
#include <QWidget>
#include <./Entity/userinfo.h>
#include "Network/tcpclient.h"
namespace Ui {
class Register;
}

class Register : public QWidget {
    Q_OBJECT

public:
    Register(QWidget* parent = 0, TcpClient* myclient = 0);
    ~Register();
    int getIDFromServer(UserInfo m);//从服务器获取ID
    int IsAccountExist(UserInfo m);//判断账号是否已经存在
    void LinkToServer();//连接到服务器
    void SaveToServer(UserInfo m);
    void sendMsgToServer(ChatMsg msg);

protected:
    void mousePressEvent(QMouseEvent* event);

    void mouseMoveEvent(QMouseEvent* event);

private slots:
    void on_confirmbtn_clicked();

    void on_backbtn_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_clicked();

    void recvMsg();

private:
    Ui::Register* ui;
    QPoint m_point;

    TcpClient* myclient; //记录本地服务器socket
    ChatMsg mymsg;
};

#endif // REGISTER_H
