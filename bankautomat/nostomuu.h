#ifndef NOSTOMUU_H
#define NOSTOMUU_H

#include <QDialog>
#include "nosto.h"
namespace Ui {
class nostoMuu;
}

class nostoMuu : public QDialog
{
    Q_OBJECT

public:
    explicit nostoMuu(int creditOrDebit,QString idString, QByteArray tokenv,QWidget *parent = nullptr);
    ~nostoMuu();

private slots:
    void on_pushButton_3_clicked();

    void on_B1_clicked();

    void on_B2_clicked();

    void on_B3_clicked();

    void on_B4_clicked();

    void on_B5_clicked();

    void on_B6_clicked();

    void on_B7_clicked();

    void on_B8_clicked();

    void on_B9_clicked();

    void on_B0_clicked();

    void on_nosta_clicked();


    void on_takaisin_clicked();

    void on_tyhjenna_clicked();

    void on_pyyhi_clicked();

    void timerout();
protected:
    virtual void mouseMoveEvent(QMouseEvent *event) override;

signals:
    QString nostoSumma(QString);

private:
    Ui::nostoMuu *ui;
    QString b;
    QByteArray token;
    int valinta;
    QString id;
    QTimer *pTimer;
    nosto *pNosto;
};

#endif // NOSTOMUU_H
