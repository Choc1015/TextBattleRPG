#pragma once
#include "Character.h"

class Dragon : public Character
{
private:
	int checkturn = 0;


public:
	Dragon(const std::string& name = "default", float health = 100, float attackDamage = 0, bool isShield = false, int shieldPercent = 5, float _shieldPower = 0.5f);


	void DecideAction(int percent, Character& target) override;





};