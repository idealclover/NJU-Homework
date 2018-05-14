#include "showcart.h"
#include "ui_showcart.h"
#include <QMessageBox>

ShowCart::ShowCart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowCart)
{
    ui->setupUi(this);


}

void ShowCart::init(CartCtrl* ncartctrl,UserCtrl* nuserctrl, ItemCtrl* nitemctrl){
    //tableView******************************************************************
    //int width = this->width();
    //int height = this->height();
    //ui->tableView->resize(width,height);

    ui->tableView->setShowGrid(true);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    model = new QStandardItemModel();
    QStringList labels = QObject::tr("ID, name, label, price, num").simplified().split(",");
    model->setHorizontalHeaderLabels(labels);
    ui->tableView->setModel(model);

    cartctrl = ncartctrl;
    itemctrl = nitemctrl;
    userctrl = nuserctrl;

    ItemCtrl* titemctrl = cartctrl->cart;
    titemctrl->readItemFromFile(MAXSHOWITEM,cartctrl->getFileName());
    int j = 0;
    for(int i = 0; i < titemctrl->getItemTotalNum(); i++){
        if(titemctrl->getItemNum(i) == -1 || titemctrl->getItemNum(i) == 0) continue;
        model->setItem(j, 0, new QStandardItem(QString::fromStdString(titemctrl->getItemID(i))));
        model->setItem(j, 1, new QStandardItem(QString::fromStdString(titemctrl->getItemName(i))));
        model->setItem(j, 2, new QStandardItem(QString::fromStdString(titemctrl->getItemLabel(i))));
        model->setItem(j, 3, new QStandardItem(QString::number(titemctrl->getItemPrice(i))));
        model->setItem(j, 4, new QStandardItem(QString::number(titemctrl->getItemNum(i))));
        j++;
    }

    ui->tableView->show();
}

ShowCart::~ShowCart()
{
    delete ui;
}

void ShowCart::on_delBtn_clicked()
{
    string targetID = cartctrl->cart->getItemID(ui->tableView->currentIndex().row());
    cartctrl->cart->delItem(targetID);
    model->removeRows(ui->tableView->currentIndex().row(),1);
}

void ShowCart::on_buyBtn_clicked()
{
    QMessageBox message(QMessageBox::Warning,"Information",tr("Total cost: %1, sure to buy?").arg(cartctrl->cart->getTotalPrice())
                        ,QMessageBox::Yes|QMessageBox::No,NULL);
    if (message.exec()==QMessageBox::Yes)  {
        cartctrl->buyItem(itemctrl,userctrl->getName());
    }
}
