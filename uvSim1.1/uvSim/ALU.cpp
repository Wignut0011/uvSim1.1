#include "ALU.h"



ALU::ALU()
{
	gate = Gates();
}


ALU::~ALU()
{
}

//Hayden Burker
int ALU::Add(int first, int second)
{
	if (second == 0) {
		return first;
	}

	return Add(gate.XOR(first, second), gate.AND(first, second) << 1);
}

//Hayden Burker
int ALU::Subtract(int first, int second)
{
	return Add(first, Compliment(second)); // Use 2's compliment to invert second
}

//Hayden Burker
int ALU::Multiply(int first, int second)
{
	bool IsNeg = false;
	if (second < 0) {
		IsNeg = true;
		second = Compliment(second);
	}

	int sum = 0;
	while (second > 0) {
		sum = Add(sum, first);
		second = Subtract(second, 1);
	}
	if (IsNeg)
		return Compliment(sum);
	return sum;
}

//Hayden Burker
int ALU::Divide(int first, int second)
{
	bool IsNeg = false;
	if (second < 0) {
		second = Compliment(second);
		IsNeg = !IsNeg;
	}
	if (first < 0) {
		first = Compliment(first);
		IsNeg = !IsNeg;
	}

	int sum = 0;
	while (first >= second) {
		sum = Add(sum, 1);
		first = Subtract(first, second);
	}
	if (IsNeg == true)
		return (Add(gate.NOT(sum),1));
	return sum;
}

//Hayden Burker
int ALU::Modulo(int first, int second)
{
	return 0;
}

//Hayden Burker
int ALU::Exponent(int first, int second)
{
	if (second == 0)
		return 1;
	else if (second < 0)
		return 0;
	int sum = 1;
	while (second > 0) {
		sum = Multiply(sum, first);
		second = Subtract(second, 1);
	}
	return sum;
}

//Daniel Jones
int ALU::Compliment(int number)
{
	return (Add(gate.NOT(number), 1));
}
