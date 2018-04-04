#include "cpu.h"
#include <QThread>
#include <QCoreApplication>

#include <QApplication>
#include "consolewindow.h"
#include "core.h"


using namespace std;








void CPU::CreateCores(std::vector<int> &memLoc){
    // detach from the current console window
        // if launched from a console window, that will still run waiting for the new console (below) to close
        // it is useful to detach from Qt Creator's <Application output> panel
        //FreeConsole();



    for(int i = 0; i<memLoc.size(); i++){
        ConsoleWindow *d = new ConsoleWindow;
        d->show();
        d->setWindowTitle(QString::fromStdString("Program at Mem: "+ std::to_string(memLoc.at(i))));
        Core *s = new Core(d, memLoc.at(i));
        QObject::connect(s, SIGNAL(finished()), s, SLOT(quit()));
        s->start();
        threadPool.push_back(s);
        threadRep.push_back(0);
    }




}
