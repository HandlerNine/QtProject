#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Network/tcpclient.h"
#include "chatmessage/qnchatmessage.h"
#include <Entity/userinfo.h>
#include <QListWidgetItem>
#include <QMainWindow>
#include <QMouseEvent>
#include <QToolButton>
#include <QPropertyAnimation>
#include "Entity/chatmsg.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

    int i = 0;

    void show_sendMessage(QString content);
    void show_recvMessage(QString content);

    void dealMessage(QNChatMessage* messageW, QListWidgetItem* item, QString text, QString time, QNChatMessage::User_Type type);
    void dealMessageTime(QString curMsgTime);
    void sendIDToServer(UserInfo tmp_user);
    void LinkToServer();//code by xwb
    qint32 GetIDFromName(QString fd_name);//通过好友名字查找好友ID
    void LinkToFriend(qint32 ID);//通过ID连接到好友

protected:
    void resizeEvent(QResizeEvent* event);

    void mousePressEvent(QMouseEvent* event);

    void mouseMoveEvent(QMouseEvent* event);

private slots:
    void on_pushButton_clicked();

    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

    void on_settingButton_clicked();

    void on_singleButton_clicked();

    void on_moreButton_clicked();

    void recvMsg();

    void sendMsg(ChatMsg msg);

    void on_shakebtn_clicked();

    void on_FixHeadbtn_clicked();

        void on_friendList_itemClicked(QListWidgetItem *item);

private:
    Ui::MainWindow* ui;
    TcpClient* myclient; //记录本地服务器socket
    QPoint m_point;
    QPropertyAnimation *pShakeAnimation= nullptr;

    ChatMsg mymsg;   //记录收集到的和使用的chatmsg
    int Friend_ID = 0;
};

#endif // MAINWINDOW_H
