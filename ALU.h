/*
--------Updates--------

Optimized version of ALU

Bitwise shifts are used to optimize operations like Multiply and Exponent

ALU now uses bitset instead of int

Fixed a bug with exponential function ( (1 or -1) to the power of a negative number returns 0 instead of 1 or -1 )

Division and modulus no longer check divide by zero. The caller (core class) handles it.

Refactored gates so each bitwise operation has its own class (ALU is facade)

*/

/*
UVSim ALU
by Hayden Burker
Refactored by: Daniel Jones
*/

#ifndef ALU_H
#define ALU_H

#include <cassert>
#include "Not.h"
#include "XOr.h"
#include "And.h"
#include "Shift.h"



class ALU {
	static enum { SIZE = sizeof(int) * CHAR_BIT };
	typedef std::bitset<SIZE> INT; // defines Gates::INT as a bitset

	/*
	returns the result of an unsigned int comparison.
	a > b returns 1, a == b returns 0, and a < b returns -1.
	*/
	int GreaterThan(INT&, INT&);

public: 

	ALU();
	~ALU();

	And AndGate;
	XOr XOrGate;
	Not NotGate;
	Shift ShiftGate;


	/*
	returns the sum of the first and second integer.
	*/
	INT Add(INT first, INT second);

	/*
	returns the result of subtracting the second integer from the first integer.
	*/
	INT Subtract(INT first, INT second);

	/*
	returns the product of the first and second integer.
	*/
	INT Multiply(INT first, INT second);

	/*
	returns the result of dividing the first integer by the second integer.
	*/
	INT Divide(INT first, INT second);

	/*
	returns the remainder of dividing the first integer by the second integer.
	*/
	INT Modulo(INT first, INT second);

	/*
	returns the result of raising the first number to the second.
	*/
	INT Exponent(INT first, INT second);

	/*
	Returns the two's Compliment of a number.
	*/
	INT Compliment(INT number);

	
};

#endif // !ALU_H