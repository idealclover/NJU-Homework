/********************************************************************************
** Form generated from reading UI file 'logindlg.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDLG_H
#define UI_LOGINDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDlg
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *pwdLineEdit;
    QLineEdit *usrLineEdit;
    QPushButton *exitButton;
    QPushButton *loginButton;
    QCheckBox *isAdminCheckBox;
    QCheckBox *isNewUserCheckBox;

    void setupUi(QDialog *LoginDlg)
    {
        if (LoginDlg->objectName().isEmpty())
            LoginDlg->setObjectName(QStringLiteral("LoginDlg"));
        LoginDlg->resize(481, 239);
        formLayoutWidget = new QWidget(LoginDlg);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(50, 40, 381, 71));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        pwdLineEdit = new QLineEdit(formLayoutWidget);
        pwdLineEdit->setObjectName(QStringLiteral("pwdLineEdit"));
        pwdLineEdit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, pwdLineEdit);

        usrLineEdit = new QLineEdit(formLayoutWidget);
        usrLineEdit->setObjectName(QStringLiteral("usrLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, usrLineEdit);

        exitButton = new QPushButton(LoginDlg);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(340, 180, 91, 41));
        loginButton = new QPushButton(LoginDlg);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setGeometry(QRect(50, 180, 91, 41));
        isAdminCheckBox = new QCheckBox(LoginDlg);
        isAdminCheckBox->setObjectName(QStringLiteral("isAdminCheckBox"));
        isAdminCheckBox->setGeometry(QRect(350, 130, 81, 21));
        isNewUserCheckBox = new QCheckBox(LoginDlg);
        isNewUserCheckBox->setObjectName(QStringLiteral("isNewUserCheckBox"));
        isNewUserCheckBox->setGeometry(QRect(50, 130, 121, 21));
        QWidget::setTabOrder(usrLineEdit, pwdLineEdit);
        QWidget::setTabOrder(pwdLineEdit, isAdminCheckBox);
        QWidget::setTabOrder(isAdminCheckBox, loginButton);
        QWidget::setTabOrder(loginButton, exitButton);

        retranslateUi(LoginDlg);
        QObject::connect(exitButton, SIGNAL(clicked()), LoginDlg, SLOT(close()));

        QMetaObject::connectSlotsByName(LoginDlg);
    } // setupUi

    void retranslateUi(QDialog *LoginDlg)
    {
        LoginDlg->setWindowTitle(QApplication::translate("LoginDlg", "Dialog", nullptr));
        label->setText(QApplication::translate("LoginDlg", "Username", nullptr));
        label_2->setText(QApplication::translate("LoginDlg", "Password", nullptr));
        exitButton->setText(QApplication::translate("LoginDlg", "Exit", nullptr));
        loginButton->setText(QApplication::translate("LoginDlg", "Login", nullptr));
        isAdminCheckBox->setText(QApplication::translate("LoginDlg", "Admin", nullptr));
        isNewUserCheckBox->setText(QApplication::translate("LoginDlg", "New user", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDlg: public Ui_LoginDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDLG_H
