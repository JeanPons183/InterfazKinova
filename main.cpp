#include "mainwindow.h"

#include <QApplication>

#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    std::cout << "Hola mundo" << std::endl;
    return a.exec();
}
