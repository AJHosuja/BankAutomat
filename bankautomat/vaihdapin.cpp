#include "vaihdapin.h"
#include "ui_vaihdapin.h"

vaihdaPin::vaihdaPin(int creditOrDebit,QString idString, QByteArray tokenv,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vaihdaPin)
{
    ui->setupUi(this);

    QPixmap bkgnd(":/image/images/background.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    valinta = creditOrDebit;
    id = idString;
    token = tokenv;
    this->setFixedSize(950,600);
}

vaihdaPin::~vaihdaPin()
{
    delete ui;
}

void vaihdaPin::on_takaisin_clicked()
{
    Kayttoliittyma *kayttoliittyma = new Kayttoliittyma(valinta,id, token);
    kayttoliittyma->show();
    this->~vaihdaPin();
}


void vaihdaPin::on_vaihda_clicked()
{
    QString oldpin = ui->vanha->text();
    QString newpin1 = ui->uusi->text();
    QString newpin2 = ui->uusi2->text();

    if (newpin1==newpin2){
    pRest_api = new Rest_api_ddl;
    connect(pRest_api, SIGNAL(responsedata(QByteArray)),
            this, SLOT(responseData(QByteArray)));
    QJsonObject jsonObj;
    jsonObj.insert("id", id);
    jsonObj.insert("old_pin", oldpin);
    jsonObj.insert("new_pin", newpin1);
    pRest_api->restapi("post","http://restapigroup5tvt21spo1.herokuapp.com/vaihdapin", jsonObj, token);
    } else {
        QMessageBox *msg = new QMessageBox(this);
        msg->setText("Uusi pin ei ole samanlainen");
        msg->setWindowTitle("Kirjoita molemmat pinnit samalla-lailla");
        msg->setIcon(QMessageBox::Critical);
        msg->show();
        QTimer *ppTimer = new QTimer(this);
        connect(ppTimer, SIGNAL(timeout()), msg, SLOT(close()));
        ppTimer->start(10000);
    }
}

void vaihdaPin::responseData(QByteArray data)
{
     qDebug() << data;

}

