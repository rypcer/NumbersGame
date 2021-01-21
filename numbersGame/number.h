//----------------------------------------------------
//	Code by Ajmal Sarif 2020 w1722688
//----------------------------------------------------
#pragma once
#include <iostream>
#include <list>
#include <string>
#include <typeinfo>
using namespace std;

class number
{
protected:
	int value;
	bool splitable;
	bool selected = false;
public:
	number(int _value, bool _isSplitable);
	virtual int getValue();
	virtual bool isSplitable();
	virtual void split(list<number*>& myNumbers);
	virtual void printMe();
	bool isSelected(list<number*>& selectedList);
	virtual void printNums();
};

