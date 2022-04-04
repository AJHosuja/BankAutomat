#include "pin_dll.h"

Pin_DLL::Pin_DLL(QObject * parent) : QObject(parent)
{
    qDebug() << "Pin DLL luotu";
    pPinEngine = new PinEngine(this);
    connect(pPinEngine,SIGNAL(sendPinToInterface(QString)),
            this, SLOT(recvPinToEngine(QString)));

}

Pin_DLL::~Pin_DLL()
{
    qDebug() << "Pin DLL tuhottu";
    disconnect(pPinEngine,SIGNAL(sendPinToInterface(QString)),
               this,SLOT(recvPinToEngine(QString)));
    delete pPinEngine;
    pPinEngine = nullptr;

}

void Pin_DLL::recvB0clicked()
{
    qDebug() << "Nappia 0 painettu";
    pPinEngine->clickHandler("0");
}

void Pin_DLL::recvB1clicked()
{
    qDebug() << "Nappia 1 painettu";
    pPinEngine->clickHandler("1");
}

void Pin_DLL::recvB2clicked()
{
    qDebug() << "Nappia 2 painettu";
    pPinEngine->clickHandler("2");
}

void Pin_DLL::recvB3clicked()
{
    qDebug() << "Nappia 3 painettu";
    pPinEngine->clickHandler("3");
}

void Pin_DLL::recvB4clicked()
{
    qDebug() << "Nappia 4 painettu";
    pPinEngine->clickHandler("4");
}

void Pin_DLL::recvB5clicked()
{
    qDebug() << "Nappia 5 painettu";
    pPinEngine->clickHandler("5");
}

void Pin_DLL::recvB6clicked()
{
    qDebug() << "Nappia 6 painettu";
    pPinEngine->clickHandler("6");
}

void Pin_DLL::recvB7clicked()
{
    qDebug() << "Nappia 7 painettu";
    pPinEngine->clickHandler("7");
}

void Pin_DLL::recvB8clicked()
{
    qDebug() << "Nappia 8 painettu";
    pPinEngine->clickHandler("8");
}

void Pin_DLL::recvB9clicked()
{
    qDebug() << "Nappia 9 painettu";
    pPinEngine->clickHandler("9");
}

void Pin_DLL::recvPinToEngine(QString b)
{
    qDebug() << "Pin vastaanotettu enginestä ";
    emit sendPinToExe(b);
}



