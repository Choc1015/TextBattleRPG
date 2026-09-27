#pragma once
#include "Character.h"


class Goblin : public Character
{

public:

	Goblin(const std::string& name = "default", float health = 100, float attackDamage = 0, bool isShield = false, int shieldPercent = 2, float _shieldPower = 0.5f);
	void DecideAction(int percent, Character& target) override;






};