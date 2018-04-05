#ifndef SHIFT_H
#define SHIFT_H

#include <bitset>
#include <climits>

class Shift {
	static enum { SIZE = sizeof(int) * CHAR_BIT };
	typedef std::bitset<SIZE> INT;
public:
	Shift() {};
	~Shift() {};

	//Hayden Burker and Daniel Jones
	INT ShiftLeft(INT number)
	{
		return (number << 1);
	}

	//Hayden Burker and Daniel Jones
	INT ShiftRight(INT number)
	{
		return (number >> 1);
	}

};


#endif // !SHIFT_H
