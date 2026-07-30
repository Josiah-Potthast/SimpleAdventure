#include "Item.h"

Item::Item(ITEM_NAME item, int weight) : name(item), weight(weight)
{

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
	default:
		throw ItemNotFound();
	}
}

int Item::getWeight() const
{
	return weight;
}