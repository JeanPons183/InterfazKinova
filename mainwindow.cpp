#include "mainwindow.h"
#include "./ui_mainwindow.h"

int tiempo;

double kp1;
double kp2;
double kp3;
double kp4;
double kp5;
double kp6;

double ki1;
double ki2;
double ki3;
double ki4;
double ki5;
double ki6;

double kd1;
double kd2;
double kd3;
double kd4;
double kd5;
double kd6;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_PDSel_clicked()
{

}

void MainWindow::on_PDSel_toggled(bool checked)
{

}

void MainWindow::on_CambiarTiempoPB_clicked()
{
    // Setear el tiempo con el cesar
}

int MainWindow::on_TiempoS_valueChanged(int arg1)
{
    return tiempo = arg1;
}

void MainWindow::on_IniciarPB_clicked()
{
    // setear las ganancias e iniciar las acciones
}


//--------------------------------- funciones de Ganancias -------------------------//
double MainWindow::on_KP1_valueChanged(double arg1)
{
    return kp1 = arg1;
}
double MainWindow::on_KP2_valueChanged(double arg1)
{
    return kp2 = arg1;
}
double MainWindow::on_KP3_valueChanged(double arg1)
{
    return kp3 = arg1;
}
double MainWindow::on_KP4_valueChanged(double arg1)
{
    return kp4 = arg1;
}
double MainWindow::on_KP5_valueChanged(double arg1)
{
    return kp5 = arg1;
}
double MainWindow::on_KP6_valueChanged(double arg1)
{
    return kp6 = arg1;
}

double MainWindow::on_KI1_valueChanged(double arg1)
{
    return ki1 = arg1;
}
double MainWindow::on_KI2_valueChanged(double arg1)
{
    return ki2 = arg1;
}
double MainWindow::on_KI3_valueChanged(double arg1)
{
    return ki3 = arg1;
}
double MainWindow::on_KI4_valueChanged(double arg1)
{
    return ki4 = arg1;
}
double MainWindow::on_KI5_valueChanged(double arg1)
{
    return ki5 = arg1;
}
double MainWindow::on_KI6_valueChanged(double arg1)
{
    return ki6 = arg1;
}

double MainWindow::on_KD1_valueChanged(double arg1)
{
    return kd1 = arg1;
}
double MainWindow::on_KD2_valueChanged(double arg1)
{
    return kd2 = arg1;
}
double MainWindow::on_KD3_valueChanged(double arg1)
{
    return kd3 = arg1;
}
double MainWindow::on_KD4_valueChanged(double arg1)
{
    return kd4 = arg1;
}
double MainWindow::on_KD5_valueChanged(double arg1)
{
    return kd5 = arg1;
}
double MainWindow::on_KD6_valueChanged(double arg1)
{
    return kd6 = arg1;
}

//----------------------------------------------------------------------------------------------//








