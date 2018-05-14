#ifndef SHOWLISTVIEW_H
#define SHOWLISTVIEW_H

#include <QDialog>
#include <QStandardItem>
#include "../Controller/filectrl.h"
#include "../Controller/itemctrl.h"
#include "../const.h"

namespace Ui {
class ShowListView;
}

class ShowListView : public QDialog
{
    Q_OBJECT

public:
    explicit ShowListView(QWidget *parent = 0);
    ~ShowListView();

private:
    Ui::ShowListView *ui;
    QStandardItemModel* model;
};

#endif // SHOWLISTVIEW_H
