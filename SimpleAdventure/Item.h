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
	virtual bool use() = 0;
};

enum ITEM_NAME
{
	SWORD,
};

#endif