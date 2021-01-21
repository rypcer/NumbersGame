#include "numberList.h"


//Constructor
numberList::numberList() 
{
	// Initialize list with 10 given Numbers
	for (int i = 1; i <= 10; i++) 
	{
		myNumbers.push_back(new givenNumber(i));
	}
	userAnswer = new number (0, 0);
} 


#pragma region GetterSetters
int numberList::getTargetNum() { return targetNum; }
void numberList::setTargetNum(int _targetNum) { targetNum = _targetNum; }
#pragma endregion




#pragma region ActionFunctions
void numberList::add(number* x, number* y) 
{
	int num1 = x->getValue();
	int num2 = y->getValue();
	int sum = num1 + num2;
	number* sumPtr = new compositeNumber(sum, x, y, '+', true);
	myNumbers.push_back(sumPtr);
	deleteValue(num1);
	deleteValue(num2);
	// IF number large enough stop generating
	if (sum >= 100 && sum <= 900) { userAnswer = sumPtr; }
	
}

void numberList::subtract(number* x, number* y)
{
	int num1 = x->getValue();
	int num2 = y->getValue();
	int sum = num1 - num2;
	
	if (num1 > num2)
	{
		number* sumPtr = new compositeNumber(sum, x, y, '-', true);
		myNumbers.push_back(sumPtr);
		deleteValue(num1);
		deleteValue(num2);
		if (sum >= 100 && sum <= 900) { userAnswer = sumPtr; }
	}
	else
	{
		cout << "\n-- Cannot Subtract from Greater or Equal Number --\n";
		// Allows user to read the error message before its cleared
		Sleep(1200);
	}

}

void numberList::multiply(number* x, number* y)
{
	int num1 = x->getValue();
	int num2 = y->getValue();
	int sum = num1 * num2;
	number* sumPtr = new compositeNumber(sum, x, y, '*', true);
	myNumbers.push_back(sumPtr);
	
	deleteValue(num1);
	deleteValue(num2);
	if (sum >= 100 && sum <= 900) { userAnswer = sumPtr; }
	
}

void numberList::divide(number* x, number* y) 
{
	int num1 = x->getValue();
	int num2 = y->getValue();
	int sum = num1 / num2;
	
	if (num1 % num2 == 0)
	{
		number* sumPtr = new compositeNumber(sum, x, y, '/', true);
		myNumbers.push_back(sumPtr);
		deleteValue(num1);
		deleteValue(num2);
		if (sum >= 100 && sum <= 900) { userAnswer = sumPtr; }
	
	}
	else
	{
		cout << "\n-- Result would NOT produce a WHOLE Number --\n";
		Sleep(1200);
	}
	
}

void numberList::split(int x) 
{
	// Stops checking for further values
	bool singleCheck=1;
	for (number* n : myNumbers) 
	{
		if (x == n->getValue())
		{
			if (n->isSplitable()==true)
			{
				n->split(myNumbers);
				singleCheck = 0;
				break;
			}
		}
	}
	if(singleCheck){cout << "\n--- NOT SPLIT ABLE! ---\n"; Sleep(1200);}

}

bool numberList::isTargetFound() 
{ 
	if (userAnswer->getValue() == targetNum) {
		system("CLS");
		cout << " -- TARGET NUMBER FOUND-- \n\nYour way of doing was: ";
		userAnswer->printMe();
		cout << ".\n\n";
		return true;
	}
	return false; 
}

void numberList::print() 
{
	cout << "Your target Number is " << targetNum << ".\nYour current Numbers are: ";
	for (number *num : myNumbers) {
		num->printMe();
		cout << ",";
	}
	// Cursor moves 1 position backwards
	cout << '\b';  
	// Overwrites comma ',' with period
	cout << ".\n";   
}
#pragma endregion


#pragma region InputFunctions
bool numberList::isInsideList(string _userInput) 
{
	// Finds first value that matches
	int findThisValue = stoi(_userInput);
	for (number* num : myNumbers) {
		if(findThisValue == num->getValue())
			return true;
	}
	return false;
}

// Repeats until the correct value is entered by the user
string numberList::inputcheck(string userInput, bool isNumberInput,bool& skip, string message)
{
	cout << message;
	while (true)
	{
		cin >> userInput;
		// Checks for Number Input
		if (isNumberInput) {
			if (isNumber(userInput) && isInsideList(userInput))
			{
				return userInput;
			}
			else { cout << "\n----- " << userInput << " is not in your List of Numbers! -----" << endl << endl; }
		}
		// Checks for Actions Inputs
		else {
			userInput = stringToUpper(userInput);
			if (userInput == "QUIT" || userInput == "S" || userInput == "*" 
				|| userInput == "/" || userInput == "+" || userInput == "-")
			{
				(userInput=="S")?skip=1:skip=0;
				return userInput;
			}
			else { cout << "\n----- Try Again! -----" << endl << endl; }
		}
		cout << message;
		cin.clear();
		// Deletes everything until new line is reached which will also be deleted
		cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
	}

}

int numberList::getValue(int value)
{
	// Gets first value that matches
	for (number* n : myNumbers) {
		if (value == n->getValue())
		{
			return n->getValue();
		}
	}
}

number* numberList::getNumberPtr(int value)
{
	// Gets an unselected value that matches
	for (number* n : myNumbers) {
		if (value == n->getValue() && !n->isSelected(selectedList))
		{
			return n;
		}
	}
	// IF NO UNSELECTED VALUE WAS FOUND
	return NULL; 
}

void numberList::deleteValue(int value)
{
	// Gets first value that matches
	for (auto i = myNumbers.begin(); i != myNumbers.end(); i++) {
		if ((*i)->getValue() == value) {  
			myNumbers.erase(i);
			return;
		}
	}
}

void numberList::inputActions(const string& _num1 = string(), const string& _num2 = string(), string action = string(), const bool& skip = 0) 
{
	int num1 = getValue(stoi(_num1));
	number* num1Ptr = getNumberPtr(num1);
	selectedList.push_back(getNumberPtr(num1)); // Number is added so num2 doesn't get the same pointer

	// We skip this part if we split a number 
	if (!skip)
	{
		int num2 = getValue(stoi(_num2));
		number* num2Ptr = getNumberPtr(num2);
		if (num2Ptr == NULL) 
		{
			selectedList.clear();
			cout << "\n-- Cannot Select Same Value again! --\n";
			Sleep(1200);
		}
		else if (stringToUpper(action) == "+")
			add(num1Ptr,num2Ptr);
		else if (stringToUpper(action) == "-")
			subtract(num1Ptr, num2Ptr);
		else if (stringToUpper(action) == "*")
			multiply(num1Ptr,num2Ptr);
		else if (stringToUpper(action) == "/")
			divide(num1Ptr, num2Ptr);
	}
	if (stringToUpper(action) == "S")
		split(num1);
	//Clear selected numbers
	selectedList.clear();
}
#pragma endregion



