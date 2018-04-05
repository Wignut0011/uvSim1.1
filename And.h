#ifndef AND_H
#define AND_H

#include <bitset>
#include <climits>

class And {
	static enum { SIZE = sizeof(int) * CHAR_BIT };
	typedef std::bitset<SIZE> INT;
public:
	And() {};
	~And() {};

	//Hayden Burker
	INT AND(INT first, INT second)
	{
		return (first & second);
	}

};


#endif // !AND_H
