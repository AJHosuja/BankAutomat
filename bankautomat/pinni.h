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

private slots:
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

private:
    Ui::Pinni *ui;
    QString rfid;
    QString b;
    QNetworkAccessManager *postManager;
    QNetworkReply *reply;
    QByteArray response_data;
};

#endif // PINNI_H
