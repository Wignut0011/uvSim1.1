#include "compiler.h"




Compiler::Compiler(std::stringstream &input){

    int c = 0;
    while(true){
        std::string grabed;
       std::getline(input, grabed);
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
    cPU.CreateCores();
}
