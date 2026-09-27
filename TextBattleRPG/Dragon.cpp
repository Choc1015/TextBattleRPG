#include "Dragon.h"
#include <iostream>


Dragon::Dragon(const std::string& name, float health, float attackDamage, bool isShield, int shieldPercent, float _shieldPower)
	: Character(name, health, attackDamage, isShield, shieldPercent, _shieldPower)
{
}

void Dragon::DecideAction(int percent, Character& target)
{
	checkturn += 1;
	if (checkturn == 3 && IsDead() == false)
	{
		bIsShield = false;
		float temp = attackDamage;
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

