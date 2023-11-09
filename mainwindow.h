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

    int RobotConnect(int argc, char **argv);

    bool move_to_zeros_position(k_api::Base::BaseClient* base);


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
