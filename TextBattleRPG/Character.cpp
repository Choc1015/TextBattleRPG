#include "Character.h"
#include <iostream>

using namespace std;

Character::Character(const std::string& name, float health, float attackDamage, bool isShield, int shieldPercent, float _shieldPower)
	: name(name), health(health), attackDamage(attackDamage), bIsShield(isShield), shieldPercent(shieldPercent), shieldPower(_shieldPower)
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

void Character::DecideAction(int percent, Character& target)
{
	Attack(target);
}



void Character::Attack(Character& target)
{
	if (IsDead())
		return;

	if (bIsShield)
	{
		cout << name << "이(가) 방어!" << endl;
		return;
	}



	if (target.IsDead() == false)
	{
		target.TakeDamage(attackDamage);
		std::cout << name << "이(가) 공격!" << std::endl;
	}


}

void Character::SetShield(bool isShield)
{
	this->bIsShield = isShield;
}

void Character::DecideShield(int roll)
{
	if (roll >= shieldPercent)
	{
		bIsShield = false;


	}
	else
	{
		bIsShield = true;
	}
}

void Character::TakeDamage(float damage)
{
	if (bIsShield)
	{
		health -= damage *(1 - shieldPower);
	}
	else
	{
		health -= damage;
	}



}

bool Character::IsDead() const
{
	return health <= 0;
}


