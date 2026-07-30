#include "Game.h"

Game::Game() : Game(NORMAL)
{

}

Game::Game(DIFFICULTY mode)
{
	gamemode = mode;
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