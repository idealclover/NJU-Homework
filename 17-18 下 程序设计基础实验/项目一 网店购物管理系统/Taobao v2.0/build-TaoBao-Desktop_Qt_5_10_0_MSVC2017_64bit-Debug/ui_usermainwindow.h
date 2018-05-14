/********************************************************************************
** Form generated from reading UI file 'usermainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERMAINWINDOW_H
#define UI_USERMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserMainWindow
{
public:
    QWidget *centralwidget;
    QTableView *tableView;
    QSplitter *splitter;
    QPushButton *AddToCartBtn;
    QPushButton *seeCartBtn;
    QPushButton *logOutBtn;
    QPushButton *exitBtn;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *UserMainWindow)
    {
        if (UserMainWindow->objectName().isEmpty())
            UserMainWindow->setObjectName(QStringLiteral("UserMainWindow"));
        UserMainWindow->resize(782, 600);
        centralwidget = new QWidget(UserMainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(0, 30, 781, 481));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(140, 530, 531, 31));
        splitter->setOrientation(Qt::Horizontal);
        AddToCartBtn = new QPushButton(splitter);
        AddToCartBtn->setObjectName(QStringLiteral("AddToCartBtn"));
        splitter->addWidget(AddToCartBtn);
        seeCartBtn = new QPushButton(splitter);
        seeCartBtn->setObjectName(QStringLiteral("seeCartBtn"));
        splitter->addWidget(seeCartBtn);
        logOutBtn = new QPushButton(splitter);
        logOutBtn->setObjectName(QStringLiteral("logOutBtn"));
        splitter->addWidget(logOutBtn);
        exitBtn = new QPushButton(splitter);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));
        splitter->addWidget(exitBtn);
        UserMainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(UserMainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        UserMainWindow->setStatusBar(statusbar);

        retranslateUi(UserMainWindow);
        QObject::connect(exitBtn, SIGNAL(clicked()), UserMainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(UserMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *UserMainWindow)
    {
        UserMainWindow->setWindowTitle(QApplication::translate("UserMainWindow", "MainWindow", nullptr));
        AddToCartBtn->setText(QApplication::translate("UserMainWindow", "Add to cart", nullptr));
        seeCartBtn->setText(QApplication::translate("UserMainWindow", "View cart", nullptr));
        logOutBtn->setText(QApplication::translate("UserMainWindow", "logout", nullptr));
        exitBtn->setText(QApplication::translate("UserMainWindow", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserMainWindow: public Ui_UserMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMAINWINDOW_H
