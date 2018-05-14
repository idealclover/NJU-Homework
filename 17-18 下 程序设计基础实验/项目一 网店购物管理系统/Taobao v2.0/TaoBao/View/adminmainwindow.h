#ifndef ADMINMAINWINDOW_H
#define ADMINMAINWINDOW_H

#include <QMainWindow>
#include <QStandardItem>
#include "../Controller/itemctrl.h"
#include "../Controller/cartctrl.h"
#include "../Controller/userctrl.h"
#include "showlistview.h"
#include "additemview.h"

namespace Ui {
class AdminMainWindow;
}

class AdminMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminMainWindow(QWidget *parent = 0);
    ~AdminMainWindow();

private slots:
    void on_showListBtn_clicked();
    void on_delBtn_clicked();
    void on_addBtn_clicked();

private:
    Ui::AdminMainWindow *ui;
    QStandardItemModel* model;
    void refresh();
    UserCtrl* userctrl;
    ItemCtrl* itemctrl;
    CartCtrl* cartctrl;
};

#endif // ADMINMAINWINDOW_H
