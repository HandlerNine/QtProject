#ifndef USERINFO_H
#define USERINFO_H

#include <QByteArray>
#include <QDataStream>
#include <QFile>
#include <QIODevice>
#include <QList>
#include <QObject>

class UserInfo {
public:
    explicit UserInfo(quint32 id = 0x0000,
        QString user_name = "",
        QString user_password = ""
        // QString avatar_name = ""
    );
    // info_get
    QString getPassword() const;
    // QString getAvatarName() const;

signals:

protected:
    quint32 id;
    QString user_name;
    QString user_password;
    // QString avatar_name;

public:
    quint32 getID() const;
    QString getName() const;
    QList<UserInfo> OpenFile(QString fileName); // 根据文件地址,返回userinfo的list
    void WriteFile(QString fileName, UserInfo tmp_user); //将userinfo信息转换成QByteArray写入文件

    //对于UserInfo的QByteArray编码方式
    // | quint32 id | quint32 name size | name | quint32 pwd size | password | quint32 avatar_name size | avatar |
    static UserInfo fromQByteArray(QByteArray chat_msg);
    QByteArray toQByteArray();

    // QByteArray OpenFiles(QString fileName);
};

#endif // USERINFO_H
