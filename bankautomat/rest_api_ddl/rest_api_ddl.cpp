#include "rest_api_ddl.h"


void Rest_api_ddl::login(QString rfid, QString pin)
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

QString Rest_api_ddl::login_responseData(QString rfid, QString pin)
{
    login(rfid, pin);

    return response_data;
}

void Rest_api_ddl::loginSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug() << response_data;
    emit responsedata(response_data);
}
