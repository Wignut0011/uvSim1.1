#include "core.h"
#include <stdexcept>
#include <string>


void Core::RunProgram(){
   // Console.show();
    // program starting text
   // Console.write("*********** Program started *********** \n");

    // check if it is hault
    while(OperatorReg != 4300 ){
      //  if(wait == true){
     //       break;
      //  }
        OperatorReg = Memory[PC];
        PC++;
        OperandReg = Memory[PC];
        PC++;
        RunInstruction();
    }

    // program finished:
    //if(wait != true)
  //  Console.write("*********** Program has finished *********** \n");

    // keep the window open:
   // Console.read();
}

bool Core::RunInstruction(){


    switch (OperatorReg) {
        // READ
    case 1000: // Branch out to CPU
   //         Console.write("Please input a number: ");
            try{
            //reading = true;
     //       Memory[OperandReg] = std::stoi(Console.read()); // Abinadi changed this
    }
            catch(...){
        Memory[OperandReg] = 6;
    }
//            reading = false;
        break;

        // WRITE
    case 1100:// Branch out to CPU
            //cout << "Write to location " << operand << endl;
            //cout << "Contents at " << operand << ": " << memory[operand] << endl;
        //std::string output = "Contents at " +  + ": " + std::to_string(Memory[OperandReg]) + std::endl;
           // Console.write("Contents at ");
           // Console.write(std::to_string(OperandReg));
           // Console.write(": ");
           // Console.write(std::to_string(Memory[OperandReg]));
           // Console.write("\n");
        break;

        // LOAD
    case 2000:// Branch out to CPU
            //cout << "Load from location " << operand << endl;
            AC = Memory[OperandReg];
        break;

        // STORE
    case 2100:// Branch out to CPU
            //cout << "Store to loaction " << operand << endl;
            Memory[OperandReg] = AC;
        break;

        // ADD
    case 3000:// Branch out to CPU
            //Accumulator = alu.add(Accumulator, memory[operand]);
        break;

        // SUBTRACT
    case 3100:// Branch out to CPU
            //Accumulator = alu.subtract(Accumulator, memory[operand]);
        break;

        // DIVIDE
    case 3200:// Branch out to CPU
            //Accumulator = alu.divide(Accumulator, memory[operand]);
        break;

        // MULITPLY
    case 3300:// Branch out to CPU
            //Accumulator = alu.multiply(Accumulator, memory[operand]);
        break;

        // BRANCH
    case 4000:// Branch out to CPU
            //cout << "this is BRANCH" << endl;
            PC = OperandReg-1;
        break;

        // BRANCH NEG
    case 4100:// Branch out to CPU
        //cout << "this is BRANCH NEG" << endl;
        if (AC < 0)
            PC = OperandReg-1;
        break;

        // BRANCH ZERO
    case 4200:// Branch out to CPU
        //cout << "this is BRANCH ZERO" << endl;
        if (AC == 0)
            PC = OperandReg-1;
        break;

    // HALT
    case 4300: if (OperandReg != 00) //ErrorHandler(3);
             //else return false;
             break;

    case 0:
        // do nothing because we are justing fillilng memory
        // placed here by abinadi
        break;

    // ERROR 2 (Incorrect opcode)
    default: //ErrorHandler(2);


        break;
    }
    return true;

}
