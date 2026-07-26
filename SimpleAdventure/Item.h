#ifndef ITEM_H
#define ITEM_H

class Item
{
private:
public:
	virtual bool use() = 0;
	virtual int calcDamage() = 0;
};

#endif