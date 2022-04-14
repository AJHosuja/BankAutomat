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

#include "pin_dll.h"


namespace Ui {
class Pinni;
}

class Pinni : public QDialog
{
    Q_OBJECT

public:
    explicit Pinni(QString tunnus, QWidget *parent = nullptr);
    ~Pinni();
    void login(QString rfid, QString pin);
private:
    void clickHandler(QString i);
    Pin_DLL * pPinDll;


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
    void loginSlot(QNetworkReply *reply);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void recvPinToDll(QString);
    void recvSymbolToDll(QString);
    void timerout();


    void on_Clear_clicked();

    void on_Backspace_clicked();

private:
    Ui::Pinni *ui;
    QString rfid;
    QString b;
    QString i;
    QNetworkAccessManager *postManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QTimer *pTimer;

};

#endif // PINNI_H
