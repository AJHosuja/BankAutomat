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
    b.append(i);
    if (b.length() == 4){
        emit sendPinToInterface(b);    }
    qDebug() << "Pin lähetetty enginestä";
}
