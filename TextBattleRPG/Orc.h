#pragma once
#include "Character.h"

class Orc : public Character
{

public:
	Orc(const std::string& name = "default", float health = 0, float attackDamage = 0, bool isShield = false, int shieldPercent = 7);


	void DecideAction(int percent, Character& target) override;
	void Shield(int percent) override;

	void TakeDamage(float attackDamage) override;


};
