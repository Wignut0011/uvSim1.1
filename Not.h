#ifndef NOT_H
#define NOT_H

#include <bitset>
#include <climits>

class Not {
	static enum { SIZE = sizeof(int) * CHAR_BIT };
	typedef std::bitset<SIZE> INT;
public:
	Not() {};
	~Not() {};

	// Daniel Jones
	INT NOT(INT number)
	{
		return ~number;
	}

};


#endif // !NOT_H
