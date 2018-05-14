#include "usermainwindow.h"
#include "ui_usermainwindow.h"
#include "addtocartview.h"
#include "showcart.h"

#include <QMessageBox>

UserMainWindow::UserMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserMainWindow)
{
    ui->setupUi(this);


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

    itemctrl = new ItemCtrl();
    itemctrl->readItemFromFile(MAXSHOWITEM,string(ITEMFILENAME));
    int j = 0;
    for(int i = 0; i < itemctrl->getItemTotalNum(); i++){
        if(itemctrl->getItemNum(i) == -1 || itemctrl->getItemNum(i) == 0) continue;
        model->setItem(j, 0, new QStandardItem(QString::fromStdString(itemctrl->getItemID(i))));
        model->setItem(j, 1, new QStandardItem(QString::fromStdString(itemctrl->getItemName(i))));
        model->setItem(j, 2, new QStandardItem(QString::fromStdString(itemctrl->getItemLabel(i))));
        model->setItem(j, 3, new QStandardItem(QString::number(itemctrl->getItemPrice(i))));
        model->setItem(j, 4, new QStandardItem(QString::number(itemctrl->getItemNum(i))));
        j++;
    }

    ui->tableView->show();
}

void UserMainWindow::passUserCtrl(UserCtrl *nuserctrl){
    userctrl = nuserctrl;
    cartctrl = new CartCtrl((userctrl->getName())+string(".txt"));
}

UserMainWindow::~UserMainWindow()
{
    delete ui;
}

void UserMainWindow::addItemToCart(int num){

    QMessageBox::warning(this, tr("Waring"),
                         tr("add succeed!%1").arg(num),
                         QMessageBox::Yes);
    int targetNum = ui->tableView->currentIndex().row();
    cartctrl->cart->addNewItem(itemctrl->getItemID(targetNum),itemctrl->getItemName(targetNum), itemctrl->getItemLabel(targetNum), itemctrl->getItemPrice(targetNum), num);
}

void UserMainWindow::on_AddToCartBtn_clicked()
{
    AddToCartView addtocartview;
    connect(&addtocartview,SIGNAL(addToCartNum(int)),this,SLOT(addItemToCart(int)));
    addtocartview.show();
    if(addtocartview.exec() == QDialog::Accepted){
    }
}

void UserMainWindow::refresh(){
    itemctrl->readItemFromFile(MAXSHOWITEM,string(ITEMFILENAME));
    int j = 0;
    for(int i = 0; i < itemctrl->getItemTotalNum(); i++){
        if(itemctrl->getItemNum(i) == -1 || itemctrl->getItemNum(i) == 0) continue;
        model->setItem(j, 0, new QStandardItem(QString::fromStdString(itemctrl->getItemID(i))));
        model->setItem(j, 1, new QStandardItem(QString::fromStdString(itemctrl->getItemName(i))));
        model->setItem(j, 2, new QStandardItem(QString::fromStdString(itemctrl->getItemLabel(i))));
        model->setItem(j, 3, new QStandardItem(QString::number(itemctrl->getItemPrice(i))));
        model->setItem(j, 4, new QStandardItem(QString::number(itemctrl->getItemNum(i))));
        j++;
    }
}

void UserMainWindow::on_seeCartBtn_clicked()
{
    ShowCart showcart;
    showcart.init(cartctrl,userctrl,itemctrl);
    showcart.show();
    if(showcart.exec() == QDialog::Accepted){
        refresh();
    }
}

void UserMainWindow::on_logOutBtn_clicked()
{

}
