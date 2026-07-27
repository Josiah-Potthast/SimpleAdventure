#include "Item.h"

Item::Item(ITEM_NAME item) : name(item)
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