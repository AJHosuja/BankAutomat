#include "rfid_interface.h"



Rfid_Interface::Rfid_Interface()
{
    qDebug()<<"Interface constructor";
    pEngine = new rfid_engine();
    connect(pEngine, SIGNAL(sendNumbertoInterface(QByteArray)),
            this, SLOT(ReceiveNumberfromEngine(QByteArray)));
}

Rfid_Interface::~Rfid_Interface()
{
    qDebug()<<"Interface destructor";
}



void Rfid_Interface::ReceiveNumberfromEngine(QByteArray ID)
{
      qDebug()<<"Interface receive number from Engine";
      emit SendNumbertoEXE(ID);
}
