#include "Goblin.h"


Goblin::Goblin(const std::string& name, float health, float attackDamage, bool isShield, int shieldPercent, float _shieldPower)
	: Character(name, health, attackDamage, isShield, shieldPercent, _shieldPower)
{

}

 void Goblin::DecideAction(int percent, Character& target) 
{
	if (percent < 3)
	{
		Attack(target);
		Attack(target);
	}
	else
	{
		Attack(target);
	}

}

