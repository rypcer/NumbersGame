#include "givenNumber.h"

// Constructer
givenNumber::givenNumber(int _value) : number(_value, splitable) {}

// Functions
void givenNumber::printMe() { cout << value; }
bool givenNumber::isSplitable() { return splitable; }
bool givenNumber::isSelected(list<number*>& selectedList)
{
	for (auto i = selectedList.begin(); i != selectedList.end(); i++) {
		// prevent selecting other numbers with same value 
		if (*i == this) {  
			return true;
		}

	}
	return false;
}void givenNumber::printNums() 
{
	cout << value; //printMe();
};

