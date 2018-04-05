#ifndef XOR_H
#define XOR_H

#include <bitset>
#include <climits>

class XOr {
	static enum { SIZE = sizeof(int) * CHAR_BIT };
	typedef std::bitset<SIZE> INT;
public:
	XOr() {};
	~XOr() {};

	//Hayden Burker
	INT XOR(INT first, INT second)
	{
		return (first ^ second);
	}

};


#endif // !XOR_H
