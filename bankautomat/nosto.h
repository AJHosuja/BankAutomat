#ifndef NOSTO_H
#define NOSTO_H

#include <QDialog>
#include "rest_api_ddl.h"

namespace Ui {
class nosto;
}

class nosto : public QDialog
{
    Q_OBJECT

public:
    explicit nosto(QWidget *parent = nullptr);
    ~nosto();

private slots:
    void on_b1_clicked();
    void responseData(QByteArray data);
private:
    Ui::nosto *ui;
    Rest_api_ddl *pRest_api;
};

#endif // NOSTO_H
