#include "mainwindow.h"
#include "./ui_mainwindow.h"

int tiempo;
bool iniciar = true;

double kp1MaxValue;

double kp1;     const double kp1Max = 20.0;
double kp2;     const double kp2Max = 20.0;
double kp3;     const double kp3Max = 20.0;
double kp4;     const double kp4Max = 20.0;
double kp5;     const double kp5Max = 20.0;
double kp6;     const double kp6Max = 20.0;

double ki1;     const double ki1Max = 20.0;
double ki2;     const double ki2Max = 20.0;
double ki3;     const double ki3Max = 20.0;
double ki4;     const double ki4Max = 20.0;
double ki5;     const double ki5Max = 20.0;
double ki6;     const double ki6Max = 20.0;

double kd1;     const double kd1Max = 20.0;
double kd2;     const double kd2Max = 20.0;
double kd3;     const double kd3Max = 20.0;
double kd4;     const double kd4Max = 20.0;
double kd5;     const double kd5Max = 20.0;
double kd6;     const double kd6Max = 20.0;

double kp; double kpMax;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->KP1->installEventFilter(this);
    ui->KP2->installEventFilter(this);
    ui->KP3->installEventFilter(this);
    ui->KP4->installEventFilter(this);
    ui->KP5->installEventFilter(this);
    ui->KP6->installEventFilter(this);
    ui->KI1->installEventFilter(this);
    ui->KI2->installEventFilter(this);
    ui->KI3->installEventFilter(this);
    ui->KI4->installEventFilter(this);
    ui->KI5->installEventFilter(this);
    ui->KI6->installEventFilter(this);
    ui->KD1->installEventFilter(this);
    ui->KD2->installEventFilter(this);
    ui->KD3->installEventFilter(this);
    ui->KD4->installEventFilter(this);
    ui->KD5->installEventFilter(this);
    ui->KD6->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::FocusOut)
    {
        if (object == ui->KP1 && kp1 < kp1Max)
        {
            QString mensaje = "El valor es menor que " + QString::number(kp1Max);
            QMessageBox::information(this, "Error en KP1", mensaje);
        }
        else if (object == ui->KP2 && kp2 < kp2Max)
        {
            QString mensaje = "El valor es menor que " + QString::number(kp3Max);
            QMessageBox::information(this, "Error en KP2", mensaje);
        }
        else if (object == ui->KP3 && kp3 < kp3Max)
        {
            QString mensaje = "El valor es menor que " + QString::number(kp4Max);
            QMessageBox::information(this, "Error en KP3", mensaje);
        }
        else if (object == ui->KP4 && kp4 < kp4Max)
        {
            QString mensaje = "El valor es menor que " + QString::number(kp5Max);
            QMessageBox::information(this, "Error en KP4", mensaje);
        }
        else if (object == ui->KP5 && kp5 < kp5Max)
        {
            QString mensaje = "El valor es menor que " + QString::number(kp5Max);
            QMessageBox::information(this, "Error en KP5", mensaje);
        }
        else if (object == ui->KP6 && kp6 < kp6Max)
        {
            QString mensaje = "El valor es menor que " + QString::number(kp6Max);
            QMessageBox::information(this, "Error en KP6", mensaje);
        }

        //----------------------------------------
        if (object == ui->KI1 && ki1 < ki1Max)
        {
            QString mensaje = "El valor es menor que " + QString::number(ki1Max);
            QMessageBox::information(this, "Error en KI1", mensaje);
        }
        else if (object == ui->KI2 && ki2 < ki2Max)
        {
            QString mensaje = "El valor es menor que " + QString::number(ki3Max);
            QMessageBox::information(this, "Error en KI2", mensaje);
        }
        else if (object == ui->KI3 && ki3 < ki3Max)
        {
            QString mensaje = "El valor es menor que " + QString::number(ki4Max);
            QMessageBox::information(this, "Error en KI3", mensaje);
        }
        else if (object == ui->KI4 && ki4 < ki4Max)
        {
            QString mensaje = "El valor es menor que " + QString::number(ki5Max);
            QMessageBox::information(this, "Error en KI4", mensaje);
        }
        else if (object == ui->KI5 && ki5 < ki5Max)
        {
            QString mensaje = "El valor es menor que " + QString::number(ki5Max);
            QMessageBox::information(this, "Error en KI5", mensaje);
        }
        else if (object == ui->KI6 && ki6 < ki6Max)
        {
            QString mensaje = "El valor es menor que " + QString::number(ki6Max);
            QMessageBox::information(this, "Error en KI6", mensaje);
        }
        //-----------------------------------------------------------
        if (object == ui->KD1 && kd1 < kd1Max)
        {
            QString mensaje = "El valor es menor que " + QString::number(kd1Max);
            QMessageBox::information(this, "Error en KD1", mensaje);
        }
        else if (object == ui->KD2 && kd2 < kd2Max)
        {
            QString mensaje = "El valor es menor que " + QString::number(kd3Max);
            QMessageBox::information(this, "Error en KD2", mensaje);
        }
        else if (object == ui->KD3 && kd3 < kd3Max)
        {
            QString mensaje = "El valor es menor que " + QString::number(kd4Max);
            QMessageBox::information(this, "Error en KD3", mensaje);
        }
        else if (object == ui->KD4 && kd4 < kd4Max)
        {
            QString mensaje = "El valor es menor que " + QString::number(kd5Max);
            QMessageBox::information(this, "Error en KD4", mensaje);
        }
        else if (object == ui->KD5 && kd5 < kd5Max)
        {
            QString mensaje = "El valor es menor que " + QString::number(kd5Max);
            QMessageBox::information(this, "Error en KD5", mensaje);
        }
        else if (object == ui->KD6 && kd6 < kd6Max)
        {
            QString mensaje = "El valor es menor que " + QString::number(kd6Max);
            QMessageBox::information(this, "Error en KD6", mensaje);
        }
    }
    return false;
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

void MainWindow::on_TiempoS_valueChanged(int arg1)
{
    tiempo = arg1;
}

void MainWindow::on_IniciarPB_clicked()
{
    // setear las ganancias e iniciar las acciones
    // No se si aqui dejar la validacion o nel
}


//--------------------------------- funciones de Ganancias -------------------------//
void MainWindow::on_KP1_valueChanged(double arg1)
{
    kp1 = arg1;
}
void MainWindow::on_KP2_valueChanged(double arg1)
{
    kp2 = arg1;
}
void MainWindow::on_KP3_valueChanged(double arg1)
{
        kp3 = arg1 ;
}
void MainWindow::on_KP4_valueChanged(double arg1)
{
        kp4 = arg1;
}

void MainWindow::on_KP5_valueChanged(double arg1)
{
    kp5 = arg1;
}
void MainWindow::on_KP6_valueChanged(double arg1)
{
    kp6 = arg1;
}
void MainWindow::on_KI1_valueChanged(double arg1)
{
    ki1 = arg1;
}
void MainWindow::on_KI2_valueChanged(double arg1)
{
    ki2 = arg1;
}
void MainWindow::on_KI3_valueChanged(double arg1)
{
    ki3 = arg1;
}
void MainWindow::on_KI4_valueChanged(double arg1)
{
    ki4 = arg1;
}
void MainWindow::on_KI5_valueChanged(double arg1)
{
    ki5 = arg1;
}
void MainWindow::on_KI6_valueChanged(double arg1)
{
    ki6 = arg1;
}

void MainWindow::on_KD1_valueChanged(double arg1)
{
    kd1 = arg1;
}
void MainWindow::on_KD2_valueChanged(double arg1)
{
    kd2 = arg1;
}
void MainWindow::on_KD3_valueChanged(double arg1)
{
    kd3 = arg1;
}
void MainWindow::on_KD4_valueChanged(double arg1)
{
    kd4 = arg1;
}
void MainWindow::on_KD5_valueChanged(double arg1)
{
    kd5 = arg1;
}
void MainWindow::on_KD6_valueChanged(double arg1)
{
    kd6 = arg1;
}

void MainWindow::showNotification(const QString &title, const QString &message)
{
    QMessageBox::information(this, title, message);
}

//----------------------------------------------------------------------------------------------//









