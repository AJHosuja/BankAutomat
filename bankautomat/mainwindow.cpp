#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pinni.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->setStyleSheet("background-image:url(E:/Banksimul projekti/group_5/group5/bankautomat/images/main_background.png)");

    QPixmap bkgnd(":/image/images/main_background.png");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);
        this->setFixedSize(950,600);




}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_avaapin_clicked()
{

    QString tunnus = ui->tunnus->text();

    this->hide();
    Pinni *pPinni = new Pinni(tunnus, this);
    pPinni->exec();



}




