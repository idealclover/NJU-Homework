#ifndef USERMAINWINDOW_H
#define USERMAINWINDOW_H

#include <QMainWindow>
#include <QStandardItem>
#include "../Controller/itemctrl.h"
#include "../Controller/cartctrl.h"
#include "../Controller/userctrl.h"

namespace Ui {
class UserMainWindow;
}

class UserMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserMainWindow(QWidget *parent = 0);
    ~UserMainWindow();

private slots:
    void addItemToCart(int num);
    void passUserCtrl(UserCtrl* nuserctrl);
    void on_AddToCartBtn_clicked();

    void on_seeCartBtn_clicked();

    void on_logOutBtn_clicked();

private:
    void refresh();
    Ui::UserMainWindow *ui;
    QStandardItemModel* model;
    UserCtrl* userctrl;
    ItemCtrl* itemctrl;
    CartCtrl* cartctrl;
};

#endif // USERMAINWINDOW_H
