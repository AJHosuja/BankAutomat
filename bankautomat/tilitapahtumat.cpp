#include "tilitapahtumat.h"
#include "ui_tilitapahtumat.h"
#include "kayttoliittyma.h"

Tilitapahtumat::Tilitapahtumat(int creditOrDebit,QString idString, QByteArray token, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tilitapahtumat)
{
    ui->setupUi(this);

    QPixmap bkgnd(":/image/images/background.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    tokenv=token;
    valinta = creditOrDebit;
    id = idString;
}

Tilitapahtumat::~Tilitapahtumat()
{
    delete ui;
}




void Tilitapahtumat::on_suljetilita_clicked()
{
    Kayttoliittyma *kayttoliittyma = new Kayttoliittyma(valinta,id, tokenv);
    kayttoliittyma->show();
    this->~Tilitapahtumat();
}

