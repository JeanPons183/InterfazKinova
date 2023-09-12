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
    void on_IniciarPB_clicked();

    void on_PausePB_clicked();

    void on_StopPB_clicked();

    void on_StopPB_2_clicked();

    void on_RegresarPB_clicked();

    void on_GuardarTrayectoriaPB_clicked();

    void on_ConectarPB_clicked();

    void on_CambiarControlPB_clicked();

    void on_CambiarTiempoPB_clicked();

    void on_ActivarGraficasPB_clicked();

    void on_cambiarGainsPB_clicked();

    void on_PosZeroPB_clicked();

    void on_PosPackPB_clicked();

    void on_CambiarQdPB_clicked();

    void on_actionKinova_Gen_3_Lite_User_Manual_triggered();

    void on_actionControl_IV_Class_Notes_triggered();

    void on_AgregarGraficaPB_clicked();

    void on_EliminarGraficaPB_clicked();

    void Controlador(int select);

    void SaveValues();

    void SetValues();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
