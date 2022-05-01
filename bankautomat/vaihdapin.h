#ifndef VAIHDAPIN_H
#define VAIHDAPIN_H

#include <QDialog>
#include "kayttoliittyma.h"
#include "rest_api_ddl.h"

namespace Ui {
class vaihdaPin;
}

class vaihdaPin : public QDialog
{
    Q_OBJECT

public:
    explicit vaihdaPin(int creditOrDebit,QString idString, QByteArray tokenv,QWidget *parent = nullptr);
    ~vaihdaPin();

private slots:
    void on_takaisin_clicked();

    void vaihda();
    void responseData(QByteArray data);
    void clickhandler(QString click);
    void on_Bu1_clicked();
    void on_Bu2_clicked();
    void on_Bu3_clicked();
    void on_Bu4_clicked();
    void on_Bu5_clicked();
    void on_Bu6_clicked();
    void on_Bu7_clicked();
    void on_Bu8_clicked();
    void on_Bu9_clicked();
    void on_Bu0_clicked();
    void timerout();
    void on_peruuta_clicked();

    void on_pyyhi_clicked();

    void on_tyhjenna_clicked();

private:
    Ui::vaihdaPin *ui;
    QByteArray token;
    int valinta;
    QString id;
    Rest_api_ddl *pRest_api;
    QString old;
    QString new_1;
    QString new_2;
    QString clickString;
    int tila;
    QTimer *pTimer;
};

#endif // VAIHDAPIN_H
