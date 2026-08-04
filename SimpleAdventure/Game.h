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

// manages the creation and destruction of most of the objects,
// as well as controlling the taking of turns
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
	// default constructor
	Game();
	// parameterized constructor
	Game(DIFFICULTY mode);
	// destructor
	virtual ~Game(); 

	// returns the size of the NPCs member
	int getNumNPCs() const;
	// returns a pointer to the npc in NPCs at a subscript
	NonPlayerCharacter* getNPC(int index) const;
	// creates a new npc and adds it to NPCs
	void spawn(NPC_NAME npc);
	// takes a pointer to an npc
	// if it is in the NPCs vector, removes it
	// if not, throws an exception
	void despawn(NonPlayerCharacter* npc);
	// takes in an ITEM_NAME enum and returns a dynamically
	// allocated object of that type
	Item* createItem(ITEM_NAME item);
	// gives an Item to an Entity, defaults to the player member
	void giveItem(Item* item, Entity* target = nullptr);
	// creates a new Item and gives it to an Entity,
	// defaulting to the player member
	void giveItem(ITEM_NAME item, Entity* target = nullptr);
	// uses menus to get user input for their action
	// calls statusTrigger at the end
	void takeTurn(PlayerCharacter* player);
	// uses the type of the currently held Item to determine 
	// an action
	// calls statusTrigger at the end
	void takeTurn(NonPlayerCharacter* npc);
	// checks and updates certain status effects,
	// triggered at the end of each turn
	void statusTrigger(Entity* target);
	// starting with the player, gives a turn to each Entity
	void playRound();
	// using an infinite loop, calls playRound() until a 
	// PlayerCharacter::GameOver exception is thrown
	void playGame();

	// returns a random EFFECT_NAME enum
	EFFECT_NAME random(Effect* type) const;
	// returns a random ITEM_NAME enum
	ITEM_NAME random(Item* type) const;
	// returns a random NPC_NAME enum
	NPC_NAME random(NonPlayerCharacter* type) const;

	// thrown when spawn() does not have a case statement for
	// the type passed in
	class CannotSpawn {};
	// thrown when the pointer passed into despawn() is not
	// in the NPCs vector
	class CannotDespawn {};
};

// used to scale certain aspects of a Game to make it 
// easier or harder (currently unimplemented)
enum DIFFICULTY
{
	HARD = 1,
	NORMAL = 2,
	EASY = 3,
};

#endif