#ifndef DUMMY_H
#define DUMMY_H
#include "NonPlayerCharacter.h"

class Dummy : public NonPlayerCharacter
{
private:
public:
	Dummy();

	void act(Entity* target) override;

	void die();
};

#endif