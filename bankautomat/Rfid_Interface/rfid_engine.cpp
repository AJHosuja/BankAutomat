#include "rfid_engine.h"



rfid_engine::rfid_engine()
{
    qDebug()<<"Engine constructor!";
    serialPort = new QSerialPort;

    serialPort->setPortName("COM3");
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setBaudRate(QSerialPort::Baud9600, QSerialPort::AllDirections);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);
    serialPort->open(QIODevice::ReadOnly);


   connect(serialPort, SIGNAL(readyRead()),
           this,SLOT(SignalReady()));
}

rfid_engine::~rfid_engine()
{
    qDebug()<<"Engine destructor!";
}

void rfid_engine::SignalReady()
{
    ID = serialPort->readAll();
    qDebug()<<"pääsi tänne";
    qDebug()<<ID;
    //ID.chop(4);
    //ID2=ID.mid(5, 10);
    ID2=ID.simplified();
    ID3=ID2.mid(1);
    ID3.chop(2);
    qDebug()<<ID;
    qDebug()<<ID2;
    qDebug()<<ID3;
    emit sendNumbertoInterface(ID3);
}
