#include "kayttoliittyma.h"
#include "ui_kayttoliittyma.h"
#include "mainwindow.h"

Kayttoliittyma::Kayttoliittyma(int creditOrDebit, QByteArray tokenv, QWidget *parent) :
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
        qDebug() << tokenv;
    } else if (creditOrDebit==2){
        qDebug() << "credit";
        qDebug() << tokenv;
    }


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


