#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDesktopServices>
#include <iostream>
#include <qvector.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //Configuración Inicial de la Ventana Principal------------------------------------------------------------------------------------------------------
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //---------------------------------------------------------------------------------------------------------------------------------------------------

private slots:

    // Configuración de la ventana Frame
    //---------------------------------------------------------------------------------------------------------------------------------------------------
    void PausarUI();

    void PlayUI();

    void Controlador(int select);
    //---------------------------------------------------------------------------------------------------------------------------------------------------

    // Robot Settings Frame
    //---------------------------------------------------------------------------------------------------------------------------------------------------
    void on_CambiarControlPB_clicked();

    void on_CambiarTiempoPB_clicked();
    //---------------------------------------------------------------------------------------------------------------------------------------------------

    // Ganancias Frame
    //---------------------------------------------------------------------------------------------------------------------------------------------------
    void on_cambiarGainsPB_clicked();

    void SaveValues();

    void SetValues();
    //---------------------------------------------------------------------------------------------------------------------------------------------------

    // Posicion Frame
    //---------------------------------------------------------------------------------------------------------------------------------------------------
    void on_PosZeroPB_clicked();

    void on_PosHomePB_clicked();

    void on_PosPackPB_clicked();

    void on_CambiarQdPB_clicked();
    //---------------------------------------------------------------------------------------------------------------------------------------------------

    // Ejecucion Frame
    //---------------------------------------------------------------------------------------------------------------------------------------------------
    void on_IniciarPB_clicked();

    void on_StopPB_clicked();

    void on_CancelarGravedadPB_clicked();

    void on_RegresarZeroPB_clicked();

    void on_FinalizarPB_clicked();

    void on_FinalizarPB_2_clicked();

    void on_AccionTerminadaRB_toggled(bool checked);

    void on_regresarMenuPB_clicked();

    /*
    void Temporizador();
    //---------------------------------------------------------------------------------------------------------------------------------------------------

    //Graficas Frame
    //---------------------------------------------------------------------------------------------------------------------------------------------------
    void on_ActivarGraficasPB_clicked();

    void CrearGrafica();

    void ConfigurarGrafica(int index);

    void GraficarTrayectoria(int index);

    void on_PosicionDeseadaRD_toggled(bool checked);

    void ActualizarGrafica();

    void on_ElegirGraficaCB_currentIndexChanged(int index);

    void on_GuardarTrayectoriaPB_clicked();
    */
    //---------------------------------------------------------------------------------------------------------------------------------------------------

    // MenuBar Frame
    //---------------------------------------------------------------------------------------------------------------------------------------------------
    void on_actionKinova_Gen_3_Lite_User_Manual_triggered();

    void on_actionControl_IV_Class_Notes_triggered();
    //---------------------------------------------------------------------------------------------------------------------------------------------------

    // Conectar Frame
    //---------------------------------------------------------------------------------------------------------------------------------------------------
    void on_ConectarPB_clicked();

    bool desconectarRobot();
    //---------------------------------------------------------------------------------------------------------------------------------------------------

    // Funciones de Kinova
    //---------------------------------------------------------------------------------------------------------------------------------------------------
    int64_t GetTickUs();

    bool move_to_zero_position(k_api::Base::BaseClient* base);

    bool move_to_home_position(k_api::Base::BaseClient* base);

    bool move_to_packaging_position(k_api::Base::BaseClient* base);

    create_event_listener_by_promise(std::promise<k_api::Base::ActionEvent>& finish_promise);

    void on_moverAltoNivelPB_clicked();

    void on_goToZeroPB_clicked();

    void on_goToHomePB_clicked();

    void on_goToPackPB_clicked();

    void actualizarPosicionesRobot();

    //---- Funciónes de Errores

    void DisplayDetalllesError(k_api::Base::ConfigurationChangeNotification& data);



    //--------------------------------------------------------------------------------------------------------------

private:
    Ui::MainWindow *ui;
    double tiempo;
    QTimer * miTemporizador;    // Variables y objeto de la clase QTimer, al conectarse con una funcion puede activarla al pasar una establecida cantidad de milisegundos

};
#endif // MAINWINDOW_H
