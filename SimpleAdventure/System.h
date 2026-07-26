#ifndef SYSTEM_H
#define SYSTEM_H
#include <iostream>
#include "Console.h"
#include "Game.h"
using namespace std;

class Game;

class System
{
private:
	inline static vector<Game> games;
public:
	// getters and setters for settings
	static void startGame(/*parameters*/);
	static void quickStart();
};

#endif