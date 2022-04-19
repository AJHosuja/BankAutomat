#include "kayttoliittyma.h"
#include "ui_kayttoliittyma.h"
#include "mainwindow.h"
#include "saldo.h"

Kayttoliittyma::Kayttoliittyma(int creditOrDebit,QString idString, QByteArray tokenv, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Kayttoliittyma)
{
    ui->setupUi(this);

    QPixmap bkgnd(":/image/images/background.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);



    if (creditOrDebit==1){
        qDebug() << "debit";
        qDebug() << idString;
        qDebug() << tokenv;
    } else if (creditOrDebit==2){
        qDebug() << "credit";
        qDebug() << tokenv;
        qDebug() << idString;
    }


    valinta = creditOrDebit;
    id = idString;
    token = tokenv;


}

Kayttoliittyma::~Kayttoliittyma()
{
    delete ui;
}

void Kayttoliittyma::on_kirjauduulos_clicked()
{
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
    this->~Kayttoliittyma();
}



void Kayttoliittyma::on_naytasaldo_clicked()
{
    qDebug() << "Näytä saldo painettu";

    this->hide();

    if (valinta==1){
        qDebug() << "SALDO DEBIT";
        saldo *pSaldo;
        pSaldo = new saldo(1,id,token);
        pSaldo->exec();
    } else if (valinta==2){
        qDebug() << "SALDO CREDIT";
        saldo *pSaldo;
        pSaldo = new saldo(2,id,token);
        pSaldo->exec();
    }
    this->~Kayttoliittyma();




}



void Kayttoliittyma::on_nosto_clicked()
{
    nosto *pNosto = new nosto;
    this->hide();
    pNosto->exec();

}

