#ifndef KAYTTOLIITTYMA_H
#define KAYTTOLIITTYMA_H

#include <QDialog>

namespace Ui {
class Kayttoliittyma;
}

class Kayttoliittyma : public QDialog
{
    Q_OBJECT

public:
    explicit Kayttoliittyma(int creditOrDebit, QByteArray tokenv,QWidget *parent = nullptr);
    ~Kayttoliittyma();

private slots:
    void on_kirjauduulos_clicked();
    void on_naytasaldo_clicked();

private:
    Ui::Kayttoliittyma *ui;
    QByteArray tokenv;
    int valinta;


};

#endif // KAYTTOLIITTYMA_H
