#ifndef DUMMY_H
#define DUMMY_H
#include "NonPlayerCharacter.h"

// high HP, actionless NPC, mostly for testing
class Dummy : public NonPlayerCharacter
{
private:
public:
	// default constructor
	Dummy();

	// prints a message and do nothing else
	void act(Entity* target) override;

	// prints a message and fully heals the Dummy
	void die();
};

#endif