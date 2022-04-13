#include "kayttoliittyma.h"
#include "ui_kayttoliittyma.h"
#include "mainwindow.h"

Kayttoliittyma::Kayttoliittyma(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Kayttoliittyma)
{
    ui->setupUi(this);

    QPixmap bkgnd(":/image/images/background.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

Kayttoliittyma::~Kayttoliittyma()
{
    delete ui;
}

void Kayttoliittyma::on_kirjauduulos_clicked()
{
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
    this->~Kayttoliittyma();
}

