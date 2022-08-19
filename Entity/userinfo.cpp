#include "userinfo.h"

UserInfo::UserInfo(quint32 id,
    QString user_name,
    QString user_password)
    : id(id)
    , user_name(user_name)
    , user_password(user_password)
{
}

quint32 UserInfo::getID() const
{
    return id;
}
QString UserInfo::getName() const
{
    return user_name;
}
QString UserInfo::getPassword() const
{
    return user_password;
}
/*
 * QByteArray内容的排列顺序为
 * quint32 id
 * quint32 size_name
 *  QString user_name
 * quint32 size_password
 *  QString user_password
 */
UserInfo UserInfo::fromQByteArray(QByteArray in_msg)
{
    QDataStream in(in_msg);
    in.setVersion(QDataStream::Qt_5_8);

    UserInfo tmp_user;
    quint32 size;

    // get_id
    in >> tmp_user.id;

    // get_name
    in >> size;
    QByteArray tmpName;
    tmpName.resize(size);
    in >> tmpName;
    tmp_user.user_name = QString(tmpName);

    // get_password
    in >> size;
    QByteArray tmpPassword;
    tmpPassword.resize(size);
    in >> tmpPassword;
    tmp_user.user_password = QString(tmpPassword);

    return tmp_user;
}
/*
 * QByteArray内容的排列顺序为
 * quint32 id
 * quint32 size_name
 *  QString user_name
 * quint32 size_password
 *  QString user_password
 */
QByteArray UserInfo::toQByteArray()
{
    QByteArray qba;
    QDataStream out(&qba, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_8);

    // out_id
    out << quint32(id);

    // out_name
    out << quint32(0); // 给size_name预留空间
    out << user_name.toUtf8(); // user_name
    out.device()->seek(4); // 定位到id后面 准备输入user_size
    out << (quint32)(qba.size() - sizeof(quint32) * 2); //计算得到user_size
    int index = qba.size();
    out.device()->seek(index); //定位到行末

    // out_password
    out << quint32(0);
    out << user_password.toUtf8();
    out.device()->seek(index);
    out << (quint32)(qba.size() - index - sizeof(quint32)); //计算得到user_size
    out.device()->seek(qba.size()); //定位到行末\

    return qba;
}
