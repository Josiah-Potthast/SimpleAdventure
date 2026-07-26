#include "Console.h"

void Console::print(string message, int tempDelay)
{
	for (int i = 0; i < message.length(); i++)
	{
		cout << message[i];
		this_thread::sleep_for(chrono::milliseconds(tempDelay));
	}
}

void Console::printNumberedList(const vector<string> list)
{
	for (int i = 0; i < list.size(); i++)
		print(list[i]);
}

void Console::getInput(string& destination)
{
	getline(cin, destination);
	cin.ignore(1000, '\n');
}

void Console::getInput(int& destination)
{
	cin >> destination;
	cin.ignore(1000, '\n');
}

void Console::getInput(double& destination)
{
	cin >> destination;
	cin.ignore(1000, '\n');
}

int Console::getCharDelay()
{
	return charDelay;
}

void Console::setCharDelay(int ms)
{
	if (ms >= 0)
		charDelay = ms;
	else
		throw NegativeCharDelay();
}