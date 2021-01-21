#include "customLibrary.h"

namespace customLibrary 
{

	bool isNumber(const std::string& s)
	{
		// Find a character that is a digit then return false otherwise true 
		return std::find_if(s.begin(), s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
	}
	std::string stringToUpper(std::string text)
	{
		std::string upperCaseString;
		for (char c : text)
		{
			upperCaseString.push_back(toupper(c));
		}
		return upperCaseString;
	}

	
};
