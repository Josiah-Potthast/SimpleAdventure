#include "Spell.h"

Spell::Spell() : Spell(1.2)
{

}

Spell::Spell(int scaling) : level(1), experience(0), EXP_SCALING(scaling)
{

}

void Spell::cast(Entity* target)
{
	double expNeeded = 100;
	for (int i = 1; i < level; i++)
		expNeeded *= EXP_SCALING;

	experience += 10;
	if (experience >= expNeeded)
	{
		if (expNeeded <= experience)
			experience -= expNeeded;
		else
			experience = 0;
		level++;
	}
}

int Spell::getLevel() const
{
	return level;
}

SPELL_NAME Spell::getNameEnum() const
{
	return name;
}

string Spell::getName(SPELL_NAME spell)
{
	switch (spell)
	{
	case FIREBALL:
		return "fireball";
	case LIGHTNING_BOLT:
		return "lightning bolt";
	case FROST_BEAM:
		return "frost beam";
	case TELEKINESIS:
		return "telekinesis";
	case SWORD_WHISPERING:
		return "sword whispering";
	default:
		throw SpellNotFound();
	}
}