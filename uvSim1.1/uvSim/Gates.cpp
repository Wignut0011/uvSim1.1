#include "Gates.h"



Gates::Gates()
{
}


Gates::~Gates()
{
}

//Hayden Burker
int Gates::AND(int first, int second)
{
	return (first & second);
}

//Hayden Burker
int Gates::XOR(int first, int second)
{
	return (first ^ second);
}

//Daniel Jones
int Gates::NOT(int number)
{
	return ~number;
}



//Hayden Burker and Daniel Jones
int Gates::ShiftLeft(int number)
{
	return (number << 1);
}

//Hayden Burker and Daniel Jones
int Gates::ShiftRight(int number)
{
	return (number << 1);
}
