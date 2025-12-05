#pragma once

#include <string>
#include "Weapon.h"
#include "Spell.h"

class Character
{

public:

	Character(std::string name, Weapon weapon); // Constructor
	Character(std::string name, Weapon weapon, Spell spell);
	Character(Character const& other);
	~Character(); // Destructor

	void receiveDamage(int damage);
	void attack(Character& target);
	void throwSpell(Character& target);
	void drinkHealthPotion(int quantity);
	void changeWeapon(Weapon newWeapon);
	bool isAlive() const; // Doesn't change the object, so is declared as const

	// Getters
	std::string getName() const;
	int getHealth() const;
	int getMana() const;

	void displayState() const;

private:

	std::string m_name;
	int m_health;
	int m_mana;
	Weapon m_weapon;
	Spell m_spell;
};

