#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Configura el manejador de mensajes personalizado
    void myMessageHandler(QtMsgType type, const QMessageLogContext &, const QString &msg);
    qInstallMessageHandler(myMessageHandler);

    MainWindow w;
    w.show();
    return a.exec();
}
