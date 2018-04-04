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
    std::vector<int> MemLoc = {0};
   CPU cPU;
};

#endif // COMPILER_H
