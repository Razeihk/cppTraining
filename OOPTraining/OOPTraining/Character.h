#pragma once

#include <string>
#include "Weapon.h"

class Character
{

public:

	Character(); //Construct
	Character(std::string weaponName, int weaponDamage);
	Character(Character const& other);
	~Character(); // Destruct

	void receiveDamage(int damage);
	void attack(Character& target);
	void drinkHealthPotion(int quantity);
	void changeWeapon(std::string newWeapon, int newWeaponDamage);
	bool isAlive() const; // Doesn't change the object, so is declared as const
	void displayState() const;

private:

	int m_health;
	int m_mana;
	Weapon m_weapon;
};

