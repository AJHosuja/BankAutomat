/********************************************************************************
** Form generated from reading UI file 'credit_debit.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDIT_DEBIT_H
#define UI_CREDIT_DEBIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_credit_Debit
{
public:
    QLabel *label;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *Credit;
    QPushButton *Debit;

    void setupUi(QDialog *credit_Debit)
    {
        if (credit_Debit->objectName().isEmpty())
            credit_Debit->setObjectName(QString::fromUtf8("credit_Debit"));
        credit_Debit->resize(950, 600);
        label = new QLabel(credit_Debit);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 160, 681, 101));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        horizontalLayoutWidget = new QWidget(credit_Debit);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(350, 290, 251, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Credit = new QPushButton(horizontalLayoutWidget);
        Credit->setObjectName(QString::fromUtf8("Credit"));

        horizontalLayout->addWidget(Credit);

        Debit = new QPushButton(horizontalLayoutWidget);
        Debit->setObjectName(QString::fromUtf8("Debit"));

        horizontalLayout->addWidget(Debit);


        retranslateUi(credit_Debit);

        QMetaObject::connectSlotsByName(credit_Debit);
    } // setupUi

    void retranslateUi(QDialog *credit_Debit)
    {
        credit_Debit->setWindowTitle(QCoreApplication::translate("credit_Debit", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("credit_Debit", "Kortillasi on k\303\244yt\303\266ss\303\244 Credit ja Debit ominaisuus. <br> Kumpaa haluat k\303\244ytt\303\244\303\244?", nullptr));
        Credit->setText(QCoreApplication::translate("credit_Debit", "Credit", nullptr));
        Debit->setText(QCoreApplication::translate("credit_Debit", "Debit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class credit_Debit: public Ui_credit_Debit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREDIT_DEBIT_H
