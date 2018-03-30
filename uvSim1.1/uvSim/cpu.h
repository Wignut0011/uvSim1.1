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

    std::vector<Core*> _cores;

public:

    void SetMem(int (&mem)[1000]);

    void CreateCores();
    //<Core> Cores;
    // vector<DWORDS> IdS;
};

#endif // CPU_H
