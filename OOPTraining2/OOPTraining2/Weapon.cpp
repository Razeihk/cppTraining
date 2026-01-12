#include "Weapon.h"
#include <iostream>

using namespace std;

Weapon::Weapon(string Name)
	: m_Name(Name)
{
	if (m_Name == "Rusty sword")
	{
		m_Damage = 5;
	}
	else if (m_Name == "Spear")
	{
		m_Damage = 10;
	}
	else if (m_Name == "GreatSword")
	{
		m_Damage = 15;
	}
	else if (m_Name == "Double Axe")
	{
		m_Damage = 20;
	}
}

Weapon::Weapon(Weapon& const Weapon)
	:m_Name(Weapon.m_Name), m_Damage(Weapon.m_Damage)
{

}

void Weapon::DisplayWeapon() const
{
	cout << "Weapon name: " << GetName() << endl;
	cout << "Weapon damage: " << GetDamage() << endl;
}

// GETTERS

string Weapon::GetName() const
{
	return m_Name;
}

int Weapon::GetDamage() const
{
	return m_Damage;
}