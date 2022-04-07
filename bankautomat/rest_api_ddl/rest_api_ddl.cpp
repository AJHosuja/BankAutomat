#include "rest_api_ddl.h"


void Rest_api_ddl::login(QString rfid, QString pin)
{
    QJsonObject jsonObj;
    jsonObj.insert("card_number", rfid);
    jsonObj.insert("pin_code", pin);
    //site_url="http://restapigroup5tvt21spo1.herokuapp.com/login";
    site_url="http://localhost:3000/login";
    QNetworkRequest request((site_url));
    postManager = new QNetworkAccessManager();
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    connect(postManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));
    reply = postManager->post(request, QJsonDocument(jsonObj).toJson());

}

void Rest_api_ddl::nosto(QString type, QString id_account, QString amount, QString rfid, QByteArray token)
{
   if (type == "credit"){
        site_url="http://localhost:3000/nostocredit";
   } else if (type == "debit"){
        site_url="http://localhost:3000/nostodebit";
   }

   QJsonObject jsonObj;
   jsonObj.insert("id_account", id_account);
   jsonObj.insert("amount", amount);
   jsonObj.insert("cardnumber", rfid);

   QNetworkRequest request((site_url));
   postManager = new QNetworkAccessManager();
   request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
   ////////////////
   QByteArray myToken="Bearer " + token;
   request.setRawHeader(QByteArray("Authorization"),(myToken));
   ///////////////

   connect(postManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(nostoSlot(QNetworkReply*)));
   reply = postManager->post(request, QJsonDocument(jsonObj).toJson());

}

void Rest_api_ddl::loginSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    emit responsedata(response_data);
}

void Rest_api_ddl::nostoSlot(QNetworkReply *reply)
{

    response_data=reply->readAll();
    qDebug() << response_data;
    qDebug() << "onnistui";
    emit nostoResponse(response_data);
}
