#ifndef CORE_H
#define CORE_H
#include <QPlainTextEdit>
#include <QObject>
#include <sstream>
#include <QEventLoop>
#include <string>

#include "consolewindow.h"
#include "memory.h"

class Core
{
public:
    explicit Core(int _id){
        id = _id;

        AC = 0;
        PC = 0;

    }

    int id;
    bool stop;

    int PC;
    int AC;
    int OperatorReg;
    int OperandReg;

    void RunProgram();
    bool RunInstruction();

public slots:
    void changeData();
signals:

};

#endif // CORE_H
