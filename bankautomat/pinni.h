#ifndef PINNI_H
#define PINNI_H

#include <QDialog>

namespace Ui {
class Pinni;
}

class Pinni : public QDialog
{
    Q_OBJECT

public:
    explicit Pinni(QWidget *parent = nullptr);
    ~Pinni();

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

private:
    Ui::Pinni *ui;
};

#endif // PINNI_H
