#ifndef CONSOLE_H
#define CONSOLE_H
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <thread>
#include <chrono>
using namespace std;

class Console
{
private:
	inline static int charDelay = 10; // number of miliseconds between characters when printing
public:
	static void print(string message, int tempDelay = charDelay);
	static void printNumberedList(const vector<string> list);
	static int displayMenu(vector<string> menu);

	template <class T>
	static void getInput(T& destination);
	static void getInput(string& destination);

	static int getCharDelay();
	static void setCharDelay(int ms);

	class NegativeCharDelay {};
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