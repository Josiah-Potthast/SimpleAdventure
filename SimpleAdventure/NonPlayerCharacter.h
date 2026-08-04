#ifndef NONPLAYERCHARACTER_H
#define NONPLAYERCHARACTER_H
#include "Entity.h"
#include "PlayerCharacter.h"

enum NPC_NAME;

// abstract base class for all Entity subclasses except
// PlayerCharacter
class NonPlayerCharacter : public Entity
{
private:
	NPC_NAME name;
public:
	// default constructor
	NonPlayerCharacter();
	// parameterized constructor
	NonPlayerCharacter(int maxHP, int maxMP, int maxSP);

	// calls Entity::takeDamage() and descibes the result
	int takeDamage(int damage, STAT_TYPE type = HEALTH) override;
	// describes the attack, then calls takeDamage on the target
	void dealDamage(int damage, Entity* target, STAT_TYPE type = HEALTH) override;

	// returns the name member
	NPC_NAME getNameEnum() const;
	// returns a string representing the npc type
	static string getName(NPC_NAME npc);

	// thrown when a switch statement does not have a case
	// for a type of npc
	class NonPlayerCharacterNotFound {};
};

// used with switch statements to differentiate between npcs
enum NPC_NAME
{
	DUMMY,
};

#endif