#pragma once

#include <string>
#include "Weapon.h"
#include "WeaponRanged.h"
#include "Spell.h"
#include "HealthPotion.h"

class Character
{

public:

	Character(std::string name, int range, Weapon weapon, WeaponRanged weaponRanged); // Constructor
	Character(std::string name, int range, Weapon weapon, Spell spell);
	Character(Character const& other);
	~Character(); // Destructor

	// FIGHT
	void receiveDamage(int damage);
	void attack(Character& target);
	void attackRanged(Character& target);
	void throwSpell(Character& target);

	// HEALING
	void drinkHealthPotion(HealthPotion healthPotion);

	// MISC
	void changeWeapon(Weapon newWeapon);
	void changeWeaponRanged(WeaponRanged newWeapon);
	void move(int speed, Character& target);
	bool isAlive() const; // Doesn't change the object, so is declared as const

	// Getters
	std::string getName() const;
	int getHealth() const;
	int getMana() const;
	int getRange() const;
	int getSpeed() const;

	void displayState() const;

private:

	// CHARACTER
	std::string m_name;
	int m_health;
	int m_mana;
	int m_speed;

	// WEAPONS
	Weapon m_weapon;
	WeaponRanged m_weaponRanged;
	Spell m_spell;

	// MISC
	int m_Range;
};

