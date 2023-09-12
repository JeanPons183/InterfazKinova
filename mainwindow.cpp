#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDesktopServices>

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

int segundos=0; // Tiempo seleccionado para la acción del Robot
double deltaT=0.001; // Periodo de tiempo de acción

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
    ui->Plots->resize(1901,21);

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
        ui->Plots->resize(1901,51);

        ui->RunMode->setVisible(true); // se despliega el Run mode
        ui->SimulacionRB->setChecked(true); // por defecto se usa el modo simulación

        ui->ActivarGraficasPB->setVisible(true); // se activa el boton que permite graficar

        ui->label_Estado->setVisible(true);    // se despliegan las etiquetas del estado del robot
        ui->label_EstadoActual->setVisible(true);
        ui->label_EstadoActual->setText("Stand by");
        ui->label_119->setVisible(true);
        ui->label_ControlSelected->setVisible(true);

        //ui->label_IP->setText("IP");

        //deshabilitamos funciones
        ui->ControlSelectCB->addItem("PD + Cancelación de Gravedad");
        ui->ControlSelectCB->addItem("PD + Compensación de Gravedad");
        ui->ControlSelectCB->addItem("P'D' + Cancelación de Gravedad");
        ui->ControlSelectCB->addItem("P'D' + Compensación de Gravedad");
        ui->ControlSelectCB->addItem("sPsD + Cancelación de Gravedad");
        ui->ControlSelectCB->addItem("sPsD + Compensación de Gravedad");
        ui->ControlSelectCB->addItem("sPs'D' + Cancelación de Gravedad");
        ui->ControlSelectCB->addItem("sPs'D' + Compensación de Gravedad");
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
    //--------------------------------------------
    ui->ProgresoPBar->setVisible(true);
    ui->RunStop->setCurrentIndex(1);

    //Funcion del Robot();

}


void MainWindow::on_PausePB_clicked()
{
    //Mantener posición o pausar, no sé cual funcione
    ui->RunStop->setCurrentIndex(2);
}

void MainWindow::on_ContinuarPB_clicked()
{
    //Reanudar la acción
    ui->RunStop->setCurrentIndex(1);
}

void MainWindow::on_StopPB_clicked()
{
    //Detener todo
    ui->RunStop->setCurrentIndex(3);
}


void MainWindow::on_StopPB_2_clicked()
{
    //tener una señal que se conecte con los dos botones de STOP
    ui->RunStop->setCurrentIndex(3);
}


void MainWindow::on_RegresarPB_clicked()
{
    //Dejar que te permita hacer otra prueba
    ui->RunStop->setCurrentIndex(0);
}


void MainWindow::on_GuardarTrayectoriaPB_clicked()
{

}


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
            segundos=ui->TiempoSB->value();
            ui->ScreenTiempo->setCurrentIndex(0);
            ui->label_Segundos->setText(QString::number(segundos));
            TiempoActivado=true;
            TiempoActivadoBoton=false;
        }else{ //Error, numero igual a 0
            QMessageBox::warning(this,tr("Error!"),tr("El tiempo seleccionado no es correcto"));
            ui->MostrarErrores->append("El tiempo: " +QString::number(ui->TiempoSB->value())+" no es un valor valido");
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
}


void MainWindow::on_ActivarGraficasPB_clicked()
{
    if(GraficasActivadoBoton){
        ui->ActivarGraficasPB->setText("Activar Gráficas");
        ui->Plots->resize(1901,51);
        ui->GraficasTiempoRealRB->setVisible(false);
        ui->GraficasDespuesRB->setVisible(false);
        GraficasActivadoBoton=false;
    }else{
        ui->ActivarGraficasPB->setText("Desactivar Gráficas");
        ui->Plots->resize(1901,541);
        ui->GraficasTiempoRealRB->setVisible(true);
        ui->GraficasDespuesRB->setVisible(true);
        ui->GraficasDespuesRB->setChecked(true);
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

    ui->label_posqd1->setText(QString::number(qd[0]));
    ui->label_posqd2->setText(QString::number(qd[1]));
    ui->label_posqd3->setText(QString::number(qd[2]));
    ui->label_posqd4->setText(QString::number(qd[3]));
    ui->label_posqd5->setText(QString::number(qd[4]));
    ui->label_posqd6->setText(QString::number(qd[5]));

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

    ui->label_posqd1->setText(QString::number(qd[0]));
    ui->label_posqd2->setText(QString::number(qd[1]));
    ui->label_posqd3->setText(QString::number(qd[2]));
    ui->label_posqd4->setText(QString::number(qd[3]));
    ui->label_posqd5->setText(QString::number(qd[4]));
    ui->label_posqd6->setText(QString::number(qd[5]));

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

        //Checar rangos de las posiciones y por singularidades

        ui->ScreenQd->setCurrentIndex(0);

        ui->label_posqd1->setText(QString::number(qd[0])); //Cambia el valor en las etiquetas por los valores guardados
        ui->label_posqd2->setText(QString::number(qd[1]));
        ui->label_posqd3->setText(QString::number(qd[2]));
        ui->label_posqd4->setText(QString::number(qd[3]));
        ui->label_posqd5->setText(QString::number(qd[4]));
        ui->label_posqd6->setText(QString::number(qd[5]));
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
    QDesktopServices::openUrl(QUrl::fromLocalFile(qApp->applicationDirPath()+"/"+"Gen3_lite_USER_GUIDE_R03.pdf"));
    //ui->MostrarErrores->setText(qApp->applicationDirPath());
}


void MainWindow::on_actionControl_IV_Class_Notes_triggered()
{
    QDesktopServices::openUrl(QUrl::fromLocalFile(qApp->applicationDirPath()+"/"+"Manual Control IV_v17-01-22.pdf"));
}


void MainWindow::on_AgregarGraficaPB_clicked()
{

}


void MainWindow::on_EliminarGraficaPB_clicked()
{

}

void MainWindow::Controlador(int select) // selector te permite seleccionar la pantalla de etiquetas o la pantalla de SpinBox, valor 0 o 1
{

    // Juntar ifs con operador or || para cortar código

    ui->ScreenGains->setVisible(true);
    ui->cambiarGainsPB->setVisible(true);

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
    ui->ki6SB->setVisible(false); // se desactivan las pertenencias de Ki

    if((ui->label_ControlSelected->text())=="PD + Cancelación de Gravedad"){
        banderaVirtual=false;
        ui->Screenmc->setVisible(false);
        ui->ScreenvirtualGains->setVisible(false);
        ui->label_Masavirtual->setVisible(false);
        if(select){
            ui->ScreenGains->setCurrentIndex(1);

        }else{ // Cero es la pantalla de etiquetas

            ui->ScreenGains->setCurrentIndex(0);
        }
    }else if((ui->label_ControlSelected->text())=="PD + Compensación de Gravedad"){
        banderaVirtual=false;
        ui->Screenmc->setVisible(false);
        ui->ScreenvirtualGains->setVisible(false);
        ui->label_Masavirtual->setVisible(false);
        if(select){
            ui->ScreenGains->setCurrentIndex(1);
        }else{ // Cero es la pantalla de etiquetas
            ui->ScreenGains->setCurrentIndex(0);
        }
    }else if((ui->label_ControlSelected->text())=="P'D' + Cancelación de Gravedad"){
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
    }else if((ui->label_ControlSelected->text())=="P'D' + Compensación de Gravedad"){
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
    }else if((ui->label_ControlSelected->text())=="sPsD + Cancelación de Gravedad"){
        banderaVirtual=false;
        ui->Screenmc->setVisible(false);
        ui->ScreenvirtualGains->setVisible(false);
        ui->label_Masavirtual->setVisible(false);
        if(select){
            ui->ScreenGains->setCurrentIndex(1);
        }else{ // Cero es la pantalla de etiquetas
            ui->ScreenGains->setCurrentIndex(0);
        }
    }else if((ui->label_ControlSelected->text())=="sPsD + Compensación de Gravedad"){
        banderaVirtual=false;
        ui->Screenmc->setVisible(false);
        ui->ScreenvirtualGains->setVisible(false);
        ui->label_Masavirtual->setVisible(false);
        if(select){
            ui->ScreenGains->setCurrentIndex(1);
        }else{ // Cero es la pantalla de etiquetas
            ui->ScreenGains->setCurrentIndex(0);
        }
    }else if((ui->label_ControlSelected->text())=="sPs'D' + Cancelación de Gravedad"){
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
    }else if((ui->label_ControlSelected->text())=="sPs'D' + Compensación de Gravedad"){
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
    }
    kp[0]= ui->kp1SB->value();
    kp[1]= ui->kp2SB->value();
    kp[2]= ui->kp3SB->value();
    kp[3]= ui->kp4SB->value();
    kp[4]= ui->kp5SB->value();
    kp[5]= ui->kp6SB->value();
    //--------------------------------
    /*
    ki[0]= ui->ki1SB->value();
    ki[1]= ui->ki2SB->value();
    ki[2]= ui->ki3SB->value();
    ki[3]= ui->ki4SB->value();
    ki[4]= ui->ki5SB->value();
    ki[5]= ui->ki6SB->value();
    */
    //--------------------------------
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

    //--------------------------------
    /*
    ui->ki1SB->setValue(ki[0]);
    ui->ki2SB->setValue(ki[1]);
    ui->ki3SB->setValue(ki[2]);
    ui->ki4SB->setValue(ki[3]);
    ui->ki5SB->setValue(ki[4]);
    ui->ki6SB->setValue(ki[5]);
    */
    //--------------------------------

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





