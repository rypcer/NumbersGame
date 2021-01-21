//----------------------------------------------------
//	Code by Ajmal Sarif 2020 w1722688
//----------------------------------------------------
#pragma once
#include "number.h"
class givenNumber : public number
{
private:
	bool splitable = false;
public:
	givenNumber(int _value);
	bool isSplitable();	
	void printMe();
	void printNums();
	bool isSelected(list<number*>& selectedList);
};

