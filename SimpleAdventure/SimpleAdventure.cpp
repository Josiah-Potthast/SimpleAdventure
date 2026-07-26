// Josiah Potthast
// Module 4 Lab: System Model

#include <iostream>
#include "System.h"
#include "Console.h"
using namespace std;

int main()
{
	PlayerCharacter player;
	while (player.getHP() > 0)
	{
		cout << "HP: " << player.getHP() << endl;
		cout << "XP: " << player.getExperience() << endl;
		cout << "Lvl: " << player.getLevel() << endl << endl;
		player.takeDamage(1);
	}
}