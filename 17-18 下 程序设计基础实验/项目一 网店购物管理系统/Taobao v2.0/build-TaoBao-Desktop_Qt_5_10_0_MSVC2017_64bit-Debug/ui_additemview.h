/********************************************************************************
** Form generated from reading UI file 'additemview.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDITEMVIEW_H
#define UI_ADDITEMVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddItemView
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *nameEdit;
    QLabel *label;
    QLineEdit *labelEdit;
    QLabel *label_3;
    QDoubleSpinBox *priceDoubleSpinBox;
    QLabel *label_4;
    QSpinBox *numSpinBox;

    void setupUi(QDialog *AddItemView)
    {
        if (AddItemView->objectName().isEmpty())
            AddItemView->setObjectName(QStringLiteral("AddItemView"));
        AddItemView->resize(400, 191);
        buttonBox = new QDialogButtonBox(AddItemView);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(20, 150, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        formLayoutWidget = new QWidget(AddItemView);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(30, 20, 331, 111));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        nameEdit = new QLineEdit(formLayoutWidget);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nameEdit);

        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        labelEdit = new QLineEdit(formLayoutWidget);
        labelEdit->setObjectName(QStringLiteral("labelEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, labelEdit);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        priceDoubleSpinBox = new QDoubleSpinBox(formLayoutWidget);
        priceDoubleSpinBox->setObjectName(QStringLiteral("priceDoubleSpinBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, priceDoubleSpinBox);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        numSpinBox = new QSpinBox(formLayoutWidget);
        numSpinBox->setObjectName(QStringLiteral("numSpinBox"));

        formLayout->setWidget(3, QFormLayout::FieldRole, numSpinBox);


        retranslateUi(AddItemView);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddItemView, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddItemView, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddItemView);
    } // setupUi

    void retranslateUi(QDialog *AddItemView)
    {
        AddItemView->setWindowTitle(QApplication::translate("AddItemView", "Dialog", nullptr));
        label_2->setText(QApplication::translate("AddItemView", "Name", nullptr));
        label->setText(QApplication::translate("AddItemView", "Label", nullptr));
        label_3->setText(QApplication::translate("AddItemView", "Price", nullptr));
        label_4->setText(QApplication::translate("AddItemView", "Number", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddItemView: public Ui_AddItemView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDITEMVIEW_H
