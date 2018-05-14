#include "additemview.h"
#include "ui_additemview.h"

AddItemView::AddItemView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddItemView)
{
    ui->setupUi(this);
}

AddItemView::~AddItemView()
{
    delete ui;
}



void AddItemView::on_buttonBox_accepted()
{
    name= ui->nameEdit->text().toStdString();
    label= ui->labelEdit->text().toStdString();
    price = ui->priceDoubleSpinBox->value();
    num = ui->numSpinBox->value();
}
