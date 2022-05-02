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
    tila = 0;

    pTimer = new QTimer(this);
    connect(pTimer, SIGNAL(timeout()),
             this, SLOT(timerout()));
    pTimer->start(10000);

    setMouseTracking(true);

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


void vaihdaPin::vaihda()
{
    qDebug() << "taalla";
    qDebug() << old;
    qDebug() << new_1;
    qDebug() << new_2;
    if (new_1==new_2){
    pRest_api = new Rest_api_ddl;
    connect(pRest_api, SIGNAL(responsedata(QByteArray)),
            this, SLOT(responseData(QByteArray)));
    QJsonObject jsonObj;
    jsonObj.insert("id", id);
    jsonObj.insert("old_pin", old);
    jsonObj.insert("new_pin", new_1);
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
     if (data == "true") {
         QMessageBox *msg = new QMessageBox(this);
         msg->setText("Pin koodisi on vaihdettu");
         msg->setWindowTitle("Onnistui");
         msg->setIcon(QMessageBox::NoIcon);
         msg->setStandardButtons(QMessageBox::Yes);
         msg->show();
         QTimer *ppTimer = new QTimer(this);
         connect(ppTimer, SIGNAL(timeout()), msg, SLOT(close()));
         ppTimer->start(10000);
         if(msg->exec() == QMessageBox::Yes){
             Kayttoliittyma *kayttoliittyma = new Kayttoliittyma(valinta,id, token);
             kayttoliittyma->show();
             this->~vaihdaPin();
         }
     }

     if (data == "false") {
         QMessageBox *msg = new QMessageBox(this);
         msg->setText("Pin koodisi oli virheellinen. Kokeile laittamalla oikea PIN-koodi");
         msg->setWindowTitle("Virhe");
         msg->setIcon(QMessageBox::Critical);
         msg->show();
         QTimer *ppTimer = new QTimer(this);
         connect(ppTimer, SIGNAL(timeout()), msg, SLOT(close()));
         ppTimer->start(10000);
         tila = 0;
         ui->label->setText("Anna vanha PIN-koodisi");
     }

}

void vaihdaPin::clickhandler(QString click)
{
        pTimer->start(10000);
        clickString.append(click);
        ui->lineEdit->setText(clickString);
        qDebug() << clickString;
        if (clickString.length() == 4){
            ui->lineEdit->setText(" ");
            if (tila==0){
            old = clickString;
            clickString.clear();
            ui->label->setText("Anna uusi PIN koodi");
            tila++;
            } else if (tila==1){
            ui->label->setText("Toista uusi PIN koodi");
            new_1 = clickString;
            clickString.clear();
            tila++;
            } else if (tila==2){
            new_2 = clickString;
            clickString.clear();
            tila = 0;
            vaihda();
            }
        }
}





void vaihdaPin::on_Bu1_clicked()
{
    clickhandler("1");
}
void vaihdaPin::on_Bu2_clicked()
{
    clickhandler("2");
}
void vaihdaPin::on_Bu3_clicked()
{
    clickhandler("3");
}
void vaihdaPin::on_Bu4_clicked()
{
    clickhandler("4");
}
void vaihdaPin::on_Bu5_clicked()
{
    clickhandler("5");
}
void vaihdaPin::on_Bu6_clicked()
{
    clickhandler("6");
}
void vaihdaPin::on_Bu7_clicked()
{
    clickhandler("7");
}
void vaihdaPin::on_Bu8_clicked()
{
    clickhandler("8");
}
void vaihdaPin::on_Bu9_clicked()
{
    clickhandler("9");
}
void vaihdaPin::on_Bu0_clicked()
{
    clickhandler("0");
}
void vaihdaPin::timerout()
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
        this->~vaihdaPin();
    }
}



void vaihdaPin::on_peruuta_clicked()
{
    pTimer->start(10000);
    if (tila == 2){
        ui->label->setText("Anna uusi PIN koodi");
        tila--;
    } else if (tila == 1){
        ui->label->setText("Anna vanha PIN-koodisi");
        tila--;
    }
}


void vaihdaPin::on_pyyhi_clicked()
{
    clickString.chop(1);
    ui->lineEdit->setText(clickString);
}


void vaihdaPin::on_tyhjenna_clicked()
{
    clickString.clear();
    ui->lineEdit->setText(clickString);
}

void vaihdaPin::mouseMoveEvent(QMouseEvent *e){
    qDebug() << "mouse tracking vaihdaPin";
    pTimer->start(10000);
}
