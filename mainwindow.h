#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qspinbox.h"
#include <QMainWindow>
#include <QLCDNumber>
#include <QDoubleSpinBox>



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
    void on_PDSel_clicked();

    void on_PDSel_toggled(bool checked);

    void on_KP1_valueChanged(double arg1);

    void on_TiempoS_valueChanged(int arg1);

    void on_KD1_valueChanged(double arg1);

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
