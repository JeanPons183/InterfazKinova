#include "mainwindow.h"
#include "./ui_mainwindow.h"

int tiempo;
bool iniciar = true;

double kp1MaxValue;

double kp1;     const double kp1Max = 20.0;
double kp2;     const double kp2Max = 0.0;
double kp3;     const double kp3Max = 0.0;
double kp4;     const double kp4Max = 0.0;
double kp5;     const double kp5Max = 0.0;
double kp6;     const double kp6Max = 0.0;

double ki1;     const double ki1Max = 0.0;
double ki2;     const double ki2Max = 0.0;
double ki3;     const double ki3Max = 0.0;
double ki4;     const double ki4Max = 0.0;
double ki5;     const double ki5Max = 0.0;
double ki6;     const double ki6Max = 0.0;

double kd1;     const double kd1Max = 0.0;
double kd2;     const double kd2Max = 0.0;
double kd3;     const double kd3Max = 0.0;
double kd4;     const double kd4Max = 0.0;
double kd5;     const double kd5Max = 0.0;
double kd6;     const double kd6Max = 0.0;

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
    // No se si aqui dejar la validacion o nel
}


//--------------------------------- funciones de Ganancias -------------------------//
double MainWindow::on_KP1_valueChanged(double arg1)
{
    if(arg1<kp1Max)
        {
            QString mensaje = "El valor es menor que " + QString::number(kp1Max);
            QMessageBox::information(this, "Error en KP1", mensaje);
             // Esta es la forma que encontré pero es muy molesta lel
            iniciar = false;
        }
        // que muestre la notificacion

    return kp1 = arg1;
}
double MainWindow::on_KP2_valueChanged(double arg1)
{
    if (arg1 < kp1Max)
        {
            // Mostrar la notificación en un QLabel
            QString mensaje = "El valor es menor que " + QString::number(kp1Max);
            ui->notificationLabel->setText(mensaje); // Suponiendo que tienes un QLabel llamado "notificationLabel" en tu interfaz
        }
        else
        {
            ui->notificationLabel->setText(""); // Si el valor es mayor o igual, borra la notificación
            // Tambien es esta forma pero se ve feo :'c
        }

        // Actualizar la variable kp1
        kp2 = arg1;
    return kp2 = arg1;
}
double MainWindow::on_KP3_valueChanged(double arg1)
{
    if (arg1 < kp1Max)
        {
            // Mostrar la notificación en la barra de estado
            QString mensaje = "El valor es menor que " + QString::number(kp1Max);
            statusBar()->showMessage(mensaje); // Muestra el mensaje en la barra de estado
            // Esta forma es la menos invasiva, mas bonita pero facil de perder de vistas
        }
        else
        {
            statusBar()->clearMessage(); // Si el valor es mayor o igual, borra el mensaje de la barra de estado
        }

        // Actualizar la variable kp1
        kp3 = arg1;

        return kp3;
}
double MainWindow::on_KP4_valueChanged(double arg1)
{
    if (arg1 < kp1Max)
        {
            // Guardar el valor de kp1Max para utilizarlo en el evento focusOutEvent
            kp1MaxValue = kp1Max;
        }

        return kp4 = arg1; // Actualizar el valor de kp1
}

void MainWindow::focusOutEvent(QFocusEvent *event)
{
    QMainWindow::focusOutEvent(event); // Llama a la implementación base
    // Verificar si el valor de KP1 es menor que kp1Max cuando se pierde el foco
    if (kp4 < kp1MaxValue)
    {
        QString mensaje = "El valor es menor que " + QString::number(kp1Max);
        QMessageBox::information(this, "Notificación", mensaje);
    }
}


double MainWindow::on_KP5_valueChanged(double arg1)
{
    if (arg1 < kp1Max)
        {
            // Mostrar notificación en función genérica
            QString mensaje = "El valor es menor que " + QString::number(kp1Max);
            showNotification("Error en KP3", mensaje);
        }
    kp3 = arg1;
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

void MainWindow::showNotification(const QString &title, const QString &message)
{
    QMessageBox::information(this, title, message);
}

//----------------------------------------------------------------------------------------------//









