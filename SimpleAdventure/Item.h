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
public:
	Item(ITEM_NAME item);

	ITEM_NAME getName() const;

	virtual int use() = 0;

	static string enumToString(ITEM_NAME item);

	class ItemNotFound {};
};

enum ITEM_NAME
{
	SWORD,
};

#endif