#include "nosto.h"
#include "ui_nosto.h"
#include "nostomuu.h"
nosto::nosto(int creditOrDebit,QString idString, QByteArray tokenv,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nosto)
{
    ui->setupUi(this);

    QPixmap bkgnd(":/image/images/background.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    const QSize size = QSize(200, 75);
    ui->b1->setFixedSize(size);
    ui->b2->setFixedSize(size);
    ui->b3->setFixedSize(size);
    ui->b4->setFixedSize(size);
    ui->b5->setFixedSize(size);
    ui->b6->setFixedSize(size);

    setMouseTracking(true);

    pRest_api = new Rest_api_ddl;
    connect(pRest_api, SIGNAL(responsedata(QByteArray)),
            this, SLOT(responseData(QByteArray)));

    valinta = creditOrDebit;
    id = idString;
    token = tokenv;
    this->setFixedSize(950,600);

    pTimer = new QTimer(this);
    connect(pTimer, SIGNAL(timeout()),
             this, SLOT(timerout()));
    pTimer->start(10000);
    qDebug() << "luotiin nosto";

}


nosto::~nosto()
{
    delete ui;
}

void nosto::on_b1_clicked()
{
    pTimer->start(10000);
    if (valinta == 1) {
        kysymyshandlerDebit("20");
    } else if (valinta == 2) {
        kysymyshandlerCredit("20");
    }


}




void nosto::on_b2_clicked()
{
    pTimer->start(10000);
    if (valinta == 1) {
        kysymyshandlerDebit("40");
    } else if (valinta == 2) {
        kysymyshandlerCredit("40");
    }
}

void nosto::on_b3_clicked()
{
    pTimer->start(10000);
    if (valinta == 1) {
        kysymyshandlerDebit("60");
    }else if (valinta == 2) {
        kysymyshandlerCredit("60");
    }
}

void nosto::on_b4_clicked()
{
    pTimer->start(10000);
    if (valinta == 1) {
        kysymyshandlerDebit("100");
    }else if (valinta == 2) {
        kysymyshandlerCredit("100");
    }
}

void nosto::on_b6_clicked()
{
    pTimer->start(10000);
    if (valinta == 1) {
        kysymyshandlerDebit("500");
    }else if (valinta == 2) {
        kysymyshandlerCredit("500");
    }

}


void nosto::on_b5_clicked()
{
    pTimer->start(10000);
    if (valinta == 1) {
        kysymyshandlerDebit("200");
    }else if (valinta == 2) {
        kysymyshandlerCredit("200");
    }

}

void nosto::on_Takaisin_clicked()
{
    Kayttoliittyma *kayttoliittyma = new Kayttoliittyma(valinta,id, token);
    kayttoliittyma->show();
    this->~nosto();
}

void nosto::responseData(QByteArray data)
{
    qDebug() << data ;
    disconnect(pRest_api, SIGNAL(responsedata(QByteArray)),
            this, SLOT(responseData(QByteArray)));
    if (data == "ei katetta") {
        QMessageBox *msg = new QMessageBox(this);
        msg->setText("Nosto ei onnistunut, tilillä ei ole katetta");
        msg->setWindowTitle("Ei katetta");
        msg->setIcon(QMessageBox::Critical);
        msg->show();
        QTimer *ppTimer = new QTimer(this);
        connect(ppTimer, SIGNAL(timeout()), msg, SLOT(close()));
        ppTimer->start(10000);
    } else if (data == "true"){
                QMessageBox *msg = new QMessageBox(this);
                msg->setText("Nosto onnistui tililtäsi on veloitettu " + summa + "€");
                msg->setWindowTitle("Onnistui");
                msg->show();
                QTimer *ppTimer = new QTimer(this);
                connect(ppTimer, SIGNAL(timeout()), msg, SLOT(close()));
                ppTimer->start(10000);

    }

}

void nosto::nostocredit(QString ammount)
{
    summa = ammount;
    qDebug()  << "pääsi tänne" + ammount;
    connect(pRest_api, SIGNAL(responsedata(QByteArray)),
            this, SLOT(responseData(QByteArray)));
    QJsonObject jsonObj;
    jsonObj.insert("id_account", id);
    jsonObj.insert("amount", ammount);
    jsonObj.insert("cardnumber", "testi_muutetaan");
    pRest_api->restapi("post","http://restapigroup5tvt21spo1.herokuapp.com/nostoCredit", jsonObj, token);

}

void nosto::nostodebit(QString ammount)
{
    summa = ammount;
        connect(pRest_api, SIGNAL(responsedata(QByteArray)),
                this, SLOT(responseData(QByteArray)));
        QJsonObject jsonObj;
        jsonObj.insert("id_account", id);
        jsonObj.insert("amount", ammount);
        jsonObj.insert("cardnumber", "testi_muutetaan");
        pRest_api->restapi("post","http://restapigroup5tvt21spo1.herokuapp.com/nostodebit", jsonObj, token);


}




void nosto::on_muu_clicked()
{
        nostoMuu *pMuuNosto = new nostoMuu(valinta,id,token);
        this->~nosto();
        pMuuNosto->show();
}

void nosto::kysymyshandlerCredit(QString ammount)
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Haluatko varmasti jatkaa.", "Haluatko varmasti nostaa " + ammount + "€ Credit tililtäsi?"
                          ,QMessageBox::Yes | QMessageBox::No );
    if (reply == QMessageBox::Yes){
        nostocredit(ammount);
    }
}

void nosto::kysymyshandlerDebit(QString ammount)
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Haluatko varmasti jatkaa.", "Haluatko varmasti nostaa " + ammount + "€ debit tililtäsi?"
                          ,QMessageBox::Yes | QMessageBox::No );
    if (reply == QMessageBox::Yes){
        nostodebit(ammount);
    }
}

void nosto::timerout()
{

    QMessageBox *msg = new QMessageBox(this);
    msg->setText("Aikakatkaisu. Mitään nappia ei painettu. Palataan käyttöliittymään.");
    msg->setWindowTitle("Aikakatkaisu");
    msg->setIcon(QMessageBox::Critical);
    msg->setStandardButtons(QMessageBox::Yes);
    msg->show();
    QTimer *ppTimer = new QTimer(this);
    connect(ppTimer, SIGNAL(timeout()), msg, SLOT(close()));
    ppTimer->start(10000);
    if(msg->exec() == QMessageBox::Yes){
        Kayttoliittyma *kayttoliittyma = new Kayttoliittyma(valinta,id, token);
        kayttoliittyma->show();
        this->~nosto();
    }


}

void nosto::mouseMoveEvent(QMouseEvent *e){
    qDebug() << "mouse tracking nosto";
    pTimer->start(10000);
}

