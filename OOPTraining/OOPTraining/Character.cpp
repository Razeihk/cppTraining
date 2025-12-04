#include "Character.h"
#include <iostream>

using namespace std;

Character::Character() : m_health(100), m_mana(100), m_weapon()
{
	// Creates a new Character
	// Defines its weapon and weaponDamage when creating a new one
	// Automatically initialises the health and mana values
}

Character::Character(string weaponName, int weaponDamage) : m_health(100), m_mana(100)
{

}

Character::Character(Character const& other) : m_health(other.m_health), m_mana(other.m_mana), m_weapon(other.m_weapon)
{
	// Creates a new Character
	// Takes a reference to an already existing Character to create an exact copy of it
	// Multiple implementations allows to send different parameters when creating an object
}


void Character::receiveDamage(int damage)
{
	m_health -= damage;

	if (m_health < 0)
	{
		m_health = 0;
	}
}

void Character::attack(Character &target)
{
	target.receiveDamage(m_weapon.getDamage());
}

void Character::drinkHealthPotion(int quantity)
{
	m_health += quantity;

	if (m_health > 100)
	{
		m_health = 100;
	}
}

void Character::changeWeapon(string newWeaponName, int newWeaponDamage)
{
	m_weapon.changeWeapon(newWeaponName, newWeaponDamage);
}

bool Character::isAlive() const
{
	return m_health > 0;
}

void Character::displayState() const
{
	cout << "Health: " << m_health << endl;
	cout << "Mana: " << m_health << endl;
	m_weapon.display();
}

Character::~Character()
{
	/*Destruct
	Doesnt' do anything here
	Usually would delete dynamic allocation (new)
	And do several checks before destroying the object
	This is used to avoir memory leaks, and make sure the program frees the memory space when it's not needed anymore*/
}