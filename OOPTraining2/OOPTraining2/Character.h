#pragma once

#include <string>
#include "Weapon.h"

namespace CharacterConsts
{
	constexpr int c_MaxHealth = 100;
}
using namespace CharacterConsts;

class Character
{
public:
	// CONSTRUCTORS
	Character(std::string Name, std::string& Weapon);
	Character(Character const& CharacterCopy);

	// FUNCTIONS
	void BasicAttack(Character& Target);
	void ReceiveDamage(int Damage);


	// DISPLAY
	void DisplayCharacter() const;
	void DisplayWeaponPointer() const;


	// GETTERS
	std::string GetName() const;
	int GetHealth() const;


	// OPERATORS
	Character& operator=(Character const& CharacterToCopy); // The operator is mandatory when using a copy constructor


	// DESTRUCTOR
	~Character();

protected:
	std::string m_Name = "NoName";
	int m_Health = c_MaxHealth;

	Weapon* m_Weapon = nullptr;
};