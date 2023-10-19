#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDesktopServices>
#include <qvector.h>

// Robot Control Simulation Libraries
#include "Controls.h"
#include "Dynamics.h"
#include "Robot.h"
#include "Simulation.h"

//------------------------------------------------------------------------------------------------

//bool Go=false; // bandera para el boton de iniciar

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

// Global Objects

Robot<1> bot("r" , &robot::singlePendulum); // Crear robot

Control<1> ctrl(&gravity::singlePendulum); // Crear controlador

// Gloabal Control Variables

int segundos=0; // Tiempo seleccionado para la acción del Robot
double deltaT=0.001; // Periodo de tiempo de acción
int TiempoTotal= 0;

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

bool banderaPID=false; // bandera para activar ganancias Ki
bool banderaVirtual=false; // bandera para activar las ganancias que inyectan amortiguamiento virtual


//------------------------------------------------------------------------------------------------

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

    // Default Robot values
    bot.q[0] = 0; // Position
    bot.qp[0] = 0; // Valocity
    bot.tau[0] = 0; // Torque

}

MainWindow::~MainWindow()
{
    delete ui;
}

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

void MainWindow::on_IniciarPB_clicked()
{
    PausarUI();
    //--------------------------------------------
    ui->ProgresoPBar->setVisible(true);
    ui->ScreenRunStop->setCurrentIndex(1);

    // Simulation
    Sim<1> sim(&bot , &ctrl);

    sim.Time = segundos*h_; // Tiempo en milisegundos
    sim.S = 100; // Muestras

    sim.Cycle(); // Ejecutar simulación


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

void MainWindow::on_GuardarTrayectoriaPB_clicked()
{

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
    PlayUI();

    ui->ScreenRunStop->setCurrentIndex(0);
}

void MainWindow::on_CambiarControlPB_clicked()
{
    if(ControlActivadoBoton){
        ui->label_ControlSelected->setText(ui->ControlSelectCB->currentText());
        ui->CambiarControlPB->setText("Cambiar Control");
        ui->ControlSelectCB->setEnabled(false);

        Controlador(0);// funcion que dependiendo el controlador muestra las etiquetas de Ki o mc

        /*Index del ComboBox
         *0->PD + Cancelación de Gravedad
         *1->PD + Compensación de Gravedad
         *2->P'D' + Cancelación de Gravedad
         *3->P'D' + Compensación de Gravedad
         *4->sPsD + Cancelación de Gravedad
         *5->sPsD + Compensación de Gravedad
         *6->sPs'D' + Cancelación de Gravedad
         *7->sPs'D' + Compensación de Gravedad
         */

        // Switch Case Controlador
        switch(ui->ControlSelectCB->currentIndex()){ // Checa el controlador
        case 0:
            ctrl.controler = _PD_canG_;
            break;
        case 1:
            ctrl.controler = _PD_comG_;
            break;
        case 2:
            ctrl.controler = _P_d_canG_;
            break;
        case 3:
            ctrl.controler = _P_d_comG_;
            break;
        default:
            ctrl.controler = _canG_;
            break;
        }

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
            segundos=ui->TiempoSB->value();
            ui->ScreenTiempo->setCurrentIndex(0);
            ui->label_Segundos->setText(QString::number(segundos));
            TiempoActivado=true;
            TiempoActivadoBoton=false;
            TiempoTotal= segundos / deltaT;
            ui->MostrarErrores->setText(QString::number(TiempoTotal));
        }else{ //Error, numero igual a 0
            QMessageBox::warning(this,tr("Error!"),tr("El tiempo seleccionado no es correcto"));
            ui->MostrarErrores->append("El tiempo: " +QString::number(ui->TiempoSB->value())+", no es un valor valido");
        }
    }else{
        ui->CambiarTiempoPB->setText("Guardar");
        ui->ScreenTiempo->setCurrentIndex(1);
        ui->TiempoSB->setValue(segundos);
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

void MainWindow::on_ActivarGraficasPB_clicked()
{

    if(GraficasActivadoBoton){ //se desactivan las graficas
        ui->ActivarGraficasPB->setText("Activar Gráficas");
        ui->Plots->resize(1881,51);

        ui->GraficasTiempoRealRB->setEnabled(false);
        ui->GraficasDespuesRB->setEnabled(false);
        ui->GraficasDespuesRB->setChecked(false);
        ui->GraficasTiempoRealRB->setVisible(false);
        ui->GraficasDespuesRB->setVisible(false);

        GraficasActivadoBoton=false;
    }else{ //activamos las graficas
        ui->ActivarGraficasPB->setText("Desactivar Gráficas");
        ui->Plots->resize(1881,481);
        SetGrafica();
        if(ui->SimulacionRB->isChecked())//activa las opciones de simulación
        {
            ui->GraficasTiempoRealRB->setVisible(false);
            ui->GraficasDespuesRB->setVisible(false);
            ui->ScreenGrafica->setCurrentIndex(0);
            PlotSignals(ui->ElegirGraficaSimCB->currentIndex());
        }
        else if(ui->CorrerRobotRB->isChecked()) //activa las opciones de acción real
        {

            ui->GraficasTiempoRealRB->setVisible(true);
            ui->GraficasDespuesRB->setVisible(true);
            ui->GraficasTiempoRealRB->setEnabled(true);
            ui->GraficasDespuesRB->setEnabled(true);
            ui->GraficasDespuesRB->setChecked(true);

            if(ui->GraficasDespuesRB->isChecked()) //activa las graficas si se seleccionó graficar despues
            {
                ui->ScreenGrafica->setCurrentIndex(1);
                PlotSignals(ui->ElegirGraficaCB->currentIndex());
            }
            else if(ui->GraficasTiempoRealRB->isChecked()) //activa las graficas de tiempo real
            {
                ui->ScreenGrafica->setCurrentIndex(2);
                PlotSignals(ui->ElegirGraficaTrCB->currentIndex());
            }
        }

        GraficasActivadoBoton=true;
    }
}

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

        ctrl.qd[0] = qd[0]*PI/180; // Controler desired position

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

void MainWindow::on_actionKinova_Gen_3_Lite_User_Manual_triggered()
{
    QDesktopServices::openUrl(QUrl::fromLocalFile(qApp->applicationDirPath()+"/"+"Gen3_lite_USER_GUIDE.pdf"));
    //ui->MostrarErrores->setText(qApp->applicationDirPath());
}

void MainWindow::on_actionControl_IV_Class_Notes_triggered()
{
    QDesktopServices::openUrl(QUrl::fromLocalFile(qApp->applicationDirPath()+"/"+"Manual Control IV.pdf"));
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

        ctrl.K1[0] = kc[0]; // Controler gain
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

    // Controler Gains
    ctrl.P[0] = kp[0];
    ctrl.D[0] = kd[0];
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

void MainWindow::SetGrafica(){

    //int TiempoTotal= segundos / deltaT;

    QFont legendFont = font();  // start out with MainWindow's font.
    legendFont.setPointSize(9); // and make a bit smaller for legend

    if(ui->ScreenGrafica->currentIndex()==0){
        ui->grafica0->legend->setVisible(true);
        ui->grafica0->legend->setFont(legendFont);
        ui->grafica0->legend->setBrush(QBrush(QColor(255,255,255,230)));
        // by default, the legend is in the inset layout of the main axis rect. So this is how we access it to change legend placement:

        ui->grafica0->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignBottom|Qt::AlignRight);
        ui->grafica0->xAxis->setLabel("Tiempo");
        ui->grafica0->xAxis->setRange(0,TiempoTotal);
        ui->grafica0->yAxis->setLabel("Rotación de la articulación (deg°)");
        ui->grafica0->yAxis->setRange(-155,155);
        ui->grafica0->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables); //  Plottables are selectable (e.g. graphs, curves, bars,... see QCPAbstractPlottable) tbd

        ui->grafica0->rescaleAxes(); // funciones que hacen update a la gráfica
        ui->grafica0->replot();
        ui->grafica0->update();

    }else if(ui->ScreenGrafica->currentIndex()==1){
        ui->grafica1->legend->setVisible(true);
        ui->grafica1->legend->setFont(legendFont);
        ui->grafica1->legend->setBrush(QBrush(QColor(255,255,255,230)));
        // by default, the legend is in the inset layout of the main axis rect. So this is how we access it to change legend placement:

        ui->grafica1->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignBottom|Qt::AlignRight);
        ui->grafica1->xAxis->setLabel("Tiempo");
        ui->grafica1->xAxis->setRange(0,TiempoTotal);
        ui->grafica1->yAxis->setLabel("Rotación de la articulación (deg°)");
        ui->grafica1->yAxis->setRange(-155,155);
        ui->grafica1->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables); //  Plottables are selectable (e.g. graphs, curves, bars,... see QCPAbstractPlottable) tbd

        ui->grafica1->rescaleAxes(); // funciones que hacen update a la gráfica
        ui->grafica1->replot();
        ui->grafica1->update();

    }else if(ui->ScreenGrafica->currentIndex()==2){
        ui->grafica2->legend->setVisible(true);
        ui->grafica2->legend->setFont(legendFont);
        ui->grafica2->legend->setBrush(QBrush(QColor(255,255,255,230)));
        // by default, the legend is in the inset layout of the main axis rect. So this is how we access it to change legend placement:

        ui->grafica2->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignBottom|Qt::AlignRight);
        ui->grafica2->xAxis->setLabel("Tiempo");
        ui->grafica2->xAxis->setRange(0,TiempoTotal);
        ui->grafica2->yAxis->setLabel("Rotación de la articulación (deg°)");
        ui->grafica2->yAxis->setRange(-155,155);
        ui->grafica2->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables); //  Plottables are selectable (e.g. graphs, curves, bars,... see QCPAbstractPlottable) tbd

        ui->grafica2->rescaleAxes(); // funciones que hacen update a la gráfica
        ui->grafica2->replot();
        ui->grafica2->update();
    }


}

void MainWindow::on_GraficasDespuesRB_toggled(bool checked)
{
    if(checked){
        ui->ScreenGrafica->setCurrentIndex(1);
        //SetGrafica();
        /*
        if(TareaFinalizada){
            SetGrafica();
        }else{

        }
        */
    }else{
        if(ui->GraficasTiempoRealRB->isChecked()){
            ui->ScreenGrafica->setCurrentIndex(2);
            //SetGrafica();
        }else{

        }
    }

}

void MainWindow::on_ElegirGraficaCB_currentIndexChanged(int index)
{
    PlotSignals(index);
}

void MainWindow::on_ElegirGraficaSimCB_currentIndexChanged(int index)
{
    PlotSignals(index);
}

void MainWindow::on_ElegirGraficaTrCB_currentIndexChanged(int index)
{
    PlotSignals(index);
}

void MainWindow::on_SimulacionRB_toggled(bool checked)
{
    if(checked){
        //poner en la pantalla de simulación

        ui->ScreenGrafica->setCurrentIndex(0);
        /*
        ui->GraficasTiempoRealRB->setEnabled(false);
        ui->GraficasDespuesRB->setEnabled(false);
        ui->GraficasDespuesRB->setChecked(false);
        ui->GraficasTiempoRealRB->setVisible(false);
        ui->GraficasDespuesRB->setVisible(false);
        */
        //SetGrafica();

    }else{
        if(ui->CorrerRobotRB->isChecked()){
            //poner en la pantalla de accion real
            ui->ScreenGrafica->setCurrentIndex(1);
            /*
            ui->GraficasTiempoRealRB->setVisible(true);
            ui->GraficasDespuesRB->setVisible(true);
            ui->GraficasTiempoRealRB->setEnabled(true);
            ui->GraficasDespuesRB->setEnabled(true);
            ui->GraficasDespuesRB->setChecked(true);
            */
            //SetGrafica();

        }else{
        //no esta accionado ningun RB
        }
    }
}

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

void MainWindow::PlotSignals(int index)
{

    if(ui->ScreenGrafica->currentIndex()==0){//Simulacion
        /*
        ui->grafica0->graph(0)->data()->clear();
        ui->grafica0->graph(1)->data()->clear();
        ui->grafica0->graph(2)->data()->clear();
        ui->grafica0->graph(3)->data()->clear();
        ui->grafica0->graph(4)->data()->clear();
        ui->grafica0->graph(5)->data()->clear();
        ui->grafica0->graph(6)->data()->clear();
        ui->grafica0->graph(7)->data()->clear();
        ui->grafica0->graph(8)->data()->clear();
        ui->grafica0->graph(9)->data()->clear();
        ui->grafica0->graph(10)->data()->clear();
        ui->grafica0->graph(11)->data()->clear();
*/

        ui->grafica0->replot();
        ui->grafica0->update();

        switch (index) {
        case 0: //q1
            ui->grafica0->addGraph();
            ui->grafica0->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica0->graph(0)->setPen(QPen(Qt::cyan));
            ui->grafica0->graph(0)->setName("Posición de la Articulación 1.");
            break;
        case 1: //q1 qd1
            ui->grafica0->addGraph();
            ui->grafica0->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica0->graph(0)->setPen(QPen(Qt::cyan));
            ui->grafica0->graph(0)->setName("Posición de la Articulación 1.");
            ui->grafica0->addGraph();
            ui->grafica0->graph(1)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica0->graph(1)->setPen(QPen(Qt::darkCyan));
            ui->grafica0->graph(1)->setName("Posición Deseada 1.");
            break;
        case 2: //q2
            ui->grafica0->addGraph();
            ui->grafica0->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica0->graph(0)->setPen(QPen(Qt::magenta));
            ui->grafica0->graph(0)->setName("Posición de la Articulación 2.");
            break;
        case 3: //q2 qd2
            ui->grafica0->addGraph();
            ui->grafica0->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica0->graph(0)->setPen(QPen(Qt::magenta));
            ui->grafica0->graph(0)->setName("Posición de la Articulación 2.");
            ui->grafica0->addGraph();
            ui->grafica0->graph(1)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica0->graph(1)->setPen(QPen(Qt::darkMagenta));
            ui->grafica0->graph(1)->setName("Posición Deseada 2.");
            break;
        case 4: //q3
            ui->grafica0->addGraph();
            ui->grafica0->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica0->graph(0)->setPen(QPen(Qt::yellow));
            ui->grafica0->graph(0)->setName("Posición de la Articulación 3.");
            break;
        case 5: //q3 qd3
            ui->grafica0->addGraph();
            ui->grafica0->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica0->graph(0)->setPen(QPen(Qt::yellow));
            ui->grafica0->graph(0)->setName("Posición de la Articulación 3.");
            ui->grafica0->addGraph();
            ui->grafica0->graph(1)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica0->graph(1)->setPen(QPen(Qt::darkYellow));
            ui->grafica0->graph(1)->setName("Posición Deseada 3.");
            break;
        case 6: //q4
            ui->grafica0->addGraph();
            ui->grafica0->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica0->graph(0)->setPen(QPen(Qt::gray));
            ui->grafica0->graph(0)->setName("Posición de la Articulación 4.");
            break;
        case 7: //q4 qd4
            ui->grafica0->addGraph();
            ui->grafica0->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica0->graph(0)->setPen(QPen(Qt::gray));
            ui->grafica0->graph(0)->setName("Posición de la Articulación 4.");
            ui->grafica0->addGraph();
            ui->grafica0->graph(1)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica0->graph(1)->setPen(QPen(Qt::darkGray));
            ui->grafica0->graph(1)->setName("Posición Deseada 4.");
            break;
        case 8: //q5
            ui->grafica0->addGraph();
            ui->grafica0->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica0->graph(0)->setPen(QPen(Qt::red));
            ui->grafica0->graph(0)->setName("Posición de la Articulación 5.");
            break;
        case 9: //q5 qd5
            ui->grafica0->addGraph();
            ui->grafica0->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica0->graph(0)->setPen(QPen(Qt::red));
            ui->grafica0->graph(0)->setName("Posición de la Articulación 5.");
            ui->grafica0->addGraph();
            ui->grafica0->graph(1)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica0->graph(1)->setPen(QPen(Qt::darkRed));
            ui->grafica0->graph(1)->setName("Posición Deseada 5.");
            break;
        case 10: //q6
            ui->grafica0->addGraph();
            ui->grafica0->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica0->graph(0)->setPen(QPen(Qt::green));
            ui->grafica0->graph(0)->setName("Posición de la Articulación 6.");
            break;
        case 11: //q6 qd6
            ui->grafica0->addGraph();
            ui->grafica0->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica0->graph(0)->setPen(QPen(Qt::green));
            ui->grafica0->graph(0)->setName("Posición de la Articulación 6.");
            ui->grafica0->addGraph();
            ui->grafica0->graph(1)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica0->graph(1)->setPen(QPen(Qt::darkGreen));
            ui->grafica0->graph(1)->setName("Posición Deseada 6.");
            break;
        case 12: //all current positions
            ui->grafica0->addGraph();
            ui->grafica0->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica0->graph(0)->setPen(QPen(Qt::cyan));
            ui->grafica0->graph(0)->setName("Posición de la Articulación 1.");
            ui->grafica0->addGraph();
            ui->grafica0->graph(1)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica0->graph(1)->setPen(QPen(Qt::magenta));
            ui->grafica0->graph(1)->setName("Posición de la Articulación 2.");
            ui->grafica0->addGraph();
            ui->grafica0->graph(2)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica0->graph(2)->setPen(QPen(Qt::yellow));
            ui->grafica0->graph(2)->setName("Posición de la Articulación 3.");
            ui->grafica0->addGraph();
            ui->grafica0->graph(3)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica0->graph(3)->setPen(QPen(Qt::gray));
            ui->grafica0->graph(3)->setName("Posición de la Articulación 4.");
            ui->grafica0->addGraph();
            ui->grafica0->graph(4)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica0->graph(4)->setPen(QPen(Qt::red));
            ui->grafica0->graph(4)->setName("Posición de la Articulación 5.");
            ui->grafica0->addGraph();
            ui->grafica0->graph(5)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica0->graph(5)->setPen(QPen(Qt::green));
            ui->grafica0->graph(5)->setName("Posición de la Articulación 6.");
            break;
        case 13: //all signals
            ui->grafica0->addGraph();
            ui->grafica0->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica0->graph(0)->setPen(QPen(Qt::cyan));
            ui->grafica0->graph(0)->setName("Posición de la Articulación 1.");
            ui->grafica0->addGraph();
            ui->grafica0->graph(1)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica0->graph(1)->setPen(QPen(Qt::darkCyan));
            ui->grafica0->graph(1)->setName("Posición Deseada 1.");
            ui->grafica0->addGraph();
            ui->grafica0->graph(2)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica0->graph(2)->setPen(QPen(Qt::magenta));
            ui->grafica0->graph(2)->setName("Posición de la Articulación 2.");
            ui->grafica0->addGraph();
            ui->grafica0->graph(3)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica0->graph(3)->setPen(QPen(Qt::darkMagenta));
            ui->grafica0->graph(3)->setName("Posición Deseada 2.");
            ui->grafica0->addGraph();
            ui->grafica0->graph(4)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica0->graph(4)->setPen(QPen(Qt::yellow));
            ui->grafica0->graph(4)->setName("Posición de la Articulación 3.");
            ui->grafica0->addGraph();
            ui->grafica0->graph(5)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica0->graph(5)->setPen(QPen(Qt::darkYellow));
            ui->grafica0->graph(5)->setName("Posición Deseada 3.");
            ui->grafica0->addGraph();
            ui->grafica0->graph(6)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica0->graph(6)->setPen(QPen(Qt::gray));
            ui->grafica0->graph(6)->setName("Posición de la Articulación 4.");
            ui->grafica0->addGraph();
            ui->grafica0->graph(7)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica0->graph(7)->setPen(QPen(Qt::darkGray));
            ui->grafica0->graph(7)->setName("Posición Deseada 4.");
            ui->grafica0->addGraph();
            ui->grafica0->graph(8)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica0->graph(8)->setPen(QPen(Qt::red));
            ui->grafica0->graph(8)->setName("Posición de la Articulación 5.");
            ui->grafica0->addGraph();
            ui->grafica0->graph(9)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica0->graph(9)->setPen(QPen(Qt::darkRed));
            ui->grafica0->graph(9)->setName("Posición Deseada 5.");
            ui->grafica0->addGraph();
            ui->grafica0->graph(10)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica0->graph(10)->setPen(QPen(Qt::green));
            ui->grafica0->graph(10)->setName("Posición de la Articulación 6.");
            ui->grafica0->addGraph();
            ui->grafica0->graph(11)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica0->graph(11)->setPen(QPen(Qt::darkGreen));
            ui->grafica0->graph(11)->setName("Posición Deseada 6.");
            break;
        default: //error

            break;
        }
        ui->grafica0->rescaleAxes();
        ui->grafica0->replot();
        ui->grafica0->update();

    }else if(ui->ScreenGrafica->currentIndex()==1){//Despues
        ui->grafica1->graph(0)->data()->clear();
        ui->grafica1->graph(1)->data()->clear();
        ui->grafica1->graph(2)->data()->clear();
        ui->grafica1->graph(3)->data()->clear();
        ui->grafica1->graph(4)->data()->clear();
        ui->grafica1->graph(5)->data()->clear();
        ui->grafica1->graph(6)->data()->clear();
        ui->grafica1->graph(7)->data()->clear();
        ui->grafica1->graph(8)->data()->clear();
        ui->grafica1->graph(9)->data()->clear();
        ui->grafica1->graph(10)->data()->clear();
        ui->grafica1->graph(11)->data()->clear();

        ui->grafica1->replot();
        ui->grafica1->update();

        switch (index) {
        case 0: //q1
            ui->grafica1->addGraph();
            ui->grafica1->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica1->graph(0)->setPen(QPen(Qt::cyan));
            ui->grafica1->graph(0)->setName("Posición de la Articulación 1.");
            break;
        case 1: //q1 qd1
            ui->grafica1->addGraph();
            ui->grafica1->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica1->graph(0)->setPen(QPen(Qt::cyan));
            ui->grafica1->graph(0)->setName("Posición de la Articulación 1.");
            ui->grafica1->addGraph();
            ui->grafica1->graph(1)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica1->graph(1)->setPen(QPen(Qt::darkCyan));
            ui->grafica1->graph(1)->setName("Posición Deseada 1.");
            break;
        case 2: //q2
            ui->grafica1->addGraph();
            ui->grafica1->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica1->graph(0)->setPen(QPen(Qt::magenta));
            ui->grafica1->graph(0)->setName("Posición de la Articulación 2.");
            break;
        case 3: //q2 qd2
            ui->grafica1->addGraph();
            ui->grafica1->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica1->graph(0)->setPen(QPen(Qt::magenta));
            ui->grafica1->graph(0)->setName("Posición de la Articulación 2.");
            ui->grafica1->addGraph();
            ui->grafica1->graph(1)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica1->graph(1)->setPen(QPen(Qt::darkMagenta));
            ui->grafica1->graph(1)->setName("Posición Deseada 2.");
            break;
        case 4: //q3
            ui->grafica1->addGraph();
            ui->grafica1->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica1->graph(0)->setPen(QPen(Qt::yellow));
            ui->grafica1->graph(0)->setName("Posición de la Articulación 3.");
            break;
        case 5: //q3 qd3
            ui->grafica1->addGraph();
            ui->grafica1->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica1->graph(0)->setPen(QPen(Qt::yellow));
            ui->grafica1->graph(0)->setName("Posición de la Articulación 3.");
            ui->grafica1->addGraph();
            ui->grafica1->graph(1)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica1->graph(1)->setPen(QPen(Qt::darkYellow));
            ui->grafica1->graph(1)->setName("Posición Deseada 3.");
            break;
        case 6: //q4
            ui->grafica1->addGraph();
            ui->grafica1->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica1->graph(0)->setPen(QPen(Qt::gray));
            ui->grafica1->graph(0)->setName("Posición de la Articulación 4.");
            break;
        case 7: //q4 qd4
            ui->grafica1->addGraph();
            ui->grafica1->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica1->graph(0)->setPen(QPen(Qt::gray));
            ui->grafica1->graph(0)->setName("Posición de la Articulación 4.");
            ui->grafica1->addGraph();
            ui->grafica1->graph(1)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica1->graph(1)->setPen(QPen(Qt::darkGray));
            ui->grafica1->graph(1)->setName("Posición Deseada 4.");
            break;
        case 8: //q5
            ui->grafica1->addGraph();
            ui->grafica1->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica1->graph(0)->setPen(QPen(Qt::red));
            ui->grafica1->graph(0)->setName("Posición de la Articulación 5.");
            break;
        case 9: //q5 qd5
            ui->grafica1->addGraph();
            ui->grafica1->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica1->graph(0)->setPen(QPen(Qt::red));
            ui->grafica1->graph(0)->setName("Posición de la Articulación 5.");
            ui->grafica1->addGraph();
            ui->grafica1->graph(1)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica1->graph(1)->setPen(QPen(Qt::darkRed));
            ui->grafica1->graph(1)->setName("Posición Deseada 5.");
            break;
        case 10: //q6
            ui->grafica1->addGraph();
            ui->grafica1->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica1->graph(0)->setPen(QPen(Qt::green));
            ui->grafica1->graph(0)->setName("Posición de la Articulación 6.");
            break;
        case 11: //q6 qd6
            ui->grafica1->addGraph();
            ui->grafica1->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica1->graph(0)->setPen(QPen(Qt::green));
            ui->grafica1->graph(0)->setName("Posición de la Articulación 6.");
            ui->grafica1->addGraph();
            ui->grafica1->graph(1)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica1->graph(1)->setPen(QPen(Qt::darkGreen));
            ui->grafica1->graph(1)->setName("Posición Deseada 6.");
            break;
        case 12: //all current positions
            ui->grafica1->addGraph();
            ui->grafica1->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica1->graph(0)->setPen(QPen(Qt::cyan));
            ui->grafica1->graph(0)->setName("Posición de la Articulación 1.");
            ui->grafica1->addGraph();
            ui->grafica1->graph(1)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica1->graph(1)->setPen(QPen(Qt::magenta));
            ui->grafica1->graph(1)->setName("Posición de la Articulación 2.");
            ui->grafica1->addGraph();
            ui->grafica1->graph(2)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica1->graph(2)->setPen(QPen(Qt::yellow));
            ui->grafica1->graph(2)->setName("Posición de la Articulación 3.");
            ui->grafica1->addGraph();
            ui->grafica1->graph(3)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica1->graph(3)->setPen(QPen(Qt::gray));
            ui->grafica1->graph(3)->setName("Posición de la Articulación 4.");
            ui->grafica1->addGraph();
            ui->grafica1->graph(4)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica1->graph(4)->setPen(QPen(Qt::red));
            ui->grafica1->graph(4)->setName("Posición de la Articulación 5.");
            ui->grafica1->addGraph();
            ui->grafica1->graph(5)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica1->graph(5)->setPen(QPen(Qt::green));
            ui->grafica1->graph(5)->setName("Posición de la Articulación 6.");
            break;
        case 13: //all signals
            ui->grafica1->addGraph();
            ui->grafica1->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica1->graph(0)->setPen(QPen(Qt::cyan));
            ui->grafica1->graph(0)->setName("Posición de la Articulación 1.");
            ui->grafica1->addGraph();
            ui->grafica1->graph(1)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica1->graph(1)->setPen(QPen(Qt::darkCyan));
            ui->grafica1->graph(1)->setName("Posición Deseada 1.");
            ui->grafica1->addGraph();
            ui->grafica1->graph(2)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica1->graph(2)->setPen(QPen(Qt::magenta));
            ui->grafica1->graph(2)->setName("Posición de la Articulación 2.");
            ui->grafica1->addGraph();
            ui->grafica1->graph(3)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica1->graph(3)->setPen(QPen(Qt::darkMagenta));
            ui->grafica1->graph(3)->setName("Posición Deseada 2.");
            ui->grafica1->addGraph();
            ui->grafica1->graph(4)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica1->graph(4)->setPen(QPen(Qt::yellow));
            ui->grafica1->graph(4)->setName("Posición de la Articulación 3.");
            ui->grafica1->addGraph();
            ui->grafica1->graph(5)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica1->graph(5)->setPen(QPen(Qt::darkYellow));
            ui->grafica1->graph(5)->setName("Posición Deseada 3.");
            ui->grafica1->addGraph();
            ui->grafica1->graph(6)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica1->graph(6)->setPen(QPen(Qt::gray));
            ui->grafica1->graph(6)->setName("Posición de la Articulación 4.");
            ui->grafica1->addGraph();
            ui->grafica1->graph(7)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica1->graph(7)->setPen(QPen(Qt::darkGray));
            ui->grafica1->graph(7)->setName("Posición Deseada 4.");
            ui->grafica1->addGraph();
            ui->grafica1->graph(8)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica1->graph(8)->setPen(QPen(Qt::red));
            ui->grafica1->graph(8)->setName("Posición de la Articulación 5.");
            ui->grafica1->addGraph();
            ui->grafica1->graph(9)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica1->graph(9)->setPen(QPen(Qt::darkRed));
            ui->grafica1->graph(9)->setName("Posición Deseada 5.");
            ui->grafica1->addGraph();
            ui->grafica1->graph(10)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica1->graph(10)->setPen(QPen(Qt::green));
            ui->grafica1->graph(10)->setName("Posición de la Articulación 6.");
            ui->grafica1->addGraph();
            ui->grafica1->graph(11)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica1->graph(11)->setPen(QPen(Qt::darkGreen));
            ui->grafica1->graph(11)->setName("Posición Deseada 6.");
            break;
        default: //error

            break;
        }
        ui->grafica1->rescaleAxes();
        ui->grafica1->replot();
        ui->grafica1->update();

    }else if(ui->ScreenGrafica->currentIndex()==2){//TR
        ui->grafica2->graph(0)->data()->clear();
        ui->grafica2->graph(1)->data()->clear();
        ui->grafica2->graph(2)->data()->clear();
        ui->grafica2->graph(3)->data()->clear();
        ui->grafica2->graph(4)->data()->clear();
        ui->grafica2->graph(5)->data()->clear();
        ui->grafica2->graph(6)->data()->clear();
        ui->grafica2->graph(7)->data()->clear();
        ui->grafica2->graph(8)->data()->clear();
        ui->grafica2->graph(9)->data()->clear();
        ui->grafica2->graph(10)->data()->clear();
        ui->grafica2->graph(11)->data()->clear();

        ui->grafica2->replot();
        ui->grafica2->update();

        switch (index) {
        case 0: //q1
            ui->grafica2->addGraph();
            ui->grafica2->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica2->graph(0)->setPen(QPen(Qt::cyan));
            ui->grafica2->graph(0)->setName("Posición de la Articulación 1.");
            break;
        case 1: //q1 qd1
            ui->grafica2->addGraph();
            ui->grafica2->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica2->graph(0)->setPen(QPen(Qt::cyan));
            ui->grafica2->graph(0)->setName("Posición de la Articulación 1.");
            ui->grafica2->addGraph();
            ui->grafica2->graph(1)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica2->graph(1)->setPen(QPen(Qt::darkCyan));
            ui->grafica2->graph(1)->setName("Posición Deseada 1.");
            break;
        case 2: //q2
            ui->grafica2->addGraph();
            ui->grafica2->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica2->graph(0)->setPen(QPen(Qt::magenta));
            ui->grafica2->graph(0)->setName("Posición de la Articulación 2.");
            break;
        case 3: //q2 qd2
            ui->grafica2->addGraph();
            ui->grafica2->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica2->graph(0)->setPen(QPen(Qt::magenta));
            ui->grafica2->graph(0)->setName("Posición de la Articulación 2.");
            ui->grafica2->addGraph();
            ui->grafica2->graph(1)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica2->graph(1)->setPen(QPen(Qt::darkMagenta));
            ui->grafica2->graph(1)->setName("Posición Deseada 2.");
            break;
        case 4: //q3
            ui->grafica2->addGraph();
            ui->grafica2->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica2->graph(0)->setPen(QPen(Qt::yellow));
            ui->grafica2->graph(0)->setName("Posición de la Articulación 3.");
            break;
        case 5: //q3 qd3
            ui->grafica2->addGraph();
            ui->grafica2->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica2->graph(0)->setPen(QPen(Qt::yellow));
            ui->grafica2->graph(0)->setName("Posición de la Articulación 3.");
            ui->grafica2->addGraph();
            ui->grafica2->graph(1)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica2->graph(1)->setPen(QPen(Qt::darkYellow));
            ui->grafica2->graph(1)->setName("Posición Deseada 3.");
            break;
        case 6: //q4
            ui->grafica2->addGraph();
            ui->grafica2->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica2->graph(0)->setPen(QPen(Qt::gray));
            ui->grafica2->graph(0)->setName("Posición de la Articulación 4.");
            break;
        case 7: //q4 qd4
            ui->grafica2->addGraph();
            ui->grafica2->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica2->graph(0)->setPen(QPen(Qt::gray));
            ui->grafica2->graph(0)->setName("Posición de la Articulación 4.");
            ui->grafica2->addGraph();
            ui->grafica2->graph(1)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica2->graph(1)->setPen(QPen(Qt::darkGray));
            ui->grafica2->graph(1)->setName("Posición Deseada 4.");
            break;
        case 8: //q5
            ui->grafica2->addGraph();
            ui->grafica2->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica2->graph(0)->setPen(QPen(Qt::red));
            ui->grafica2->graph(0)->setName("Posición de la Articulación 5.");
            break;
        case 9: //q5 qd5
            ui->grafica2->addGraph();
            ui->grafica2->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica2->graph(0)->setPen(QPen(Qt::red));
            ui->grafica2->graph(0)->setName("Posición de la Articulación 5.");
            ui->grafica2->addGraph();
            ui->grafica2->graph(1)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica2->graph(1)->setPen(QPen(Qt::darkRed));
            ui->grafica2->graph(1)->setName("Posición Deseada 5.");
            break;
        case 10: //q6
            ui->grafica2->addGraph();
            ui->grafica2->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica2->graph(0)->setPen(QPen(Qt::green));
            ui->grafica2->graph(0)->setName("Posición de la Articulación 6.");
            break;
        case 11: //q6 qd6
            ui->grafica2->addGraph();
            ui->grafica2->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica2->graph(0)->setPen(QPen(Qt::green));
            ui->grafica2->graph(0)->setName("Posición de la Articulación 6.");
            ui->grafica2->addGraph();
            ui->grafica2->graph(1)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica2->graph(1)->setPen(QPen(Qt::darkGreen));
            ui->grafica2->graph(1)->setName("Posición Deseada 6.");
            break;
        case 12: //all current positions
            ui->grafica2->addGraph();
            ui->grafica2->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica2->graph(0)->setPen(QPen(Qt::cyan));
            ui->grafica2->graph(0)->setName("Posición de la Articulación 1.");
            ui->grafica2->addGraph();
            ui->grafica2->graph(1)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica2->graph(1)->setPen(QPen(Qt::magenta));
            ui->grafica2->graph(1)->setName("Posición de la Articulación 2.");
            ui->grafica2->addGraph();
            ui->grafica2->graph(2)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica2->graph(2)->setPen(QPen(Qt::yellow));
            ui->grafica2->graph(2)->setName("Posición de la Articulación 3.");
            ui->grafica2->addGraph();
            ui->grafica2->graph(3)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica2->graph(3)->setPen(QPen(Qt::gray));
            ui->grafica2->graph(3)->setName("Posición de la Articulación 4.");
            ui->grafica2->addGraph();
            ui->grafica2->graph(4)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica2->graph(4)->setPen(QPen(Qt::red));
            ui->grafica2->graph(4)->setName("Posición de la Articulación 5.");
            ui->grafica2->addGraph();
            ui->grafica2->graph(5)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica2->graph(5)->setPen(QPen(Qt::green));
            ui->grafica2->graph(5)->setName("Posición de la Articulación 6.");
            break;
        case 13: //all signals
            ui->grafica2->addGraph();
            ui->grafica2->graph(0)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica2->graph(0)->setPen(QPen(Qt::cyan));
            ui->grafica2->graph(0)->setName("Posición de la Articulación 1.");
            ui->grafica2->addGraph();
            ui->grafica2->graph(1)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica2->graph(1)->setPen(QPen(Qt::darkCyan));
            ui->grafica2->graph(1)->setName("Posición Deseada 1.");
            ui->grafica2->addGraph();
            ui->grafica2->graph(2)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica2->graph(2)->setPen(QPen(Qt::magenta));
            ui->grafica2->graph(2)->setName("Posición de la Articulación 2.");
            ui->grafica2->addGraph();
            ui->grafica2->graph(3)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica2->graph(3)->setPen(QPen(Qt::darkMagenta));
            ui->grafica2->graph(3)->setName("Posición Deseada 2.");
            ui->grafica2->addGraph();
            ui->grafica2->graph(4)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica2->graph(4)->setPen(QPen(Qt::yellow));
            ui->grafica2->graph(4)->setName("Posición de la Articulación 3.");
            ui->grafica2->addGraph();
            ui->grafica2->graph(5)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica2->graph(5)->setPen(QPen(Qt::darkYellow));
            ui->grafica2->graph(5)->setName("Posición Deseada 3.");
            ui->grafica2->addGraph();
            ui->grafica2->graph(6)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica2->graph(6)->setPen(QPen(Qt::gray));
            ui->grafica2->graph(6)->setName("Posición de la Articulación 4.");
            ui->grafica2->addGraph();
            ui->grafica2->graph(7)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica2->graph(7)->setPen(QPen(Qt::darkGray));
            ui->grafica2->graph(7)->setName("Posición Deseada 4.");
            ui->grafica2->addGraph();
            ui->grafica2->graph(8)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica2->graph(8)->setPen(QPen(Qt::red));
            ui->grafica2->graph(8)->setName("Posición de la Articulación 5.");
            ui->grafica2->addGraph();
            ui->grafica2->graph(9)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica2->graph(9)->setPen(QPen(Qt::darkRed));
            ui->grafica2->graph(9)->setName("Posición Deseada 5.");
            ui->grafica2->addGraph();
            ui->grafica2->graph(10)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica2->graph(10)->setPen(QPen(Qt::green));
            ui->grafica2->graph(10)->setName("Posición de la Articulación 6.");
            ui->grafica2->addGraph();
            ui->grafica2->graph(11)->data()->clear(); // borra datos previamente guardados en el widget
            ui->grafica2->graph(11)->setPen(QPen(Qt::darkGreen));
            ui->grafica2->graph(11)->setName("Posición Deseada 6.");
            break;
        default: //error

            break;
        }
        ui->grafica2->rescaleAxes();
        ui->grafica2->replot();
        ui->grafica2->update();
    }else{ //nada

    }


}




void MainWindow::on_ControlSelectCB_activated(int index)
{

}

