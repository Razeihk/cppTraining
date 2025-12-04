#include "Character.h"

using namespace std;

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
	target.receiveDamage(m_weaponDamage);
}

void Character::drinkHealthPotion(int quantity)
{
	m_health += quantity;

	if (m_health < 100)
	{
		m_health = 100;
	}
}

void Character::changeWeapon(string newWeaponName, int newWeaponDamage)
{
	m_weapon = newWeaponName;
	m_weaponDamage = newWeaponDamage;
}

bool Character::isAlive()
{
	return m_health > 0;
}