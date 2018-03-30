#ifndef COMPILER_H
#define COMPILER_H
#include <istream>
#include <sstream>
#include "CPU.h"
#include "memory.h"

class Compiler
{

public:

    Compiler(std::stringstream &input);
    void ExtractCode();
    void Run();

private:
   //vector<int> MemLoc;
   CPU cPU;
};

#endif // COMPILER_H
