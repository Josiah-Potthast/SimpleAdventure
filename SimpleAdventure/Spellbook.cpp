#include "Spellbook.h"

int Spellbook::use(Entity* target)
{
	if (spells.size() == 0)
		return 0;
	Console::print("Select a spell to cast:\n");
	vector<string> spellMenu;
	for (int i = 0; i < spells.size(); i++)
		spellMenu.push_back(spells[i]->getName(spells[i]->getNameEnum())
			+ " [" + to_string(spells[i]->getLevel()) + "]");
	int spellSub = Console::displayMenu(spellMenu);
	spells[spellSub]->cast(target);
}