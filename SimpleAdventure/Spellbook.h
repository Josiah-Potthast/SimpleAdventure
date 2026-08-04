#ifndef SPELLBOOK_H
#define SPELLBOOK_H
#include "Item.h"
#include "Spell.h"

// holds a list of known spells, and allows casting them
class Spellbook : public Item
{
private:
	vector<Spell*> spells;
public:
	// lets the user select one of the Spellbook's spells
	// to cast on the target
	int use(Entity* target) override;
};

#endif