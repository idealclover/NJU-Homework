#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>

#include "view/logindlg.h"
#include "view/usermainwindow.h"
#include "View/adminmainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    LoginDlg dlg;


    if(dlg.exec() == QDialog::Accepted){
        if(dlg.isAdmin == true){
            AdminMainWindow b;
           // QObject::connect(&dlg,SIGNAL(sendUserCtrl(UserCtrl*)),&u,SLOT(passUserCtrl(UserCtrl*)));
            b.show();
            return a.exec();
        }else{
            UserMainWindow u;
            QObject::connect(&dlg,SIGNAL(sendUserCtrl(UserCtrl*)),&u,SLOT(passUserCtrl(UserCtrl*)));
            dlg.senduserctrl();
            u.show();
            return a.exec();
        }
        //w.show();
        //return a.exec();
    }
    else return 0;
}
