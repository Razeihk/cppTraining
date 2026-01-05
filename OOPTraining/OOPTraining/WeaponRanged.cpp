#include <iostream>
#include "WeaponRanged.h"

using namespace std;

WeaponRanged::WeaponRanged()
	:m_Name("Bow"), m_Damage(1), m_Range(5)
{

}

WeaponRanged::WeaponRanged(string name, int damage, int range)
	:m_Name(name), m_Damage(damage), m_Range(range)
{

}

void WeaponRanged::changeWeapon(WeaponRanged newWeaponRanged)
{
	m_Name = newWeaponRanged.getName();
	m_Damage = newWeaponRanged.getDamage();
	m_Range = newWeaponRanged.getRange();
}

void WeaponRanged::display() const
{
	cout << "Ranged weapon: " << m_Name << "(Damage: " << m_Damage << ", Range:" << m_Range << ")" << endl;
}

string WeaponRanged::getName() const
{
	return m_Name;

}

int WeaponRanged::getDamage() const
{
	return m_Damage;
}

int WeaponRanged::getRange() const
{
	return m_Range;
}