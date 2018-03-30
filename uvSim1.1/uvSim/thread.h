#ifndef THREAD_H
#define THREAD_H
#include <QThread>
#include <QObject>
#include "consolewindow.h"
#include <bitset>
#include <exception>
using namespace std;

class Thread: public QThread
{

public:
    // registers stored in int array
    enum{accumulator, opcode, operand};
    int regs[3] = {0};

    // pc this gets set on construction of the thread to the start of the program
    int PC;

    ConsoleWindow * console;

    Thread(ConsoleWindow * c, int pc){
        console = c;
        PC = pc;
    }



private:
    void run()
    {

        // basically if any error occurs end the program and display that
        // it broke.
        try{
     RunProgram();
        }
        catch(runtime_error & e){
            write("\n");
            write(e.what());
            write(" Program has stopeed");
        }
        catch(...){
            write("\n An unknow error has occured. the program has stopped");
        }

        //read();



}


private:

    void write(const std::string & s ){
         console->write(s);
    }

    std::string read(){
        // call the read function in the console
        console->read();

        // wait for the enter key to be pressed
        QEventLoop loop;
        loop.connect(console, SIGNAL(grabbedKey()),&loop,  SLOT(quit()),Qt::BlockingQueuedConnection);
        loop.exec();

        // We've exited the event loop so there must be input, return the input
        string bob = console->getOutPut();
        return console->getOutPut();
    }

    void RunProgram(){

       write("*********** Program started *********** \n");

        // set the opcode register initially so if we encounter
       // a hault first the program will stop
       regs[opcode] = Memory[PC];
        // check if it is hault
        while(regs[opcode] != 4300 ){

            regs[opcode] = Memory[PC];
            PC++;
            regs[operand] = Memory[PC];
            PC++;
            RunInstruction();

        }

        write("*********** Program has finished *********** \n");
    }

    bool RunInstruction(){


        switch (regs[opcode]) {
            // READ
        case 1000:
                write("Please input a number: ");
                try{
                Memory[regs[operand]] = std::stoi(read()); // Abinadi changed this
        }
                catch(...){
            throw runtime_error("Something went wrong with read.");
        }

            break;

            // WRITE
        case 1100:
                write("Contents at ");
                write(std::to_string(regs[operand]));
                write(": ");
                write(std::to_string(Memory[regs[operand]]));
                write("\n");
            break;

            // LOAD
        case 2000:
                regs[accumulator] = Memory[regs[operand]];
            break;

            // STORE
        case 2100:// Branch out to CPU
                Memory[regs[operand]] = regs[accumulator];
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
                PC = regs[operand]-1;
            break;

            // BRANCH NEG
        case 4100:// Branch out to CPU
            //cout << "this is BRANCH NEG" << endl;
            if (regs[accumulator] < 0)
                PC = regs[operand]-1;
            break;

            // BRANCH ZERO
        case 4200:// Branch out to CPU
            //cout << "this is BRANCH ZERO" << endl;
            if (regs[accumulator] == 0)
                PC = regs[accumulator]-1;
            break;

        // HALT
        case 4300: if (regs[operand] != 00) //ErrorHandler(3);
                 //else return false;
                 break;

        case 0:
            // do nothing because we are justing filling memory
            // placed here by abinadi
            break;

        // ERROR 2
        default: //ErrorHandler(2);

            throw runtime_error("Unknow opcode has been encountered");

            break;
        }
        return true;

    }


};

#endif // THREAD_H
