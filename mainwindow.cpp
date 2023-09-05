#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

//bool Go=false; // bandera para el boton de iniciar

//Banderas para iniciar la acción del robot--------------------
bool RobotConectado=false;
bool GananciasActivado=false;
bool TiempoActivado=false;
bool ControlActivado=false;
//bool banderaPausa=false;
bool PosicionDeseada=false;
bool GraficasActivado=false;
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

double Maxkp[6];   // Valores maximos para las Ganancias Kp
double Maxki[6];   // Valores maximos para las Ganancias Ki
double Maxkd[6];   // Valores maximos para las Ganancias Kd

double Mc=0; //Valor de la masa virtual del controlador

double q[6];    // Coordenadas generalizadas del Robot (deg)
long double q_rad[6]; // Posicion actual en radianes

double qd[6];  // Coordenadas generalizadas de la posición deseada (deg)
long double qd_rad[6]; // Posicion deseada en radianes

bool banderaPID=false; // bandera para activar ganancias Ki

//Selector={"BorrarTodo", "BorrarLabelsGanancias", "BorrarSpinBoxGanancias", "BorrarLabelsTiempo", "BorrarSpinBoxTiempo", "BorrarLabelsQd", "BorrarSpinBoxQd","BorrarGraficas"};
//Lista de opciones para la función Labels, la cual activa o desactiva partes de la interfaz

//añadir detener ui a la funcion labels


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Kinova Gen3 Lite");
    MainWindow::setWindowState(Qt::WindowMaximized);
    //SET stretch max and min
    Labels("BorrarTodo");
    ui->PlayPausePB->setDisabled(true);
    ui->StopPB->setVisible(false);
    ui->GuardarTrayectoriaPB->setDisabled(true);
    ui->Graficas_checkBox->setDisabled(true);
    ui->ControlSelect->setEnabled(false);
    //ui->Graficas_checkBox->setDisabled(true);
    //Labels("BorrarTodo");


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ConectarPB_clicked()
{

    //conectar robot

    //activar interfaz
    ui->ConectarPB->setVisible(false);
    ui->ConeccionCB->setChecked(true);
    ui->ConeccionCB->setEnabled(false);
    QMessageBox::information(this,tr("Robot Conectado"),tr("Conección exitosa con el robot"));

    // agregar controladores
    ui->ControlSelect->addItem("PD + Cancelación de Gravedad");
    ui->ControlSelect->addItem("PD + Compensación de Gravedad");
    ui->ControlSelect->addItem("P'D' + Cancelación de Gravedad");
    ui->ControlSelect->addItem("P'D' + Compensación de Gravedad");
    ui->ControlSelect->addItem("sPsD + Cancelación de Gravedad");
    ui->ControlSelect->addItem("sPsD + Compensación de Gravedad");
    ui->ControlSelect->addItem("sPs'D' + Cancelación de Gravedad");
    ui->ControlSelect->addItem("sPs'D' + Compensación de Gravedad");

    Labels("ActivarTodo");
    ui->ControlSelect->setVisible(false);
    ui->label_ControlSelected->setText("Seleccione un controlador");

    RobotConectado=true;
}


void MainWindow::on_PlayPausePB_clicked()
{
    ui->Graficas_checkBox->setDisabled(true);
    if(banderaPausaBoton){
        ui->PlayPausePB->setText("Continuar");
        banderaPausaBoton=false;
    }else{
        Labels("Detener");
        ui->StopPB->setVisible(true);
        ui->StopPB->setEnabled(true);
        ui->PlayPausePB->setText("Pausar");
        //banderaPausaBoton=true;
        //Robot();
        banderaPausaBoton=true;
    }
    Robot();
}


void MainWindow::on_StopPB_clicked()
{
    Labels("Continuar");
    ui->PlayPausePB->setText("Iniciar");
    ui->Graficas_checkBox->setEnabled(true);
    ui->StopPB->setVisible(false);
    banderaPausaBoton=false;
    StopTotal=true;
}


void MainWindow::on_Graficas_checkBox_stateChanged(int arg1)
{
    if(arg1==2){
        Labels("ActivarGraficas");
        //agregar opciones a combo box de las graficas
        ui->ElegirGraficaCB->addItem("Posición de la Articulación 1");
        ui->ElegirGraficaCB->addItem("Posición de la Articulación 2");
        ui->ElegirGraficaCB->addItem("Posición de la Articulación 3");
        ui->ElegirGraficaCB->addItem("Posición de la Articulación 4");
        ui->ElegirGraficaCB->addItem("Posición de la Articulación 5");
        ui->ElegirGraficaCB->addItem("Posición de la Articulación 6");
        ui->ElegirGraficaCB->addItem("Posición deseada 1");
        ui->ElegirGraficaCB->addItem("Posición deseada 2");
        ui->ElegirGraficaCB->addItem("Posición deseada 3");
        ui->ElegirGraficaCB->addItem("Posición deseada 4");
        ui->ElegirGraficaCB->addItem("Posición deseada 5");
        ui->ElegirGraficaCB->addItem("Posición deseada 6");
        //GraficasActivado=true;
    }else if(arg1==0){
        Labels("BorrarGraficas");
        //GraficasActivado=false;
    }else{
        QMessageBox::warning(this,tr("Error!"),tr("Hay un error en las gráficas, Error 02"));
        ui->MostrarErrores->append("Hay un error en las gráficas");
    }
}


void MainWindow::on_GuardarTrayectoriaPB_clicked()
{

}


void MainWindow::on_cambiarGainsPB_clicked()
{
    if(GananciasActivadoBoton){
        ui->cambiarGainsPB->setText("Cambiar Ganancias");

        kp[0]= ui->kp1SB->value();
        kp[1]= ui->kp2SB->value();
        kp[2]= ui->kp3SB->value();
        kp[3]= ui->kp4SB->value();
        kp[4]= ui->kp5SB->value();
        kp[5]= ui->kp6SB->value();
        //ki[0]= ui->ki1SB->value();
        //ki[1]= ui->ki2SB->value();
        //ki[2]= ui->ki3SB->value();
        //ki[3]= ui->ki4SB->value();
        //ki[4]= ui->ki5SB->value();
        //ki[5]= ui->ki6SB->value();
        kd[0]= ui->kd1SB->value();
        kd[1]= ui->kd2SB->value();
        kd[2]= ui->kd3SB->value();
        kd[3]= ui->kd4SB->value();
        kd[4]= ui->kd5SB->value();
        kd[5]= ui->kd6SB->value();


        Labels("BorrarSpinBoxGanancias");
        Labels("ActivarLabelsGanancias");
        GananciasActivado=true;
        GananciasActivadoBoton=false;

    }else{
        if(ControlActivado==false){//elegir controlador previamente
            QMessageBox::warning(this,tr("Error!"),tr("Por favor seleccione un controlador."));
            ui->MostrarErrores->append("No hay un controlador seleccionado");
        }else{
            Labels("BorrarLabelsGanancias");
            Labels("ActivarSpinBoxGanancias");

            ui->cambiarGainsPB->setText("Guardar");

            GananciasActivado=false;
            GananciasActivadoBoton=true;
        }

    }
    if(GananciasActivado && ControlActivado && TiempoActivado && PosicionDeseada){ // Chequeo de banderas para activar el boton de iniciar
        ui->PlayPausePB->setEnabled(true);
    }else{
        ui->PlayPausePB->setEnabled(false);
    }

}


void MainWindow::on_CambiarControlPB_clicked()
{
    if(ControlActivadoBoton){
        ui->label_ControlSelected->setText(ui->ControlSelect->currentText());
        ui->CambiarControlPB->setText("Cambiar Control");
        ui->ControlSelect->setEnabled(false);
        ui->LabelsGainsLabels->setVisible(true);
        Labels("ActivarLabelsGanancias");
        ControlActivado=true;
        ControlActivadoBoton=false;
    }else{
        ui->CambiarControlPB->setText("Guardar");
        ui->ControlSelect->setVisible(true);
        ui->ControlSelect->setEnabled(true);
        ControlActivado=false;
        ControlActivadoBoton=true;
    }
    if(GananciasActivado && ControlActivado && TiempoActivado && PosicionDeseada){ // Chequeo de banderas para activar el boton de iniciar
        ui->PlayPausePB->setEnabled(true);
    }else{
        ui->PlayPausePB->setEnabled(false);
    }
}


void MainWindow::on_CambiarTiempoPB_clicked()
{
    if(TiempoActivadoBoton){
        if((ui->TiempoValueSB->value())!=0){// comprobando que el tiempo no sea igual a 0
            ui->CambiarTiempoPB->setText("Cambiar Tiempo");
            segundos=ui->TiempoValueSB->value();
            Labels("ActivarLabelsTiempo");
            Labels("BorrarSpinBoxTiempo");
            ui->label_Tiempo->setText(QString::number(segundos));
            TiempoActivado=true;
            TiempoActivadoBoton=false;
        }else{ //Error, numero igual a 0
            QMessageBox::warning(this,tr("Error!"),tr("El tiempo seleccionado no es correcto"));
            ui->MostrarErrores->append("El tiempo: " +QString::number(ui->TiempoValueSB->value())+" no es correcto");
        }
    }else{
        ui->CambiarTiempoPB->setText("Guardar");
        Labels("BorrarLabelsTiempo");
        Labels("ActivarSpinBoxTiempo");
        ui->TiempoValueSB->setValue(segundos);
        TiempoActivado=false;
        TiempoActivadoBoton=true;
    }
    if(GananciasActivado && ControlActivado && TiempoActivado && PosicionDeseada){ // Chequeo de banderas para activar el boton de iniciar
        ui->PlayPausePB->setEnabled(true);
    }else{
        ui->PlayPausePB->setEnabled(false);
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

        Labels("ActivarLabelsQd");
        Labels("BorrarSpinBoxQd");

        ui->CambiarQdPB->setText("Cambiar Posición Deseada");
        ui->PosPackPB->setDisabled(false);
        ui->PosZeroPB->setDisabled(false);
        PosicionDeseada=true;
        PosicionDeseadaBoton=false;
    }else{
        Labels("BorrarLabelsQd");
        Labels("ActivarSpinBoxQd");
        ui->PosPackPB->setDisabled(true);
        ui->PosZeroPB->setDisabled(true);

        ui->CambiarQdPB->setText("Guardar");
        PosicionDeseada=false;
        PosicionDeseadaBoton=true;
    }
    if(GananciasActivado && ControlActivado && TiempoActivado && PosicionDeseada){ // Chequeo de banderas para activar el boton de iniciar
        ui->PlayPausePB->setEnabled(true);
    }else{
        ui->PlayPausePB->setEnabled(false);
    }
}


void MainWindow::on_PosPackPB_clicked()
{
    //check if it's not the position it is already in
    qd[0]=0;
    qd[1]=0;
    qd[2]=0;
    qd[3]=0;
    qd[4]=0;
    qd[5]=0;
    PosicionDeseada=true;
    Labels("ActivarLabelsQd");
}


void MainWindow::on_PosZeroPB_clicked()
{
    //check if it's not the position it is already in
    for (int i = 0; i < 6; i++) {
        qd[i]=0;
    }
    PosicionDeseada=true;
    Labels("ActivarLabelsQd");
}


void MainWindow::on_radioButton_clicked(bool checked)
{

}


void MainWindow::on_AgregarGraficaPB_clicked()
{

}


void MainWindow::on_EliminarGraficaPB_clicked()
{

}

void MainWindow::Robot()
{

    double size= segundos / deltaT;
    int size2 = size;
    ui->ProgresoPBar->reset();
    ui->ProgresoPBar->setMinimum(0);
    ui->ProgresoPBar->setMaximum(size);
    double Time[ size2 ];
    int i=0;
    for (i = 0; i < size2; i++) {
        ui->ProgresoPBar->setValue(i+1);
        /*
        if(banderaPausaBoton){  //botonPausa
            if(StopTotal){  //Stop Total se activo el boton de detener
                break;
            }
        }
        */
    }
    if(i == size2){ // se acabó la simulación
        ui->StopPB->setEnabled(false);
        ui->PlayPausePB->setText("Iniciar");
        Labels("Continuar");
        ui->GuardarTrayectoriaPB->setVisible(true);
        ui->GuardarTrayectoriaPB->setEnabled(true);
    }
}

void MainWindow::Labels(QString Selected)
{
    /*Opciones Borrar:
     * "BorrarTodo", "BorrarLabelsGanancias", "BorrarSpinBoxGanancias", "BorrarLabelsTiempo", "BorrarSpinBoxTiempo", "BorrarLabelsQd", "BorrarSpinBoxQd","BorrarGraficas"
     *
     *
     *Opciones Activar:
     * "ActivarTodo", "ActivarLabelsGanancias", "ActivarSpinBoxGanancias", "ActivarLabelsTiempo", "ActivarSpinBoxTiempo", "ActivarLabelsQd", "ActivarSpinBoxQd","ActivarGraficas"
     *
     */
    //Opciones Borrar:---------------------------------------------------------------------------------------------------------
    if (Selected == "BorrarTodo")    {
        //----------------------------------------------------------------------------- Borrar
        //BorraGraficas
        ui->GuardarTrayectoriaPB->setVisible(false);
        ui->label_Graficas->setVisible(false);
        ui->grafica1->setVisible(false);
        ui->grafica2->setVisible(false);
        ui->AgregarGraficaPB->setVisible(false);
        ui->EliminarGraficaPB->setVisible(false);
        ui->ElegirGraficaCB->setVisible(false);
        ui->GraficasTiempoRealRB->setVisible(false);

        //-----------------------------------------------
        //BorraControl/Tiempo
        ui->ControlScreenCB->setVisible(false);
        ui->label_ControlSelected->setVisible(false);
        ui->CambiarControlPB->setVisible(false);

        ui->TiempoAccion->setVisible(false);
        ui->TiempoValueSB->setVisible(false);
        ui->CambiarTiempoPB->setVisible(false);
        //-------------------------------------------
        //BorraGanancias

        ui->LabelsGainsActuators->setVisible(false); //labels del actuador y controlador
        ui->GainScreenInputSB->setVisible(false); // spin boxes
        ui->LabelsGainsLabels->setVisible(false); //labels valor ganancias
        ui->mcvalueSB->setVisible(false); //spinbox mc

        ui->label_mc->setVisible(false); //label mc

        ui->label_mcvalue->setVisible(false);//label value of mc

        ui->cambiarGainsPB->setVisible(false); //push button de cambiar ganancias

        ui->label_ControlSelected->setText(""); //borrar el texto del controlador seleccionado

        //-----------------------------------------
        //BorraPosiciones

        ui->PosRobotLabels->setVisible(false);
        ui->QScreenLabels->setVisible(false);  //borra las etiquetas de la posición del robot


        ui->PosDeseadaRobotLabels->setVisible(false);
        ui->QdScreenLabels->setVisible(false); //borra las etiquetas de posición deseada del robot
        ui->QdSreenInputSB->setVisible(false); //borra los spinbox de qd

        ui->ChangePosScreenButtons->setVisible(false); // borra los botones para cambiar qd
        //---------------------------------------------------
        // ...
    }else if (Selected == "BorrarLabelsGanancias")    {

        // ...
        ui->LabelsGainsLabels->setVisible(false); //labels valor ganancias
        //ui->label_ControlSelected->setText(""); //borrar el texto del controlador seleccionado
        if(ui->ControlSelect->currentText()=="P'D' + Cancelación de Gravedad"||ui->ControlSelect->currentText()=="P'D' + Compensación de Gravedad"||ui->ControlSelect->currentText()=="sPs'D' + Cancelación de Gravedad"||ui->ControlSelect->currentText()=="sPs'D' + Compensación de Gravedad"){
            ui->label_mcvalue->setVisible(false);
        }

    }else if (Selected == "BorrarSpinBoxGanancias")    {
        // ...
        ui->GainScreenInputSB->setVisible(false);
        if(ui->ControlSelect->currentText()=="P'D' + Cancelación de Gravedad"||ui->ControlSelect->currentText()=="P'D' + Compensación de Gravedad"||ui->ControlSelect->currentText()=="sPs'D' + Cancelación de Gravedad"||ui->ControlSelect->currentText()=="sPs'D' + Compensación de Gravedad"){
            ui->mcvalueSB->setVisible(false);
        }
    }else if (Selected == "BorrarLabelsTiempo")    {
        // ...
        ui->label_Tiempo->setVisible(false);
    }else if (Selected == "BorrarSpinBoxTiempo")    {
        // ...
        ui->TiempoValueSB->setVisible(false);
    }else if (Selected == "BorrarLabelsQd")    {
        // ...
        ui->QdScreenLabels->setVisible(false);

    }else if (Selected == "BorrarSpinBoxQd")    {
        // ...
        ui->QdSreenInputSB->setVisible(false);
    }else if (Selected == "BorrarGraficas")    {
        // ...
        ui->label_Graficas->setVisible(false);
        ui->grafica1->setVisible(false);
        ui->grafica2->setVisible(false);
        ui->AgregarGraficaPB->setVisible(false);
        ui->EliminarGraficaPB->setVisible(false);
        ui->ElegirGraficaCB->setVisible(false);
        ui->GraficasTiempoRealRB->setVisible(false);
    }//------------------------------------------------------------------------------------------------------------------------- Activar
    else if (Selected == "ActivarTodo")    {
        // ...
        ui->ControlScreenCB->setVisible(true);
        ui->label_ControlSelected->setVisible(true);
        ui->CambiarControlPB->setVisible(true);
        ui->Graficas_checkBox->setDisabled(false);

        ui->TiempoAccion->setVisible(true);
        ui->CambiarTiempoPB->setVisible(true);

        ui->LabelsGainsActuators->setVisible(true); //labels del actuador y controlador
        ui->LabelsGainsLabels->setVisible(true); //labels valor ganancias

        ui->cambiarGainsPB->setVisible(true); //push button de cambiar ganancias

        ui->PosRobotLabels->setVisible(true);
        ui->QScreenLabels->setVisible(true);  //borra las etiquetas de la posición del robot


        ui->PosDeseadaRobotLabels->setVisible(true);
        ui->QdScreenLabels->setVisible(true); //borra las etiquetas de posición deseada del robot
        ui->ChangePosScreenButtons->setVisible(true);

    }else if (Selected == "ActivarLabelsGanancias")    {
        // ...
        ui->LabelsGainsLabels->setVisible(true); //labels valor ganancias
        ui->label_FirstG->setText("Kp");
        ui->label_kp1->setText(QString::number(kp[0]));
        ui->label_kp2->setText(QString::number(kp[1]));
        ui->label_kp3->setText(QString::number(kp[2]));
        ui->label_kp4->setText(QString::number(kp[3]));
        ui->label_kp5->setText(QString::number(kp[4]));
        ui->label_kp6->setText(QString::number(kp[5]));
        /*
        ui->label_SecondG->setText("Ki");
        ui->label_ki1->setText(QString::number(ki[0]));
        ui->label_ki2->setText(QString::number(ki[1]));
        ui->label_ki3->setText(QString::number(ki[2]));
        ui->label_ki4->setText(QString::number(ki[3]));
        ui->label_ki5->setText(QString::number(ki[4]));
        ui->label_ki6->setText(QString::number(ki[5]));
        */
        ui->label_ThirdG->setText("Kd");
        ui->label_kd1->setText(QString::number(kd[0]));
        ui->label_kd2->setText(QString::number(kd[1]));
        ui->label_kd3->setText(QString::number(kd[2]));
        ui->label_kd4->setText(QString::number(kd[3]));
        ui->label_kd5->setText(QString::number(kd[4]));
        ui->label_kd6->setText(QString::number(kd[5]));
        if(ui->ControlSelect->currentText()=="P'D' + Cancelación de Gravedad"||ui->ControlSelect->currentText()=="P'D' + Compensación de Gravedad"||ui->ControlSelect->currentText()=="sPs'D' + Cancelación de Gravedad"||ui->ControlSelect->currentText()=="sPs'D' + Compensación de Gravedad"){
            ui->label_mc->setVisible(true);
            ui->label_mcvalue->setVisible(true);
            ui->label_mcvalue->setText(QString::number(Mc));
        }

    }else if (Selected == "ActivarSpinBoxGanancias")    {
        // ...
        ui->GainScreenInputSB->setVisible(true);
        if(banderaPID==false){
            ui->ki1SB->setVisible(false);
            ui->ki2SB->setVisible(false);
            ui->ki3SB->setVisible(false);
            ui->ki4SB->setVisible(false);
            ui->ki5SB->setVisible(false);
            ui->ki6SB->setVisible(false);
        }
        ui->label_FirstG->setText("Kp");
        ui->kp1SB->setValue(kp[0]);
        ui->kp2SB->setValue(kp[1]);
        ui->kp3SB->setValue(kp[2]);
        ui->kp4SB->setValue(kp[3]);
        ui->kp5SB->setValue(kp[4]);
        ui->kp6SB->setValue(kp[5]);
        //ui->ki1SB->setValue(ki[0]);
        //ui->ki2SB->setValue(ki[1]);
        //ui->ki3SB->setValue(ki[2]);
        //ui->ki4SB->setValue(ki[3]);
        //ui->ki5SB->setValue(ki[4]);
        //ui->ki6SB->setValue(ki[5]);
        ui->label_ThirdG->setText("Kd");
        ui->kd1SB->setValue(kd[0]);
        ui->kd2SB->setValue(kd[1]);
        ui->kd3SB->setValue(kd[2]);
        ui->kd4SB->setValue(kd[3]);
        ui->kd5SB->setValue(kd[4]);
        ui->kd6SB->setValue(kd[5]);
        if(ui->ControlSelect->currentText()=="P'D' + Cancelación de Gravedad"||ui->ControlSelect->currentText()=="P'D' + Compensación de Gravedad"||ui->ControlSelect->currentText()=="sPs'D' + Cancelación de Gravedad"||ui->ControlSelect->currentText()=="sPs'D' + Compensación de Gravedad"){
            ui->label_mc->setVisible(true);
            ui->mcvalueSB->setVisible(true);
        }

    }else if (Selected == "ActivarLabelsTiempo")    {
        // ...
        ui->label_Tiempo->setVisible(true);

    }else if (Selected == "ActivarSpinBoxTiempo")    {
        // ...
        ui->TiempoValueSB->setVisible(true);

    }else if (Selected == "ActivarLabelsQd")    {
        // ...
        ui->QdScreenLabels->setVisible(true); //Activa las etiquetas de los valores de las ganancias

        ui->label_posqd1->setText(QString::number(qd[0])); //Cambia el valor en las etiquetas por los valores guardados
        ui->label_posqd2->setText(QString::number(qd[1]));
        ui->label_posqd3->setText(QString::number(qd[2]));
        ui->label_posqd4->setText(QString::number(qd[3]));
        ui->label_posqd5->setText(QString::number(qd[4]));
        ui->label_posqd6->setText(QString::number(qd[5]));


    }else if (Selected == "ActivarSpinBoxQd")    {
        // ...
        ui->QdSreenInputSB->setVisible(true);

        ui->qd1SB->setValue(qd[0]);
        ui->qd2SB->setValue(qd[1]);
        ui->qd3SB->setValue(qd[2]);
        ui->qd4SB->setValue(qd[3]);
        ui->qd5SB->setValue(qd[4]);
        ui->qd6SB->setValue(qd[5]);

    }else if (Selected == "ActivarGraficas")    {
        // ...
        ui->label_Graficas->setVisible(true);
        ui->grafica1->setVisible(true);
        ui->grafica2->setVisible(true);
        ui->AgregarGraficaPB->setVisible(true);
        ui->EliminarGraficaPB->setVisible(true);
        ui->ElegirGraficaCB->setVisible(true);
        ui->GraficasTiempoRealRB->setVisible(true);

    }else if(Selected == "Detener"){
        ui->CambiarTiempoPB->setDisabled(true);
        ui->CambiarControlPB->setDisabled(true);
        ui->ChangePosScreenButtons->setDisabled(true);
        ui->cambiarGainsPB->setDisabled(true);

    }else if(Selected == "Continuar"){
        ui->CambiarTiempoPB->setDisabled(false);
        ui->CambiarControlPB->setDisabled(false);
        ui->ChangePosScreenButtons->setDisabled(false);
        ui->cambiarGainsPB->setDisabled(false);

    }//-------------------------------------------------------------------------------------------------------------------------
    else{
        QMessageBox::warning(this,tr("Error en el programa"),tr("Hubo un error a la hora de correr el programa. Error: 01"));
    }
}
