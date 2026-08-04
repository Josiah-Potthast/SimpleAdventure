// Josiah Potthast
// Module 4 Lab: System Model

#include <iostream>
#include "System.h"
#include "Console.h"
using namespace std;

int main()
{
	System::quickStart();
	Game game;
	game.spawn(DUMMY);
	game.giveItem(SWORD);
	game.playGame();

	PlayerCharacter player;
	Entity* target = new Dummy();
	player.gainItem(new Sword());
	player.gainItem(new Sword());
	player.gainItem(new Sword());
	player.equip(player.getInventory()[0]);

	try
	{
		for (int i = 0; i < 200; i++)
		{
			player.act(target);
			Console::print("Dummy HP: " + to_string(target->getHP()) + "\n");
		}

		vector<Item*> i = player.getInventory();
		for (Item* p : i)
			Console::print(Item::getName(p->getNameEnum()) + "\n");
		while (player.getHP() > 0)
		{
			Console::print("HP: " + to_string(player.getHP()) + "\n");
			Console::print("XP: " + to_string(player.getExperience()) + "\n");
			Console::print("Lv: " + to_string(player.getLevel()) + "\n\n");
			player.takeDamage(5);
		}
	}
	catch (PlayerCharacter::GameOver e)
	{
		return 0;
	}
}