/********************************************************************************
** Form generated from reading UI file 'addtocartview.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDTOCARTVIEW_H
#define UI_ADDTOCARTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddToCartView
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *addNumSpinBox;

    void setupUi(QDialog *AddToCartView)
    {
        if (AddToCartView->objectName().isEmpty())
            AddToCartView->setObjectName(QStringLiteral("AddToCartView"));
        AddToCartView->resize(400, 160);
        buttonBox = new QDialogButtonBox(AddToCartView);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 120, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        horizontalLayoutWidget = new QWidget(AddToCartView);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(60, 30, 271, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        addNumSpinBox = new QSpinBox(horizontalLayoutWidget);
        addNumSpinBox->setObjectName(QStringLiteral("addNumSpinBox"));

        horizontalLayout->addWidget(addNumSpinBox);


        retranslateUi(AddToCartView);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddToCartView, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddToCartView, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddToCartView);
    } // setupUi

    void retranslateUi(QDialog *AddToCartView)
    {
        AddToCartView->setWindowTitle(QApplication::translate("AddToCartView", "Dialog", nullptr));
        label->setText(QApplication::translate("AddToCartView", "\350\257\267\351\200\211\346\213\251\346\267\273\345\212\240\347\232\204\346\225\260\351\207\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddToCartView: public Ui_AddToCartView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTOCARTVIEW_H
