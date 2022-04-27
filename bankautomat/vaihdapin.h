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

    void on_vaihda_clicked();
    void responseData(QByteArray data);
private:
    Ui::vaihdaPin *ui;
    QByteArray token;
    int valinta;
    QString id;
    Rest_api_ddl *pRest_api;
};

#endif // VAIHDAPIN_H
