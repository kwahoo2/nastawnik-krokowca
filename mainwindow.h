#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "serialdriver.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    SerialDriver *mySerDrv;
    int Xold, Yold, Zold;

signals:
    void sendSteps(const quint8);

private slots:
    void on_horizontalSliderX_valueChanged(int value);
    void on_horizontalSliderY_valueChanged(int value);
    void on_horizontalSliderZ_valueChanged(int value);
};

#endif // MAINWINDOW_H
