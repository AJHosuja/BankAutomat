#include "credit_debit.h"
#include "ui_credit_debit.h"
#include <QDebug>


credit_Debit::credit_Debit(QByteArray token, QString idString, QWidget *parent):
    QDialog(parent),
    ui(new Ui::credit_Debit)
{

    ui->setupUi(this);
    QPixmap bkgnd(":/image/images/background.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    qDebug() << "pääsi tänne";
    tokenv=token;
    id=idString;
    this->setFixedSize(950,600);

    setMouseTracking(true);

    pTimer = new QTimer(this);
    connect(pTimer, SIGNAL(timeout()),
             this, SLOT(timerout()));
    pTimer->start(10000);

}

credit_Debit::~credit_Debit()
{
    delete ui;
}

void credit_Debit::on_Credit_clicked()
{
    Kayttoliittyma *pKayttoliittyma;
    this->hide();
    pKayttoliittyma = new Kayttoliittyma(2,id, tokenv);
    this->~credit_Debit();
    pKayttoliittyma->exec();

}


void credit_Debit::on_Debit_clicked()
{
    Kayttoliittyma *pKayttoliittyma;
    this->hide();
    pKayttoliittyma = new Kayttoliittyma(1, id,tokenv);
    this->~credit_Debit();
    pKayttoliittyma->exec();

}

void credit_Debit::timerout()
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
        this->~credit_Debit();
    }
}

void credit_Debit::mouseMoveEvent(QMouseEvent *e){
    qDebug() << "mouse tracking credit";
    pTimer->start(10000);
}
