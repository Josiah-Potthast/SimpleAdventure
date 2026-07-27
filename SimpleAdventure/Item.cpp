#include "Item.h"

Item::Item(ITEM_NAME item) : name(item)
{

}

ITEM_NAME Item::getName() const
{
	return name;
}

string Item::enumToString(ITEM_NAME item)
{
	switch (item)
	{
	case SWORD:
		return "sword";
	default:
		throw ItemNotFound();
	}
}