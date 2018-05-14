/********************************************************************************
** Form generated from reading UI file 'showcart.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWCART_H
#define UI_SHOWCART_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_ShowCart
{
public:
    QTableView *tableView;
    QSplitter *splitter;
    QPushButton *buyBtn;
    QPushButton *delBtn;
    QPushButton *exitBtn;

    void setupUi(QDialog *ShowCart)
    {
        if (ShowCart->objectName().isEmpty())
            ShowCart->setObjectName(QStringLiteral("ShowCart"));
        ShowCart->resize(1061, 300);
        tableView = new QTableView(ShowCart);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(0, 0, 881, 301));
        splitter = new QSplitter(ShowCart);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(910, 20, 131, 81));
        splitter->setOrientation(Qt::Vertical);
        buyBtn = new QPushButton(splitter);
        buyBtn->setObjectName(QStringLiteral("buyBtn"));
        splitter->addWidget(buyBtn);
        delBtn = new QPushButton(splitter);
        delBtn->setObjectName(QStringLiteral("delBtn"));
        splitter->addWidget(delBtn);
        exitBtn = new QPushButton(splitter);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));
        splitter->addWidget(exitBtn);

        retranslateUi(ShowCart);
        QObject::connect(buyBtn, SIGNAL(clicked()), ShowCart, SLOT(accept()));
        QObject::connect(exitBtn, SIGNAL(clicked()), ShowCart, SLOT(exec()));

        QMetaObject::connectSlotsByName(ShowCart);
    } // setupUi

    void retranslateUi(QDialog *ShowCart)
    {
        ShowCart->setWindowTitle(QApplication::translate("ShowCart", "Dialog", nullptr));
        buyBtn->setText(QApplication::translate("ShowCart", "Buy All", nullptr));
        delBtn->setText(QApplication::translate("ShowCart", "Delete", nullptr));
        exitBtn->setText(QApplication::translate("ShowCart", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowCart: public Ui_ShowCart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWCART_H
