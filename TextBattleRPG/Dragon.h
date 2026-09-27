#pragma once
#include "Character.h"

class Dragon : public Character
{
private:
	int checkturn = 0;


public:
	Dragon(const std::string& name = "default", float health = 0, float attackDamage = 0, bool isShield = false, int shieldPercent = 5);


	void DecideAction(int percent, Character& target) override;
	void Shield(int percent) override;





};