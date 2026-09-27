#include "Orc.h"

Orc::Orc(const std::string& name, float health, float attackDamage, bool isShield, int shieldPercent)
	: Character(name, health, attackDamage, isShield, shieldPercent)
{
}

void Orc::DecideAction(int percent, Character& target)
{
	Attack(target);
}

void Orc::Shield(int percent)
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

void Orc::TakeDamage(float attackDamage)
{
	if (bIsShield)
	{
		health -= attackDamage * 0.7f;
	}
	else
	{
		health -= attackDamage;
	}

}




