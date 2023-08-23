#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Configura el manejador de mensajes personalizado
    //qInstallMessageHandler(myMessageHandler);

    MainWindow w;
    w.show();
    return a.exec();
}
