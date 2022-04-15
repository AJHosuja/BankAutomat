#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "pinni.h"
#include "kayttoliittyma.h"

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

    void on_avaakayt_clicked();

private:
    Ui::MainWindow *ui;
    Pinni *pPinni;
    Kayttoliittyma *pKayttoliittyma;
};
#endif // MAINWINDOW_H
