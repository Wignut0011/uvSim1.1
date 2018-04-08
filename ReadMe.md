```
        ___  ___  ___      ___ ________  ___  _____ ______      
       |\  \|\  \|\  \    /  /|\   ____\|\  \|\   _ \  _   \    
       \ \  \\\  \ \  \  /  / | \  \___|\ \  \ \  \\\__\ \  \   
        \ \  \\\  \ \  \/  / / \ \_____  \ \  \ \  \\|__| \  \  
         \ \  \\\  \ \    / /   \|____|\  \ \  \ \  \    \ \  \ 
          \ \_______\ \__/ /      ____\_\  \ \__\ \__\    \ \__\
           \|_______|\|__|/      |\_________\|__|\|__|     \|__|
                                 \|_________|
```
## UVSIM MACHINE LANGUAGE SIMULATOR V1.1 (Work In Progress)


### Index
```
*INTRO
*DIRECTIONS
  -MEMORY
  -ACCUMULATOR
  -PC
  -OPCODE
  -OPERAND
  -CONTROL BRANCH
  -UVSIM OPCODES
  -STARTING UVSIM
  -EDITOR (Main Program)

*INSTRUCTIONS
  -IO
    -READ
    -WRITE
  -READ\WRITE
    -LOAD
    -STORE
  -ARITHMITIC
    -ADD
    -SUBTRACT
    -DIVIDE
    -MULTIPLY
    -EXPONENT
    -MODULUS
  -CONTROL
    -BRANCH
    -BRANCH NEG
    -BRANCH ZER
    -HALT
  -SIMULATOR
    -NEW CORE
    -BREAK
```


##                              INTRO


*This program is intended as a learning tool for Machine language*

In real life, hardware works in 1s and 0s, binary. When you program in high 
level languages like c++ and python, that program gets converted to this
binary machine language when it compiles. Every CPU has it's different machine
language but in the end, every program gets converted so your machine can run
that program in binary. UVSIM is a simulator that emulates machine language 
programing.

This simulator uses lines of code comprising of 4 digits each line and 2 lines 
each piece of code. One line of an opcode and a second line comprising an operand.
It utilizes one register called the Accumulator. The total memory space is 1000 
lines in total.

*Please refer to the instruction list in order to input the correct code*


## DIRECTIONS


In order to understand Machine Language, there's a few components to 
understand.

* Memory
* Accumulator (Register)
* PC
* Opcode
* Operand
* Control Branch


### Memory

```
Memory is the total space that your program can by stored on. This 
simulator can hold 1000 lines of code. Each line has a location named by
a 4 decimal number such as 0001, 0503, 9999 etc. You can't go beyond the limits
of this hard number since this simulator is intended to emulate machine 
language and in real life this limit would be the amount of actual memory
it contains.
```

### Accumulator

```
This represents a single register. The accumulator is meant to simulate the
cache inside your CPU. A temporary location to store data outside memory for
fast and easy access. In terms of this simulator, you will use the 
accumulator to manipulate data depending on which instruction you use.
```

### PC

```
The PC or Program Counter is a counter that displays where in memory the
program currently is. For example, if the PC is 0503 then the program is 
currently located at 0503 in memory. The PC can be manipulated to simulate
conditional branching paths in the code through Branch Control instructions.
If one of these instructions are executed then the program will deviate to 
that location. EG: PC is 4050 and 4050 contains a Branch instruction to 0067
then the PC will deviate to location 0067 and the program will continue from there.
```

### Opcode

```
The 2 digit signature that tells the CPU what instruction is to be executed
such as Load(2000), Add(3000), Branch(4000), etc. This 4 digit line of code
is the first part of a piece code with the second part being the operand.
```

### Operand

```
The second part of a pice of code. The operand of your code tell the CPU what
to do with the instruction that is to be executed. For example, if an ADD 
instruction is executed, the operand of the code tell the CPU what is to be 
added with the accumulator EG: 3000 0014 where 3000 is the ADD instruction and 
0014 (the operand) is where the data to be added to the accumulator is located.

*Some instructions don't require an opcode so please refer to the opcode
 section of this readme for more information
```

### Control Branch

```
This lets conditional deviations in the program possible. By manipulating the 
PC, you can branch off to a different part of the program depending on which 
Control Branch opcode you use. There's 3 in total in UVSIM. Branch, Branch
Negative, and Branch Zero. While the first branch can executed by simply
running the line, the other are conditional depending on the accumulator.
if the accumulator contains a 0 and the PC runs into a BranchZero then
and only then can it be executed; vice versa with BranchNegative if the 
accumulator contains a negative.
```

### UVSIM Opcodes

```
These opcodes are specifically meant for advanced emulation purposes. Currently,
there are two of these opcodes; BRANCH and NEW CORE. BRANCH is a debug opcode
that temoprarily halts the program and displays a debug dump in a new window.
Once this window closes then the program continues. NEW CORE is a tricky one.
This opcode simulates a multi-threading, which means another console will start
at this location. Effectivly running more then one program at a given time.
It will have the same functionality such as reading and writing and each are
independent of eachother.
```

### STARTING UVsim

```
To run UVsim navitage to uvSim.exe by navigating through the follwing 
folders contained in our delivered folder: uvSim->Debug->uvSim.exe  uvSim.exe will most 
likely be at the top, just double click to run it.
```

### Editor

```
This is the main interface where you input your code. On the left is where you input
your code and the right is a snapshot of what code is in memory (press "Refresh" for
the most recent snapshot). In the list-like left area, input your code in four digit
words. If the opcode you are using requires an operand. Place the operand in the next
line. EG: 2100 0046. When your done with your code, press on the "Run" button below 
the list. When running, a new window will pop up. This is a console window that will 
display the program that you had input. If you had input the Core opcode, another 
window will appear. In the end of the code execution, there will be a memory dump 
displayed on the console window which will display the memory and the contents of the 
accumulator.

*If you are adding raw data for aritmatic purposes, please insert a halt before
 adding the raw data so the program won't try to run it as code.
```

## INSTRUCTIONS

### I/O

* 1000 READ
```
Read instruction that takes input from the user and stores it in the
memory location stated in the operand.
```

* 1100 WRITE
```
Write instruction that displays data in the memory location stated in
the operand to the console window.
```

### READ/WRITE

* 2000 LOAD
```
Load instruction that loads data from the location listed in the operand
to the accumulator.
```

* 2100 STORE
```
Store instruction that stores data from the accumulator to the location 
listed in the operand.
```

### ARITHMITIC

* 3000 ADD
```
Add instruction that adds data in the accumulator with data located in 
the operand. Result is stored in the accumulator.
```

* 3100 SUBTRACT
```
Subtract instruction that subtracts data in the accumulator with data 
located in the operand. Result is stored in the accumulator.		
```

* 3200 DIVIDE
```
Divide instruction that divides data in the accumulator with data located 
in the operand. Result is stored in the accumulator.		
```	

* 3300 MULTIPLY
```
Multiply instruction that multiplies data in the accumulator with data 
located in the operand. Result is stored in the accumulator.		
```

* 3400 EXPONENT
```
The exponent instruction takes the data in the accumulator and raises it
to the power located in the operand. Result is stored in the accumulator.
```

* 3500 MODULUS
```
The exponent instruction takes the data in the accumulator and the data 
located in the operand and takes the remainder result of a division from
the both. Result is stored in the accumulator.
```

### CONTROL

* 4000 BRANCH
```
Branch instruction that directs the PC to the location listed in the 
operand
```

* 4100 BRANCH NEG
```
Branch instruction that directs the PC to the location listed in the 
operand if the accumulator contains a negative.
```

* 4200 BRANCH ZERO
```
Branch instruction that directs the PC to the location listed in the 
operand if the accumulator contains a zero.
```

* 4300 HALT
```
Halts the PC and stops the program. (End of program)
*Please leave operand at 0000
```

### SIMULATOR

* 5000 NEW CORE
```
This opcode tells the compiler to run a new core at the location
in memory specified in the operand. When this happens, a new 
window will appear and will run seperately from the first core. It 
will have all IO read/write capabilities.
```

* 5100 BREAK
```
This is meant for debug purposses. When this opcode is set in memory,
the program will temporarily halt and a new window will pop up with
debug information including the contents in the accumulator. To resume
the PC, close this window.
*Please leave operand at 0000
```
