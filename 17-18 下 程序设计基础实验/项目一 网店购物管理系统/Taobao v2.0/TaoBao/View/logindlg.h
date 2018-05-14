#ifndef LOGINDLG_H
#define LOGINDLG_H

#include <QDialog>
#include "../Controller/userctrl.h"
#include "usermainwindow.h"

namespace Ui {
class LoginDlg;
}

class LoginDlg : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDlg(QWidget *parent = 0);
    void senduserctrl(void);
    ~LoginDlg();
    bool isAdmin;
    bool isNewUser;

private slots:
    void on_loginButton_clicked();

signals:
    void sendUserCtrl(UserCtrl* userctrl);

private:
    UserMainWindow u;
    UserCtrl* userctrl;
    Ui::LoginDlg *ui;
};

#endif // LOGINDLG_H
