#include "compositeNumber.h"


compositeNumber::compositeNumber(int _value, number* _num1, number* _num2, char _op, bool _splitable) :
	number(_value,_splitable) ,num1(_num1),num2(_num2), op(_op){}

bool compositeNumber::isSplitable() 
{ return true; }

void compositeNumber::printMe()
{
	cout << value << "="; printNums();
}


void compositeNumber::printNums() 
{
	cout << "(";
	num1->printNums();
	cout << op;
	num2->printNums();
	cout << ")";
}


number* compositeNumber::getNum1()
{return num1;}

number* compositeNumber::getNum2()
{return num2;}

void compositeNumber::split(list<number*>& myNumbers)
{
	myNumbers.push_back(num1);
	myNumbers.push_back(num2);
	for (auto i = myNumbers.begin(); i != myNumbers.end(); i++) {
		// prevent deleting other numbers with same value 
		if (*i==this) { 
			myNumbers.erase(i);
			return;
		}
	}

}


