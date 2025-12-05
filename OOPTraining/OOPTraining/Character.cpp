#include "Character.h"
#include <iostream>

using namespace std;
namespace CharacterConsts
{
	constexpr int c_MaxHealth = 100;
}

Character::Character(string name, Weapon weapon) : m_health(100), m_mana(100), m_weapon(weapon), m_name(name), m_spell("None", 0, 0)
{
	// Creates a new Character
	// Defines its weapon and weaponDamage when creating a new one
	// Automatically initialises the health and mana values
}

//Character::Character(string name, Weapon weapon, Spell spell):Character(name, weapon), m_spell(spell)
//{
//
//}

Character::Character(string name, Weapon weapon, Spell spell) : m_name(name), m_health(100), m_mana(100), m_weapon(weapon), m_spell(spell)
{

}

Character::Character(Character const& other) : m_name(other.m_name), m_health(other.m_health), m_mana(other.m_mana), m_weapon(other.m_weapon), m_spell(other.m_spell)
{
	// Creates a new Character
	// Takes a reference to an already existing Character to create an exact copy of it
	// Multiple implementations allows to send different parameters when creating an object
}


void Character::receiveDamage(int damage)
{
	cout << m_name << " is taking " << damage << " damage!" << endl;
	m_health -= damage;

	if (m_health < 0)
	{
		m_health = 0;
	}
}

void Character::attack(Character &target)
{
	cout << m_name << " is attacking " << target.getName() << " with " << m_weapon.getName() << endl;
	target.receiveDamage(m_weapon.getDamage());
}

void Character::throwSpell(Character& target)
{
	
	if (m_mana - m_spell.getManaCost() >= 0)
	{
		cout << m_name << " is throwing " << m_spell.getName() << " at " << target.getName() << endl;
		m_mana -= m_spell.getManaCost();
		target.receiveDamage(m_spell.getDamage());
	}
	else
	{
		cout << m_name << " is trying to throw " << m_spell.getName() << " at " << target.getName() << " but doesn't have enough mana to cast the spell!" << endl;
	}
}

void Character::drinkHealthPotion(int quantity)
{
	cout << m_name << " drinks a health potion and restores " << quantity << " health points!" << endl;
	m_health += quantity;

	if (m_health > CharacterConsts::c_MaxHealth)
	{
		m_health = CharacterConsts::c_MaxHealth;
	}
}

void Character::changeWeapon(Weapon newWeapon)
{
	cout << m_name << " swaps their weapon for " << newWeapon.getName() << endl;
	m_weapon.changeWeapon(newWeapon.getName(), newWeapon.getDamage());
}

bool Character::isAlive() const
{
	return m_health > 0;
}

// Getters

string Character::getName() const
{
	return m_name;
}

int Character::getHealth() const
{
	return m_health;
}

int Character::getMana() const
{
	return m_mana;
}

void Character::displayState() const
{
	cout << m_name << endl;
	cout << "Health: " << m_health << endl;
	cout << "Mana: " << m_mana << endl;
	m_weapon.display();
	m_spell.display();
	cout << endl;
}

Character::~Character()
{
	/*Destruct
	Doesnt' do anything here
	Usually would delete dynamic allocation (new)
	And do several checks before destroying the object
	This is used to avoir memory leaks, and make sure the program frees the memory space when it's not needed anymore*/
}