#include "rest_api_ddl.h"


void Rest_api_ddl::login(QString rfid, QString pin)
{
    QJsonObject jsonObj;
    jsonObj.insert("card_number", rfid);
    jsonObj.insert("pin_code", pin);

    QString site_url="http://localhost:3000/login";
    QNetworkRequest request((site_url));


    postManager = new QNetworkAccessManager();
    connect(postManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));

    reply = postManager->post(request, QJsonDocument(jsonObj).toJson());

}

void Rest_api_ddl::loginSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug() << response_data;
}
