#include "Game.h"

Game::Game() : Game(NORMAL)
{

}

Game::Game(DIFFICULTY mode) : player()
{
	gamemode = mode;
}

Game::~Game()
{
	for (int i = 0; i < NPCs.size(); i++)
	{
		delete NPCs[i];
		NPCs.pop_back();
	}
}

int Game::getNumNPCs() const
{
	return NPCs.size();
}

NonPlayerCharacter* Game::getNPC(int index) const
{
	return NPCs[index];
}

void Game::spawn(NPC_NAME npc)
{
	switch (npc)
	{
	case DUMMY:
		NPCs.push_back(new Dummy());
		break;
	default:
		throw CannotSpawn();
	}
}

void Game::despawn(NonPlayerCharacter* npc)
{
	for (int i = 0; i < NPCs.size() - 1; i++)
	{
		if (NPCs[i] == npc)
		{
			NonPlayerCharacter* temp = NPCs[i + 1];
			NPCs[i + 1] = NPCs[i];
			NPCs[i] = temp;
		}
	}
	if (NPCs[NPCs.size() - 1] == npc)
	{
		delete npc;
		NPCs.pop_back();
	}
	else
		throw CannotDespawn();
}

void Game::takeTurn(PlayerCharacter* player)
{
	bool takingTurn = true;
	if (player->effects.getStacks(STUN))
	{
		takingTurn = false;
		Console::print("You are stunned!\n");
		player->effects.cure(STUN);
	}

	vector<string> turnMenu{ "Attack", "Use Item", "Inventory" };
	vector<string> inventoryMenu = player->getInventorList();
	inventoryMenu.push_back("Close Inventory");
	vector<string> targetMenu;
	for (int i = 0; i < NPCs.size(); i++)
		targetMenu.push_back(NPCs[i]->getName(NPCs[i]->getNameEnum()));
	targetMenu.push_back("self");
	vector<string>* currentMenu = &turnMenu;
	while (takingTurn)
	{
		int choice = Console::displayMenu(*currentMenu);
		if (currentMenu == &turnMenu)
		{
			if (choice == 1 && !dynamic_cast<Weapon*>(player->getHolding()))
				Console::print("You are not holding a weapon\n");
			else if (choice == 1)
				currentMenu = &targetMenu;
			else if (choice == 2)
				currentMenu = &targetMenu;
			else if (choice == 3)
				currentMenu = &inventoryMenu;
		}
		else if (currentMenu == &inventoryMenu)
		{
			if (choice < inventoryMenu.size())
				player->equip(player->getInventory()[choice - 1]);
			currentMenu = &turnMenu;
		}
		else if (currentMenu == &targetMenu)
		{
			if (choice == targetMenu.size() - 1)
				player->act(player);
			else
				player->act(NPCs[choice - 1]);
			takingTurn = false;
		}
	} 

	if (player->effects.getStacks(SHOCK) >= (rand() % 100) + 1)
		player->effects.inflict(STUN);
	if (player->effects.getStacks(POISON))
		player->takeDamage(1);
	if (player->effects.getStacks(BURN))
	{
		player->takeDamage(5);
		player->effects.cure(BURN);
	}
	if (player->effects.getStacks(FREEZE))
	{
		player->takeDamage(5, STAMINA);
		player->effects.cure(FREEZE);
	}
}

void Game::takeTurn(NonPlayerCharacter* npc)
{

}

EFFECT_NAME Game::random(Effect* type) const
{
	if (type == dynamic_cast<Effect*>(type))
		return static_cast<EFFECT_NAME>(rand() % EFFECT_TYPES);
}

ITEM_NAME Game::random(Item* type) const
{
	if (type == dynamic_cast<Item*>(type))
		return static_cast<ITEM_NAME>(rand() % ITEM_TYPES);
}

NPC_NAME Game::random(NonPlayerCharacter* type) const
{
	if (type == dynamic_cast<NonPlayerCharacter*>(type))
		return static_cast<NPC_NAME>(rand() % NPC_TYPES);
}