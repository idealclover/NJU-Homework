#include "logindlg.h"
#include "ui_logindlg.h"
#include <QMessageBox>

LoginDlg::LoginDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDlg)
{       
    userctrl = new UserCtrl();
    ui->setupUi(this);
}

LoginDlg::~LoginDlg()
{
    delete ui;
}

void LoginDlg::senduserctrl(void){
    emit sendUserCtrl(userctrl);
}

void LoginDlg::on_loginButton_clicked()
{
    isAdmin = ui->isAdminCheckBox->checkState();
    isNewUser = ui->isNewUserCheckBox->checkState();
    if(isNewUser && isAdmin){
        QMessageBox::warning(this, tr("Waring"),
                             tr("can't register admin!"),
                             QMessageBox::Yes);
    }
    else if(isNewUser){
        if (userctrl->addNewUser(ui->usrLineEdit->text().toStdString(), ui->pwdLineEdit->text().toStdString()) == false) {
            QMessageBox::warning(this, tr("Waring"),
                                 tr("user name has been used!"),
                                 QMessageBox::Yes);
        }else{
            userctrl->authUser(ui->usrLineEdit->text().toStdString(), ui->pwdLineEdit->text().toStdString());
            accept();
        }
    }
    else if(isAdmin){
        int rst = userctrl->authAdmin(ui->usrLineEdit->text().toStdString(), ui->pwdLineEdit->text().toStdString());
        switch (rst) {
        case USERNAME_UNUSED:
            QMessageBox::warning(this, tr("Waring"),
                                 tr("user name unused!"),
                                 QMessageBox::Yes);
            break;
        case PASSWORD_NOTVALID:
            QMessageBox::warning(this, tr("Waring"),
                                 tr("user name or password error!"),
                                 QMessageBox::Yes);
            break;
        default:
            accept();
        }
    }else{
        int rst = userctrl->authUser(ui->usrLineEdit->text().toStdString(), ui->pwdLineEdit->text().toStdString());
        switch (rst) {
        case USERNAME_UNUSED:
            QMessageBox::warning(this, tr("Waring"),
                                 tr("user name unused!"),
                                 QMessageBox::Yes);
            break;
        case PASSWORD_NOTVALID:
            QMessageBox::warning(this, tr("Waring"),
                                 tr("user name or password error!"),
                                 QMessageBox::Yes);
            break;
        default:
            accept();
        }
    }
    //accept();
}
