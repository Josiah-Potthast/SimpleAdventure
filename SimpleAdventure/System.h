#ifndef SYSTEM_H
#define SYSTEM_H
#include <iostream>
#include "Console.h"
#include "Game.h"
using namespace std;

class Game;

// holds and manages a vector of Game objects
class System
{
private:
	inline static vector<Game> games;
public:
	// creates a custom Game (unimplemented)
	static void startGame(/*parameters*/);
	// creates a default Game (mostly unimplemented)
	static void quickStart();
};

#endif