#include "pinni.h"
#include "ui_pinni.h"
#include <QDebug>
#include <QMessageBox>
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
}


Pinni::~Pinni()
{
    delete ui;
}

void Pinni::clickHandler(QString i)
{
    b.append(i);
    ui->lineEdit->setText(b);
    if (b.length() == 4){
        login(rfid, b);
    }
}

void Pinni::on_B1_clicked()
{
    clickHandler("1");

}


void Pinni::on_B2_clicked()
{
    clickHandler("2");
}


void Pinni::on_B3_clicked()
{
    clickHandler("3");
}


void Pinni::on_B4_clicked()
{
    clickHandler("4");
}


void Pinni::on_B5_clicked()
{
    clickHandler("5");
}


void Pinni::on_B6_clicked()
{
    clickHandler("6");
}


void Pinni::on_B7_clicked()
{
    clickHandler("7");
}


void Pinni::on_B8_clicked()
{
    clickHandler("8");
}


void Pinni::on_B9_clicked()
{
    clickHandler("9");
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

