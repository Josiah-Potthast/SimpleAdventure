#ifndef SPELL_H
#define SPELL_H
#include <iostream>
#include "Entity.h"
using namespace std;

enum SPELL_NAME;

// abstract base class for spells
class Spell
{
private:
	SPELL_NAME name;
	int level;
	int experience;
	const double EXP_SCALING;
public:
	// default constructor
	Spell();
	// parameterized constructor
	Spell(int scaling);
	// pure virtual function that takes an Entity* as the target
	// to cast the spell on
	virtual void cast(Entity* target) = 0;

	// returns level
	int getLevel() const;

	// returns the name member
	SPELL_NAME getNameEnum() const;
	// returns a string representing the spell type
	static string getName(SPELL_NAME spell);

	// thrown when a switch statement does not have a case for 
	// a given type of spell
	class SpellNotFound {};
};

// used with switch statements to differentiate between spells
enum SPELL_NAME
{
	FIREBALL,
	LIGHTNING_BOLT,
	FROST_BEAM,
	TELEKINESIS,
	SWORD_WHISPERING,
};

#endif