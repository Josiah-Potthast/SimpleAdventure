#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include "Console.h"
#include "Entity.h"
using namespace std;

enum ITEM_NAME;
class Entity;

// abstract base class of everything that can be put into the 
// iventory of an Entity
class Item
{
private:
	ITEM_NAME name;
	int weight;
public:
	// parameterized constructor
	Item(ITEM_NAME item, int weight);

	// pure virtual function
	// takes in an Entity* to use the Item on, and returns an int
	// as feedback, representing something different depending on
	// the type of Item
	virtual int use(Entity* target) = 0;
	// returns 0 for health, 1 for mana, and 2 for stamina
	virtual int getStatType() const;
	// returns the stamina cost of an item
	virtual int getWeight() const;

	// returns the name member
	ITEM_NAME getNameEnum() const;
	// returns a string representing the item type passed in
	static string getName(ITEM_NAME item);

	// thrown when a switch statement does not have a case for a
	// specified Item type
	class ItemNotFound {};
};

// used with switch statements to differentiate between items
enum ITEM_NAME
{
	SWORD,
	SPELLBOOK,
};

#endif