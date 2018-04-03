#pragma once

using namespace std;

//By: Hayden Burker & Daniel Jones

class Gates
{
public:
	Gates();
	~Gates();


	/*
		Returns the bitwise AND of two given integers.
	*/
	int AND(int first, int second);

	/*
		Returns the bitwise Exlusive OR of two given integers.
	*/
	int XOR(int first, int second);

	/*
		Returns the logical NOT of an integer.
	*/
	int NOT(int number);

	/*
		Performs a bitwise shift to the left by 1.
	*/
	int ShiftLeft(int number);

	/*
		Performs a bitwise shift to the right by 1.
	*/
	int ShiftRight(int number);
};

