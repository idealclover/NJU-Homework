#ifndef SHOWCART_H
#define SHOWCART_H

#include <QDialog>
#include "../Controller/cartctrl.h"
#include "../Controller/userctrl.h"
#include "../Controller/itemctrl.h"
#include <QStandardItem>

namespace Ui {
class ShowCart;
}

class ShowCart : public QDialog
{
    Q_OBJECT

public:
    void init(CartCtrl* ncartctrl, UserCtrl* nuserctrl, ItemCtrl* nitemctrl);
    explicit ShowCart(QWidget *parent = 0);
    ~ShowCart();

private slots:
    void on_delBtn_clicked();

    void on_buyBtn_clicked();

private:
    Ui::ShowCart *ui;
    CartCtrl* cartctrl;
    UserCtrl* userctrl;
    ItemCtrl* itemctrl;
    QStandardItemModel* model;
};

#endif // SHOWCART_H
