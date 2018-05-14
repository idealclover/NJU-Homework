/********************************************************************************
** Form generated from reading UI file 'showlistview.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWLISTVIEW_H
#define UI_SHOWLISTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_ShowListView
{
public:
    QDialogButtonBox *buttonBox;
    QTableView *tableView;

    void setupUi(QDialog *ShowListView)
    {
        if (ShowListView->objectName().isEmpty())
            ShowListView->setObjectName(QStringLiteral("ShowListView"));
        ShowListView->resize(933, 300);
        buttonBox = new QDialogButtonBox(ShowListView);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(830, 20, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        tableView = new QTableView(ShowListView);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(0, 0, 801, 301));

        retranslateUi(ShowListView);
        QObject::connect(buttonBox, SIGNAL(accepted()), ShowListView, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ShowListView, SLOT(reject()));

        QMetaObject::connectSlotsByName(ShowListView);
    } // setupUi

    void retranslateUi(QDialog *ShowListView)
    {
        ShowListView->setWindowTitle(QApplication::translate("ShowListView", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowListView: public Ui_ShowListView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWLISTVIEW_H
