#include "Item.h"

Item::Item(ITEM_NAME item, int weight) : name(item), weight(weight)
{

}

int Item::getStatType() const
{
	return 0; // HP
}

int Item::getWeight() const
{
	return weight;
}

ITEM_NAME Item::getNameEnum() const
{
	return name;
}

string Item::getName(ITEM_NAME item)
{
	switch (item)
	{
	case SWORD:
		return "sword";
	case SPELLBOOK:
		return "spellbook";
	default:
		throw ItemNotFound();
	}
}