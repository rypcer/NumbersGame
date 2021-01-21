//----------------------------------------------------
//	Code by Ajmal Sarif 2020 w1722688
//----------------------------------------------------
#include <iostream>
#include "compositeNumber.h"
#include "targetNumber.h"
#include "customLibrary.h";
#include <string>
using namespace std;

#pragma region Declarations
numberList currentNumbers;
targetNumber targetNumbers;
bool targetFound;
#pragma endregion


/* --------------------------------------------------
	It acts like a constructer so the class object 
	is initialized before game loop begins. 
	I could have done it with a constructer but then the variables
	would need to be declared inside main which wouldn't be a problem,
	but I preferred it this way. 
	-------------------------------------------------*/
void init() 
{
	//Generate Target Number and pass it in Players Numbers List
	targetNumbers.inputActions();
	currentNumbers.setTargetNum(targetNumbers.getTargetNum());
}

void getUserInput() 
{
	string num1;
	string num2;
	string action;
	bool skip = false;

	num1 = currentNumbers.inputcheck(num1,1,skip,"Enter 1st Number: ");
	action = currentNumbers.inputcheck(action,0,skip,"Enter Action: ");
	if (stringToUpper(action) == "QUIT") 
	{
		system("CLS");
		targetNumbers.print();
		exit(0);
	}
	if (!skip) 
		num2 = currentNumbers.inputcheck(num2, 1, skip, "Enter 2nd Number: "); 
	// Run the calculations
	currentNumbers.inputActions(num1,num2,action,skip);

	// Exit Loop after User successfully reached targetNumber
	if (currentNumbers.isTargetFound()) {
		targetNumbers.print();
		exit(0);
	}
}

void gameLoop() 
{
	while (!targetFound) 
	{
		cout << "Actions: QUIT, S=Split, + , - , *, / \n";
		currentNumbers.print();
		getUserInput();
		// Clear History of Game before printing new status
		system("CLS");
		
	}
}

int main(){

	init(); 
	gameLoop();

}