#ifndef USERINFO_H
#define USERINFO_H

#include <QByteArray>
#include <QDataStream>
#include <QIODevice>
#include <QObject>

class UserInfo {
private:
    explicit UserInfo(quint32 id = 0x0000,
        QString user_name = "",
        QString user_password = ""
        // QString avatar_name = ""
    );

    // info_get
    quint32 getID() const;
    QString getName() const;
    QString getPassword() const;
    // QString getAvatarName() const;

signals:

protected:
    quint32 id;
    QString user_name;
    QString user_password;
    // QString avatar_name;

public:
    //对于UserInfo的QByteArray编码方式
    // | quint32 id | quint32 name size | name | quint32 pwd size | password | quint32 avatar_name size | avatar |

    static UserInfo fromQByteArray(QByteArray chat_msg);
    QByteArray toQByteArray();
};

#endif // USERINFO_H
