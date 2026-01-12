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
	Character();
	Character(std::string Name, std::string& Weapon);
	Character(Character const& CharacterCopy);

	// FUNCTIONS
	void Attack(Character& Target);
	void ReceiveDamage(int Damage);


	// DISPLAY
	void DisplayCharacter() const;
	void DisplayWeaponPointer() const;

	// GETTERS
	std::string GetName() const;
	int GetHealth() const;


	// DESTRUCTOR
	~Character();

private:
	std::string m_Name = "NoName";
	int m_Health = c_MaxHealth;

	Weapon* m_Weapon = nullptr;
};