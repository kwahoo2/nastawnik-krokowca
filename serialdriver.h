#ifndef SERIALDRIVER_H
#define SERIALDRIVER_H
#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>

class SerialDriver : public QObject
{
    Q_OBJECT
public:
    explicit SerialDriver(QObject *parent = 0);
    bool isOpened();
    QList <QSerialPortInfo> ports;

protected:

signals:

private:
    QSerialPort *serial;
    ~SerialDriver();

private slots:

public slots:
    void sendByte(const quint8);
    void openSerial();
    void closeSerial();
    void refreshPorts();
    void setPort(const int val);
};

#endif // SERIALDRIVER_H
