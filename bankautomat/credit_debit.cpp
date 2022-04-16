#include "credit_debit.h"
#include "ui_credit_debit.h"
#include <QDebug>


credit_Debit::credit_Debit(QByteArray token, QWidget *parent):
    QDialog(parent),
    ui(new Ui::credit_Debit)
{

    ui->setupUi(this);
    QPixmap bkgnd(":/image/images/background.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    qDebug() << "pääsi tänne";
    tokenv=token;

}

credit_Debit::~credit_Debit()
{
    delete ui;
}

void credit_Debit::on_Credit_clicked()
{
    Kayttoliittyma *pKayttoliittyma;
    this->hide();
    pKayttoliittyma = new Kayttoliittyma(2, tokenv);
    this->~credit_Debit();
    pKayttoliittyma->exec();

}


void credit_Debit::on_Debit_clicked()
{
    Kayttoliittyma *pKayttoliittyma;
    this->hide();
    pKayttoliittyma = new Kayttoliittyma(1, tokenv);
    this->~credit_Debit();
    pKayttoliittyma->exec();

}

