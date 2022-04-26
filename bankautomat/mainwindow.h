#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "pinni.h"
#include "kayttoliittyma.h"
#include "saldo.h"
#include "rest_api_ddl.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_avaapin_clicked();
    void restApiData(QByteArray data);

private:
    Ui::MainWindow *ui;
    Rest_api_ddl *pRest_api;
    saldo *pSaldo;
    QString tunnus;
};
#endif // MAINWINDOW_H
