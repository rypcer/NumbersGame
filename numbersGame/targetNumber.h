//----------------------------------------------------
//	Code by Ajmal Sarif 2020 w1722688
//----------------------------------------------------
//	Comments: I know I could have derived NumberList and this class 
//	from a base class but it would not make a huge difference.
//----------------------------------------------------
#pragma once
#include <iostream>
#include "numberList.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;
using namespace customLibrary;

class targetNumber: public numberList
{
	bool targetNumberGenerated = false;
	number* targetNumPtr;
public:
	//Functions
	void add(number* x, number* y, int num1Index, int num2Index);
	void subtract(number* x, number* y, int num1Index, int num2Index);
	void multiply(number* x, number* y, int num1Index, int num2Index);
	void divide(number* x, number* y, int num1Index, int num2Index);
	void print();
	void resetList();
	number* getPtrByIndex(int value);
	void deleteByIndex(int value);
	void inputActions();

};




