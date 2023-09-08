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

    void Labels(QString Selected);

    void on_ConectarPB_clicked();

    void on_PlayPausePB_clicked();

    void on_StopPB_clicked();

    void on_Graficas_checkBox_stateChanged(int arg1);

    void on_GuardarTrayectoriaPB_clicked();

    void on_cambiarGainsPB_clicked();

    void on_CambiarControlPB_clicked();

    void on_CambiarTiempoPB_clicked();

    void on_CambiarQdPB_clicked();

    void on_PosPackPB_clicked();

    void on_PosZeroPB_clicked();

    void on_radioButton_clicked(bool checked);

    void on_AgregarGraficaPB_clicked();

    void on_EliminarGraficaPB_clicked();

    void Robot();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
