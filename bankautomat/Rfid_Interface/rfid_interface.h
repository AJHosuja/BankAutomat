#ifndef RFID_INTERFACE_H
#define RFID_INTERFACE_H

#include "Rfid_Interface_global.h"
#include <QDebug>
#include <QObject>
#include "rfid_engine.h"
#include <iostream>

class RFID_INTERFACE_EXPORT Rfid_Interface : public QObject
{
    Q_OBJECT

public:
    Rfid_Interface();
   ~Rfid_Interface();


signals:
    void SendNumbertoEXE(QByteArray);

public slots:

    void ReceiveNumberfromEngine(QByteArray);

private:
    rfid_engine * pEngine;

};

#endif // RFID_INTERFACE_H
