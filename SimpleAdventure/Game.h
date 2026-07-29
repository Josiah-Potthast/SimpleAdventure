#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "PlayerCharacter.h"
#include "NonPlayerCharacter.h"
#include "Dummy.h"
#include "Sword.h"
using namespace std;

enum DIFFICULTY;
class PlayerCharacter;

class Game
{
private:
	DIFFICULTY gamemode;
	PlayerCharacter player;
	vector<NonPlayerCharacter*> NPCs;
public:
	Game();
	Game(DIFFICULTY mode);

	int getNumNPCs() const;
	NonPlayerCharacter* getNPC(int index) const;
	void spawn(NPC_NAME npc);
	void despawn(NonPlayerCharacter* npc);

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