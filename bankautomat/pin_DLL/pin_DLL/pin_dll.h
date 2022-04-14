#ifndef PIN_DLL_H
#define PIN_DLL_H

#include "pin_DLL_global.h"
#include <QString>
#include <QDebug>
#include <QTimer>
#include <QObject>
#include "pinengine.h"

class PIN_DLL_EXPORT Pin_DLL : public QObject
{
    Q_OBJECT
public:
    Pin_DLL(QObject * parent = nullptr);
    ~Pin_DLL();

private:
    PinEngine * pPinEngine;
    QString b;
    QString i;
signals:
    void sendPinToExe(QString);
    void sendSymbolToExe(QString);
public slots:
    void recvB0clicked();
    void recvB1clicked();
    void recvB2clicked();
    void recvB3clicked();
    void recvB4clicked();
    void recvB5clicked();
    void recvB6clicked();
    void recvB7clicked();
    void recvB8clicked();
    void recvB9clicked();
    void recvClearclicked();
    void recvBackspaceclicked();

private slots:
    void recvPinToEngine(QString);
    void recvSymbolToEngine(QString);





};

#endif // PIN_DLL_H
