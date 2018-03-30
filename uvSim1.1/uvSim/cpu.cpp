#include "cpu.h"
#include "core.h"
#include <QThread>
#include <QCoreApplication>

#include <QApplication>
#include "consolewindow.h"
#include "thread.h"


static std::vector<Core*> cores;
static int count = 0;


using namespace std;








void CPU::CreateCores(){
    // detach from the current console window
        // if launched from a console window, that will still run waiting for the new console (below) to close
        // it is useful to detach from Qt Creator's <Application output> panel
        //FreeConsole();

    //Core * program = new Core();
    //Core * program2 = new Core();
   // cores.push_back(program);
   // cores.push_back(program2)

    ConsoleWindow *bob = new ConsoleWindow;
    bob->show();
    Thread *b = new Thread(bob, 0);
    QObject::connect(b, SIGNAL(finished()), b, SLOT(quit()));
    b->start();


    ConsoleWindow *d = new ConsoleWindow;
    d->show();
    Thread *s = new Thread(d, 0);
    QObject::connect(s, SIGNAL(finished()), s, SLOT(quit()));
    s->start();



}
