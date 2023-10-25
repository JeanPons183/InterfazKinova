#include "mainwindow.h"
#include "ui_mainwindow.h"

//------------------------------------------------------------------------------------------------

// Investigar la funcion saveJpg de Qcustomplot

//Constantes---------------------------------------------------

int FrecuenciaDeMuestreo=100; // La gráfica en tiempo real se actualizará cada 100 milisegundos

int DatosMostrados=10; //Cantidad de datos que se grafican en tiempo real

double pi = 3.1416;

double deltaT=0.001; // Periodo de tiempo de acción

//-------------------------------------------------------------

//Banderas para iniciar la acción del robot--------------------
bool RobotConectado=false;
bool GananciasActivado=false;
bool TiempoActivado=false;
bool ControlActivado=false;
//bool banderaPausa=false;
bool PosicionDeseada=false;
//bool GraficasActivado=false;
bool TareaFinalizada=false;
//------------------------------------------------------------

//Banderas para los botones de la GUI-------------------------
bool GananciasActivadoBoton=false;
bool TiempoActivadoBoton=false;
bool ControlActivadoBoton=false;
bool banderaPausaBoton=false;
bool PosicionDeseadaBoton=false;
bool GraficasActivadoBoton=false;
bool StopTotal=false;
//-------------------------------------------------------------

//Banderas de controlador virtual o PID------------------------
bool banderaPID=false; // bandera para activar ganancias Ki
bool banderaVirtual=false; // bandera para activar las ganancias que inyectan amortiguamiento virtual
//-------------------------------------------------------------

//Variables de los valores de configuración del Robot----------
int TiempoTotalSegundos=0; // Tiempo seleccionado para la acción del Robot
int TiempoTotalMilisegundos= 0; // Cantidad de milisegundos totales

double kp[6];   // Ganancias Kp
double ki[6];   // Ganancias Ki
double kd[6];   // Ganancias Kd
double kc[6];   // Ganancias Kc, para el controlador

double Maxkp[6];   // Valores maximos para las Ganancias Kp
double Maxki[6];   // Valores maximos para las Ganancias Ki
double Maxkd[6];   // Valores maximos para las Ganancias Kd
double Maxkc[6];   // Valores maximos para las Ganancias Kc

int GripperValue=0; // valor del porcentaje de posición del gripper 0 - 100% 0 -> Abierto, 100-> Cerrado

double Mc=0; //Valor de la masa virtual del controlador

double q[6];    // Coordenadas generalizadas del Robot (deg)
long double q_rad[6]; // Posicion actual en radianes

double qd[6];  // Coordenadas generalizadas de la posición deseada (deg)
long double qd_rad[6]; // Posicion deseada en radianes
//--------------------------------------------------------------


//Vectores para las trayectorias--------------------------------
QVector<double> TiempoMilisegundosGrafica;
QVector<double> TrayectoriaArticulacion1;
QVector<double> TrayectoriaArticulacion2;
QVector<double> TrayectoriaArticulacion3;
QVector<double> TrayectoriaArticulacion4;
QVector<double> TrayectoriaArticulacion5;
QVector<double> TrayectoriaArticulacion6;
QVector<double> ValorGripper;
//--------------------------------------------------------------


//******************************************************************************************************************************************************************************

//Configuración Inicial de la Ventana Principal---------------------------------------------------

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Inicio de ventana
    this->setWindowTitle("Kinova Gen3 Lite");
    MainWindow::setWindowState(Qt::WindowMaximized);
    //ui->RobotSetting->setMinimumHeight(minimumHeight());

    ui->ConeccionCB->setChecked(true);
    ui->ConeccionCB->setVisible(false);

    ui->RobotSetting->resize(1611,21); // al abrir la aplicacion se esconde la pantalla
    ui->Ejecucion->resize(261,21);

    ui->Plots->resize(1881,21); //pantalla de graficas reales

    ui->RunMode->setVisible(false); // se esconde el Run mode
    ui->AccionTerminadaRB->setEnabled(false);

    ui->label_119->setVisible(false);
    ui->label_ControlSelected->setVisible(false);

    ui->ControlSelectCB->setVisible(false);

    ui->ScreenGains->setVisible(false);
    ui->Screenmc->setVisible(false);
    ui->ScreenvirtualGains->setVisible(false);
    ui->label_Masavirtual->setVisible(false);
    ui->cambiarGainsPB->setVisible(false);

    ui->IniciarPB->setEnabled(false);

    ui->ActivarGraficasPB->setVisible(false); // escondemos los botones de las graficas
    ui->GraficasTiempoRealRB->setVisible(false);
    ui->GraficasDespuesRB->setVisible(false);


    ui->label_Estado->setVisible(false);    // se esconden las etiquetas del estado del robot
    ui->label_EstadoActual->setVisible(false);
    ui->ProgresoPBar->setVisible(false);    // se esconde la barra del progreso de la acción


}

MainWindow::~MainWindow()
{
    delete ui;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------

// Configuración de la ventana Frame
//---------------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::PausarUI()
{
    ui->ActivarGraficasPB->setEnabled(false);
    ui->GraficasDespuesRB->setEnabled(false);
    ui->GraficasTiempoRealRB->setEnabled(false);
    //--------------------------------------------
    ui->CambiarTiempoPB->setEnabled(false);
    ui->CambiarControlPB->setEnabled(false);
    ui->CambiarQdPB->setEnabled(false);
    ui->cambiarGainsPB->setEnabled(false);
    ui->PosPackPB->setEnabled(false);
    ui->PosZeroPB->setEnabled(false);
    //--------------------------------------------
    ui->CorrerRobotRB->setEnabled(false);
    ui->SimulacionRB->setEnabled(false);
}

void MainWindow::PlayUI()
{
    ui->ActivarGraficasPB->setEnabled(true);
    ui->GraficasDespuesRB->setEnabled(true);
    ui->GraficasTiempoRealRB->setEnabled(true);
    //--------------------------------------------
    ui->CambiarTiempoPB->setEnabled(true);
    ui->CambiarControlPB->setEnabled(true);
    ui->CambiarQdPB->setEnabled(true);
    ui->cambiarGainsPB->setEnabled(true);
    ui->PosPackPB->setEnabled(true);
    ui->PosZeroPB->setEnabled(true);
    //--------------------------------------------
    ui->CorrerRobotRB->setEnabled(true);
    ui->SimulacionRB->setEnabled(true);
}

void MainWindow::Controlador(int select) // selector te permite seleccionar la pantalla de etiquetas o la pantalla de SpinBox, valor 0 o 1
{

    // Juntar ifs con operador or || para cortar código

    ui->ScreenGains->setVisible(true);
    ui->cambiarGainsPB->setVisible(true);

    if(!banderaPID){ // se desactivan las pertenencias de Ki si no es un controlador PID ------------------------------------
        ui->label_Ki->setVisible(false);
        ui->label_Ki_2->setVisible(false);
        ui->ki1Label->setVisible(false);
        ui->ki2Label->setVisible(false);
        ui->ki3Label->setVisible(false);
        ui->ki4Label->setVisible(false);
        ui->ki5Label->setVisible(false);
        ui->ki6Label->setVisible(false);
        ui->ki1SB->setVisible(false);
        ui->ki2SB->setVisible(false);
        ui->ki3SB->setVisible(false);
        ui->ki4SB->setVisible(false);
        ui->ki5SB->setVisible(false);
        ui->ki6SB->setVisible(false);
    }
    //------------------------------------------------------------------------

    /*Index del ComboBox
     *0->PD + Cancelación de Gravedad
     *1->PD + Compensación de Gravedad
     *2->P'D' + Cancelación de Gravedad
     *3->P'D' + Compensación de Gravedad
     *4->sPsD + Cancelación de Gravedad
     *5->sPsD + Compensación de Gravedad
     *6->sPs'D' + Cancelación de Gravedad
     *7->sPs'D' + Compensación de Gravedad
     *
     *Index select
     *
     *0->Robot puede medir velocidad
     *1->Robot no puede medir velocidad
     *
     */

    if((ui->ControlSelectCB->currentIndex())==0||(ui->ControlSelectCB->currentIndex())==1||(ui->ControlSelectCB->currentIndex())==4||(ui->ControlSelectCB->currentIndex())==5){
        banderaVirtual=false;
        ui->Screenmc->setVisible(false);
        ui->ScreenvirtualGains->setVisible(false);
        ui->label_Masavirtual->setVisible(false);
        if(select){ // Uno es la pantalla de entradas (SpinBox)
            ui->ScreenGains->setCurrentIndex(1);

        }else{ // Cero es la pantalla de etiquetas

            ui->ScreenGains->setCurrentIndex(0);
        }
    }else if((ui->ControlSelectCB->currentIndex())==2||(ui->ControlSelectCB->currentIndex())==3||(ui->ControlSelectCB->currentIndex())==6||(ui->ControlSelectCB->currentIndex())==7){
        banderaVirtual=true;
        ui->Screenmc->setVisible(true);
        ui->ScreenvirtualGains->setVisible(true);
        ui->label_Masavirtual->setVisible(true);
        if(select){
            ui->ScreenGains->setCurrentIndex(1);
            ui->ScreenvirtualGains->setCurrentIndex(1);
            ui->Screenmc->setCurrentIndex(1);
        }else{ // Cero es la pantalla de etiquetas
            ui->ScreenGains->setCurrentIndex(0);
            ui->ScreenvirtualGains->setCurrentIndex(0);
            ui->Screenmc->setCurrentIndex(0);
        }
    }
}
//---------------------------------------------------------------------------------------------------------------------------------------------------

// Conectar Frame
//---------------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_ConectarPB_clicked()
{
    //Conectar Robot
    RobotConectado=true;

    if(RobotConectado){
        ui->ConectarPB->setVisible(false); // eliminamos el botón
        ui->ConeccionCB->setVisible(true);
        ui->ConeccionCB->setEnabled(false);

        ui->RobotSetting->resize(1611,411); // desplegamos los widgets
        ui->Ejecucion->resize(261,411);

        ui->Plots->resize(1881,51);

        ui->RunMode->setVisible(true); // se despliega el Run mode
        ui->SimulacionRB->setChecked(true); // por defecto se usa el modo simulación
        //ui->GraficasDespuesRB->setChecked(true);

        ui->ActivarGraficasPB->setVisible(true); // se activa el boton que permite graficar
        ui->ActivarGraficasPB->setEnabled(false);

        ui->label_Estado->setVisible(true);    // se despliegan las etiquetas del estado del robot
        ui->label_EstadoActual->setVisible(true);
        ui->label_EstadoActual->setText("Stand by");
        ui->label_119->setVisible(true);
        ui->label_ControlSelected->setVisible(true);

        //ui->label_IP->setText("IP");

        ui->ControlSelectCB->setDisabled(true);

        //conseguir q actual

        QMessageBox::information(this,tr("Robot Conectado"),tr("Conección exitosa con el robot"));
        //mensaje para el usuario de conección exitosa

    }else{
        QMessageBox::warning(this,tr("Problema con la conección del Robot"),tr("No se pudo efectuar la conección con el Robot"));
        //mensaje para el usuario de conección fallida
        ui->MostrarErrores->append("No se pudo conectar con el Robot");
    }
}
//---------------------------------------------------------------------------------------------------------------------------------------------------

// Robot Settings Frame
//---------------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_CambiarControlPB_clicked()
{
    if(ControlActivadoBoton){
        ui->label_ControlSelected->setText(ui->ControlSelectCB->currentText());
        ui->CambiarControlPB->setText("Cambiar Control");
        ui->ControlSelectCB->setEnabled(false);

        Controlador(0);// funcion que dependiendo el controlador muestra las etiquetas de Ki o mc

        ControlActivado=true;
        ControlActivadoBoton=false;

    }else{
        ui->CambiarControlPB->setText("Guardar");
        ui->ControlSelectCB->setVisible(true);
        ui->ControlSelectCB->setEnabled(true);
        ControlActivado=false;
        ControlActivadoBoton=true;
    }
    if(GananciasActivado && ControlActivado && TiempoActivado && PosicionDeseada){ // Chequeo de banderas para activar el boton de iniciar
        ui->IniciarPB->setEnabled(true);
    }else{
        ui->IniciarPB->setEnabled(false);
    }
}

void MainWindow::on_CambiarTiempoPB_clicked()
{
    if(TiempoActivadoBoton){
        if((ui->TiempoSB->value())!=0){// comprobando que el tiempo no sea igual a 0
            ui->CambiarTiempoPB->setText("Cambiar Tiempo");
            TiempoTotalSegundos=ui->TiempoSB->value();
            ui->ScreenTiempo->setCurrentIndex(0);
            ui->label_Segundos->setText(QString::number(TiempoTotalSegundos));
            TiempoActivado=true;
            TiempoActivadoBoton=false;
            TiempoTotalMilisegundos= TiempoTotalSegundos / deltaT;

        }else{ //Error, numero igual a 0
            QMessageBox::warning(this,tr("Error!"),tr("El tiempo seleccionado no es correcto"));
            ui->MostrarErrores->append("El tiempo: " +QString::number(ui->TiempoSB->value())+", no es un valor valido");
        }
    }else{
        ui->CambiarTiempoPB->setText("Guardar");
        ui->ScreenTiempo->setCurrentIndex(1);
        ui->TiempoSB->setValue(TiempoTotalSegundos);
        TiempoActivado=false;
        TiempoActivadoBoton=true;
    }
    if(GananciasActivado && ControlActivado && TiempoActivado && PosicionDeseada){ // Chequeo de banderas para activar el boton de iniciar
        ui->IniciarPB->setEnabled(true);
    }else{
        ui->IniciarPB->setEnabled(false);
    }
    if(TiempoActivado){
        ui->ActivarGraficasPB->setEnabled(true);
    }

}
//---------------------------------------------------------------------------------------------------------------------------------------------------

// Ganancias Frame
//---------------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_cambiarGainsPB_clicked()
{
    if(GananciasActivadoBoton){
        ui->cambiarGainsPB->setText("Cambiar Ganancias");

        SaveValues();
        Controlador(0);
        SetValues();
        GananciasActivado=true;
        GananciasActivadoBoton=false;

    }else{
        if(ControlActivado==false){//elegir controlador previamente
            QMessageBox::warning(this,tr("Error!"),tr("Por favor seleccione un controlador."));
            ui->MostrarErrores->append("No hay un controlador seleccionado");
        }else{

            Controlador(1);
            SetValues();
            ui->cambiarGainsPB->setText("Guardar");

            GananciasActivado=false;
            GananciasActivadoBoton=true;
        }

    }
    if(GananciasActivado && ControlActivado && TiempoActivado && PosicionDeseada){ // Chequeo de banderas para activar el boton de iniciar
        ui->IniciarPB->setEnabled(true);
    }else{
        ui->IniciarPB->setEnabled(false);
    }
}

void MainWindow::SaveValues()
{
    if(banderaVirtual){ // select se usa si no se puede medir velocidad, para un controlador de segundo orden
        Mc=ui->mcValueSB->value();
        kc[0]= ui->kc1SB->value();
        kc[1]= ui->kc2SB->value();
        kc[2]= ui->kc3SB->value();
        kc[3]= ui->kc4SB->value();
        kc[4]= ui->kc5SB->value();
        kc[5]= ui->kc6SB->value();
    }
    if(banderaPID){
        ki[0]= ui->ki1SB->value();
        ki[1]= ui->ki2SB->value();
        ki[2]= ui->ki3SB->value();
        ki[3]= ui->ki4SB->value();
        ki[4]= ui->ki5SB->value();
        ki[5]= ui->ki6SB->value();
    }
    kp[0]= ui->kp1SB->value();
    kp[1]= ui->kp2SB->value();
    kp[2]= ui->kp3SB->value();
    kp[3]= ui->kp4SB->value();
    kp[4]= ui->kp5SB->value();
    kp[5]= ui->kp6SB->value();

    kd[0]= ui->kd1SB->value();
    kd[1]= ui->kd2SB->value();
    kd[2]= ui->kd3SB->value();
    kd[3]= ui->kd4SB->value();
    kd[4]= ui->kd5SB->value();
    kd[5]= ui->kd6SB->value();
}

void MainWindow::SetValues()
{

    if(banderaVirtual){ // select se usa si no se puede medir velocidad, para un controlador de segundo orden, utiliza los valores del controlador virtual
        ui->mcValueLabel->setText(QString::number(Mc));
        ui->mcValueSB->setValue(Mc);

        ui->kc1SB->setValue(kc[0]);
        ui->kc2SB->setValue(kc[1]);
        ui->kc3SB->setValue(kc[2]);
        ui->kc4SB->setValue(kc[3]);
        ui->kc5SB->setValue(kc[4]);
        ui->kc6SB->setValue(kc[5]);

        ui->kc1Label->setText(QString::number(kc[0]));
        ui->kc2Label->setText(QString::number(kc[1]));
        ui->kc3Label->setText(QString::number(kc[2]));
        ui->kc4Label->setText(QString::number(kc[3]));
        ui->kc5Label->setText(QString::number(kc[4]));
        ui->kc6Label->setText(QString::number(kc[5]));
    }
    if(banderaPID){
        ui->ki1SB->setValue(ki[0]);
        ui->ki2SB->setValue(ki[1]);
        ui->ki3SB->setValue(ki[2]);
        ui->ki4SB->setValue(ki[3]);
        ui->ki5SB->setValue(ki[4]);
        ui->ki6SB->setValue(ki[5]);

        ui->ki1Label->setText(QString::number(ki[0]));
        ui->ki2Label->setText(QString::number(ki[1]));
        ui->ki3Label->setText(QString::number(ki[2]));
        ui->ki4Label->setText(QString::number(ki[3]));
        ui->ki5Label->setText(QString::number(ki[4]));
        ui->ki6Label->setText(QString::number(ki[5]));
    }
    ui->kp1SB->setValue(kp[0]);
    ui->kp2SB->setValue(kp[1]);
    ui->kp3SB->setValue(kp[2]);
    ui->kp4SB->setValue(kp[3]);
    ui->kp5SB->setValue(kp[4]);
    ui->kp6SB->setValue(kp[5]);

    ui->kp1Label->setText(QString::number(kp[0]));
    ui->kp2Label->setText(QString::number(kp[1]));
    ui->kp3Label->setText(QString::number(kp[2]));
    ui->kp4Label->setText(QString::number(kp[3]));
    ui->kp5Label->setText(QString::number(kp[4]));
    ui->kp6Label->setText(QString::number(kp[5]));

    ui->kd1SB->setValue(kd[0]);
    ui->kd2SB->setValue(kd[1]);
    ui->kd3SB->setValue(kd[2]);
    ui->kd4SB->setValue(kd[3]);
    ui->kd5SB->setValue(kd[4]);
    ui->kd6SB->setValue(kd[5]);

    ui->kd1Label->setText(QString::number(kd[0]));
    ui->kd2Label->setText(QString::number(kd[1]));
    ui->kd3Label->setText(QString::number(kd[2]));
    ui->kd4Label->setText(QString::number(kd[3]));
    ui->kd5Label->setText(QString::number(kd[4]));
    ui->kd6Label->setText(QString::number(kd[5]));
}

//---------------------------------------------------------------------------------------------------------------------------------------------------

// Posicion Frame
//---------------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_PosZeroPB_clicked()
{
    //check if it's not the position it is already in

    // cambia la posicon deseada a q=[0,0,0,0,0,0]' (cero deg° para cada articulación)

    qd[0]=0;
    qd[1]=0;
    qd[2]=0;
    qd[3]=0;
    qd[4]=0;
    qd[5]=0;

    ui->label_posqd1->setText(QString::number(qd[0])+"°");
        ui->label_posqd2->setText(QString::number(qd[1])+"°");
        ui->label_posqd3->setText(QString::number(qd[2])+"°");
        ui->label_posqd4->setText(QString::number(qd[3])+"°");
        ui->label_posqd5->setText(QString::number(qd[4])+"°");
        ui->label_posqd6->setText(QString::number(qd[5])+"°");

        PosicionDeseada=true;
    if(GananciasActivado && ControlActivado && TiempoActivado && PosicionDeseada){ // Chequeo de banderas para activar el boton de iniciar
        ui->IniciarPB->setEnabled(true);
    }else{
        ui->IniciarPB->setEnabled(false);
    }
}

void MainWindow::on_PosPackPB_clicked()
{
    //check if it's not the position it is already in

    // cambia la posición deseada a q=[0,0,0,0,0,0]' (deg°) posición Packaging

    qd[0]=0;
    qd[1]=0;
    qd[2]=0;
    qd[3]=0;
    qd[4]=0;
    qd[5]=0;

    ui->label_posqd1->setText(QString::number(qd[0])+"°");
        ui->label_posqd2->setText(QString::number(qd[1])+"°");
        ui->label_posqd3->setText(QString::number(qd[2])+"°");
        ui->label_posqd4->setText(QString::number(qd[3])+"°");
        ui->label_posqd5->setText(QString::number(qd[4])+"°");
        ui->label_posqd6->setText(QString::number(qd[5])+"°");

        PosicionDeseada=true;
    if(GananciasActivado && ControlActivado && TiempoActivado && PosicionDeseada){ // Chequeo de banderas para activar el boton de iniciar
        ui->IniciarPB->setEnabled(true);
    }else{
        ui->IniciarPB->setEnabled(false);
    }
}

void MainWindow::on_CambiarQdPB_clicked()
{
    if(PosicionDeseadaBoton){

        qd[0]= ui->qd1SB->value();
        qd[1]= ui->qd2SB->value();
        qd[2]= ui->qd3SB->value();
        qd[3]= ui->qd4SB->value();
        qd[4]= ui->qd5SB->value();
        qd[5]= ui->qd6SB->value();
        GripperValue= ui->gripValueSB->value();

        qd_rad[0]=qd[0]*(pi/180);
        qd_rad[1]=qd[1]*(pi/180);
        qd_rad[2]=qd[2]*(pi/180);
        qd_rad[3]=qd[3]*(pi/180);
        qd_rad[4]=qd[4]*(pi/180);
        qd_rad[5]=qd[5]*(pi/180); // Cambiamos la posición deseada recibida en grados a radianes

        //Checar rangos de las posiciones y por singularidades

        ui->ScreenQd->setCurrentIndex(0);

        ui->label_posqd1->setText(QString::number(qd[0])+"°"); //Cambia el valor en las etiquetas por los valores guardados
        ui->label_posqd2->setText(QString::number(qd[1])+"°");
            ui->label_posqd3->setText(QString::number(qd[2])+"°");
            ui->label_posqd4->setText(QString::number(qd[3])+"°");
            ui->label_posqd5->setText(QString::number(qd[4])+"°");
            ui->label_posqd6->setText(QString::number(qd[5])+"°");
            ui->label_gripperValueQd->setText(QString::number(GripperValue)+"%");

        ui->CambiarQdPB->setText("Cambiar Posición Deseada");

            PosicionDeseada=true;
        PosicionDeseadaBoton=false;
    }else{

        ui->ScreenQd->setCurrentIndex(1);

        ui->qd1SB->setValue(qd[0]);
        ui->qd2SB->setValue(qd[1]);
        ui->qd3SB->setValue(qd[2]);
        ui->qd4SB->setValue(qd[3]);
        ui->qd5SB->setValue(qd[4]);
        ui->qd6SB->setValue(qd[5]);
        ui->gripValueSB->setValue(GripperValue);

        ui->CambiarQdPB->setText("Guardar");
        PosicionDeseada=false;
        PosicionDeseadaBoton=true;
    }
    if(GananciasActivado && ControlActivado && TiempoActivado && PosicionDeseada){ // Chequeo de banderas para activar el boton de iniciar
        ui->IniciarPB->setEnabled(true);
    }else{
        ui->IniciarPB->setEnabled(false);
    }
}
//---------------------------------------------------------------------------------------------------------------------------------------------------

// Ejecucion Frame
//---------------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_IniciarPB_clicked()
{
    PausarUI();
    TiempoMilisegundosGrafica.resize(TiempoTotalMilisegundos); //cambiar a hacer el ciclo si el RB esta activado al terminar de hacer la tarea, de lo contrario dejar vacio el vector, usar el mismo para las dos graficas
    for (int i = 0; i < TiempoTotalMilisegundos; i++) {
        TiempoMilisegundosGrafica[i]=i;
    }
    //--------------------------------------------
    ui->ProgresoPBar->setVisible(true);
    ui->ScreenRunStop->setCurrentIndex(1);

    //Funcion del Robot(); poner al final de su funcion la bandera TareaFinalizada
    TareaFinalizada=true; //prueba

}

void MainWindow::on_StopPB_clicked()
{
    //Detener todo
    //parar en posicion
    //controlar mediante cancelación de gravedad
    ui->ScreenRunStop->setCurrentIndex(3);
}

void MainWindow::on_AccionTerminadaRB_toggled(bool checked)
{
    if(GraficasActivadoBoton){
        if(ui->GraficasTiempoRealRB->isChecked()){
            ui->WidgetGrafica->clearPlottables();
            ConfigurarGrafica(ui->ElegirGraficaCB->currentIndex());
            GraficarTrayectoria(ui->ElegirGraficaCB->currentIndex());
        }else{
            GraficarTrayectoria(ui->ElegirGraficaCB->currentIndex());
        }
    }
}

void MainWindow::on_CancelarGravedadPB_clicked()//boton que se muestra cuando se detiene la simulación
{

}

void MainWindow::on_RegresarZeroPB_clicked()//boton que se muestra cuando se detiene la simulación
{

}

void MainWindow::on_FinalizarPB_clicked() //boton que se muestra cuando se detiene la simulación
{
    //Detener Robot
}

void MainWindow::on_FinalizarPB_2_clicked() //boton que se muestra ya que el robot termino la acción
{
    //PlayUI();
    ui->AccionTerminadaRB->setChecked(true);
    //ui->ScreenRunStop->setCurrentIndex(0);
}

void MainWindow::Temporizador()
{
    tiempo = 0.0;
    miTemporizador = new QTimer(this);
    connect(miTemporizador, &QTimer::timeout, this, &MainWindow::ActualizarGrafica);
    miTemporizador->start(FrecuenciaDeMuestreo);
}

//---------------------------------------------------------------------------------------------------------------------------------------------------

//Graficas Frame
//---------------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_ActivarGraficasPB_clicked()
{

    if(GraficasActivadoBoton){ //se desactivan las graficas
        ui->ActivarGraficasPB->setText("Activar Gráficas");
        ui->Plots->resize(1881,51);

        ui->GraficasTiempoRealRB->setVisible(false);
        ui->GraficasDespuesRB->setVisible(false);
        ui->GraficasTiempoRealRB->setEnabled(false);
        ui->GraficasDespuesRB->setEnabled(false);
        ui->GraficasDespuesRB->setChecked(false);
        ui->label_agraficar->setVisible(false);
        //ui->label_posarticulaciones->setVisible(false);
        ui->ElegirGraficaCB->setVisible(false);
        ui->ElegirGraficaCB->setEnabled(false);
        ui->PosicionDeseadaRD->setVisible(false);
        ui->PosicionDeseadaRD->setEnabled(false);
        ui->PosicionDeseadaRD->setChecked(false);

        GraficasActivadoBoton=false;
    }else{ //activamos las graficas
        ui->ActivarGraficasPB->setText("Desactivar Gráficas");
        ui->Plots->resize(1881,481);

        ui->GraficasTiempoRealRB->setVisible(true);
        ui->GraficasDespuesRB->setVisible(true);
        ui->GraficasTiempoRealRB->setEnabled(true);
        ui->GraficasDespuesRB->setEnabled(true);
        ui->GraficasDespuesRB->setChecked(true);
        ui->label_agraficar->setVisible(true);
        //ui->label_posarticulaciones->setVisible(true);
        ui->ElegirGraficaCB->setVisible(true);
        ui->ElegirGraficaCB->setEnabled(true);
        ui->PosicionDeseadaRD->setVisible(true);
        ui->PosicionDeseadaRD->setEnabled(true);
        ui->PosicionDeseadaRD->setChecked(true);

        CrearGrafica();

        GraficasActivadoBoton=true;
    }
}

void MainWindow::on_ElegirGraficaCB_currentIndexChanged(int index)
{
    ConfigurarGrafica(index);
}

void MainWindow::CrearGrafica()
{
    QCustomPlot *grafica = ui->WidgetGrafica;
    QFont legendFont = font();  // start out with MainWindow's font.
    legendFont.setPointSize(9); // and make a bit smaller for legend

    grafica->legend->setVisible(true);
    grafica->legend->setFont(legendFont);
    grafica->legend->setBrush(QBrush(QColor(255,255,255,230)));
    // by default, the legend is in the inset layout of the main axis rect. So this is how we access it to change legend placement:

    grafica->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignBottom|Qt::AlignRight);
    grafica->xAxis->setLabel("Tiempo (ms)");
    if(ui->GraficasTiempoRealRB->isChecked()){ // Se ajusta el eje x de la grafica dependiendo del modo
        grafica->xAxis->setRange(0,1000);

    }else{
        grafica->xAxis->setRange(0,TiempoTotalMilisegundos);
    }
    grafica->yAxis->setLabel("Rotación de la articulación (deg°)");
    grafica->yAxis->setRange(-155,155);
    grafica->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables); //  Plottables are selectable (e.g. graphs, curves, bars,... see QCPAbstractPlottable) tbd

    grafica->rescaleAxes(); // funciones que hacen update a la gráfica
    grafica->replot();
    grafica->update();
}

void MainWindow::ConfigurarGrafica(int index)
{

    QCustomPlot *grafica = ui->WidgetGrafica;
    grafica->clearPlottables();
    switch (index) {
    case 0:
        grafica->addGraph();
        grafica->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
        grafica->graph(0)->setPen(QPen(Qt::cyan));
        grafica->graph(0)->setName("Posición de la Articulación 1.");

        if(ui->PosicionDeseadaRD->isChecked()){
            grafica->addGraph();
            grafica->graph(1)->data()->clear(); // borra datos previamente guardados en el widget
            grafica->graph(1)->setPen(QPen(Qt::darkCyan));
            grafica->graph(1)->setName("Posición Deseada 1.");

        }
        break;
    case 1:
        grafica->addGraph();
        grafica->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
        grafica->graph(0)->setPen(QPen(Qt::magenta));
        grafica->graph(0)->setName("Posición de la Articulación 2.");

        if(ui->PosicionDeseadaRD->isChecked()){
            grafica->addGraph();
            grafica->graph(1)->data()->clear(); // borra datos previamente guardados en el widget
            grafica->graph(1)->setPen(QPen(Qt::darkMagenta));
            grafica->graph(1)->setName("Posición Deseada 2.");

        }
        break;
    case 2:
        grafica->addGraph();
        grafica->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
        grafica->graph(0)->setPen(QPen(Qt::yellow));
        grafica->graph(0)->setName("Posición de la Articulación 3.");

        if(ui->PosicionDeseadaRD->isChecked()){
            grafica->addGraph();
            grafica->graph(1)->data()->clear(); // borra datos previamente guardados en el widget
            grafica->graph(1)->setPen(QPen(Qt::darkYellow));
            grafica->graph(1)->setName("Posición Deseada 3.");

        }
        break;
    case 3:
        grafica->addGraph();
        grafica->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
        grafica->graph(0)->setPen(QPen(Qt::gray));
        grafica->graph(0)->setName("Posición de la Articulación 4.");

        if(ui->PosicionDeseadaRD->isChecked()){
            grafica->addGraph();
            grafica->graph(1)->data()->clear(); // borra datos previamente guardados en el widget
            grafica->graph(1)->setPen(QPen(Qt::darkGray));
            grafica->graph(1)->setName("Posición Deseada 4.");
        }
        break;
    case 4:
        grafica->addGraph();
        grafica->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
        grafica->graph(0)->setPen(QPen(Qt::red));
        grafica->graph(0)->setName("Posición de la Articulación 5.");

        if(ui->PosicionDeseadaRD->isChecked()){
            grafica->addGraph();
            grafica->graph(1)->data()->clear(); // borra datos previamente guardados en el widget
            grafica->graph(1)->setPen(QPen(Qt::darkRed));
            grafica->graph(1)->setName("Posición Deseada 5.");
        }
        break;
    case 5:
        grafica->addGraph();
        grafica->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
        grafica->graph(0)->setPen(QPen(Qt::green));
        grafica->graph(0)->setName("Posición de la Articulación 6.");

        if(ui->PosicionDeseadaRD->isChecked()){
            grafica->addGraph();
            grafica->graph(1)->data()->clear(); // borra datos previamente guardados en el widget
            grafica->graph(1)->setPen(QPen(Qt::darkGreen));
            grafica->graph(1)->setName("Posición Deseada 6.");
        }
        break;
    case 6:
        grafica->addGraph();
        grafica->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
        grafica->graph(0)->setPen(QPen(Qt::cyan));
        grafica->graph(0)->setName("Posición de la Articulación 1.");

        grafica->addGraph();
        grafica->graph(1)->data()->clear(); // borra datos previamente guardados en el widget
        grafica->graph(1)->setPen(QPen(Qt::magenta));
        grafica->graph(1)->setName("Posición de la Articulación 2.");

        grafica->addGraph();
        grafica->graph(2)->data()->clear(); // borra datos previamente guardados en el widget
        grafica->graph(2)->setPen(QPen(Qt::yellow));
        grafica->graph(2)->setName("Posición de la Articulación 3.");

        grafica->addGraph();
        grafica->graph(3)->data()->clear(); // borra datos previamente guardados en el widget
        grafica->graph(3)->setPen(QPen(Qt::gray));
        grafica->graph(3)->setName("Posición de la Articulación 4.");

        grafica->addGraph();
        grafica->graph(4)->data()->clear(); // borra datos previamente guardados en el widget
        grafica->graph(4)->setPen(QPen(Qt::red));
        grafica->graph(4)->setName("Posición de la Articulación 5.");

        grafica->addGraph();
        grafica->graph(5)->data()->clear(); // borra datos previamente guardados en el widget
        grafica->graph(5)->setPen(QPen(Qt::green));
        grafica->graph(5)->setName("Posición de la Articulación 6.");

        if(ui->PosicionDeseadaRD->isChecked()){
            grafica->addGraph();
            grafica->graph(6)->data()->clear(); // borra datos previamente guardados en el widget
            grafica->graph(6)->setPen(QPen(Qt::darkCyan));
            grafica->graph(6)->setName("Posición Deseada 1.");

            grafica->addGraph();
            grafica->graph(7)->data()->clear(); // borra datos previamente guardados en el widget
            grafica->graph(7)->setPen(QPen(Qt::darkMagenta));
            grafica->graph(7)->setName("Posición Deseada 2.");

            grafica->addGraph();
            grafica->graph(8)->data()->clear(); // borra datos previamente guardados en el widget
            grafica->graph(8)->setPen(QPen(Qt::darkYellow));
            grafica->graph(8)->setName("Posición Deseada 3.");

            grafica->addGraph();
            grafica->graph(9)->data()->clear(); // borra datos previamente guardados en el widget
            grafica->graph(9)->setPen(QPen(Qt::darkGray));
            grafica->graph(9)->setName("Posición Deseada 4.");

            grafica->addGraph();
            grafica->graph(10)->data()->clear(); // borra datos previamente guardados en el widget
            grafica->graph(10)->setPen(QPen(Qt::darkRed));
            grafica->graph(10)->setName("Posición Deseada 5.");

            grafica->addGraph();
            grafica->graph(11)->data()->clear(); // borra datos previamente guardados en el widget
            grafica->graph(11)->setPen(QPen(Qt::darkGreen));
            grafica->graph(11)->setName("Posición Deseada 6.");
        }
        break;
    }
    if(TareaFinalizada){
        GraficarTrayectoria(index);
    }
    grafica->rescaleAxes();
    grafica->replot();
    //grafica->update();
}

void MainWindow::on_PosicionDeseadaRD_toggled(bool checked)
{
    ConfigurarGrafica(ui->ElegirGraficaCB->currentIndex());
}

void MainWindow::GraficarTrayectoria(int index){ // Funcion que grafica la señal despues de la acción
    QCustomPlot *grafica = ui->WidgetGrafica;
    switch (index) {
    case 0: // graficar q1
        grafica->graph(0)->setData(TiempoMilisegundosGrafica,TrayectoriaArticulacion1);
        if(ui->PosicionDeseadaRD->isChecked()){
            QVector<double> QD1(TiempoTotalMilisegundos,qd[0]);
            grafica->graph(1)->setData(TiempoMilisegundosGrafica,QD1);
        }
        break;
    case 1: // graficar q2
        grafica->graph(0)->setData(TiempoMilisegundosGrafica,TrayectoriaArticulacion2);
        if(ui->PosicionDeseadaRD->isChecked()){
            QVector<double> QD2(TiempoTotalMilisegundos,qd[1]);
            grafica->graph(1)->setData(TiempoMilisegundosGrafica,QD2);
        }
        break;
    case 2: // graficar q3
        grafica->graph(0)->setData(TiempoMilisegundosGrafica,TrayectoriaArticulacion3);
        if(ui->PosicionDeseadaRD->isChecked()){
            QVector<double> QD3(TiempoTotalMilisegundos,qd[2]);
            grafica->graph(1)->setData(TiempoMilisegundosGrafica,QD3);
        }
        break;
    case 3: // graficar q4
        grafica->graph(0)->setData(TiempoMilisegundosGrafica,TrayectoriaArticulacion4);
        if(ui->PosicionDeseadaRD->isChecked()){
            QVector<double> QD4(TiempoTotalMilisegundos,qd[3]);
            grafica->graph(1)->setData(TiempoMilisegundosGrafica,QD4);
        }
        break;
    case 4: // graficar q5
        grafica->graph(0)->setData(TiempoMilisegundosGrafica,TrayectoriaArticulacion5);
        if(ui->PosicionDeseadaRD->isChecked()){
            QVector<double> QD5(TiempoTotalMilisegundos,qd[4]);
            grafica->graph(1)->setData(TiempoMilisegundosGrafica,QD5);
        }
        break;
    case 5: // graficar q6
        grafica->graph(0)->setData(TiempoMilisegundosGrafica,TrayectoriaArticulacion6);
        if(ui->PosicionDeseadaRD->isChecked()){
            QVector<double> QD6(TiempoTotalMilisegundos,qd[5]);
            grafica->graph(1)->setData(TiempoMilisegundosGrafica,QD6);
        }
        break;
    case 6: // graficar todas las señales
        grafica->graph(0)->setData(TiempoMilisegundosGrafica,TrayectoriaArticulacion1);
        if(ui->PosicionDeseadaRD->isChecked()){
            QVector<double> QD1(TiempoTotalMilisegundos,qd[0]);
            QVector<double> QD2(TiempoTotalMilisegundos,qd[1]);
            QVector<double> QD3(TiempoTotalMilisegundos,qd[2]);
            QVector<double> QD4(TiempoTotalMilisegundos,qd[3]);
            QVector<double> QD5(TiempoTotalMilisegundos,qd[4]);
            QVector<double> QD6(TiempoTotalMilisegundos,qd[5]);
            grafica->graph(1)->setData(TiempoMilisegundosGrafica,QD1);
            grafica->graph(3)->setData(TiempoMilisegundosGrafica,QD2);
            grafica->graph(5)->setData(TiempoMilisegundosGrafica,QD3);
            grafica->graph(7)->setData(TiempoMilisegundosGrafica,QD4);
            grafica->graph(9)->setData(TiempoMilisegundosGrafica,QD5);
            grafica->graph(11)->setData(TiempoMilisegundosGrafica,QD6);
        }
        break;
    default:
        //error al graficar
        break;
    }
    grafica->rescaleAxes();
    grafica->replot();
    grafica->update();
}

void MainWindow::ActualizarGrafica(){ // Funcion que grafica la señal en tiempo real
    QCustomPlot *grafica = ui->WidgetGrafica;
    switch (ui->ElegirGraficaCB->currentIndex()) {
    case 0: // graficar q1
        TiempoMilisegundosGrafica.append(TiempoMilisegundosGrafica.isEmpty() ? 0 : TiempoMilisegundosGrafica.last() + FrecuenciaDeMuestreo); // si el vector está vacio se inicializa con 0, de lo contrario se usa el ultimo miembro y se le suma la frecuencia de muestreo
        //TrayectoriaArticulacion1.append();
        if(ui->PosicionDeseadaRD->isChecked()){

            //grafica->addGraph(0)->addData();
        }
        if(DatosMostrados < TiempoMilisegundosGrafica.size()){
            TiempoMilisegundosGrafica.removeFirst();
            TrayectoriaArticulacion1.removeFirst();
        }

        break;
    case 1: // graficar q2

        if(ui->PosicionDeseadaRD->isChecked()){

        }
        break;
    case 2: // graficar q3

        if(ui->PosicionDeseadaRD->isChecked()){

        }
        break;
    case 3: // graficar q4

        if(ui->PosicionDeseadaRD->isChecked()){

        }
        break;
    case 4: // graficar q5

        if(ui->PosicionDeseadaRD->isChecked()){

        }
        break;
    case 5: // graficar q6

        if(ui->PosicionDeseadaRD->isChecked()){

        }
        break;
    case 6: // graficar todas las señales

        if(ui->PosicionDeseadaRD->isChecked()){

        }
        break;
    default:
        //error al graficar
        break;
    }
    grafica->rescaleAxes();
    grafica->replot();
}

void MainWindow::on_GuardarTrayectoriaPB_clicked()
{

}

//---------------------------------------------------------------------------------------------------------------------------------------------------

// MenuBar Frame
//---------------------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_actionKinova_Gen_3_Lite_User_Manual_triggered()
{
    QDesktopServices::openUrl(QUrl::fromLocalFile(qApp->applicationDirPath()+"/"+"Gen3_lite_USER_GUIDE.pdf"));
    //ui->MostrarErrores->setText(qApp->applicationDirPath());
}

void MainWindow::on_actionControl_IV_Class_Notes_triggered()
{
    QDesktopServices::openUrl(QUrl::fromLocalFile(qApp->applicationDirPath()+"/"+"Manual Control IV.pdf"));
}
//---------------------------------------------------------------------------------------------------------------------------------------------------






