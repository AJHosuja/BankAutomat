#include "rest_api_ddl.h"


void Rest_api_ddl::restapi(QString type, QString url, QJsonObject jsonObj, QByteArray Tokenv)
{
    QJsonObject json = jsonObj;
    QString site_url=url;
    QNetworkRequest request((site_url));
    QByteArray myToken="Bearer " + Tokenv;
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    Manager = new QNetworkAccessManager();
    connect(Manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replySlot(QNetworkReply*)));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
     if (type == "post") {
        reply = Manager->post(request, QJsonDocument(jsonObj).toJson());
    } else if (type == "put") {
        reply = Manager->put(request, QJsonDocument(jsonObj).toJson());
    }


}

void Rest_api_ddl::restapi(QString type, QString url, QByteArray Tokenv)
{

    QString site_url=url;
    QNetworkRequest request((site_url));
    QByteArray myToken="Bearer " + Tokenv;
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    Manager = new QNetworkAccessManager();
    connect(Manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replySlot(QNetworkReply*)));
    if (type == "get"){
        reply = Manager->get(request);
    } else if (type == "delete") {
        reply = Manager->deleteResource(request);
    }
}

void Rest_api_ddl::restapiL(QString url, QJsonObject jsonObj)
{

    QString site_url=url;
    QNetworkRequest request((site_url));
    Manager = new QNetworkAccessManager();
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    connect(Manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replySlot(QNetworkReply*)));
    reply = Manager->post(request, QJsonDocument(jsonObj).toJson());



}

void Rest_api_ddl::restapiL(QString url)
{
    QString site_url=url;
    QNetworkRequest request((site_url));
    Manager = new QNetworkAccessManager();
    connect(Manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replySlot(QNetworkReply*)));
    reply = Manager->get(request);
}

void Rest_api_ddl::replySlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    //qDebug() << response_data;
    emit responsedata(response_data);
}

