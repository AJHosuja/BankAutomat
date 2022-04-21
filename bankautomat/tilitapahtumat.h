#ifndef TILITAPAHTUMAT_H
#define TILITAPAHTUMAT_H

#include <QDialog>

namespace Ui {
class Tilitapahtumat;
}

class Tilitapahtumat : public QDialog
{
    Q_OBJECT

public:
    explicit Tilitapahtumat(int creditOrDebit,QString idString, QByteArray token, QWidget *parent = nullptr);
    ~Tilitapahtumat();

private slots:


    void on_suljetilita_clicked();

private:
    Ui::Tilitapahtumat *ui;
    QByteArray tokenv;
    QString id;
    int valinta;
};

#endif // TILITAPAHTUMAT_H
