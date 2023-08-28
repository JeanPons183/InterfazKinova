#include "mainwindow.h"
#include "./ui_mainwindow.h"


bool banderaSeleccionControl = false;

int tiempo;
bool iniciar = true;

double kp1;         const double kp1Max = 20.0;
double kp2;         const double kp2Max = 20.0;
double kp3;         const double kp3Max = 20.0;
double kp4;         const double kp4Max = 20.0;
double kp5;         const double kp5Max = 20.0;
double kp6;         const double kp6Max = 20.0;
double KP[6] = {kp1,kp2,kp3,kp4,kp5,kp6};

double ki1;         const double ki1Max = 20.0;
double ki2;         const double ki2Max = 20.0;
double ki3;         const double ki3Max = 20.0;
double ki4;         const double ki4Max = 20.0;
double ki5;         const double ki5Max = 20.0;
double ki6;         const double ki6Max = 20.0;
double KI[6] = {ki1,ki2,ki3,ki4,ki5,ki6};

double kd1;         const double kd1Max = 20.0;
double kd2;         const double kd2Max = 20.0;
double kd3;         const double kd3Max = 20.0;
double kd4;         const double kd4Max = 20.0;
double kd5;         const double kd5Max = 20.0;
double kd6;         const double kd6Max = 20.0;
double KD[6] = {kd1,kd2,kd3,kd4,kd5,kd6};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
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

//--------------------------------- funciones de coneccion -------------------------//

void MainWindow::on_coneccionMark_stateChanged(int arg1)
{
}

void MainWindow::on_ConectarPB_clicked()
{
    // Si la conexion es un exito, que lo haga sino nel
    // Aqui una bandera para la conexion y mandarla a la funcion de debajo
    ui->coneccionMark->setChecked(true); // Establece el estado del QCheckBox como marcado

}

//--------------------------------- funciones de seleccion de control -------------------------//

void MainWindow::on_cambiarControlPB_clicked()
{
    for (int i = 0; i < ui->controladoresLO->count(); ++i)
        {
            QWidget *widget = ui->controladoresLO->itemAt(i)->widget();
            if (widget)
                widget->setEnabled(true); // Deshabilitar el widget
        }
}

void MainWindow::on_PDCancGSel_clicked()
{
    deshabilitarControlador();
    ui->KPLabel->setText("KP");
    ui->KILabel->setText("KD");

    ui->KDLabel->close();

    ui->KP1->show(); // Esto lo elimina
    ui->KP2->show(); // Esto lo elimina
    ui->KP3->show(); // Esto lo elimina
    ui->KP4->show(); // Esto lo elimina
    ui->KP5->show(); // Esto lo elimina
    ui->KP6->show(); // Esto lo elimina

    ui->KI1->show(); // Esto lo elimina
    ui->KI2->show(); // Esto lo elimina
    ui->KI3->show(); // Esto lo elimina
    ui->KI4->show(); // Esto lo elimina
    ui->KI5->show(); // Esto lo elimina
    ui->KI6->show(); // Esto lo elimina

    ui->KD1->close();
    ui->KD2->close();
    ui->KD3->close();
    ui->KD4->close();
    ui->KD5->close();
    ui->KD6->close();
}

void MainWindow::on_PDCompGSel_clicked()
{
    deshabilitarControlador();

    ui->KPLabel->show();
    ui->KILabel->show();
    ui->KDLabel->show();

    ui->KPLabel->setText("KP");
    ui->KILabel->setText("KD");
    ui->KDLabel->setText("K");

    ui->KP1->show(); // Esto lo elimina
    ui->KP2->show(); // Esto lo elimina
    ui->KP3->show(); // Esto lo elimina
    ui->KP4->show(); // Esto lo elimina
    ui->KP5->show(); // Esto lo elimina
    ui->KP6->show(); // Esto lo elimina

    ui->KI1->show(); // Esto lo elimina
    ui->KI2->show(); // Esto lo elimina
    ui->KI3->show(); // Esto lo elimina
    ui->KI4->show(); // Esto lo elimina
    ui->KI5->show(); // Esto lo elimina
    ui->KI6->show(); // Esto lo elimina

    ui->KD1->show();
    ui->KD2->show();
    ui->KD3->show();
    ui->KD4->show();
    ui->KD5->show();
    ui->KD6->show();
}

void MainWindow::on_PdCancGSel_clicked()
{
    deshabilitarControlador();

    ui->KPLabel->show();
    ui->KILabel->show();
    ui->KDLabel->show();

    ui->KPLabel->setText("KP");
    ui->KILabel->setText("KD");
    ui->KDLabel->setText("K");
    // Falta asignarle los valores de KI a KD y de KD a K

    ui->KP1->show(); // Esto lo elimina
    ui->KP2->show(); // Esto lo elimina
    ui->KP3->show(); // Esto lo elimina
    ui->KP4->show(); // Esto lo elimina
    ui->KP5->show(); // Esto lo elimina
    ui->KP6->show(); // Esto lo elimina

    ui->KI1->show(); // Esto lo elimina
    ui->KI2->show(); // Esto lo elimina
    ui->KI3->show(); // Esto lo elimina
    ui->KI4->show(); // Esto lo elimina
    ui->KI5->show(); // Esto lo elimina
    ui->KI6->show(); // Esto lo elimina

    ui->KD1->show();
    ui->KD2->show();
    ui->KD3->show();
    ui->KD4->show();
    ui->KD5->show();
    ui->KD6->show();
}

void MainWindow::on_PdCompGSel_clicked()
{
    deshabilitarControlador();

    ui->KPLabel->show();
    ui->KILabel->show();
    ui->KDLabel->show();

    ui->KPLabel->setText("KP");
    ui->KILabel->setText("KD");
    ui->KDLabel->setText("K");

    ui->KP1->show(); // Esto lo elimina
    ui->KP2->show(); // Esto lo elimina
    ui->KP3->show(); // Esto lo elimina
    ui->KP4->show(); // Esto lo elimina
    ui->KP5->show(); // Esto lo elimina
    ui->KP6->show(); // Esto lo elimina

    ui->KI1->show(); // Esto lo elimina
    ui->KI2->show(); // Esto lo elimina
    ui->KI3->show(); // Esto lo elimina
    ui->KI4->show(); // Esto lo elimina
    ui->KI5->show(); // Esto lo elimina
    ui->KI6->show(); // Esto lo elimina

    ui->KD1->show();
    ui->KD2->show();
    ui->KD3->show();
    ui->KD4->show();
    ui->KD5->show();
    ui->KD6->show();
}

void MainWindow::on_sPsdCancGSel_clicked()
    {
        deshabilitarControlador();

        ui->KPLabel->show();
        ui->KILabel->show();
        ui->KDLabel->show();

        ui->KPLabel->setText("KP");
        ui->KILabel->setText("KD");
        ui->KDLabel->setText("K");

        ui->KP1->show(); // Esto lo elimina
        ui->KP2->show(); // Esto lo elimina
        ui->KP3->show(); // Esto lo elimina
        ui->KP4->show(); // Esto lo elimina
        ui->KP5->show(); // Esto lo elimina
        ui->KP6->show(); // Esto lo elimina

        ui->KI1->show(); // Esto lo elimina
        ui->KI2->show(); // Esto lo elimina
        ui->KI3->show(); // Esto lo elimina
        ui->KI4->show(); // Esto lo elimina
        ui->KI5->show(); // Esto lo elimina
        ui->KI6->show(); // Esto lo elimina

        ui->KD1->show();
        ui->KD2->show();
        ui->KD3->show();
        ui->KD4->show();
        ui->KD5->show();
        ui->KD6->show();
    }

void MainWindow::on_sPsdCompGSel_clicked()
    {
        deshabilitarControlador();

        ui->KPLabel->show();
        ui->KILabel->show();
        ui->KDLabel->show();

        ui->KPLabel->setText("KP");
        ui->KILabel->setText("KD");
        ui->KDLabel->setText("K");

        ui->KP1->show(); // Esto lo elimina
        ui->KP2->show(); // Esto lo elimina
        ui->KP3->show(); // Esto lo elimina
        ui->KP4->show(); // Esto lo elimina
        ui->KP5->show(); // Esto lo elimina
        ui->KP6->show(); // Esto lo elimina

        ui->KI1->show(); // Esto lo elimina
        ui->KI2->show(); // Esto lo elimina
        ui->KI3->show(); // Esto lo elimina
        ui->KI4->show(); // Esto lo elimina
        ui->KI5->show(); // Esto lo elimina
        ui->KI6->show(); // Esto lo elimina

        ui->KD1->show();
        ui->KD2->show();
        ui->KD3->show();
        ui->KD4->show();
        ui->KD5->show();
        ui->KD6->show();
    }


//--------------------------------- funciones de tiempo -------------------------//

void MainWindow::on_TiempoS_valueChanged(int arg1)
{
    tiempo = arg1;
}

void MainWindow::on_CambiarTiempoPB_clicked()
{

    // Setear el tiempo con el cesar
}

//--------------------------------- funciones de ejecucion -------------------------//

void MainWindow::on_IniciarPB_clicked()
{
    // ---------------------- Deshabilitacion de elementos ------------------------//
    ui->TiempoS->setEnabled(false);
    ui->ConectarPB->setEnabled(false);
    ui->cambiarControlPB->setEnabled(false);

    for (int i = 0; i < ui->GananciasLO->count(); ++i)
        {
            QWidget *widget = ui->GananciasLO->itemAt(i)->widget();
            if (widget)
                widget->setEnabled(false); // Deshabilitar el widget ganancias
        }
    for (int i = 0; i < ui->pdLO->count(); ++i)
        {
            QWidget *widget = ui->pdLO->itemAt(i)->widget();
            if (widget)
                widget->setEnabled(false); // Deshabilitar el widget qDeseada
        }

    // setear las ganancias e iniciar las acciones
    // No se si aqui dejar la validacion o nel

    // ---------------------- Inicia el programa ------------------------//

    ui->EjecutarLabel->setText("Pausar");
    ui->IniciarPB->setText("Pause");
    int muestra = 0;
    for(int i=0;i<tiempo+100;i++)
            {
                muestra = ((i*100)/tiempo);
                QString cadena = QString::number(muestra);
                qDebug() << "El número como cadena: " << cadena << "Tiempo: " << tiempo;
                ui->progressBar->setValue(muestra);

                // Esto vuelve al estado inicial
                if(muestra>=100)
                {
                    ui->EjecutarLabel->setText("Ejecutar");
                    ui->IniciarPB->setText("Play");
                    ui->progressBar->setValue(100);

                    on_DetenerPB_clicked();             //Importante, se debe de tener claro que se desea aqui

                    break;
                }
            }
}

void MainWindow::on_DetenerPB_clicked()
{
    ui->TiempoS->setEnabled(true);
    ui->ConectarPB->setEnabled(true);
    ui->cambiarControlPB->setEnabled(true);

    for (int i = 0; i < ui->GananciasLO->count(); ++i)
        {
            QWidget *widget = ui->GananciasLO->itemAt(i)->widget();
            if (widget)
                widget->setEnabled(true); // habilitar el widget
        }
    for (int i = 0; i < ui->pdLO->count(); ++i)
        {
            QWidget *widget = ui->pdLO->itemAt(i)->widget();
            if (widget)
                widget->setEnabled(true); // habilitar el widget
        }
}

//--------------------------------- funciones de seleccion de controladores -------------------------//

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
    kp3 = arg1;
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

// Muestra de errores y quiza la notificaciones de las ganancias con el errorTextBrowser
//----------------------------------------------------------------------------------------------//
void MainWindow::on_guardarGananciasPB_clicked()
{
    ui->errorTextBrowser->clear();
    if (kp1 > kp1Max)
    {
        QString mensaje = "El valor es mayor que " + QString::number(kp1Max);
        QString titulo = "Error en KP1";
        ui->errorTextBrowser->append(titulo);
        ui->errorTextBrowser->append(mensaje);
    }
     if (kp2 > kp2Max)
    {
        QString mensaje = "El valor es mayor que " + QString::number(kp3Max);
        QString titulo = "Error en KP2";
        ui->errorTextBrowser->append(titulo);
        ui->errorTextBrowser->append(mensaje);
    }
     if (kp3 > kp3Max)
    {
        QString mensaje = "El valor es mayor que " + QString::number(kp4Max);
        QString titulo = "Error en KP3";
        ui->errorTextBrowser->append(titulo);
        ui->errorTextBrowser->append(mensaje);
    }
     if (kp4 > kp4Max)
    {
        QString mensaje = "El valor es mayor que " + QString::number(kp5Max);
        QString titulo = "Error en KP4";
        ui->errorTextBrowser->append(titulo);
        ui->errorTextBrowser->append(mensaje);
    }
     if (kp5 > kp5Max)
    {
        QString mensaje = "El valor es mayor que " + QString::number(kp5Max);
        QString titulo = "Error en KP5";
        ui->errorTextBrowser->append(titulo);
        ui->errorTextBrowser->append(mensaje);
    }
     if (kp6 > kp6Max)
    {
        QString mensaje = "El valor es mayor que " + QString::number(kp6Max);
        QString titulo = "Error en KP6";
        ui->errorTextBrowser->append(titulo);
        ui->errorTextBrowser->append(mensaje);
    }

    //----------------------------------------
    if (ki1 > ki1Max)
    {
        QString mensaje = "El valor es mayor que " + QString::number(ki1Max);
        QString titulo = "Error en KI1";
        ui->errorTextBrowser->append(titulo);
        ui->errorTextBrowser->append(mensaje);
    }
     if (ki2 > ki2Max)
    {
        QString mensaje = "El valor es mayor que " + QString::number(ki3Max);
        QString titulo = "Error en KI2";
        ui->errorTextBrowser->append(titulo);
        ui->errorTextBrowser->append(mensaje);
    }
     if (ki3 > ki3Max)
    {
        QString mensaje = "El valor es mayor que " + QString::number(ki4Max);
        QString titulo = "Error en KI3";
        ui->errorTextBrowser->append(titulo);
        ui->errorTextBrowser->append(mensaje);
    }
     if (ki4 > ki4Max)
    {
        QString mensaje = "El valor es mayor que " + QString::number(ki5Max);
        QString titulo = "Error en KI4";
        ui->errorTextBrowser->append(titulo);
        ui->errorTextBrowser->append(mensaje);
    }
     if (ki5 > ki5Max)
    {
        QString mensaje = "El valor es mayor que " + QString::number(ki5Max);
        QString titulo = "Error en KI5";
        ui->errorTextBrowser->append(titulo);
        ui->errorTextBrowser->append(mensaje);
    }
     if (ki6 > ki6Max)
    {
        QString mensaje = "El valor es mayor que " + QString::number(ki6Max);
        QString titulo = "Error en KI6";
        ui->errorTextBrowser->append(titulo);
        ui->errorTextBrowser->append(mensaje);
    }
    //-----------------------------------------------------------
    if (kd1 > kd1Max)
    {
        QString mensaje = "El valor es mayor que " + QString::number(kd1Max);
        QString titulo = "Error en KD1";
        ui->errorTextBrowser->append(titulo);
        ui->errorTextBrowser->append(mensaje);
    }
     if (kd2 > kd2Max)
    {
        QString mensaje = "El valor es mayor que " + QString::number(kd2Max);
        QString titulo = "Error en KD2";
        ui->errorTextBrowser->append(titulo);
        ui->errorTextBrowser->append(mensaje);
    }
     if (kd3 > kd3Max)
    {
        QString mensaje = "El valor es mayor que " + QString::number(kd3Max);
        QString titulo = "Error en KD3";
        ui->errorTextBrowser->append(titulo);
        ui->errorTextBrowser->append(mensaje);
    }
     if (kd4 > kd4Max)
    {
        QString mensaje = "El valor es mayor que " + QString::number(kd4Max);
        QString titulo = "Error en KD4";
        ui->errorTextBrowser->append(titulo);
        ui->errorTextBrowser->append(mensaje);
    }
     if (kd5 > kd5Max)
    {
        QString mensaje = "El valor es mayor que " + QString::number(kd5Max);
        QString titulo = "Error en KD5";
        ui->errorTextBrowser->append(titulo);
        ui->errorTextBrowser->append(mensaje);
    }
     if (kd6 > kd6Max)
    {
        QString mensaje = "El valor es mayor que " + QString::number(kd6Max);
        QString titulo = "Error en KD6";
        ui->errorTextBrowser->append(titulo);
        ui->errorTextBrowser->append(mensaje);
    }
}

bool MainWindow::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::FocusOut)
    {
        if (object == ui->KP1 && kp1 > kp1Max)
        {
            QString mensaje = "El valor es mayor que " + QString::number(kp1Max);
            QString titulo = "Error en KP1";
            QMessageBox::warning(this, titulo, mensaje);
        }
        else if (object == ui->KP2 && kp2 > kp2Max)
        {
            QString mensaje = "El valor es mayor que " + QString::number(kp3Max);
            QString titulo = "Error en KP2";
            QMessageBox::warning(this, titulo, mensaje);
        }
        else if (object == ui->KP3 && kp3 > kp3Max)
        {
            QString mensaje = "El valor es mayor que " + QString::number(kp4Max);
            QString titulo = "Error en KP3";
            QMessageBox::warning(this, titulo, mensaje);
        }
        else if (object == ui->KP4 && kp4 > kp4Max)
        {
            QString mensaje = "El valor es mayor que " + QString::number(kp5Max);
            QString titulo = "Error en KP4";
            QMessageBox::warning(this, titulo, mensaje);
        }
        else if (object == ui->KP5 && kp5 > kp5Max)
        {
            QString mensaje = "El valor es mayor que " + QString::number(kp5Max);
            QString titulo = "Error en KP5";
            QMessageBox::warning(this, titulo, mensaje);
        }
        else if (object == ui->KP6 && kp6 > kp6Max)
        {
            QString mensaje = "El valor es mayor que " + QString::number(kp6Max);
            QString titulo = "Error en KP6";
            QMessageBox::warning(this, titulo, mensaje);
        }

        //----------------------------------------
        if (object == ui->KI1 && ki1 > ki1Max)
        {
            QString mensaje = "El valor es mayor que " + QString::number(ki1Max);
            QString titulo = "Error en KI1";
            QMessageBox::warning(this, titulo, mensaje);
        }
        else if (object == ui->KI2 && ki2 > ki2Max)
        {
            QString mensaje = "El valor es mayor que " + QString::number(ki3Max);
            QString titulo = "Error en KI2";
            QMessageBox::warning(this, titulo, mensaje);
        }
        else if (object == ui->KI3 && ki3 > ki3Max)
        {
            QString mensaje = "El valor es mayor que " + QString::number(ki4Max);
            QString titulo = "Error en KI3";
            QMessageBox::warning(this, titulo, mensaje);
        }
        else if (object == ui->KI4 && ki4 > ki4Max)
        {
            QString mensaje = "El valor es mayor que " + QString::number(ki5Max);
            QString titulo = "Error en KI4";
            QMessageBox::warning(this, titulo, mensaje);
        }
        else if (object == ui->KI5 && ki5 > ki5Max)
        {
            QString mensaje = "El valor es mayor que " + QString::number(ki5Max);
            QString titulo = "Error en KI5";
            QMessageBox::warning(this, titulo, mensaje);
        }
        else if (object == ui->KI6 && ki6 > ki6Max)
        {
            QString mensaje = "El valor es mayor que " + QString::number(ki6Max);
            QString titulo = "Error en KI6";
            QMessageBox::warning(this, titulo, mensaje);
        }
        //-----------------------------------------------------------
        if (object == ui->KD1 && kd1 > kd1Max)
        {
            QString mensaje = "El valor es mayor que " + QString::number(kd1Max);
            QString titulo = "Error en KD1";
            QMessageBox::warning(this, titulo, mensaje);
        }
        else if (object == ui->KD2 && kd2 > kd2Max)
        {
            QString mensaje = "El valor es mayor que " + QString::number(kd2Max);
            QString titulo = "Error en KD2";
            QMessageBox::warning(this, titulo, mensaje);
        }
        else if (object == ui->KD3 && kd3 > kd3Max)
        {
            QString mensaje = "El valor es mayor que " + QString::number(kd3Max);
            QString titulo = "Error en KD3";
            QMessageBox::warning(this, titulo, mensaje);
        }
        else if (object == ui->KD4 && kd4 > kd4Max)
        {
            QString mensaje = "El valor es mayor que " + QString::number(kd4Max);
            QString titulo = "Error en KD4";
            QMessageBox::warning(this, titulo, mensaje);
        }
        else if (object == ui->KD5 && kd5 > kd5Max)
        {
            QString mensaje = "El valor es mayor que " + QString::number(kd5Max);
            QString titulo = "Error en KD5";
            QMessageBox::warning(this, titulo, mensaje);
        }
        else if (object == ui->KD6 && kd6 > kd6Max)
        {
            QString mensaje = "El valor es mayor que " + QString::number(kd6Max);
            QString titulo = "Error en KD6";
            QMessageBox::warning(this, titulo, mensaje);
        }
    }
    return false;
}


void MainWindow::deshabilitarControlador()
{
    for (int i = 0; i < ui->controladoresLO->count()-1; ++i)
        {
            QWidget *widget = ui->controladoresLO->itemAt(i)->widget();
            if (widget)
                widget->setEnabled(false); // Deshabilitar el widget
        }
}




