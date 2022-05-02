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

        pRfid_Interface = new Rfid_Interface;
        connect(pRfid_Interface, SIGNAL(SendNumbertoEXE(QByteArray)),
                this, SLOT(comData(QByteArray)));

        setMouseTracking(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::comData(QByteArray data2)
{
    disconnect(pRfid_Interface, SIGNAL(SendNumbertoEXE(QByteArray)),
            this, SLOT(comData(QByteArray)));
    qDebug() << data2;
    data3 = data2;
    QString url = "http://restapigroup5tvt21spo1.herokuapp.com/login/" + data2;
    //qDebug() << url;
    pRest_api->restapiL(url);
}

void MainWindow::restApiData(QByteArray data)
{

    qDebug() << data;
    QTextCodec *codec = QTextCodec::codecForName("KOI8-R");
    tunnus = codec->toUnicode(data3);
    connect(pRfid_Interface, SIGNAL(SendNumbertoEXE(QByteArray)),
            this, SLOT(comData(QByteArray)));
    if (data=="true"){

    Pinni *pPinni = new Pinni(tunnus, this);
    pPinni->show();

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





