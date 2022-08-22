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
    void LinkToServer();//连接到服务器
    qint32 GetIdFromName(QString u_name);//从服务器获取ID

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();


private:
    Ui::addfriend *ui;

    TcpClient* myclient; //记录本地服务器socket
};

#endif // ADDFRIEND_H
