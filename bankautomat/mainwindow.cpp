#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pinni.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-image:url(E:/Banksimul projekti/group_5/group5/bankautomat/images/main_background.png)");
    pPinni = new Pinni;
    //qApp->setStyleSheet("background-image:url(E:/Banksimul projekti/group_5/group5/bankautomat/images/bank_card.png)");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_avaapin_clicked()
{
    pPinni->exec();
}

