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

public slots:
    void loginSlot(QNetworkReply *reply);

private:
    QNetworkAccessManager *postManager;
    QNetworkReply *reply;
    QByteArray response_data;
};

#endif // REST_API_DDL_H
