// Josiah Potthast
// Module 4 Lab: System Model

#include <iostream>
#include "System.h"
#include "Console.h"
using namespace std;

int main()
{
	vector<string> menu{ "Number one", "Number two", "Number three", "Number four", "Number five" };

	Console::displayMenu(menu);
	
	string str = "Hello World! This additional text is for testing purposes!\n";
	Console::print(str);
	Console::setCharDelay(30);
	Console::print(str, 10);

	Console::print(str);
}