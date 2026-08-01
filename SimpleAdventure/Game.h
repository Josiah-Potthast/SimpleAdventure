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

	// tally of effect types
	const int EFFECT_TYPES = 5;
	// tally of non-abstract items
	const int ITEM_TYPES = 2;
	// tally of non-abstract npcs
	const int NPC_TYPES = 1;
public:
	Game();
	Game(DIFFICULTY mode);
	~Game();

	int getNumNPCs() const;
	NonPlayerCharacter* getNPC(int index) const;
	void spawn(NPC_NAME npc);
	void despawn(NonPlayerCharacter* npc);
	void takeTurn(PlayerCharacter* player);
	void takeTurn(NonPlayerCharacter* npc);

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