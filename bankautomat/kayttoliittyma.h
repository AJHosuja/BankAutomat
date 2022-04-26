#ifndef KAYTTOLIITTYMA_H
#define KAYTTOLIITTYMA_H

#include <QDialog>
#include "nosto.h"
#include "vaihdapin.h"

namespace Ui {
class Kayttoliittyma;
}

class Kayttoliittyma : public QDialog
{
    Q_OBJECT

public:
    explicit Kayttoliittyma(int creditOrDebit,QString idString, QByteArray tokenv,QWidget *parent = nullptr);
    ~Kayttoliittyma();

private slots:
    void on_kirjauduulos_clicked();
    void on_naytasaldo_clicked();

    void on_nosto_clicked();

    void on_tilitap_clicked();
    void fnameLname(QByteArray data);
    void on_sulje_clicked();
    void showTime();
    void on_vaihda_clicked();

private:
    Ui::Kayttoliittyma *ui;
    QByteArray token;
    int valinta;
    QString id;

};

#endif // KAYTTOLIITTYMA_H
