#pragma once
#include <string>



class Character
{
private:
	
	std::string	name;
	float health;
	float attackDamage;
	bool bIsShield;

public:

	Character(const std::string& name = "default", float health = 0, float attackDamage = 0, bool isShield = false);
	std::string GetName() const;
	float GetHealth() const;
	float GetAttackDamage() const;

	void SetName(const std::string& name);
	void SetHealth(float health);
	void SetAttackDamage(float attackDamage);
	void SetShield(bool isShield);


	void Attack(Character& target);
	void TakeDamage(float attackDamage);
	bool IsDead() const;


};