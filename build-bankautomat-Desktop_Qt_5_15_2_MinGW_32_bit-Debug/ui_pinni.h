/********************************************************************************
** Form generated from reading UI file 'pinni.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PINNI_H
#define UI_PINNI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Pinni
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *B5;
    QPushButton *B3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *B9;
    QPushButton *B6;
    QPushButton *B8;
    QPushButton *B1;
    QPushButton *B4;
    QPushButton *B0;
    QPushButton *B7;
    QPushButton *B2;
    QPushButton *Clear;
    QPushButton *Backspace;
    QLineEdit *lineEdit;

    void setupUi(QDialog *Pinni)
    {
        if (Pinni->objectName().isEmpty())
            Pinni->setObjectName(QString::fromUtf8("Pinni"));
        Pinni->resize(950, 600);
        gridLayoutWidget = new QWidget(Pinni);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(230, 170, 491, 341));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        B5 = new QPushButton(gridLayoutWidget);
        B5->setObjectName(QString::fromUtf8("B5"));

        gridLayout->addWidget(B5, 2, 1, 1, 1);

        B3 = new QPushButton(gridLayoutWidget);
        B3->setObjectName(QString::fromUtf8("B3"));

        gridLayout->addWidget(B3, 1, 2, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 4, 2, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 4, 0, 1, 1);

        B9 = new QPushButton(gridLayoutWidget);
        B9->setObjectName(QString::fromUtf8("B9"));

        gridLayout->addWidget(B9, 3, 2, 1, 1);

        B6 = new QPushButton(gridLayoutWidget);
        B6->setObjectName(QString::fromUtf8("B6"));

        gridLayout->addWidget(B6, 2, 2, 1, 1);

        B8 = new QPushButton(gridLayoutWidget);
        B8->setObjectName(QString::fromUtf8("B8"));

        gridLayout->addWidget(B8, 3, 1, 1, 1);

        B1 = new QPushButton(gridLayoutWidget);
        B1->setObjectName(QString::fromUtf8("B1"));

        gridLayout->addWidget(B1, 1, 0, 1, 1);

        B4 = new QPushButton(gridLayoutWidget);
        B4->setObjectName(QString::fromUtf8("B4"));

        gridLayout->addWidget(B4, 2, 0, 1, 1);

        B0 = new QPushButton(gridLayoutWidget);
        B0->setObjectName(QString::fromUtf8("B0"));

        gridLayout->addWidget(B0, 4, 1, 1, 1);

        B7 = new QPushButton(gridLayoutWidget);
        B7->setObjectName(QString::fromUtf8("B7"));

        gridLayout->addWidget(B7, 3, 0, 1, 1);

        B2 = new QPushButton(gridLayoutWidget);
        B2->setObjectName(QString::fromUtf8("B2"));

        gridLayout->addWidget(B2, 1, 1, 1, 1);

        Clear = new QPushButton(gridLayoutWidget);
        Clear->setObjectName(QString::fromUtf8("Clear"));

        gridLayout->addWidget(Clear, 4, 0, 1, 1);

        Backspace = new QPushButton(gridLayoutWidget);
        Backspace->setObjectName(QString::fromUtf8("Backspace"));

        gridLayout->addWidget(Backspace, 4, 2, 1, 1);

        lineEdit = new QLineEdit(Pinni);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(230, 120, 491, 51));
        QFont font;
        font.setPointSize(28);
        lineEdit->setFont(font);
        lineEdit->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        lineEdit->setAlignment(Qt::AlignCenter);

        retranslateUi(Pinni);

        QMetaObject::connectSlotsByName(Pinni);
    } // setupUi

    void retranslateUi(QDialog *Pinni)
    {
        Pinni->setWindowTitle(QCoreApplication::translate("Pinni", "Dialog", nullptr));
        B5->setText(QCoreApplication::translate("Pinni", "5", nullptr));
        B3->setText(QCoreApplication::translate("Pinni", "3", nullptr));
        pushButton->setText(QCoreApplication::translate("Pinni", "Backspace", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Pinni", "Clear", nullptr));
        B9->setText(QCoreApplication::translate("Pinni", "9", nullptr));
        B6->setText(QCoreApplication::translate("Pinni", "6", nullptr));
        B8->setText(QCoreApplication::translate("Pinni", "8", nullptr));
        B1->setText(QCoreApplication::translate("Pinni", "1", nullptr));
        B4->setText(QCoreApplication::translate("Pinni", "4", nullptr));
        B0->setText(QCoreApplication::translate("Pinni", "0", nullptr));
        B7->setText(QCoreApplication::translate("Pinni", "7", nullptr));
        B2->setText(QCoreApplication::translate("Pinni", "2", nullptr));
        Clear->setText(QCoreApplication::translate("Pinni", "Clear", nullptr));
        Backspace->setText(QCoreApplication::translate("Pinni", "Backspace", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Pinni: public Ui_Pinni {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PINNI_H
