#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "PlayerCharacter.h"
#include "NonPlayerCharacter.h"
#include "Dummy.h"
#include "Sword.h"
#include "Spellbook.h"
using namespace std;

enum DIFFICULTY;
class PlayerCharacter;

class Game
{
private:
	DIFFICULTY gamemode;
	PlayerCharacter player;
	vector<NonPlayerCharacter*> NPCs;

	// tally of non-abstract effects
	const int EFFECT_TYPES = 0;
	// tally of non-abstract items
	const int ITEM_TYPES = 1;
	// tally of non-abstract npcs
	const int NPC_TYPES = 1;
public:
	Game();
	Game(DIFFICULTY mode);

	int getNumNPCs() const;
	NonPlayerCharacter* getNPC(int index) const;
	void spawn(NPC_NAME npc);
	void despawn(NonPlayerCharacter* npc);

	EFFECT_NAME random(Effect* type) const;
	ITEM_NAME random(Item* type) const;
	NPC_NAME random(NonPlayerCharacter* type) const;

	class CannotSpawn {};
	class CannotDespawn {};
};

enum DIFFICULTY
{
	HARD = 1,
	NORMAL = 2,
	EASY = 3,
};

#endif