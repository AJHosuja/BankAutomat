#include "pinni.h"
#include "ui_pinni.h"
#include <QDebug>
#include <QMessageBox>
#include "mainwindow.h"
#include "kayttoliittyma.h"
Pinni::Pinni(QString tunnus, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pinni)
{
    ui->setupUi(this);
    qDebug() << tunnus;
    QPixmap bkgnd(":/image/images/background.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    rfid = tunnus;

    pPinDll = new Pin_DLL(this);
    connect(pPinDll,SIGNAL(sendPinToExe(QString)),
            this, SLOT(recvPinToDll(QString)));

    connect(pPinDll,SIGNAL(sendSymbolToExe(QString)),
            this, SLOT(recvSymbolToDll(QString)));
    pTimer = new QTimer(this);

    setMouseTracking(true);
       connect(pTimer, SIGNAL(timeout()),
             this, SLOT(timerout()));

       pRest_api = new Rest_api_ddl;
       connect(pRest_api, SIGNAL(responsedata(QByteArray)),
               this, SLOT(loginData(QByteArray)));

       // msec
       pTimer->start(10000);
        this->setFixedSize(950,600);
       ui->lineEdit->setReadOnly(true);


       int size = 75;
       ui->B1->setFixedHeight(size);
       ui->B2->setFixedHeight(size);
       ui->B3->setFixedHeight(size);
       ui->B4->setFixedHeight(size);
       ui->B5->setFixedHeight(size);
       ui->B6->setFixedHeight(size);
       ui->B7->setFixedHeight(size);
       ui->B8->setFixedHeight(size);
       ui->B9->setFixedHeight(size);
       ui->B0->setFixedHeight(size);
       ui->Clear->setFixedHeight(size);
       ui->Backspace->setFixedHeight(size);

}


Pinni::~Pinni()
{
    delete ui;

    disconnect(pPinDll, SIGNAL(sendPinToExe(QString)),
               this, SLOT(recvPinToDll(QString)));

    disconnect(pPinDll,SIGNAL(sendSymbolToExe(QString)),
               this, SLOT(recvSymbolToDll(QString)));

    delete pPinDll;
    pPinDll = nullptr;
}

void Pinni::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << "mouse tracking pinni";
    pTimer->start(10000);
}

void Pinni::on_B0_clicked()
{
    pPinDll->recvB0clicked();
    pTimer->start(10000);
}

void Pinni::on_B1_clicked()
{
    pPinDll->recvB1clicked();
    pTimer->start(10000);
}


void Pinni::on_B2_clicked()
{
    pPinDll->recvB2clicked();
    pTimer->start(10000);
}


void Pinni::on_B3_clicked()
{
    pPinDll->recvB3clicked();
    pTimer->start(10000);
}


void Pinni::on_B4_clicked()
{
    pPinDll->recvB4clicked();
    pTimer->start(10000);
}


void Pinni::on_B5_clicked()
{
    pPinDll->recvB5clicked();
    pTimer->start(10000);
}


void Pinni::on_B6_clicked()
{
    pPinDll->recvB6clicked();
    pTimer->start(10000);
}


void Pinni::on_B7_clicked()
{
    pPinDll->recvB7clicked();
    pTimer->start(10000);
}


void Pinni::on_B8_clicked()
{
    pPinDll->recvB8clicked();
    pTimer->start(10000);
}


void Pinni::on_B9_clicked()
{
    pPinDll->recvB9clicked();
    pTimer->start(10000);
}




void Pinni::on_pushButton_clicked()
{
    b.chop(1);
    ui->lineEdit->setText(b);

}


void Pinni::on_pushButton_2_clicked()
{
    b.clear();
    ui->lineEdit->setText(b);
}

void Pinni::recvPinToDll(QString b)
{
    qDebug() << "Pin vastaanotettu dll:lästä";


    QJsonObject jsonObj;
    jsonObj.insert("card_number", rfid);
    jsonObj.insert("pin_code", b);
    pRest_api->restapiL("http://restapigroup5tvt21spo1.herokuapp.com/login", jsonObj);

}

void Pinni::recvSymbolToDll(QString b)
{
    qDebug() << "symbol vastaanotettu dll:lästä";
    ui->lineEdit->setText(b);

}

void Pinni::timerout()
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
        this->~Pinni();
    }

}

void Pinni::loginData(QByteArray data)
{
    qDebug() << data;
    if (data == "false"){
        QMessageBox *msg = new QMessageBox(this);
        msg->setText("Pin-koodisi oli virheellinen yritä uudelleen.");
        msg->setWindowTitle("Väärä pin-koodi");
        msg->setIcon(QMessageBox::Critical);
        msg->show();
    } else if (data == "locked"){
        QMessageBox *msg = new QMessageBox(this);
        msg->setText("Yritit liian monta kertaa väärin, tilisi on lukittu. "
                     "Ota yhteyttä pankkiin avataksesi tilin.");
        msg->setWindowTitle("Tilisi on lukittu");
        msg->setIcon(QMessageBox::Critical);
        msg->show();
    } else if (data == "tilisi on jo aiemmin lukittu"){
        QMessageBox *msg = new QMessageBox(this);
        msg->setText("Tilisi on jo aiemmin lukittu. "
                     "Ota yhteyttä pankkiin avataksesi tilin.");
        msg->setWindowTitle("Tilisi on jo aiemmin lukittu");
        msg->setIcon(QMessageBox::Critical);
        msg->show();
    }else {
    tokenv = data;
    QJsonObject jsonObj;
    disconnect(pRest_api, SIGNAL(responsedata(QByteArray)),
            this, SLOT(loginData(QByteArray)));
    connect(pRest_api, SIGNAL(responsedata(QByteArray)),
            this, SLOT(creditOrDebitData(QByteArray)));
    jsonObj.insert("rfid", rfid);
    pRest_api->restapiL("http://restapigroup5tvt21spo1.herokuapp.com/login/creditCheck", jsonObj);
    }
}

void Pinni::creditOrDebitData(QByteArray data_1)
{
    qDebug() << data_1;

    QJsonDocument json_doc = QJsonDocument::fromJson(data_1);
        QJsonArray json_array = json_doc.array();
        QString idString;
        foreach(const QJsonValue &pointer, json_array){
                QJsonObject json = pointer.toObject();
                data=(json["debit_credit"].toString());
                int id=(json["id_account"].toInt());
                idString = QString::number(id);

            }
        qDebug() << data;
        qDebug() << idString;
    if (data=="credit") {
        credit_Debit *pCredit_Debit;
        this->hide();
        pCredit_Debit = new credit_Debit(tokenv,idString);
        this->~Pinni();
        pCredit_Debit->exec();

    } else if (data=="debit") {
        Kayttoliittyma *pKayttoliittyma;
        this->hide();
        pKayttoliittyma = new Kayttoliittyma(1,idString, tokenv);
        this->~Pinni();
        pKayttoliittyma->exec();

    }
}

void Pinni::on_Clear_clicked()
{
    qDebug() << "Clear painettu";
    pPinDll->recvClearclicked();
    pTimer->start(10000);
}


void Pinni::on_Backspace_clicked()
{
    qDebug() << "Backspace painettu";
    pPinDll->recvBackspaceclicked();
    pTimer->start(10000);
}


