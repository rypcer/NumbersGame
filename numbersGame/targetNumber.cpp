#include "targetNumber.h"


void targetNumber::resetList() {
	// Initialize list with 10 given Numbers
	for (int i = 1; i <= 10; i++)
	{
		numberList::myNumbers.push_back(new givenNumber(i));
	}

}
#pragma region ActionFunctions

void targetNumber::add(number* x, number* y, int num1Index, int num2Index)
{
	int num1 = x->getValue();
	int num2 = y->getValue();
	int sum = num1 + num2;
	number* sumPtr = new compositeNumber(sum, x, y, '+', true);
	numberList::myNumbers.push_back(sumPtr);
	deleteByIndex(num1Index);
	deleteByIndex(num2Index);
	// IF number large enough stop generating
	if (sum >= 100 && sum <= 900) { targetNumPtr = sumPtr; targetNumberGenerated = true; }

	
}

void targetNumber::subtract(number* x, number* y, int num1Index, int num2Index)
{
	int num1 = x->getValue();
	int num2 = y->getValue();
	int sum = num1 - num2;
	number* sumPtr = new compositeNumber(sum, x, y, '-', true);
	if (num1 > num2)
	{
		numberList::myNumbers.push_back(sumPtr);
		deleteByIndex(num1Index);
		deleteByIndex(num2Index);
		if (sum >= 100 && sum <= 900) { targetNumPtr = sumPtr; targetNumberGenerated = true; }
		
	}

}

void targetNumber::multiply(number* x, number* y, int num1Index, int num2Index)
{
	int num1 = x->getValue();
	int num2 = y->getValue();
	int sum = num1 * num2;
	number* sumPtr = new compositeNumber(sum, x, y, '*', true);
	numberList::myNumbers.push_back(sumPtr);
	deleteByIndex(num1Index);
	deleteByIndex(num2Index);
	if (sum >= 100 && sum <= 900) { targetNumPtr = sumPtr; targetNumberGenerated = true; }
	
}

void targetNumber::divide(number* x, number* y, int num1Index, int num2Index)
{
	int num1 = x->getValue();
	int num2 = y->getValue();
	int sum = num1 / num2;
	
	if (num1 % num2 == 0)
	{
		number* sumPtr = new compositeNumber(sum, x, y, '/', true);
		numberList::myNumbers.push_back(sumPtr);
		deleteByIndex(num1Index);
		deleteByIndex(num2Index);
		if (sum >= 100 && sum <= 900) { targetNumPtr = sumPtr; targetNumberGenerated = true; }
	}

}

void targetNumber::print()
{
	cout << "One way of doing it was: ";
	targetNumPtr->printMe();
	cout << ".\n";
}


number* targetNumber::getPtrByIndex(int value)
{
	int i = 0;
	// Gets an unselected value that matches
	for (number* n : myNumbers) {
		if (value == i && !n->isSelected(selectedList))
		{
			return n;
		}
		i++;
	}
	// If no UNSELECTED VALUE was found
	return NULL;
}
void targetNumber::deleteByIndex(int value)
{
	int in = 0;
	// Gets first value that matches
	for (auto i = myNumbers.begin(); i != myNumbers.end(); i++) {
		if (in == value)
		{
			myNumbers.erase(i);
			return;
		}
		in++;
	}
}
void targetNumber::inputActions()
{
	srand(time(NULL));

	// Loop until suitable target number is generated
	while (!targetNumberGenerated) 
	{
		int op = rand() % 4;
		int num1Index = rand() % (myNumbers.size() - 1) + 1;
		int num2Index = rand() % (myNumbers.size() - 1) + 1;

		number* num1Ptr = getPtrByIndex(num1Index);
		// Number is added so num2 doesn't get the same pointer
		numberList::selectedList.push_back(getPtrByIndex(num1Index));
		number* num2Ptr = getPtrByIndex(num2Index);

		// If myNumbers has 2 items reset it
		if (numberList::myNumbers.size() == 2)
		{
			numberList::myNumbers.clear();
			resetList();
		}
		// Skips rest if Null
		if (num2Ptr == NULL) {}
		//When a number is more than 900 or all numbers are used up then reset myNumbers 
		else if (num1Ptr->getValue() > 900 || num2Ptr->getValue() > 900)
		{
			numberList::myNumbers.clear();
			resetList();
		}
		else if (op == 0)
		{
			add(num1Ptr, num2Ptr, num1Index, num2Index);
		}
		else if (op == 1)
		{
			subtract(num1Ptr, num2Ptr, num1Index, num2Index);
		}
		else if (op == 2)
		{
			multiply(num1Ptr, num2Ptr, num1Index, num2Index);
		}
		else if (op == 3)
		{
			divide(num1Ptr, num2Ptr, num1Index, num2Index);
		}
		//Clear selected numbers
		numberList::selectedList.clear();
	}
	// Assign generated number as targetNum
	numberList::targetNum = targetNumPtr->getValue();
}

#pragma endregion