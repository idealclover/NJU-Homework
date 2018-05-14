#include "addtocartview.h"
#include "ui_addtocartview.h"
#include "showlistview.h"

AddToCartView::AddToCartView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddToCartView)
{
    ui->setupUi(this);


}

AddToCartView::~AddToCartView()
{
    delete ui;
}

void AddToCartView::on_buttonBox_accepted()
{
    emit addToCartNum(ui->addNumSpinBox->value());
}
