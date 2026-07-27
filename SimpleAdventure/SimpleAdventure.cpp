// Josiah Potthast
// Module 4 Lab: System Model

#include <iostream>
#include "System.h"
#include "Console.h"
using namespace std;

int main()
{
	PlayerCharacter player;
	Entity* target = new Dummy();
	player.gainItem(new Sword());
	player.gainItem(new Sword());
	player.gainItem(new Sword());
	player.equip(player.getInventory()[0]);
	for (int i = 0; i < 200; i++)
	{
		player.dealDamage(player.getHolding()->use(), target);
		Console::print("Dummy HP: " + to_string(target->getHP()) + "\n");
	}

	vector<Item*> i = player.getInventory();
	for (Item* p : i)
		Console::print(Item::enumToString(p->getName()) + "\n");
	while (player.getHP() > 0)
	{
		Console::print("HP: " + to_string(player.getHP()) + "\n");
		Console::print("XP: " + to_string(player.getExperience()) + "\n");
		Console::print("Lv: " + to_string(player.getLevel()) + "\n\n");
		player.takeDamage(1);
	}
}