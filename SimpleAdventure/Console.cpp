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
	{
		print(to_string(i + 1) + ". ");
		print(list[i]);
		print("\n");
	}
}

int Console::displayMenu(vector<string> menu)
{
	int choice = 0;
	printNumberedList(menu);
	print("Input: ");
	getInput<int>(choice);

	while (choice < 1 || choice > menu.size())
	{
		print("That is not an option, please try again\n");
		printNumberedList(menu);
		print("Input: ");
		getInput<int>(choice);
	}

	return choice;
}

void Console::getInput(string& destination)
{
	getline(cin, destination);
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