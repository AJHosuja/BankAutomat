#ifndef TILITAPAHTUMAT_H
#define TILITAPAHTUMAT_H

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
#include "kayttoliittyma.h"
#include "rest_api_ddl.h"

namespace Ui {
class Tilitapahtumat;
}

class Tilitapahtumat : public QDialog
{
    Q_OBJECT

public:
    explicit Tilitapahtumat(int creditOrDebit,QString idString, QByteArray token, QWidget *parent = nullptr);
    ~Tilitapahtumat();

private slots:


    void on_suljetilita_clicked();
    void transactionSlot(QByteArray);
    void transactionSlot2(QByteArray);

    void timerout();
    void tilitiedotDebit(QByteArray);



    void on_edelliset10_clicked();

    void on_seuraavat10_clicked();
protected:
    virtual void mouseMoveEvent(QMouseEvent *event) override;

private:
    Ui::Tilitapahtumat *ui;
    QByteArray tokenv;
    QString id;
    int valinta;
    int arraykoko;
    int seuraavat;
    int maara=0;
    QByteArray data2;
    QByteArray response_data2;



    QTableWidget *table;
    QString i;
    QString J;
    QNetworkAccessManager *postManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QTimer *pTimer;
    QStandardItemModel *model;
    Rest_api_ddl *pRest_api;

};

#endif // TILITAPAHTUMAT_H
