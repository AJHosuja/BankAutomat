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

namespace Ui {
class saldo;
}

class saldo : public QDialog
{
    Q_OBJECT

public:
    explicit saldo(int creditOrDebit, QByteArray tokenv, QWidget *parent = nullptr);
    ~saldo();
    void login(QString rfid, QString pin);
    void tilitiedotDebit();
    void tilitiedotCredit();



private slots:
    void transactionSlot(QNetworkReply *reply);
    void on_kirjauduulos_sadlo_clicked();
    void timerout();

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

};

#endif // SALDO_H
