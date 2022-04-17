/********************************************************************************
** Form generated from reading UI file 'kayttoliittyma.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KAYTTOLIITTYMA_H
#define UI_KAYTTOLIITTYMA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Kayttoliittyma
{
public:
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QPushButton *nosto;
    QVBoxLayout *verticalLayout_3;
    QPushButton *naytasaldo;
    QVBoxLayout *verticalLayout_4;
    QPushButton *tilitap;
    QVBoxLayout *verticalLayout_5;
    QPushButton *kirjauduulos;

    void setupUi(QDialog *Kayttoliittyma)
    {
        if (Kayttoliittyma->objectName().isEmpty())
            Kayttoliittyma->setObjectName(QString::fromUtf8("Kayttoliittyma"));
        Kayttoliittyma->resize(950, 600);
        verticalLayout_6 = new QVBoxLayout(Kayttoliittyma);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(Kayttoliittyma);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);


        verticalLayout_6->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        nosto = new QPushButton(Kayttoliittyma);
        nosto->setObjectName(QString::fromUtf8("nosto"));

        verticalLayout_2->addWidget(nosto);


        verticalLayout_6->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        naytasaldo = new QPushButton(Kayttoliittyma);
        naytasaldo->setObjectName(QString::fromUtf8("naytasaldo"));

        verticalLayout_3->addWidget(naytasaldo);


        verticalLayout_6->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        tilitap = new QPushButton(Kayttoliittyma);
        tilitap->setObjectName(QString::fromUtf8("tilitap"));

        verticalLayout_4->addWidget(tilitap);


        verticalLayout_6->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        kirjauduulos = new QPushButton(Kayttoliittyma);
        kirjauduulos->setObjectName(QString::fromUtf8("kirjauduulos"));

        verticalLayout_5->addWidget(kirjauduulos);


        verticalLayout_6->addLayout(verticalLayout_5);


        retranslateUi(Kayttoliittyma);

        QMetaObject::connectSlotsByName(Kayttoliittyma);
    } // setupUi

    void retranslateUi(QDialog *Kayttoliittyma)
    {
        Kayttoliittyma->setWindowTitle(QCoreApplication::translate("Kayttoliittyma", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Kayttoliittyma", "\"Tilin omistaja\"", nullptr));
        nosto->setText(QCoreApplication::translate("Kayttoliittyma", "Nosto", nullptr));
        naytasaldo->setText(QCoreApplication::translate("Kayttoliittyma", "N\303\244yt\303\244 saldo", nullptr));
        tilitap->setText(QCoreApplication::translate("Kayttoliittyma", "Tilitapahtumat", nullptr));
        kirjauduulos->setText(QCoreApplication::translate("Kayttoliittyma", "Kirjaudu ulos", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Kayttoliittyma: public Ui_Kayttoliittyma {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KAYTTOLIITTYMA_H
