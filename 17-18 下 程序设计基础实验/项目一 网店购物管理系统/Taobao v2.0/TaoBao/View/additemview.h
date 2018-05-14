#ifndef ADDITEMVIEW_H
#define ADDITEMVIEW_H

#include <QDialog>

namespace Ui {
class AddItemView;
}

class AddItemView : public QDialog
{
    Q_OBJECT

public:
    explicit AddItemView(QWidget *parent = 0);
    ~AddItemView();
    std::string name;
    std::string label;
    float price;
    int num;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddItemView *ui;

};

#endif // ADDITEMVIEW_H
