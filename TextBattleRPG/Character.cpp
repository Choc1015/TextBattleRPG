#include "Character.h"


Character::Character(const std::string& name, float health, float attackDamage, bool isShield)
	: name(name),health(health), attackDamage(attackDamage), bIsShield(isShield)
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

void Character::SetShield(bool isShield)
{
	this->bIsShield = isShield;
}

void Character::Attack(Character& target)
{
	// target 캐싱하는 방법
	if (IsDead())
		return;

	if (bIsShield)
		return;


	if (target.IsDead() == false)
	{
		target.TakeDamage(attackDamage);
	}


}

void Character::TakeDamage(float attackDamage)
{
	if (bIsShield)
	{
		health -= attackDamage / 2;
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
