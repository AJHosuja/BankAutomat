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
    explicit Kayttoliittyma(QWidget *parent = nullptr);
    ~Kayttoliittyma();

private slots:
    void on_kirjauduulos_clicked();

private:
    Ui::Kayttoliittyma *ui;
};

#endif // KAYTTOLIITTYMA_H
