#include "Character.h"
#include <iostream>

Character::Character(const std::string& name, float health, float attackDamage, bool isShield, int shieldPercent)
	: name(name), health(health), attackDamage(attackDamage), bIsShield(isShield), shieldPercent(shieldPercent)
{
}




std::string Character::GetName() const
{
	return name;
}

float Character::GetHealth() const
{
	return health;
}

float Character::GetAttackDamage() const
{
	return attackDamage;
}

int Character::GetShieldPercent() const
{
	return shieldPercent;
}


void Character::SetName(const std::string& name)
{
	this->name = name;

}

void Character::SetHealth(float health)
{
	this->health = health;
}

void Character::SetAttackDamage(float attackDamage)
{
	this->attackDamage = attackDamage;

}

void Character::Attack(Character& target)
{
	if (IsDead())
		return;

	if (bIsShield)
	{
		std::cout << name << "이(가) 방어!" << std::endl;
		return;
	}



	if (target.IsDead() == false)
	{
		target.TakeDamage(attackDamage);
		std::cout << name << "이(가) 공격!" << std::endl;
	}


}

void Character::Shield(bool isShield)
{
	this->bIsShield = isShield;
}

void Character::TakeDamage(float attackDamage)
{
	if (bIsShield)
	{
		health -= attackDamage * 0.5f;
	}
	else
	{
		health -= attackDamage;
	}



}

bool Character::IsDead() const
{
	return health <= 0;
}
