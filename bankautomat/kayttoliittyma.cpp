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

    setMouseTracking(true);

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
    this->setFixedSize(950,600);

    Rest_api_ddl *pRest_api = new Rest_api_ddl;
    connect(pRest_api, SIGNAL(responsedata(QByteArray)),
            this, SLOT(fnameLname(QByteArray)));
    QString url = "http://restapigroup5tvt21spo1.herokuapp.com/user/" + id;
    pRest_api->restapi("get",url,tokenv);

    QTimer *aika = new QTimer(this);
    connect(aika, SIGNAL(timeout()), this, SLOT(showTime()));
    aika->start();

    pTimer = new QTimer(this);
    connect(pTimer, SIGNAL(timeout()),
             this, SLOT(timerout()));
    pTimer->start(30000);

}

Kayttoliittyma::~Kayttoliittyma()
{
    delete ui;
    qDebug() << "Käyttöliittymä tuhottu";
}

void Kayttoliittyma::showTime()
{
        QTime time =QTime::currentTime();
        QDate date =QDate::currentDate();
        QString time_text=time.toString("hh : mm : ss");
        QString date_text=date.toString();
        ui->time->setText(date_text +"   "+ time_text);
}
void Kayttoliittyma::fnameLname(QByteArray data)
{

    QJsonDocument json_doc = QJsonDocument::fromJson(data);
        QJsonArray json_array = json_doc.array();

        foreach(const QJsonValue &pointer, json_array){
                QJsonObject json = pointer.toObject();
                fName=(json["fname"].toString());
                lName=(json["lname"].toString());
                QStringList list1 = fName.split(' ');
                    for (int i = 0; i < list1.size(); ++i)
                        list1[i].replace(0, 1, list1[i][0].toUpper());
                fName = list1.join(" ");

                QStringList list2 = lName.split(' ');
                    for (int i = 0; i < list2.size(); ++i)
                        list2[i].replace(0, 1, list2[i][0].toUpper());
                lName = list2.join(" ");
                }
        qDebug() << fName;
        qDebug() << lName;
        ui->label->setText("Hei "+fName+ " " +lName+ "!");

}


void Kayttoliittyma::on_kirjauduulos_clicked()
{

    this->~Kayttoliittyma();
}



void Kayttoliittyma::on_naytasaldo_clicked()
{
    qDebug() << "Näytä saldo painettu";

    this->hide();

    if (valinta==1){
        qDebug() << "SALDO DEBIT";
        saldo *pSaldo;
        pSaldo = new saldo(1,id,fName, lName,token);
        this->~Kayttoliittyma();
        pSaldo->exec();
    } else if (valinta==2){
        qDebug() << "SALDO CREDIT";
        saldo *pSaldo;
        pSaldo = new saldo(2,id, fName, lName,token);
        this->~Kayttoliittyma();
        pSaldo->exec();
    }



}



void Kayttoliittyma::on_nosto_clicked()
{
    nosto *pNosto = new nosto(valinta,id,token);
    this->hide();
    this->~Kayttoliittyma();
    pNosto->show();

}


void Kayttoliittyma::on_tilitap_clicked()
{
    Tilitapahtumat *pTilitapahtumat = new Tilitapahtumat(valinta,id,token);
    this->hide();
    this->~Kayttoliittyma();
    pTilitapahtumat->exec();
}



void Kayttoliittyma::on_sulje_clicked()
{
    this->hide();
    this->~Kayttoliittyma();
}



void Kayttoliittyma::on_vaihda_clicked()
{
    vaihdaPin *pvaihdaPin = new vaihdaPin(valinta,id,token);
    this->hide();
    pvaihdaPin->show();
    this->~Kayttoliittyma();

}

void Kayttoliittyma::timerout()
{
    QMessageBox *msg = new QMessageBox(this);
    msg->setText("Aikakatkaisu mitään nappia ei painettu. Palataan alkuun.");
    msg->setWindowTitle("Aikakatkaisu");
    msg->setIcon(QMessageBox::Critical);
    msg->setStandardButtons(QMessageBox::Yes);
    msg->show();
    QTimer *ppTimer = new QTimer(this);
    connect(ppTimer, SIGNAL(timeout()), msg, SLOT(close()));
    ppTimer->start(10000);
    if(msg->exec() == QMessageBox::Yes){
        this->~Kayttoliittyma();
    }

}

void Kayttoliittyma::mouseMoveEvent(QMouseEvent *e){
    pTimer->start(30000);
}
