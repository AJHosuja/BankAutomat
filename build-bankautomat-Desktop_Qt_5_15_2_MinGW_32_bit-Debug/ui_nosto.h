/********************************************************************************
** Form generated from reading UI file 'nosto.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOSTO_H
#define UI_NOSTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_nosto
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QPushButton *b3;
    QPushButton *b4;
    QPushButton *b1;
    QPushButton *b2;
    QPushButton *muu;
    QPushButton *Takaisin;
    QLabel *label;

    void setupUi(QDialog *nosto)
    {
        if (nosto->objectName().isEmpty())
            nosto->setObjectName(QString::fromUtf8("nosto"));
        nosto->resize(950, 600);
        verticalLayoutWidget = new QWidget(nosto);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(260, 190, 431, 281));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        b3 = new QPushButton(verticalLayoutWidget);
        b3->setObjectName(QString::fromUtf8("b3"));
        QFont font;
        font.setPointSize(22);
        b3->setFont(font);

        gridLayout->addWidget(b3, 1, 0, 1, 1);

        b4 = new QPushButton(verticalLayoutWidget);
        b4->setObjectName(QString::fromUtf8("b4"));
        b4->setFont(font);

        gridLayout->addWidget(b4, 1, 1, 1, 1);

        b1 = new QPushButton(verticalLayoutWidget);
        b1->setObjectName(QString::fromUtf8("b1"));
        b1->setFont(font);

        gridLayout->addWidget(b1, 0, 0, 1, 1);

        b2 = new QPushButton(verticalLayoutWidget);
        b2->setObjectName(QString::fromUtf8("b2"));
        b2->setFont(font);

        gridLayout->addWidget(b2, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        muu = new QPushButton(verticalLayoutWidget);
        muu->setObjectName(QString::fromUtf8("muu"));
        muu->setFont(font);

        verticalLayout->addWidget(muu);

        Takaisin = new QPushButton(nosto);
        Takaisin->setObjectName(QString::fromUtf8("Takaisin"));
        Takaisin->setGeometry(QRect(40, 560, 80, 21));
        label = new QLabel(nosto);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(260, 100, 451, 71));
        QFont font1;
        font1.setPointSize(20);
        label->setFont(font1);

        retranslateUi(nosto);

        QMetaObject::connectSlotsByName(nosto);
    } // setupUi

    void retranslateUi(QDialog *nosto)
    {
        nosto->setWindowTitle(QCoreApplication::translate("nosto", "Dialog", nullptr));
        b3->setText(QCoreApplication::translate("nosto", "50\342\202\254", nullptr));
        b4->setText(QCoreApplication::translate("nosto", "100\342\202\254", nullptr));
        b1->setText(QCoreApplication::translate("nosto", "20\342\202\254", nullptr));
        b2->setText(QCoreApplication::translate("nosto", "40\342\202\254", nullptr));
        muu->setText(QCoreApplication::translate("nosto", "Muu summa", nullptr));
        Takaisin->setText(QCoreApplication::translate("nosto", "Takaisin", nullptr));
        label->setText(QCoreApplication::translate("nosto", "Valitse summa mink\303\244 haluat nostaa,<br> tai valitse muu summa.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class nosto: public Ui_nosto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOSTO_H
