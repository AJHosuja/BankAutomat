#ifndef RFID_ENGINE_H
#define RFID_ENGINE_H

#include <QObject>
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>

using namespace std;


class rfid_engine : public QObject
{
     Q_OBJECT

public:
    rfid_engine();
    ~rfid_engine();

signals:
    void sendNumbertoInterface(QByteArray);

private slots:
    void SignalReady();

private:

    QSerialPort *serialPort;
    QByteArray ID;
    QByteArray ID2;
    QByteArray ID3;
};

#endif // RFID_ENGINE_H
