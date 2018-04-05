#include "ALU.h"

ALU::ALU()
{
	NotGate = Not();
	XOrGate = XOr();
	AndGate = And();
	ShiftGate = Shift();
}


ALU::~ALU()
{
}

// Daniel Jones
ALU::INT ALU::Compliment(INT number) {
	return Add(NotGate.NOT(number), 1); // Get 2's compliment of a value
}

// Hayden Burker
int ALU::GreaterThan(INT &first, INT &second) {
	// Bit comparison between a and b.
	// Doesn't treat last bit as a negative (unsigned integer comparison).

	assert(first.size() == second.size());
	for (int i = first.size() - 1; i >= 0; i--) {
		if (first[i] ^ second[i] == 1) {
			if (first[i] > second[i])
				return 1;
			else {
				return -1;
			}
		}
	}
	return 0;
}

// Hayden Burker
ALU::INT ALU::Add(INT first, INT second) {
	// Algorithm performs add operation using 'AND' and 'XOR' operations.

	INT temp = XOrGate.XOR(first, second);
	second = AndGate.AND(first, second) << 1;
	first = temp;

	// Optimized algorithm simulates the remaining 'AND', 'XOR', and shift operations.
	// Skips any 'AND', 'OR', and shift operations that do nothing.
	assert(first.size() == second.size());
	for (int i = 0; i < second.size(); i++) {
		if (second[i]) {
			if (first[i]) {
				second[i] = 0;
				if (i != second.size() - 1)
					second[i + 1] = 1; // Carry value
				first[i] = 0;
			}
			else {
				second[i] = 0;
				first[i] = 1;
			}
		}
	}

	return first;
}

// Hayden Burker
ALU::INT ALU::Subtract(INT first, INT second) {
	return Add(first, Compliment(second));
}

// Hayden Burker
ALU::INT ALU::Multiply(INT first, INT second) {
	bool IsNeg = false;
	if (second[second.size() - 1]) { // b < 0
		IsNeg = !IsNeg;
		second = Compliment(second);
	}

	INT sum = 0;
	INT mult = 1;

	while (second != 0) {
		if (second[0]) {
			sum = Add(sum, first);
		}
		first = ShiftGate.ShiftLeft(first);
		second = ShiftGate.ShiftRight(second);
	}
	if (IsNeg)
		return Compliment(sum);
	return sum;
}

// Hayden Burker
ALU::INT ALU::Divide(INT first, INT second) {
	bool IsNeg = false;
	if (second[second.size() - 1]) { // b > 0
		second = Compliment(second);
		IsNeg = !IsNeg;
	}
	if (first[first.size() - 1]) { // a > 0
		first = Compliment(first);
		IsNeg = !IsNeg;
	}

	INT sum = 0;
	INT mult = 1;
	while (GreaterThan(first, second) > 0) { // Unsigned int comparison: a > b
		mult = ShiftGate.ShiftLeft(mult);
		second = ShiftGate.ShiftLeft(second);
	}

	while (mult != 0) {

		if (GreaterThan(first, second) >= 0) { // a >= b
			sum = Add(sum, mult);
			first = Subtract(first, second);
		}

		second = ShiftGate.ShiftRight(second);
		mult = ShiftGate.ShiftRight(mult);

	}

	if (IsNeg)
		return Compliment(sum);
	return sum;
}

// Hayden Burker
ALU::INT ALU::Exponent(INT first, INT second) {
	// Special cases
	if (second == 0)
		return 1;
	if (((second[second.size() - 1]) || first == 0) && !(first == 1 || first == Compliment(1))) // (b < 0 || a == 0) && a isn't 1 or -1
		return 0;
	if (first == -1 && second[second.size() - 1])
		second = Compliment(second);

	INT sum = 1;
	while (!second[second.size() - 1] && second != 0) { // b > 0
		if (second[0])
			sum = Multiply(sum, first);
		first = Multiply(first, first);
		second = ShiftGate.ShiftRight(second);
	}
	return sum;
}

// Hayden Burker
ALU::INT ALU::Modulo(INT a, INT b) {
	bool IsNeg = false;
	if (b[b.size() - 1]) { // b < 0
		b = Compliment(b);
	}
	if (a[a.size() - 1]) { // a < 0
		IsNeg = true;
		a = Compliment(a);
	}

	INT mult = 1;
	while (GreaterThan(a, b) > 0) {
		mult = mult << 1;
		b = b << 1;
	}

	while (mult != 0) {
		if (GreaterThan(a, b) >= 0) {
			a = Subtract(a, b);
		}

		b = ShiftGate.ShiftRight(b);
		mult = ShiftGate.ShiftRight(mult);
	}

	if (IsNeg)
		return Compliment(a);
	return a;
}