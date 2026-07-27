#ifndef NONPLAYERCHARACTER_H
#define NONPLAYERCHARACTER_H
#include "Entity.h"

class NonPlayerCharacter : public Entity
{
private:

public:
	NonPlayerCharacter();
	NonPlayerCharacter(int maxHP, int maxMP, int maxSP);
};

#endif