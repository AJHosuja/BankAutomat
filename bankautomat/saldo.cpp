#include "saldo.h"
#include "ui_saldo.h"

saldo::saldo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::saldo)
{
    ui->setupUi(this);

    QPixmap bkgnd(":/image/images/background.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    //table = new QTableWidget(this);



}

saldo::~saldo()
{
    delete ui;
}

void saldo::tilitiedot()
{
//    for (int i = 0 ; i < table->rowCount(); i++)
//    {
//        QTableWidgetItem *item;
//        for (int j = 0; J < table->columnCount(); j++)
//        {
//            item = new QTableWidgetItem;

//            if (j == 0)
//                item->setText("name" + QString::number(i));
//            if (j == 1)
//                item->setText("Surname" + QString::number(i));
//            if (j == 2)
//                item->setText("Age" + QString::number(i));
//            if (j == 3)
//                item->setText("Address" + QString::number(i));

//            table->setItem(i, j, item);

//        }
//    }

}

void saldo::on_pushButton_loadTable_clicked()
{
    QJsonObject jsonObj;
    jsonObj.insert("id", '*');
    jsonObj.insert("account_number", '1');
    QString site_url="http://localhost:3000/transactions";
    QNetworkRequest request((site_url));
    postManager = new QNetworkAccessManager();
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    connect(postManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(transactionSlot(QNetworkReply*)));
    reply = postManager->get(request);

    qDebug() << "tiedot luettu";

    response_data=reply->readAll();
    qDebug() << response_data;



}

void saldo::transactionSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug() << response_data;
    QString DataAsString = QString(response_data);
    //ui->tableView_2->setModel(DataAsString)




}

