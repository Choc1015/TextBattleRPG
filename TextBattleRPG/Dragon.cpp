#include "Dragon.h"
#include <iostream>


Dragon::Dragon(const std::string& name, float health, float attackDamage, bool isShield, int shieldPercent)
	: Character(name, health, attackDamage, isShield, shieldPercent)
{
}

void Dragon::DecideAction(int percent, Character& target)
{
	checkturn += 1;
	if (checkturn == 3)
	{
		bIsShield = false;
		int temp = attackDamage;
		attackDamage *= 3;
		Attack(target);
		std::cout << "드래곤이 브레스를 뿜습니다!" << std::endl;
		checkturn = 0;
		attackDamage = temp;
	}
	else
	{
		Attack(target);
	}

}

void Dragon::Shield(int percent)
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
