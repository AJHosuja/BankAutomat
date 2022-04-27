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

    QPixmap bkgnd(":/image/images/main.png");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);
        this->setFixedSize(950,600);

        pRest_api = new Rest_api_ddl;
        connect(pRest_api, SIGNAL(responsedata(QByteArray)),
                this, SLOT(restApiData(QByteArray)));


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_avaapin_clicked()
{

    tunnus = ui->tunnus->text();
    QString url = "http://restapigroup5tvt21spo1.herokuapp.com/login/" + tunnus;
    //qDebug() << url;
    pRest_api->restapiL(url);





}

void MainWindow::restApiData(QByteArray data)
{

    qDebug() << data;

    if (data=="true"){
    this->hide();
    Pinni *pPinni = new Pinni(tunnus, this);
    pPinni->exec();
    } else if (data=="false"){
        QMessageBox *msg = new QMessageBox(this);
        msg->setText("Kyseisellä kortilla ei ole tiliä!");
        msg->setWindowTitle("VIRHE!");
        msg->setIcon(QMessageBox::Critical);
        msg->show();
        QTimer *ppTimer = new QTimer(this);
        connect(ppTimer, SIGNAL(timeout()), msg, SLOT(close()));
        ppTimer->start(10000);
    }

}




