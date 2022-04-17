/********************************************************************************
** Form generated from reading UI file 'saldo.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SALDO_H
#define UI_SALDO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_saldo
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_omistaja;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QTableView *tableView;
    QPushButton *kirjauduulos_sadlo;
    QPushButton *PalaaTakaisin;
    QLabel *label;
    QLabel *label_2;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEdit_credit;

    void setupUi(QDialog *saldo)
    {
        if (saldo->objectName().isEmpty())
            saldo->setObjectName(QString::fromUtf8("saldo"));
        saldo->resize(950, 600);
        verticalLayoutWidget = new QWidget(saldo);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 381, 61));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_omistaja = new QLabel(verticalLayoutWidget);
        label_omistaja->setObjectName(QString::fromUtf8("label_omistaja"));

        verticalLayout->addWidget(label_omistaja);

        verticalLayoutWidget_2 = new QWidget(saldo);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 100, 181, 31));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(verticalLayoutWidget_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout_2->addWidget(lineEdit);

        verticalLayoutWidget_4 = new QWidget(saldo);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(10, 140, 921, 381));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(verticalLayoutWidget_4);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout_4->addWidget(tableView);

        kirjauduulos_sadlo = new QPushButton(saldo);
        kirjauduulos_sadlo->setObjectName(QString::fromUtf8("kirjauduulos_sadlo"));
        kirjauduulos_sadlo->setGeometry(QRect(380, 560, 121, 21));
        PalaaTakaisin = new QPushButton(saldo);
        PalaaTakaisin->setObjectName(QString::fromUtf8("PalaaTakaisin"));
        PalaaTakaisin->setGeometry(QRect(380, 530, 121, 21));
        label = new QLabel(saldo);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 80, 191, 16));
        label_2 = new QLabel(saldo);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(240, 80, 191, 16));
        verticalLayoutWidget_3 = new QWidget(saldo);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(240, 100, 160, 24));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        lineEdit_credit = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_credit->setObjectName(QString::fromUtf8("lineEdit_credit"));

        verticalLayout_3->addWidget(lineEdit_credit);


        retranslateUi(saldo);

        QMetaObject::connectSlotsByName(saldo);
    } // setupUi

    void retranslateUi(QDialog *saldo)
    {
        saldo->setWindowTitle(QCoreApplication::translate("saldo", "Dialog", nullptr));
        label_omistaja->setText(QCoreApplication::translate("saldo", "\"Tilin omistaja\"", nullptr));
        kirjauduulos_sadlo->setText(QCoreApplication::translate("saldo", "Kirjaudu ulos", nullptr));
        PalaaTakaisin->setText(QCoreApplication::translate("saldo", "Palaa takaisin", nullptr));
        label->setText(QCoreApplication::translate("saldo", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">TILIN SALDO / DEBIT:</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("saldo", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">TILIN SALDO / CREDIT:</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class saldo: public Ui_saldo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SALDO_H
