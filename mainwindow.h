#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLCDNumber>
#include <QDoubleSpinBox>
// Para mostrar las notificaciones
#include <QMessageBox>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    void showNotification(const QString &title, const QString &message);


private slots:

    //--------------------------------- funciones de coneccion -------------------------//
    void on_ConectarPB_clicked();
    void on_coneccionMark_stateChanged(int arg1);

    //--------------------------------- funciones de seleccion de control -------------------------//
    void on_cambiarControlPB_clicked();
    void deshabilitarControlador();

    //--------------------------------- funciones de Ganancias -------------------------//
    void on_guardarGananciasPB_clicked();
    void on_KP1_valueChanged(double arg1);
    void on_KP2_valueChanged(double arg1);
    void on_KP3_valueChanged(double arg1);
    void on_KP4_valueChanged(double arg1);
    void on_KP5_valueChanged(double arg1);
    void on_KP6_valueChanged(double arg1);

    void on_KD1_valueChanged(double arg1);
    void on_KD2_valueChanged(double arg1);
    void on_KD3_valueChanged(double arg1);
    void on_KD4_valueChanged(double arg1);
    void on_KD5_valueChanged(double arg1);
    void on_KD6_valueChanged(double arg1);

    void on_KI1_valueChanged(double arg1);
    void on_KI2_valueChanged(double arg1);
    void on_KI3_valueChanged(double arg1);
    void on_KI4_valueChanged(double arg1);
    void on_KI5_valueChanged(double arg1);
    void on_KI6_valueChanged(double arg1);

    bool eventFilter(QObject *object, QEvent *event) override;
    void on_PDCancGSel_clicked();
    void on_PDCompGSel_clicked();
    void on_PdCancGSel_clicked();
    void on_PdCompGSel_clicked();
    void on_sPsdCancGSel_clicked();
    void on_sPsdCompGSel_clicked();


    //--------------------------------- funciones de qdeseado -------------------------//
    void on_qd1_valueChanged(double arg1);
    void on_qd2_valueChanged(double arg1);
    void on_qd3_valueChanged(double arg1);
    void on_qd4_valueChanged(double arg1);
    void on_qd5_valueChanged(double arg1);
    void on_qd6_valueChanged(double arg1);

    //--------------------------------- funciones de tiempo -------------------------//
    void on_CambiarTiempoPB_clicked();
    void on_TiempoS_valueChanged(int arg1);

    //--------------------------------- funciones de ejecucion -------------------------//
    void on_IniciarPB_clicked();
    void on_DetenerPB_clicked();


private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
