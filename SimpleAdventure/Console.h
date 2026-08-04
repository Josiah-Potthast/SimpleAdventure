#ifndef CONSOLE_H
#define CONSOLE_H
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <thread>
#include <chrono>
using namespace std;

// used by the rest of the program to display things and get input
class Console
{
private:
	inline static int charDelay = 10; // number of miliseconds between characters when printing
public:
	// takes in a string and optionally a temporary print speed, and prints it
	static void print(string message, int tempDelay = charDelay);
	// takes in a vector of strings and calls print() on each, numbering them
	static void printNumberedList(const vector<string> list);
	// takes in a vector of strings calls printNumberedList, gets a int from
	// the user validates it, and returns it
	static int displayMenu(vector<string> menu);

	// takes in a reference variable of type T, collects input with cin,
	// and clears the keyboard buffer
	template <class T>
	static void getInput(T& destination);
	// string overload uses getline(), allowing whitespaces
	static void getInput(string& destination);

	// returns the value of the static member charDelay
	static int getCharDelay();
	// sets the value of the static member charDelay
	// passing in a negative will set it to zero
	static void setCharDelay(int ms);

	class InvalidInput {};
};

template <class T>
static void Console::getInput(T& destination)
{
	cin >> destination;
	cin.ignore(1000, '\n');
	cin.unget();

	if (cin.fail())
		throw InvalidInput();
}

#endif