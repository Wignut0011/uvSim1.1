#include "mainwindow.h"
#include <QApplication>
#include "codeeditor.h"
#include "consolewindow.h"
#include "core.h"
#include <QtCore>
#include <QObject>
#include "memory.h"
#include "cpu.h"




int Memory[1000] = {0};

int main(int argc, char *argv[])
{


    QApplication b(argc, argv);
     MainWindow mainW;
     mainW.show();





     return b.exec();






}
