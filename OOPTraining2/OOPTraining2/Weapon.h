#pragma once

#include <string>
class Weapon
{
public:
	Weapon(std::string Name);
	Weapon(Weapon& const Weapon); // Not really useful

	void DisplayWeapon() const;


	//GETTERS

	std::string GetName() const;
	int GetDamage() const;

private:
	std::string m_Name = "NoName";
	int m_Damage = 0;
};