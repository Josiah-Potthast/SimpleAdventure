#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include "Console.h"
using namespace std;

enum ITEM_NAME;

class Item
{
private:
	ITEM_NAME name;
	int weight;
public:
	Item(ITEM_NAME item, int weight);

	ITEM_NAME getNameEnum() const;

	virtual int use() = 0;
	virtual int getStatType() const = 0;
	virtual int getWeight() const;

	static string getName(ITEM_NAME item);

	class ItemNotFound {};
};

enum ITEM_NAME
{
	SWORD,
};

#endif