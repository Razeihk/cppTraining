#include <iostream>
#include "Weapon.h"

using namespace std;

Weapon::Weapon() : m_name("Epee rouillee"), m_damage(10)
{

}

Weapon::Weapon(string name, int damage) : m_name(name), m_damage(damage)
{

}

void Weapon::changeWeapon(std::string name, int damage)
{
	m_name = name;
	m_damage = damage;
}

int Weapon::getDamage() const
{
	return m_damage;
}

void Weapon::display() const
{
	cout << "Weapon: " << m_name << " (Damage: " << m_damage << ")" << endl;
}