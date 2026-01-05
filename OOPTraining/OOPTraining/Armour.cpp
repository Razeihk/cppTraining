#include <iostream>
#include "Armour.h"

using namespace std;

Armour::Armour()
	:m_Name("Simple Armour"), m_damageReduction(1)
{

}

Armour::Armour(string name, int damageReduction)
	:m_Name(name), m_damageReduction(damageReduction)
{

}

void Armour::changeArmour(Armour newArmour)
{
	m_Name = newArmour.m_Name;
	m_damageReduction = newArmour.m_damageReduction;
}

// GETTERS
string Armour::getName() const
{
	return m_Name;
}

int Armour::getDamageReduction() const
{
	return m_damageReduction;
}

void Armour::display() const
{
	cout << "Armour: " << m_Name << " (Damage reduction: " << m_damageReduction << ")" << endl;
}