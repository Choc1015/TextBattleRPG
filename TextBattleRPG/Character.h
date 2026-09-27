#pragma once
#include <string>



class Character
{
protected:
	
	std::string	name;
	float health;
	float attackDamage;
	bool bIsShield;
	int shieldPercent;

public:

	Character(const std::string& name = "default", float health = 100, float attackDamage = 0, bool isShield = false, int shieldPercent = 2);

	std::string GetName() const;
	float GetHealth() const;
	float GetAttackDamage() const;
	int GetShieldPercent() const;

	void SetName(const std::string& name);
	void SetHealth(float health);
	void SetAttackDamage(float attackDamage);


	virtual void DecideAction(int percent, Character& target) {};
	void Attack(Character& target);
	void Shield(bool isShield);
	virtual void Shield(int percent) { printf("%s \n", "error"); };
	virtual void TakeDamage(float attackDamage);
	bool IsDead() const;


};