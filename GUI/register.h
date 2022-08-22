#ifndef REGISTER_H
#define REGISTER_H

#include "Entity/chatmsg.h"
#include "Entity/userinfo.h"
#include "Network/tcpclient.h"
#include <QGraphicsDropShadowEffect>
#include <QMouseEvent>
#include <QWidget>

namespace Ui {
class Register;
}

class Register : public QWidget {
    Q_OBJECT

public:
    explicit Register(QWidget* parent = 0);
    ~Register();
    int getIDFromServer();
    void sendMsgToServer(ChatMsg msg);

protected:
    void mousePressEvent(QMouseEvent* event);

    void mouseMoveEvent(QMouseEvent* event);

private slots:
    void on_confirmbtn_clicked();

    void on_backbtn_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_clicked();

private:
    Ui::Register* ui;
    QPoint m_point;

    TcpClient* myclient; //记录本地服务器socket
};

#endif // REGISTER_H
