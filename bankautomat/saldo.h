#ifndef SALDO_H
#define SALDO_H

#include <QDialog>
#include <QObject>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QTimer>
#include <QWidget>
#include <QTableWidget>
#include <QStandardItemModel>

#include "rest_api_ddl.h"

namespace Ui {
class saldo;
}

class saldo : public QDialog
{
    Q_OBJECT

public:
    explicit saldo(int creditOrDebit,QString idString, QString fName, QString lName, QByteArray tokenv, QWidget *parent = nullptr);
    ~saldo();
    void login(QString rfid, QString pin);



protected:
    virtual void mouseMoveEvent(QMouseEvent *event) override;

private slots:
    void transactionSlot(QByteArray);
    void on_kirjauduulos_sadlo_clicked();
    void timerout();
    void tilitiedotDebit(QByteArray);
    void on_PalaaTakaisin_clicked();

private:
    Ui::saldo *ui;
    QTableWidget *table;
    QString i;
    QString J;
    QNetworkAccessManager *postManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QByteArray tokenv;
    QTimer *pTimer;
    int valinta;
    QStandardItemModel *model;
    Rest_api_ddl *pRest_api;
    QString id;

};

#endif // SALDO_H
