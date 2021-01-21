//----------------------------------------------------
//	Code by Ajmal Sarif 2020 w1722688
//----------------------------------------------------
#pragma once
#include <iostream>
#include <string>
#include "number.h"
#include "customLibrary.h";
#include "givenNumber.h"
#include "compositeNumber.h"
#include <Windows.h>
using namespace std;
using namespace customLibrary;

class numberList 
{
protected:
	number* userAnswer;
	int targetNum = 0;
	list<number*>myNumbers;
	list<number*>selectedList;
public:
	//Constructor
	numberList();

	//Getters Setters
	int getTargetNum();
	void setTargetNum(int _targetNum);
	//Functions
	void add(number* x, number* y);
	void subtract(number* x, number* y);
	void multiply(number* x, number* y);
	void divide(number* x, number* y);
	void split(int x);
	bool isTargetFound();
	void print();
	//Additional Functions
	bool isInsideList(string _userInput);
	string inputcheck(string userInput, bool isNumberInput, bool& skip, string message);
	int getValue(int value);
	number* getNumberPtr(int value);
	void deleteValue(int value);
	void inputActions(const string& _num1, const string& _num2 , string action, const bool& skip);


};

