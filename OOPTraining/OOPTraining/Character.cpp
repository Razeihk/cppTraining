#include "Character.h"
#include <iostream>

using namespace std;
namespace CharacterConsts
{
	constexpr int c_MaxHealth = 100;
}

Character::Character(string name, int range, Weapon weapon, WeaponRanged weaponRanged, Armour armour)
	: m_health(100), m_mana(100), m_Range(range), m_speed (10), 
	m_Armour(armour), m_weapon(weapon), m_name(name), m_weaponRanged(weaponRanged), m_spell("None", 0, 0)
{
	// Creates a new Character
	// Defines its weapon and weaponDamage when creating a new one
	// Automatically initialises the health and mana values
}

//Character::Character(string name, Weapon weapon, Spell spell):Character(name, weapon), m_spell(spell)
//{
//
//}

Character::Character(string name, int range, Weapon weapon, Spell spell, Armour armour)
	: m_name(name), m_health(100), m_mana(100), m_speed(10), m_Range(range),
	m_Armour(armour), m_weapon(weapon), m_weaponRanged("None", 0, 0), m_spell(spell)
{

}

Character::Character(Character const& other) : m_name(other.m_name), m_health(other.m_health), m_mana(other.m_mana), m_weapon(other.m_weapon), m_weaponRanged(other.m_weaponRanged), m_spell(other.m_spell)
{
	// Creates a new Character
	// Takes a reference to an already existing Character to create an exact copy of it
	// Multiple implementations allows to send different parameters when creating an object
}


void Character::receiveDamage(int damage)
{
	int actualDamge = damage - m_Armour.getDamageReduction();
	m_health -= actualDamge;

	if (m_health < 0)
	{
		m_health = 0;
	}

	cout << m_name << " is taking " << actualDamge << " damage!" << endl;
}

void Character::attack(Character &target)
{
	cout << m_name << " is attacking " << target.getName() << " with " << m_weapon.getName() << endl;
	target.receiveDamage(m_weapon.getDamage());
}

void Character::attackRanged(Character& target)
{
	cout << m_name << " is shooting at " << target.getName() << " with " << m_weaponRanged.getName() << endl;
	if (abs(m_Range - target.m_Range) < m_weaponRanged.getRange())
	{
		target.receiveDamage(m_weaponRanged.getDamage());
	}
	else
	{
		cout << m_name << " misses, the target is too far" << endl;
	}
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

void Character::drinkHealthPotion(HealthPotion healthPotion)
{
	cout << m_name << " drinks a " << healthPotion.getPotionType() << " Health Potion and restores " << healthPotion.getPotionHealth() << " health points!" << endl;
	m_health += healthPotion.getPotionHealth();

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

void Character::changeArmour(Armour newArmour)
{
	m_Armour.changeArmour(newArmour);
	cout << m_name << " changed their amour for a " << newArmour.getName() << endl;
}


void Character::changeWeaponRanged(WeaponRanged newWeapon)
{
	cout << m_name << " swaps their range weapon for " << newWeapon.getName() << endl;
	m_weaponRanged.changeWeapon(newWeapon);
}

void Character::move(int speed, Character& target)
{
	target.m_Range -= m_speed;
	if (target.m_Range < 0)
	{
		target.m_Range = 0;
	}
	cout << m_name << " moves toward " << target.getName() << " and is now at " << target.m_Range << " metres" << endl;
}

bool Character::isAlive() const
{
	return m_health > 0;
}

// GETTERS

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

int Character::getRange() const
{
	return m_Range;
}

int Character::getSpeed() const
{
	return m_speed;

}

void Character::displayState() const
{
	if (m_health > 0)
	{
		cout << m_name << endl;
		cout << "Health: " << m_health << endl;
		cout << "Mana: " << m_mana << endl;
		cout << "Distance from Hero: " << m_Range << endl;
		m_Armour.display();
		m_weapon.display();
		m_weaponRanged.display();
		m_spell.display();
		cout << endl;
	}
	else
	{
		cout << m_name << " is dead!" << endl << endl;
	}
}

Character::~Character()
{
	/*Destruct
	Doesnt' do anything here
	Usually would delete dynamic allocation (new)
	And do several checks before destroying the object
	This is used to avoir memory leaks, and make sure the program frees the memory space when it's not needed anymore*/
}