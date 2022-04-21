#ifndef NOSTO_H
#define NOSTO_H

#include <QDialog>
#include "rest_api_ddl.h"
#include "kayttoliittyma.h"
#include "mainwindow.h"
namespace Ui {
class nosto;
}

class nosto : public QDialog
{
    Q_OBJECT

public:
    explicit nosto(int creditOrDebit,QString idString, QByteArray tokenv, QWidget *parent = nullptr);
    ~nosto();
    void nostocredit(QString ammount);
    void nostodebit(QString ammount);
private slots:
    void on_b1_clicked();
    void responseData(QByteArray data);
    void on_b2_clicked();
    void on_b3_clicked();
    void on_b4_clicked();
    void on_Takaisin_clicked();
    void on_b6_clicked();
    void on_b5_clicked();
    void on_muu_clicked();
    void kysymyshandlerCredit(QString ammount);
    void kysymyshandlerDebit(QString ammount);
    void timerout();

private:

    Ui::nosto *ui;
    Rest_api_ddl *pRest_api;
    QByteArray token;
    int valinta;
    QString id;
    QString summa;
    QTimer *pTimer;
};

#endif // NOSTO_H
