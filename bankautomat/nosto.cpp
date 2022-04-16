#include "nosto.h"
#include "ui_nosto.h"

nosto::nosto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nosto)
{
    ui->setupUi(this);

    QPixmap bkgnd(":/image/images/background.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    const QSize size = QSize(200, 100);
    ui->b1->setFixedSize(size);
    ui->b2->setFixedSize(size);
    ui->b3->setFixedSize(size);
    ui->b4->setFixedSize(size);
    //const QSize size_1 = QSize(400, 30);
    //ui->muu->setFixedSize(size_1);

}

nosto::~nosto()
{
    delete ui;
}
