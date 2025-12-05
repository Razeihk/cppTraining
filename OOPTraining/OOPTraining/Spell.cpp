#include <iostream>
#include "Spell.h"

using namespace std;

Spell::Spell(string name, int manaCost, int damage) : m_name(name), m_manaCost(manaCost), m_damage(damage)
{

}

string Spell::getName() const
{
	return m_name;
}

int Spell::getManaCost() const
{
	return m_manaCost;
}

int Spell::getDamage() const
{
	return m_damage;
}

void Spell::display() const
{
	if (m_name != "None")
	{
		cout << "Spell: " << m_name << " (Damage: " << m_damage << ")" << endl;
	}
	else
	{
		cout << "No spell" << endl;
	}
}