#ifndef CREDIT_DEBIT_H
#define CREDIT_DEBIT_H

#include <QDialog>
#include "kayttoliittyma.h"

namespace Ui {
class credit_Debit;
}

class credit_Debit : public QDialog
{
    Q_OBJECT

public:
    explicit credit_Debit(QByteArray token,QString idString,QWidget *parent = nullptr);
    ~credit_Debit();

private slots:
    void on_Credit_clicked();

    void on_Debit_clicked();
    void timerout();

protected:
    virtual void mouseMoveEvent(QMouseEvent *event) override;


private:
    Ui::credit_Debit *ui;
    QByteArray tokenv;
    QString id;
    QTimer *pTimer;

};

#endif // CREDIT_DEBIT_H
