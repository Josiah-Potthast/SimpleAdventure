#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "PlayerCharacter.h"
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
public:
	Game();
	//Game(/*parameters*/);
};

enum DIFFICULTY
{
	HARD = 1,
	NORMAL = 2,
	EASY = 3,
};

#endif