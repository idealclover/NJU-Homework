#ifndef ADDTOCARTVIEW_H
#define ADDTOCARTVIEW_H

#include <QDialog>

namespace Ui {
class AddToCartView;
}

class AddToCartView : public QDialog
{
    Q_OBJECT

public:
    explicit AddToCartView(QWidget *parent = 0);
    ~AddToCartView();
signals:
    void addToCartNum(int num);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddToCartView *ui;
};

#endif // ADDTOCARTVIEW_H
