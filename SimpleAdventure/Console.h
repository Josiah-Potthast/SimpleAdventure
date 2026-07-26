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

	static void getInput(string& destination);
	static void getInput(int& destination);
	static void getInput(double& destination);

	static int getCharDelay();
	static void setCharDelay(int ms);

	class NegativeCharDelay {};
};

#endif