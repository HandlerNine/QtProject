#include "chatmsg.h"

using namespace std;

ChatMsg::ChatMsg(
        int type,
        int sender,
        int receiver,
        const QString content)
    : _type(type)
    , _sender(sender)
    , _receiver(receiver)
    , _content(content)
{
    _send_time = (QDateTime::currentDateTime()).toString("yyyy-mm-dd_hh:mm:ss");
}

ChatMsg::ChatMsg(int type, int sender, int receiver)
    : _type(type)
    , _sender(sender)
    , _receiver(receiver)
{
    _send_time = (QDateTime::currentDateTime()).toString("yyyy-mm-dd_hh:mm:ss");
}

int ChatMsg::getType() const
{
    return _sender;
}

int ChatMsg::getSender() const
{
    return _sender;
}

int ChatMsg::getReceiver() const
{
    return _receiver;
}

QString ChatMsg::getContent()
{
    return _content;
}

QString ChatMsg::getSendTime()
{
    return _send_time;
}

QString ChatMsg::toQString()
{
    string str =to_string(this->_type) + " "  + to_string(this->_sender) + " " + to_string(this->_receiver) + " " + this->_send_time.toStdString()
            + " " + this->_content.toStdString();
    return QString::fromStdString(str);
}

void ChatMsg::toChatMsg(QString recv_string)
{
    string str = recv_string.toStdString();

    int pos0 = str.find(" ",0);
    string type = str.substr(0,pos0);
    this->_type = std::stoi(type);

    int pos1 = str.find(" ", pos0 + 1);
    string sender = str.substr(pos0+1, pos1 - pos0);
    this->_sender = std::stoi(sender);

    int pos2 = str.find(" ", pos1 + 1);
    string receiver = str.substr(pos1 + 1, pos2 - pos1);
    //    std::cout << "pos2:" << pos2 << "n" << '\n';
    this->_receiver = std::stoi(receiver);

    int pos3 = str.find(" ", pos2 + 1);
    string send_time = str.substr(pos2 + 1, pos3 - pos2 - 1);
    this->_send_time = QString::fromStdString(send_time);

    string content = str.substr(pos3 + 1, str.size() - pos3);
    this->_content = QString::fromStdString(content);
}
