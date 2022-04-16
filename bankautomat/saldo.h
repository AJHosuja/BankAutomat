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

namespace Ui {
class saldo;
}

class saldo : public QDialog
{
    Q_OBJECT

public:
    explicit saldo(QWidget *parent = nullptr);
    ~saldo();
    void login(QString rfid, QString pin);
    void tilitiedot();

private slots:
    void on_pushButton_loadTable_clicked();
    void transactionSlot(QNetworkReply *reply);

private:
    Ui::saldo *ui;
    QTableWidget *table;
    QString i;
    QString J;
    QNetworkAccessManager *postManager;
    QNetworkReply *reply;
    QByteArray response_data;

};

#endif // SALDO_H
