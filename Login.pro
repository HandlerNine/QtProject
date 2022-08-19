#-------------------------------------------------
#
# Project created by QtCreator 2022-08-18T20:27:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Login
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp \
    chatmessage/qnchatmessage.cpp \
    GUI/mainwindow.cpp \
    GUI/login.cpp \
    GUI/register.cpp \
    Entity/chatmsg.cpp \
    Entity/chatprivate.cpp \
    Entity/friendcenter.cpp \
    Entity/group.cpp \
    Entity/groupcenter.cpp \
    Entity/msg.cpp \
    Entity/receiver.cpp \
    Entity/sender.cpp \
    Entity/userinfo.cpp \
    Entity/chatgroup.cpp \
    GUI/testui.cpp \
    GUI/addfriend.cpp \
    GUI/addgroup.cpp \
    GUI/addsuccess.cpp \
    GUI/chooseadd.cpp

HEADERS  += \
    chatmessage/qnchatmessage.h \
    GUI/mainwindow.h \
    GUI/login.h \
    GUI/register.h \
    Entity/chatmsg.h \
    Entity/chatprivate.h \
    Entity/friendcenter.h \
    Entity/group.h \
    Entity/groupcenter.h \
    Entity/msg.h \
    Entity/msgtype.h \
    Entity/receiver.h \
    Entity/sender.h \
    Entity/userinfo.h \
    Entity/chatgroup.h \
    GUI/testui.h \
    GUI/addfriend.h \
    GUI/addgroup.h \
    GUI/addsuccess.h \
    GUI/chooseadd.h

FORMS    += \
    GUI/mainwindow.ui \
    GUI/login.ui \
    GUI/register.ui \
    GUI/testui.ui \
    GUI/addfriend.ui \
    GUI/addgroup.ui \
    GUI/addsuccess.ui \
    GUI/chooseadd.ui

RESOURCES += \
    images.qrc

DISTFILES +=
