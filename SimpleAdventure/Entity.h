#ifndef ENTITY_H
#define ENTITY_H
#include <iostream>
#include <vector>
#include "Console.h"
#include "Effect.h"
#include "Item.h"
using namespace std;

// used with switch statements to differentiate between stats
enum STAT_TYPE
{
	HEALTH,
	MANA,
	STAMINA,
}; 
enum EFFECT_NAME;
enum ITEM_NAME;
class Effect;
class Item;

class Entity
{
private:
	int maxHP; // maximum hit points/health points
	int maxMP; // maximum mana points
	int maxSP; // maximum stamina points
	int HP; // current hit points/health points
	int MP; // current mana points
	int SP; // current stamina points
	vector<Item*> inventory; // the Items an Entity has
	Item* holding; // the currently equiped Item
	// returns a reference to the variable holding a stat
	int& getStat(STAT_TYPE type);
	// returns a reference to the variable holding a max stat
	int& getMaxStat(STAT_TYPE type);
protected:
	// default constructor
	Entity();
	// parameterized constructor
	Entity(int maxHP, int maxMP, int maxSP);
	// destructor
	virtual ~Entity();

	// sets max hp
	void setMaxHP(int maxHP);
	// sets max mp
	void setMaxMP(int maxMP);
	// sets max sp
	void setMaxSP(int maxSP);
	// sets current hp
	void setHP(int HP);
	// sets current mp
	void setMP(int MP);
	// sets current sp
	void setSP(int SP);
public:
	Effect effects; // tracks the status effects of an Entity

	// returns max hp
	int getMaxHP() const;
	// returns max mp
	int getMaxMP() const;
	// returns max sp
	int getMaxSP() const;
	// returns current hp
	int getHP() const;
	// returns current mp
	int getMP() const;
	// returns current sp
	int getSP() const;

	// takes in a pointer to an Entity and uses the currently
	// equiped item on it
	virtual void act(Entity* target);
	// takes in a damage amount and a damage type (default HP)
	// and reduces the current stat by that amount and returns it
	virtual int takeDamage(int damage, STAT_TYPE type = HEALTH) = 0;
	// takes in a damage amount, a target Entity, and a damage type (default HP)
	// and calls takeDamage() on it
	virtual void dealDamage(int damage, Entity* target, STAT_TYPE type = HEALTH);
	// increases a current stat by an amount, up the the corresponding max
	virtual void heal(int amount, STAT_TYPE type = HEALTH);

	// adds an Item to the inventory
	virtual void gainItem(Item* item);
	// assigns holding the address of an Item
	virtual void equip(Item* item);
	// returns the inventory
	vector<Item*> getInventory() const;
	// returns a vector of strings representing the inventory
	vector<string> getInventorList() const;
	// returns the address of the currently equiped Item
	Item* getHolding();

	// governs behavior when an Entity's HP reaches zero
	virtual void die() = 0;

	// thrown when attempting to set a stat to a negative number
	class NegativeStat {};
	// thrown when attempting to set a current stat higher than the max
	class StatOverMax {};
	// thrown when attempting to deal negative damage
	class NegativeDamage {};
};

#endif