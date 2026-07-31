#ifndef SPELL_H
#define SPELL_H
#include <iostream>
#include "Entity.h"
using namespace std;

enum SPELL_NAME;

class Spell
{
private:
	SPELL_NAME name;
	int level;
	int experience;
	const double EXP_SCALING;
public:
	Spell();
	Spell(int scaling);
	virtual void cast(Entity* target) = 0;

	int getLevel() const;
	SPELL_NAME getNameEnum() const;
	static string getName(SPELL_NAME spell);

	class SpellNotFound {};
};

enum SPELL_NAME
{
	FIREBALL,
	LIGHTNING_BOLT,
	FROST_BEAM,
	TELEKINESIS,
	SWORD_WHISPERING,
};

#endif