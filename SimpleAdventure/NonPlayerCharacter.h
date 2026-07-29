#ifndef NONPLAYERCHARACTER_H
#define NONPLAYERCHARACTER_H
#include "Entity.h"
#include "PlayerCharacter.h"

enum NPC_NAME;

class NonPlayerCharacter : public Entity
{
private:
	NPC_NAME name;
public:
	NonPlayerCharacter();
	NonPlayerCharacter(int maxHP, int maxMP, int maxSP);

	int takeDamage(int damage, STAT_TYPE type = HEALTH) override;
	void dealDamage(int damage, Entity* target, STAT_TYPE type = HEALTH) override;

	NPC_NAME getNameEnum() const;
	static string getName(NPC_NAME npc);

	class NonPlayerCharacterNotFound {};
};

enum NPC_NAME
{
	DUMMY,
};

#endif