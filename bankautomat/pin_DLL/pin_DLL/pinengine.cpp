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
    qDebug() << i;


//    if (i == "10"){
//        b.clear();
//        if (b.length() > 0){
//            emit sendSymbolToInterface(b);
//        }
//    }

//    if (i == "11"){
//        b.chop(1);
//        if (b.length() > 0){
//            emit sendSymbolToInterface(b);
//        }
//    }



    b.append(i);
    emit sendSymbolToInterface(b);
    if (b.length() == 4){
        qDebug() << "Pin lähetetty enginestä";
        emit sendPinToInterface(b);
        b.clear();
        emit sendSymbolToInterface(b);
    }



}

void PinEngine::clearButton()
{
    qDebug() << "Clear tieto enginestä";
    this->b.clear();
    emit sendSymbolToInterface(b);
}

void PinEngine::backspaceButton()
{
    qDebug() << "Backspace tieto enginestä";
    this->b.chop(1);
    emit sendSymbolToInterface(b);
}


