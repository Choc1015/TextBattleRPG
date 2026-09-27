#include "Goblin.h"


Goblin::Goblin(const std::string& name, float health, float attackDamage, bool isShield, int shieldPercent)
	: Character(name, health, attackDamage, isShield, shieldPercent)
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

 void Goblin::Shield(int percent)
 {
	 if (percent < shieldPercent)
	 {
		 bIsShield = false;


	 }
	 else
	 {
		 bIsShield = true;
	 }


 }
