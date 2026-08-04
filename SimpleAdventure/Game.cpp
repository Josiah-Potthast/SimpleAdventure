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

Item* Game::createItem(ITEM_NAME item)
{
	switch (item)
	{
	case SWORD:
		return new Sword();
	default:
		throw Item::ItemNotFound();
	}
}

void Game::giveItem(Item* item, Entity* target)
{
	if (target == nullptr)
		target = &this->player;

	target->gainItem(item);
}

void Game::giveItem(ITEM_NAME item, Entity* target)
{
	giveItem(createItem(item), target);
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
			if (choice == 1)
				currentMenu = &targetMenu;
			else if (choice == 2 && player->getHolding() == nullptr)
				Console::print("You are not holding an item\n");
			else if (choice == 2 && dynamic_cast<Weapon*>(player->getHolding()))
				Console::print("You are holding a weapon\n");
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
			if (choice == targetMenu.size())
				player->act(player);
			else
				player->act(NPCs[choice - 1]);
			takingTurn = false;
		}
	} 

	statusTrigger(player);
}

void Game::takeTurn(NonPlayerCharacter* npc)
{
	if (npc->getHolding() == nullptr && npc->getInventory().size() > 0)
		npc->equip(npc->getInventory()[0]);

	Entity* target = &player;
	if (dynamic_cast<Weapon*>(npc->getHolding()))
		target = &player;

	npc->act(target);

	statusTrigger(npc);
}

void Game::statusTrigger(Entity* target)
{
	int temp;
	const int BURN_DAMAGE = 5;
	if (target->effects.getStacks(SHOCK) >= (rand() % 100) + 1)
	{
		target->effects.inflict(STUN);
		// if stun lands, cure half the stacks of shock, rounded up
		target->effects.cure(SHOCK, (target->effects.getStacks(SHOCK) + 1) / 2);
	}
	if (temp = target->effects.getStacks(POISON))
		target->takeDamage(temp);
	if (target->effects.getStacks(BURN))
	{
		target->takeDamage(BURN_DAMAGE);
		target->effects.cure(BURN);
	}
	if (target->effects.getStacks(FREEZE))
	{
		target->takeDamage(5, STAMINA);
		target->effects.cure(FREEZE);
	}
}

void Game::playRound()
{
	takeTurn(&player);
	for (int i = 0; i < NPCs.size(); i++)
		takeTurn(NPCs[i]);
}

void Game::playGame()
{
	try
	{
		int round = 1;
		while (round)
			playRound();
	}
	catch (PlayerCharacter::GameOver e)
	{
		Console::print("Game Over\n");
		exit(EXIT_SUCCESS);
	}
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