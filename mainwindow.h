#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    // Conectar frame
    void on_ConectarPB_clicked();

    // Robot Settings frame
    //--------------------------------------------------------------------------------
    void on_CambiarTiempoPB_clicked();

    void on_CambiarControlPB_clicked();

    void on_ActivarGraficasPB_clicked();

    void Controlador(int select);
    //--------------------------------------------------------------------------------

    // Ganancias frame
    //--------------------------------------------------------------------------------
    void on_cambiarGainsPB_clicked();

    void SaveValues();

    void SetValues();
    //--------------------------------------------------------------------------------

    // Posicion frame
    //--------------------------------------------------------------------------------
    void on_CambiarQdPB_clicked();

    void on_PosZeroPB_clicked();

    void on_PosPackPB_clicked();
    //--------------------------------------------------------------------------------

    // Ejecucion Frame
    //-------------------------------------------------------------------------
    void on_IniciarPB_clicked();

    void on_PausePB_clicked();

    void on_ContinuarPB_clicked();

    void on_StopPB_clicked();

    void on_StopPB_2_clicked();

    void on_RegresarPB_clicked();

    void on_GuardarTrayectoriaPB_clicked();
    //-------------------------------------------------------------------------

    // Graficas frame
    //-------------------------------------------------------------------------

    void on_AgregarGraficaPB_clicked();

    void on_EliminarGraficaPB_clicked();

    void SetGrafica(int select);

    //-------------------------------------------------------------------------


    // MenuBar Frame
    //-------------------------------------------------------------------------
    void on_actionKinova_Gen_3_Lite_User_Manual_triggered();

    void on_actionControl_IV_Class_Notes_triggered();


private:
    Ui::MainWindow *ui;











};
#endif // MAINWINDOW_H
