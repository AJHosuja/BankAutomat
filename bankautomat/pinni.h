#ifndef PINNI_H
#define PINNI_H

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
#include "kayttoliittyma.h"
#include "pin_dll.h"
#include "rest_api_ddl.h"
#include "credit_debit.h"


namespace Ui {
class Pinni;
}

class Pinni : public QDialog
{
    Q_OBJECT

public:
    explicit Pinni(QString tunnus, QWidget *parent = nullptr);
    ~Pinni();
private:
    void clickHandler(QString i);
    Pin_DLL * pPinDll;
protected:
    virtual void mouseMoveEvent(QMouseEvent *event) override;

private slots:
    void on_B0_clicked();
    void on_B1_clicked();
    void on_B2_clicked();
    void on_B3_clicked();
    void on_B4_clicked();
    void on_B5_clicked();
    void on_B6_clicked();
    void on_B7_clicked();
    void on_B8_clicked();
    void on_B9_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void recvPinToDll(QString);
    void recvSymbolToDll(QString);
    void timerout();
    void loginData(QByteArray data);
    void creditOrDebitData(QByteArray data);


    void on_Clear_clicked();

    void on_Backspace_clicked();


private:
    Ui::Pinni *ui;
    QString rfid;
    QString b;
    QString i;
    QNetworkAccessManager *postManager;
    QNetworkReply *reply;
    QByteArray tokenv;
    QTimer *pTimer;
    Rest_api_ddl *pRest_api;
    QString data;

};

#endif // PINNI_H
