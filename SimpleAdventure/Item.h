#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include "Console.h"
#include "Entity.h"
using namespace std;

enum ITEM_NAME;
class Entity;

class Item
{
private:
	ITEM_NAME name;
	int weight;
public:
	Item(ITEM_NAME item, int weight);

	virtual int use(Entity* target) = 0;
	virtual int getStatType() const;
	virtual int getWeight() const;

	ITEM_NAME getNameEnum() const;
	static string getName(ITEM_NAME item);

	class ItemNotFound {};
};

enum ITEM_NAME
{
	SWORD,
	SPELLBOOK,
};

#endif