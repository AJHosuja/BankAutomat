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
    void login(QString rfid, QString pin);
    void nosto(QString cORd, QString id_account, QString amount, QString rfid, QByteArray token);
signals:
    QByteArray responsedata(QByteArray);
    QByteArray nostoResponse(QByteArray);

public slots:
    void loginSlot(QNetworkReply *reply);
    void nostoSlot(QNetworkReply *reply);
private:
    QNetworkAccessManager *postManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QString site_url;
};

#endif // REST_API_DDL_H
