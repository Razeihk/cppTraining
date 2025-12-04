#pragma once

#include <string>

class Character
{

public:

	void receiveDamage(int damage);
	void attack(Character& target);
	void drinkHealthPotion(int quantity);
	void changeWeapon(std::string newWeapon, int newWeaponDamage);
	bool isAlive();

private:

	int m_health;
	int m_mana;
	std::string m_weapon;
	int m_weaponDamage;
};

