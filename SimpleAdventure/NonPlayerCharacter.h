#ifndef NONPLAYERCHARACTER_H
#define NONPLAYERCHARACTER_H
#include "Entity.h"

enum NPC_NAME;

class NonPlayerCharacter : public Entity
{
private:
	NPC_NAME name;
public:
	NonPlayerCharacter();
	NonPlayerCharacter(int maxHP, int maxMP, int maxSP);

	NPC_NAME getNameEnum() const;
	static string getName(NPC_NAME npc);

	class NonPlayerCharacterNotFound {};
};

enum NPC_NAME
{

};

#endif