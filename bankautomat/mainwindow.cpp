#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pinni.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: blue;");
    pPinni = new Pinni;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_avaapin_clicked()
{
    pPinni->exec();
}

