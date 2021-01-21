#include "number.h"

number::number(int _value,bool _splitable) : value(_value), splitable(_splitable){}
int number::getValue() { return value; }
bool number::isSplitable() { return splitable; }
void number::split(list<number*>& myNumbers) {}
void number::printMe() {}
bool number::isSelected(list<number*>& selectedList) 
{ 
	for (auto i = selectedList.begin(); i != selectedList.end(); i++) 
	{
		if (*i == this) {  
			return true;
		}
	}
	return false;
}

void number::printNums() {};