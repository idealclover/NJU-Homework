#-------------------------------------------------
#
# Project created by QtCreator 2018-04-17T15:32:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TaoBao
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    View/logindlg.cpp \
    Model/item.cpp \
    Model/user.cpp \
    Controller/cartctrl.cpp \
    Controller/filectrl.cpp \
    Controller/itemctrl.cpp \
    Controller/userctrl.cpp \
    View/usermainwindow.cpp \
    View/addtocartview.cpp \
    View/showcart.cpp \
    View/adminmainwindow.cpp \
    View/showlistview.cpp \
    View/additemview.cpp

HEADERS += \
        mainwindow.h \
    View/logindlg.h \
    Model/item.h \
    Model/user.h \
    Controller/cartctrl.h \
    Controller/filectrl.h \
    Controller/itemctrl.h \
    Controller/userctrl.h \
    const.h \
    setting.h \
    View/usermainwindow.h \
    View/addtocartview.h \
    View/showcart.h \
    View/adminmainwindow.h \
    View/showlistview.h \
    View/additemview.h

FORMS += \
        mainwindow.ui \
    View/logindlg.ui \
    View/usermainwindow.ui \
    View/addtocartview.ui \
    View/showcart.ui \
    View/adminmainwindow.ui \
    View/showlistview.ui \
    View/additemview.ui
