#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Xold = 0; Yold = 0; Zold = 0;
    mySerDrv = new SerialDriver(this);

    ui->setupUi(this);

    mySerDrv->openSerial();
    QObject::connect(this, SIGNAL(sendSteps(const quint8)),
                     mySerDrv, SLOT(sendByte(quint8)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_horizontalSliderX_valueChanged(int value)
{
    quint8 steps;
    if (value > Xold)
    {
        steps = 0b00000001;
    }
    if (value < Xold)
    {
        steps = 0b00001000;
    }
    Xold = value;
    emit sendSteps(steps);
}

void MainWindow::on_horizontalSliderY_valueChanged(int value)
{
    quint8 steps;
    if (value > Yold)
    {
        steps = 0b00000010;
    }
    if (value < Yold)
    {
        steps = 0b00010000;
    }
    Yold = value;
    emit sendSteps(steps);
}

void MainWindow::on_horizontalSliderZ_valueChanged(int value)
{
    quint8 steps;
    if (value > Zold)
    {
        steps = 0b00000100;
    }
    if (value < Zold)
    {
        steps = 0b00100000;
    }
    Zold = value;
    emit sendSteps(steps);
}
