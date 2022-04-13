#ifndef PINENGINE_H
#define PINENGINE_H

#include <QObject>
#include <QString>
#include <QDebug>
#include <QTimer>

class PinEngine : public QObject
{
    Q_OBJECT
public:
    PinEngine(QObject * parent = nullptr);
    ~PinEngine();
    void clickHandler(QString i);
    void clearButton();
    void backspaceButton();
    QString b;
    QString c;


signals:
    void sendPinToInterface(QString);
    void sendSymbolToInterface(QString);

};

#endif // PINENGINE_H
