#include "Warrior.h"
#include <iostream>
#include <string>

using namespace std;


// CONSTRUCTOR

Warrior::Warrior(string Name, string WeaponName, string ArmourType)
	: Character(Name, WeaponName), m_ArmourType(ArmourType)
{
	if (m_ArmourType == "Light armour")
	{
		m_ArmourEfficiency = 2;
	}
	else if (m_ArmourType == "Medium armour")
	{
		m_ArmourEfficiency = 4;
	}
	else if (m_ArmourType == "Heavy armour")
	{
		m_ArmourEfficiency = 7;
	}
}

void Warrior::DisplayCharacter() const // Masks the mother's function
{
	Character::DisplayCharacter(); // Unmasks the mother's function
	cout << "Armour type: " << m_ArmourType << endl;
}