//----------------------------------------------------
//	Code by Ajmal Sarif 2020 w1722688
//----------------------------------------------------

#pragma once
#include "number.h"

class compositeNumber : public number
{
private:
	number* num1;
	number* num2;
	char op;

public:
	compositeNumber(int _value, number* _num1, number* _num2, char _op, bool _splitable);

	void printMe();
	number* getNum1();
	number* getNum2();
	bool isSplitable();
	void split(list<number*>& myNumbers);
	void printNums();
};

