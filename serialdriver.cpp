#include "serialdriver.h"

SerialDriver::SerialDriver(QObject *parent) : QObject(parent)
{
    serial = new QSerialPort(this);
    serial->setPortName("/dev/ttyUSB0");
}
void SerialDriver::refreshPorts()
{
    ports = QSerialPortInfo::availablePorts();
}

void SerialDriver::setPort(const int val)
{
    QString portName = ports[val].portName();
    serial->setPortName("/dev/"+portName); //linux only!
    qDebug() << "Port set to " << serial->portName();
}

void SerialDriver::openSerial()
{

    serial->setBaudRate(9600);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->open(QIODevice::ReadWrite);

    serial->clear();
}

void SerialDriver::sendByte(const quint8 val)
{
    char str[] = {static_cast<char>(val)};
    serial->write(str, sizeof(str));
    qDebug() << "Sended " << str;
}

void SerialDriver::closeSerial()
{
    serial->close();
}

bool SerialDriver::isOpened()
{
    return serial->isOpen();
}

SerialDriver::~SerialDriver()
{
    serial->close();
}


