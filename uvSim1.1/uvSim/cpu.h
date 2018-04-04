#ifndef CPU_H
#define CPU_H
#include <vector>
#include "core.h"
#include <QObject>
#include "memory.h"
//#include <QThread>



class CPU
{

private:

    std::vector<Core*> threadPool;

public:



    void CreateCores(std::vector<int> &memLoc);

};

#endif // CPU_H
