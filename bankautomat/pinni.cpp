#include "pinni.h"
#include "ui_pinni.h"
#include <QDebug>
#include <QMessageBox>
#include "mainwindow.h"
Pinni::Pinni(QString tunnus, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pinni)
{
    ui->setupUi(this);
    qDebug() << tunnus;
    //this->setStyleSheet("background-image:url(E:/Banksimul projekti/group_5/group5/bankautomat/images/background.png)");
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


       connect(pTimer, SIGNAL(timeout()),
             this, SLOT(timerout()));

       // msec
       pTimer->start(10000);



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



void Pinni::login(QString rfid, QString pin)
{
    QJsonObject jsonObj;
    jsonObj.insert("card_number", rfid);
    jsonObj.insert("pin_code", pin);
    QString site_url="http://restapigroup5tvt21spo1.herokuapp.com/login";
    QNetworkRequest request((site_url));
    postManager = new QNetworkAccessManager();
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    connect(postManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));
    reply = postManager->post(request, QJsonDocument(jsonObj).toJson());
}

void Pinni::loginSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug() << response_data;

    if(response_data == "false"){
        b.clear();
        ui->lineEdit->setText(b);
        QMessageBox::information(this,"Virhe", "Väärä pinkoodi, yritä uudelleen");
        b.clear();
    }


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
    login(rfid, b);
}

void Pinni::recvSymbolToDll(QString b)
{
    qDebug() << "symbol vastaanotettu dll:lästä";
    ui->lineEdit->setText(b);

}

void Pinni::timerout()
{
    QMessageBox::information(this,"Aikakatkaisu", "Ei tapahtumia aikamääreeseen");
    MainWindow *mainWindow = new MainWindow();
        mainWindow->show();
    qDebug() << "Avataan mainWindow";
    this->~Pinni();


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

