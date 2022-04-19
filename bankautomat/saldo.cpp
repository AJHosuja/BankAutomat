#include "saldo.h"
#include "ui_saldo.h"
#include "kayttoliittyma.h"
#include "mainwindow.h"

saldo::saldo(int creditOrDebit,QString idString, QByteArray token, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::saldo)
{
    ui->setupUi(this);

    QPixmap bkgnd(":/image/images/background.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    pTimer = new QTimer(this);
    connect(pTimer, SIGNAL(timeout()),
          this, SLOT(timerout()));
    pTimer->start(10000);

    //table = new QTableWidget(this);

    tokenv=token;
    qDebug() << tokenv;
    valinta = creditOrDebit;
    id = idString;

    if (creditOrDebit==1){
        qDebug() << "debit";
        qDebug() << tokenv;
        //ui->lineEdit->setText("Debit");
    } else if (creditOrDebit==2){
        qDebug() << "credit";
        qDebug() << tokenv;
       // ui->lineEdit->setText("Credit");
    }

    pRest_api = new Rest_api_ddl;
    connect(pRest_api, SIGNAL(responsedata(QByteArray)),
            this, SLOT(transactionSlot(QByteArray)));

    QString url = "http://restapigroup5tvt21spo1.herokuapp.com/transactions/*/" + id;
    //qDebug() << url;
    pRest_api->restapi("get",url,tokenv);








}

saldo::~saldo()
{
    delete ui;
    disconnect(pRest_api, SIGNAL(responsedata(QByteArray)),
            this, SLOT(transactionSlot(QByteArray)));

    disconnect(pRest_api, SIGNAL(responsedata(QByteArray)),
            this, SLOT(tilitiedotDebit(QByteArray)));
}

void saldo::tilitiedotDebit(QByteArray data_debit)
{
    qDebug() << data_debit;
    QJsonDocument json_doc2 = QJsonDocument::fromJson(data_debit);
        QJsonArray json_array2 = json_doc2.array();
        QString creditLimit;
        QString debitBalance;
        QString creditBalance;
        foreach(const QJsonValue &pointer, json_array2){
                QJsonObject json = pointer.toObject();

                int creditLimitNumber=(json["credit_limit"].toInt());
                creditLimit = QString::number(creditLimitNumber);

                int debitBalanceNumber=(json["debit_balance"].toInt());
                debitBalance = QString::number(debitBalanceNumber);

                int creditBalanceNumber=(json["credit_balance"].toInt());
                creditBalance = QString::number(creditBalanceNumber);

                }
        qDebug() << creditLimit;
        qDebug() << debitBalance;
        qDebug() << creditBalance;
        ui->lineEdit->setText(debitBalance+" €");
        ui->lineEdit_credit->setText(creditLimit + " / " + creditBalance +" €");

}


void saldo::timerout()
{
    QMessageBox::information(this,"Aikakatkaisu", "Ei tapahtumia aikamääreeseen");
    Kayttoliittyma *kayttoliittyma = new Kayttoliittyma(valinta,id, tokenv);
    kayttoliittyma->show();
    this->~saldo();

}



void saldo::transactionSlot(QByteArray response_data)
{
       qDebug() << response_data;
       QStandardItemModel *model = new QStandardItemModel(this);


        qDebug() << response_data;
        QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
        QJsonArray json_array = json_doc.array();
        qDebug() << json_array;
        int arraySize = json_array.size();
        int x = 0;

        int idNumber[arraySize];
        QString idString[arraySize];
        QString id_receiver[arraySize];

        QString type[arraySize];
        QString transaction[arraySize];

        int ammountNumber[arraySize];
        QString ammount[arraySize];

        QString dateTime[arraySize];

        foreach(const QJsonValue &pointer, json_array){
                QJsonObject json = pointer.toObject();

                //id_transaction
                idNumber[x]=(json["id_transaction"].toInt());
                idString[x] = QString::number(idNumber[x]);

                //id_receiver
                id_receiver[x]=(json["id_receiver"].toString());

                //type
                type[x]=(json["type"].toString());

                //transaction
                transaction[x]=(json["transaction"].toString());

                //ammount
                ammountNumber[x]=(json["ammount"].toInt());
                ammount[x] = QString::number(ammountNumber[x]);

                //date_time
                dateTime[x]=(json["date_time"].toString());



                //qDebug() << user_number[x];
                x++;
            }
            model = new QStandardItemModel(arraySize,6,this);
            QModelIndex index;
             for (int i = 0; i<arraySize;i++){
                  index = model->index(i,0,QModelIndex());
                  model->setData(index, idString[i]);
                  index = model->index(i,1,QModelIndex());
                  model->setData(index, id_receiver[i]);
                  index = model->index(i,2,QModelIndex());
                  model->setData(index, type[i]);
                  index = model->index(i,3,QModelIndex());
                  model->setData(index, transaction[i]);
                  index = model->index(i,4,QModelIndex());
                  model->setData(index, ammount[i]);
                  index = model->index(i,5,QModelIndex());
                  model->setData(index, dateTime[i]);
            }
            model->setHorizontalHeaderItem(0, new QStandardItem(tr("id_transaction")));
            model->setHorizontalHeaderItem(1, new QStandardItem(tr("id_receiver")));
            model->setHorizontalHeaderItem(2, new QStandardItem(tr("type")));
            model->setHorizontalHeaderItem(3, new QStandardItem(tr("transaction")));
            model->setHorizontalHeaderItem(4, new QStandardItem(tr("amount")));
            model->setHorizontalHeaderItem(5, new QStandardItem(tr("date_time")));
            ui->tableView->setModel(model);
            ui->tableView->verticalHeader()->setVisible(false);

            disconnect(pRest_api, SIGNAL(responsedata(QByteArray)),
                    this, SLOT(transactionSlot(QByteArray)));

            connect(pRest_api, SIGNAL(responsedata(QByteArray)),
                    this, SLOT(tilitiedotDebit(QByteArray)));

            QString url_2 = "http://restapigroup5tvt21spo1.herokuapp.com/bankAccount/" + id;
            qDebug() << url_2;
            pRest_api->restapi("get",url_2,tokenv);
}





void saldo::on_kirjauduulos_sadlo_clicked()
{
    MainWindow *mainWindow = new MainWindow();
        mainWindow->show();
        this->~saldo();


}


void saldo::on_PalaaTakaisin_clicked()
{
    Kayttoliittyma *kayttoliittyma = new Kayttoliittyma(valinta,id, tokenv);
    kayttoliittyma->show();
    this->~saldo();

}



