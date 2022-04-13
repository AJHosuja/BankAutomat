#include "pinengine.h"

PinEngine::PinEngine(QObject * parent) : QObject(parent)
{
    qDebug() << "Pin Engine luotu";

}

PinEngine::~PinEngine()
{
    qDebug() << "Pin Engine tuhottu";

}

void PinEngine::clickHandler(QString i)
{
    c = b.length() * "*");
    if (b.length() > 0){
        emit sendSymbolToInterface("*");

    }
    emit sendSymbolToInterface("*");

    b.append(i);
    if (b.length() == 4){
        emit sendPinToInterface(b);    }
    qDebug() << "Pin lähetetty enginestä";

}

void PinEngine::clearButton()
{
    b.clear();
}

void PinEngine::backspaceButton()
{
    b.chop(1);
}


