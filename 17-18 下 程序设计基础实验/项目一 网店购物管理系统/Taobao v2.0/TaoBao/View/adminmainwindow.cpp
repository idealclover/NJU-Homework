#include "adminmainwindow.h"
#include "ui_adminmainwindow.h"

AdminMainWindow::AdminMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminMainWindow)
{
    ui->setupUi(this);


    //tableView******************************************************************

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
        if(itemctrl->getItemNum(i) == -1) continue;
        model->setItem(j, 0, new QStandardItem(QString::fromStdString(itemctrl->getItemID(i))));
        model->setItem(j, 1, new QStandardItem(QString::fromStdString(itemctrl->getItemName(i))));
        model->setItem(j, 2, new QStandardItem(QString::fromStdString(itemctrl->getItemLabel(i))));
        model->setItem(j, 3, new QStandardItem(QString::number(itemctrl->getItemPrice(i))));
        model->setItem(j, 4, new QStandardItem(QString::number(itemctrl->getItemNum(i))));
        j++;
    }

    ui->tableView->show();
}

AdminMainWindow::~AdminMainWindow()
{
    delete ui;
}

void AdminMainWindow::on_showListBtn_clicked()
{
    ShowListView listview;
    listview.show();
    listview.exec();
}

void AdminMainWindow::on_delBtn_clicked()
{
    string targetID = itemctrl->getItemID(ui->tableView->currentIndex().row());
    itemctrl->delItem(targetID);
    model->removeRows(ui->tableView->currentIndex().row(),1);
}

void AdminMainWindow::on_addBtn_clicked()
{
    AddItemView additemview;
    additemview.show();
    if(additemview.exec()== QDialog::Accepted){
        itemctrl->addNewItem(additemview.name, additemview.label, additemview.price, additemview.num);
        refresh();
    }
}

void AdminMainWindow::refresh(){
    delete(itemctrl);
    model->removeRows(0, model->rowCount());
    itemctrl = new ItemCtrl();
    itemctrl->readItemFromFile(MAXSHOWITEM,string(ITEMFILENAME));
    int j = 0;
    for(int i = 0; i < itemctrl->getItemTotalNum(); i++){
        if(itemctrl->getItemNum(i) == -1) continue;
        model->setItem(j, 0, new QStandardItem(QString::fromStdString(itemctrl->getItemID(i))));
        model->setItem(j, 1, new QStandardItem(QString::fromStdString(itemctrl->getItemName(i))));
        model->setItem(j, 2, new QStandardItem(QString::fromStdString(itemctrl->getItemLabel(i))));
        model->setItem(j, 3, new QStandardItem(QString::number(itemctrl->getItemPrice(i))));
        model->setItem(j, 4, new QStandardItem(QString::number(itemctrl->getItemNum(i))));
        j++;
    }
}
