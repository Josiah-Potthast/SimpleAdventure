#ifndef SPELLBOOK_H
#define SPELLBOOK_H
#include "Item.h"
#include "Spell.h"

class Spellbook : public Item
{
private:
	vector<Spell*> spells;
public:
	int use(Entity* target) override;
};

#endif