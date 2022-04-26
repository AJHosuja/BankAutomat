////////////////////////////////////////////////////////////////////////////////////////////////////////
/// how to run login
/// Rest_api_ddl *restapi;
/// restapi = new Rest_api_ddl;
/// connect(restapi, SIGNAL(responsedata(QByteArray)), this, SLOT(loginSlot(QByteArray)));
/// restapi->login(rfid, b);
///
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/// how to run login
/// connect(restapi, SIGNAL(nostoResponse(QByteArray)), this, SLOT(X(QByteArray)));
/// restapi->nosto("debit", "1", "100000", "testausta", response_data);



#ifndef REST_API_DDL_H
#define REST_API_DDL_H

#include "rest_api_ddl_global.h"
#include <QObject>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QString>
#include <QDebug>

class REST_API_DDL_EXPORT Rest_api_ddl: public QObject
{
    Q_OBJECT
public:
    void restapi(QString type, QString url, QJsonObject jsonObj, QByteArray Tokenv);
    void restapi(QString type, QString url, QByteArray Tokenv);
    void restapiL(QString url, QJsonObject jsonObj);
    void restapiL(QString url);
signals:
    QByteArray responsedata(QByteArray);

public slots:
    void replySlot(QNetworkReply *reply);

private:
    QNetworkAccessManager *Manager;
    QNetworkReply *reply;
    QByteArray response_data;
    QString site_url;
};

#endif // REST_API_DDL_H
