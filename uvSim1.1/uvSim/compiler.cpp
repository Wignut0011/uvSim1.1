#include "compiler.h"




Compiler::Compiler(std::stringstream &input){

    MemLoc.clear();

    int c = 0;

    while(true){
        std::string grabed;
        std::getline(input, grabed);

       // check if we get the program operand
       if(grabed == "5000"){
            std::string pc;
            
            // get the next memory address
            std::getline(input, pc);
            MemLoc.push_back(std::stoi(pc));
            c= std::stoi(pc);
            
            // grab the next one
            std::getline(input, grabed);
       }

         Memory[c] = std::stoi(grabed);
         c++;

         if(input.rdbuf()->in_avail() == 0){
             break;
         }
    }
}


void Compiler::ExtractCode(){

}

void Compiler::Run(){
    cPU.CreateCores(MemLoc);
}
