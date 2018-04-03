/*
UVSim ALU
by Hayden Burker
Refactored by: Daniel Jones
*/

#pragma once
#include "Gates.h"

class ALU
{
public:
	ALU();
	~ALU();

	Gates gate;
	
	/*
		returns the sum of the first and second integer.
	*/
	int Add(int first, int second);

	/*
		returns the result of subtracting the second integer from the first integer.
	*/
	int Subtract(int first, int second);

	/*
		returns the product of the first and second integer.
	*/
	int Multiply(int first, int second);

	/*
		returns the result of dividing the first integer by the second integer.
	*/
	int Divide(int first, int second);

	/*
		returns the remainder of dividing the first integer by the second integer.
	*/
	int Modulo(int first, int second);

	/*
		returns the result of raising the first number to the second.
	*/
	int Exponent(int first, int second);

	/*
		Returns the two's Compliment of a number.
	*/
	int Compliment(int number);
};

