#include "nostomuu.h"
#include "ui_nostomuu.h"
#include "nosto.h"
nostoMuu::nostoMuu(int creditOrDebit,QString idString, QByteArray tokenv,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nostoMuu)
{
    ui->setupUi(this);
    valinta = creditOrDebit;
    id = idString;
    token = tokenv;
    QPixmap bkgnd(":/image/images/background.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    ui->lineEdit->setReadOnly(true);

}

nostoMuu::~nostoMuu()
{
    delete ui;
}

void nostoMuu::on_pushButton_3_clicked()
{
    this->~nostoMuu();
    nosto *pNosto = new nosto(valinta, id, token);
    pNosto->show();
}

void nostoMuu::on_B1_clicked()
{
    b.append("1");
    ui->lineEdit->setText(b + " €");
}


void nostoMuu::on_B2_clicked()
{
    b.append("2");
    ui->lineEdit->setText(b+ " €");
}


void nostoMuu::on_B3_clicked()
{
    b.append("3");
    ui->lineEdit->setText(b+ " €");
}


void nostoMuu::on_B4_clicked()
{
    b.append("4");
    ui->lineEdit->setText(b+ " €");
}


void nostoMuu::on_B5_clicked()
{
    b.append("5");
    ui->lineEdit->setText(b+ " €");
}


void nostoMuu::on_B6_clicked()
{
    b.append("6");
    ui->lineEdit->setText(b+ " €");
}


void nostoMuu::on_B7_clicked()
{
    b.append("7");
    ui->lineEdit->setText(b+ " €");
}


void nostoMuu::on_B8_clicked()
{
    b.append("8");
    ui->lineEdit->setText(b+ " €");
}


void nostoMuu::on_B9_clicked()
{
    b.append("9");
    ui->lineEdit->setText(b+ " €");
}


void nostoMuu::on_B0_clicked()
{
    b.append("0");
    ui->lineEdit->setText(b+ " €");
}



void nostoMuu::on_nosta_clicked()
{
    int i = b.toInt();
    QString summa = b;
    if (i % 5 == 0){

        if (valinta==1) {
            QMessageBox::StandardButton reply = QMessageBox::question(this, "Haluatko varmasti jatkaa.", "Haluatko varmasti nostaa " + summa + "€ debit tililtäsi?"
                                  ,QMessageBox::Yes | QMessageBox::No );
            if (reply == QMessageBox::Yes){
                this->~nostoMuu();
                nosto *pNosto = new nosto(valinta, id, token);
                pNosto->show();
                pNosto->nostodebit(summa);
            }
        } else if (valinta==2){
            QMessageBox::StandardButton reply = QMessageBox::question(this, "Haluatko varmasti jatkaa.", "Haluatko varmasti nostaa " + summa + "€ Credit tililtäsi?"
                                  ,QMessageBox::Yes | QMessageBox::No );
            if (reply == QMessageBox::Yes){
                this->~nostoMuu();
                nosto *pNosto = new nosto(valinta, id, token);
                pNosto->show();
                pNosto->nostocredit(summa);
            }
        }
        qDebug() << summa;


    } else {
        QMessageBox *msg = new QMessageBox(this);
        msg->setText("Et voi nostaa summaa " + b + "€, koska sitä ei saa rikottua seteleiksi");
        msg->setWindowTitle("Virhe");
        msg->setIcon(QMessageBox::Critical);
        msg->show();
        QTimer *ppTimer = new QTimer(this);
        connect(ppTimer, SIGNAL(timeout()), msg, SLOT(close()));
        ppTimer->start(10000);
    }


}


void nostoMuu::on_takaisin_clicked()
{
    this->~nostoMuu();
    nosto *pNosto = new nosto(valinta, id, token);
    pNosto->show();
}


void nostoMuu::on_tyhjenna_clicked()
{
    b.clear();
    ui->lineEdit->setText(b);
}


void nostoMuu::on_pyyhi_clicked()
{
    b.chop(1);
    ui->lineEdit->setText(b+ " €");
}

