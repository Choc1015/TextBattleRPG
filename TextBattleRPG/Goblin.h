#pragma once
#include "Character.h"


class Goblin : public Character
{

public:

	Goblin(const std::string& name = "default", float health = 0, float attackDamage = 0, bool isShield = false, int shieldPercnet = 2);
	void DecideAction(int percent, Character& target) override;
	void Shield(int percent) override;






};