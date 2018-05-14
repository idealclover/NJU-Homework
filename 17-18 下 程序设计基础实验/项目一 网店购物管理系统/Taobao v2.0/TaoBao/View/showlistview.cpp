#include "showlistview.h"
#include "ui_showlistview.h"

ShowListView::ShowListView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowListView)
{
    ui->setupUi(this);

    FileCtrl* file = new FileCtrl(string(LISTFILENAME), string(LISTFILENAME));
    Bill* bill = file->getAllBills();

    ui->tableView->setShowGrid(true);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    model = new QStandardItemModel();
    QStringList labels = QObject::tr("ID, name, label, price, num, user").simplified().split(",");
    model->setHorizontalHeaderLabels(labels);
    ui->tableView->setModel(model);

    for (int i = 0; i < bill->getBillTotalNum(); i++) {
        if (bill != NULL) {
            for(int i = 0; i < bill->getBillTotalNum(); i++){
                model->setItem(i, 0, new QStandardItem(QString::fromStdString(bill->getItemID())));
                model->setItem(i, 1, new QStandardItem(QString::fromStdString(bill->getItemName())));
                model->setItem(i, 2, new QStandardItem(QString::fromStdString(bill->getItemLabel())));
                model->setItem(i, 3, new QStandardItem(QString::number(bill->getItemPrice())));
                model->setItem(i, 4, new QStandardItem(QString::number(bill->getItemNum())));
                model->setItem(i, 5, new QStandardItem(QString::fromStdString(bill->getBillUser())));
                bill = bill->getBillNext();
            }
        }
    }

    ui->tableView->show();
    delete(file);
}

ShowListView::~ShowListView()
{
    delete ui;
}
