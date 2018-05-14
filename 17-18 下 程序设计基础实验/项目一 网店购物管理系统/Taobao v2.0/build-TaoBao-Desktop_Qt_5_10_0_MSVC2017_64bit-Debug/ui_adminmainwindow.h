/********************************************************************************
** Form generated from reading UI file 'adminmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINMAINWINDOW_H
#define UI_ADMINMAINWINDOW_H

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

class Ui_AdminMainWindow
{
public:
    QWidget *centralwidget;
    QTableView *tableView;
    QSplitter *splitter;
    QPushButton *addBtn;
    QPushButton *delBtn;
    QPushButton *showListBtn;
    QPushButton *logoutBtn;
    QPushButton *exitBtn;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AdminMainWindow)
    {
        if (AdminMainWindow->objectName().isEmpty())
            AdminMainWindow->setObjectName(QStringLiteral("AdminMainWindow"));
        AdminMainWindow->resize(753, 512);
        centralwidget = new QWidget(AdminMainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(0, 0, 801, 411));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(41, 443, 681, 31));
        splitter->setOrientation(Qt::Horizontal);
        addBtn = new QPushButton(splitter);
        addBtn->setObjectName(QStringLiteral("addBtn"));
        splitter->addWidget(addBtn);
        delBtn = new QPushButton(splitter);
        delBtn->setObjectName(QStringLiteral("delBtn"));
        splitter->addWidget(delBtn);
        showListBtn = new QPushButton(splitter);
        showListBtn->setObjectName(QStringLiteral("showListBtn"));
        splitter->addWidget(showListBtn);
        logoutBtn = new QPushButton(splitter);
        logoutBtn->setObjectName(QStringLiteral("logoutBtn"));
        splitter->addWidget(logoutBtn);
        exitBtn = new QPushButton(splitter);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));
        splitter->addWidget(exitBtn);
        AdminMainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(AdminMainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        AdminMainWindow->setStatusBar(statusbar);

        retranslateUi(AdminMainWindow);
        QObject::connect(exitBtn, SIGNAL(clicked()), AdminMainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(AdminMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AdminMainWindow)
    {
        AdminMainWindow->setWindowTitle(QApplication::translate("AdminMainWindow", "MainWindow", nullptr));
        addBtn->setText(QApplication::translate("AdminMainWindow", "Add", nullptr));
        delBtn->setText(QApplication::translate("AdminMainWindow", "Delete", nullptr));
        showListBtn->setText(QApplication::translate("AdminMainWindow", "List", nullptr));
        logoutBtn->setText(QApplication::translate("AdminMainWindow", "Logout", nullptr));
        exitBtn->setText(QApplication::translate("AdminMainWindow", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminMainWindow: public Ui_AdminMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINMAINWINDOW_H
